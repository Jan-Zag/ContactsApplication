#pragma once
#include <QString>

class Contact
{
    QString m_phone;
    QString m_firstName;
    QString m_surname;
    bool m_isFavorite;
public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phone, bool isFavorite);

    QString phone() const;
    QString firstName() const;
    QString surname() const;
    bool isFavorite() const;

    void setFavorite(const bool isFavorite);
};
