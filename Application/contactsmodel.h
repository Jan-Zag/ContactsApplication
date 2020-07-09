#pragma once
#include <QAbstractListModel>
#include <vector>
#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();

    static void registerMe(const std::string& moduleName);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

private:
    ContactsReader m_contactsreader;
    std::vector<Contact> m_contacts;
    enum ContactRoles{
        NemaeRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};
