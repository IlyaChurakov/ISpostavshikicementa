#include "project.h"

Project::Project()
{ }

Project::Project(QString appointment,
               QString customer,
               QString city,
               QString streetAddress,
               QString postalCode)
    : _appointment(appointment)
    , _customer(customer)
    , _city(city)
    , _streetAddress(streetAddress)
    , _postalCode(postalCode)
{ }

QString Project::appointment() const
{
    return _appointment;
}

void Project::setAppointment(const QString &appointment)
{
    _appointment = appointment;
}

QString Project::customer() const
{
    return _customer;
}

void Project::setCustomer(const QString &customer)
{
    _customer = customer;
}

QString Project::city() const
{
    return _city;
}

void Project::setCity(const QString &city)
{
    _city = city;
}

QString Project::streetAddress() const
{
    return _streetAddress;
}

void Project::setStreetAddress(const QString &streetAddress)
{
    _streetAddress = streetAddress;
}

QString Project::postalCode() const
{
    return _postalCode;
}

void Project::setPostalCode(const QString &postalCode)
{
    _postalCode = postalCode;
}
