#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{
    const bool updateResult (updateContacts());
    if (!updateResult) {
        qWarning() << "Update contacts failed:";
    }
}

void ContactsModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NemaeRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNumberRole] = "phoneNumber";
    roles[ContactRoles::FavoriteRole] = "isFavorite";

    return roles;
}

int ContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  static_cast<int> (m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
    {
        return {};
    }

    const Contact& contact {m_contacts.at(index.row())};

    switch (role) {
    case ContactRoles::NemaeRole: {
        return QVariant::fromValue(contact.firstName());
    }
    case ContactRoles::SurnameRole: {
        return QVariant::fromValue(contact.surname());
    }
    case ContactRoles::PhoneNumberRole: {
        return QVariant::fromValue(contact.phone());
    }
    case ContactRoles::FavoriteRole: {
        return QVariant::fromValue(contact.isFavorite());
    }
    default: {
        return true;
    }
    }
}

bool ContactsModel::updateContacts()
{
    bool requestResult {false};
    std::vector<Contact> contactsResult;
    std::tie(requestResult, contactsResult) = m_contactsreader.requestContactsBrowse();

    if (requestResult) {
        m_contacts.swap(contactsResult);
        emit dataChanged(createIndex(0,0), createIndex(m_contacts.size(), 0));
    }

    return requestResult;
}
