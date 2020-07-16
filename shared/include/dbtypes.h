#pragma once
#include <QVariantList>

namespace db {
    enum class DBResult {
        OK,
        FAIL
    };

    enum class DBTables {
        Contacts
    };

    enum class DBState {
        OK,
        ERROR_NO_SQL_DRIVER,
        ERROR_SQL_WORKSPACE,
        ERROR_SQL_TABELS,
        ERROR_SQL_OPENING
    };

    using DBEntry = QVariantList;
    using DBIndex = int;
}
