#ifndef DATABASE_H
#define DATABASE_H

#include "project.h"

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>

/// Класс для работы с базой данных
class Database
{
public:
    /// Деструктор класса
    virtual ~Database();
    /// Метод подключения к базе данных
    bool connect(QObject *parent = nullptr);
    /// Метод закрытия базы данных
    void close();
    /// Вывод записей из базы данных
    void select();

    /// Метод добавления проекта в базу данных
    bool addProject(const Project &project);
    /// Метод редактирования проекта в базе данных
    bool editProject(const int id, const Project &project);
    /// Метод удаления проекта в базе данных
    bool deleteProject(const int id);

    /// Получение базы данных
    QSqlDatabase getDatabase();
    /// Возвращает модель базы данных
    QSqlQueryModel *getModel();

private:
    /// Возвращает id локации
    static int getObjectLocationId(const QString &city,
                                const QString &streetAddress,
                                const QString &postalCode);

    /// Хранит модель базы данных
    QSqlQueryModel *_model;
};

#endif // DATABASE_H
