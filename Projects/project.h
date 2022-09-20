#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

class Project
{
public:
    /// Конструктор по умолчанию
    Project();
    /// Конструктор с параметрами
    Project(QString appointment,
           QString customer,
           QString city,
           QString streetAddress,
           QString postalCode);

    QString appointment() const;
    void setAppointment(const QString &appointment);

    QString customer() const;
    void setCustomer(const QString &customer);

    QString city() const;
    void setCity(const QString &city);

    QString streetAddress() const;
    void setStreetAddress(const QString &streetAddress);

    QString postalCode() const;
    void setPostalCode(const QString &postalCode);

private:
    /// Назначение объекта
    QString _appointment;
    /// Заказчик объекта
    QString _customer;
    /// Город нахождения объекта
    QString _city;
    /// Уличный адрес объекта
    QString _streetAddress;
    /// Почтовый индекс
    QString _postalCode;
};

#endif // PROJECT_H
