#pragma once
#include "dbtypes.h"
#include "Executor.h"
#include <QString>
#include <QVariantList>
#include <vector>

namespace db {
    class Selector
    {
    public:
        std::pair<DBResult, std::vector<DBEntry>> selectAll(const QString& tableName);

    private:
        Executor m_executor;

        QString generateQuery(const QString& tableName) const;
    };
}
