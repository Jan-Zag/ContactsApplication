#include "contact.h"

Contact::Contact(QString firstName, QString surname, QString phone, bool isFavorite)
    : m_phone {std::move(phone)},
      m_firstName{std::move(firstName)},
      m_surname {std::move(surname)},
      m_isFavorite {std::move(isFavorite)}

{

}

QString Contact::phone() const
{
    return m_phone;
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::surname() const
{
    return m_surname;
}

bool Contact::isFavorite() const
{
    return m_isFavorite;
}
