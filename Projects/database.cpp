#include "database.h"

#include <QSqlQuery>

Database::~Database()
{
    close();
}

bool Database::connect(QObject *parent)
{
    auto db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("cement");
    db.setUserName("postgres");
    db.setPassword("sergey12");

    if (!db.open()) {
        return false;
    }

    _model = new QSqlQueryModel(parent);

    return true;
}

void Database::close()
{
    delete _model;
    {
        getDatabase().close();
    }
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

void Database::select()
{
    _model->setQuery("SELECT p.id, p.suplier, p.inn, l.city, "
                    "l.street_address, l.postal_code "
                    "FROM projects p "
                    "JOIN locations l "
                    "ON p.location_id = l.location_id");
}

bool Database::addProject(const Project &project)
{
    QSqlQuery query;

    query.prepare("INSERT INTO projects "
        "(suplier, inn, location_id) "
        "VALUES (:suplier, :inn, :location_id)");

    int location_id = getObjectLocationId(project.city(),
                                          project.streetAddress(),
                                          project.postalCode());

    query.bindValue(":suplier", project.appointment());
    query.bindValue(":inn", project.customer());
    query.bindValue(":location_id", location_id);

    return query.exec();
}

bool Database::editProject(const int id, const Project &project)
{
    QSqlQuery query;

    query.prepare("UPDATE projects "
    "SET suplier = :suplier, inn = :inn,  "
    "location_id = :location_id WHERE id = :id");

    int location_id = getObjectLocationId(project.city(),
                                          project.streetAddress(),
                                          project.postalCode());

    query.bindValue(":id", id);
    query.bindValue(":suplier", project.appointment());
    query.bindValue(":inn", project.customer());
    query.bindValue(":location_id", location_id);

    return query.exec();
}

bool Database::deleteProject(const int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM projects WHERE id = :id");

    query.bindValue(":id", id);

    return query.exec();
}

QSqlDatabase Database::getDatabase()
{
    return QSqlDatabase::database();
}

QSqlQueryModel *Database::getModel()
{
    return _model;
}

int Database::getObjectLocationId(const QString &city,
                                  const QString &streetAddress,
                                  const QString &postalCode)
{
    QSqlQuery query;

    query.prepare("SELECT location_id FROM locations "
                  "WHERE street_address = :street_address "
                  "and postal_code = :postal_code");

    query.bindValue(":street_address", streetAddress);
    query.bindValue(":postal_code", postalCode);

    query.exec();
    query.next();

    if (query.numRowsAffected() == 0) {
        query.prepare("INSERT INTO locations (city, street_address, postal_code) "
                    "VALUES (:city, :street_address, :postal_code) RETURNING location_id");

        query.bindValue(":city", city);
        query.bindValue(":street_address", streetAddress);
        query.bindValue(":postal_code", postalCode);

        query.exec();
        query.next();
    }

    return query.value(0).toInt();
}
