#include "contactsreader.h"

namespace  {
const std::vector<Contact> mockData{
    {"Whyle", "Johns", "380999091846"},
    {"Asher", "Blanjkef", "380993091847"},
    {"Eric", "French", "380993091843"},
    {"Michael", "Cooper", "380993091846"},
    {"Simon", "Vinter", "380935094805"},
    {"Vilson", "Vade", "380954032423"},
    {"Kate", "Brook", "380992302310"},
    {"Whyle", "Johns", "380999091846"},
    {"Asher", "Blanjkef", "380993091847"},
    {"Eric", "French", "380993091843"},
    {"Michael", "Cooper", "380993091846"},
    {"Simon", "Vinter", "380935094805"},
    {"Vilson", "Vade", "380954032423"},
    {"Kate", "Brook", "380992302310"}
};
}

std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, mockData);
}
