#pragma once
#include <QString>

class Contact
{
    QString m_phone;
    QString m_firstName;
    QString m_surname;
public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phone);

    QString phone() const;
    QString firstName() const;
    QString surname() const;
};
