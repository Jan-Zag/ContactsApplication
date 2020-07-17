#include "Processor.h"
#include "Selector.h"
#include "dbmapper.h"
#include "Manipulator.h"
#include <mutex>

namespace db {

struct Processor::ProcessorPrivate
{
    Selector selector;
    Manipulator manipulator;
#ifdef BUILD_TESTS
    std::once_flag initialized;
    void insertMockData();
#endif
};

Processor::Processor()
    :m_d {new ProcessorPrivate{}}
{
}

Processor::~Processor()
{
}

#ifdef BUILD_TESTS
void Processor::ProcessorPrivate::insertMockData()
{
    manipulator.insertRow("Contacts", {{"Fred", "Wilson", "380993091846", "true"}});
    manipulator.insertRow("Contacts", {{"Bred", "Holson", "380993091841" , "false"}});
    manipulator.insertRow("Contacts", {{"Fredy", "Horson", "380993091842", "false"}});
    manipulator.insertRow("Contacts", {{"Glir", "Gason", "380993091843", "false"}});
    manipulator.insertRow("Contacts", {{"Maret", "Diter", "380993091844", "false"}});
    manipulator.insertRow("Contacts", {{"Alex", "Kilerson", "380993091845", "false"}});
    manipulator.insertRow("Contacts", {{"Vidy", "Bidy", "380993091847", "false"}});
    manipulator.insertRow("Contacts", {{"Po", "Kilop", "380993091848", "false"}});
    manipulator.insertRow("Contacts", {{"Ivan", "Chtorm", "380993091849", "false"}});
}
#endif

std::pair<DBResult, std::vector<DBEntry> > Processor::requestTableData(DBTables table)
{
#ifdef BUILD_TESTS
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
#endif
    const auto& result = m_d->selector.selectAll(TableMapper.at(table));
    return result;
}
}
