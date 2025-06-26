#include "data_products/wfd5/WFD5ODB.hh"
#include <numeric>

using namespace dataProducts;

WFD5ODB::WFD5ODB()
    : DataProduct()
    ,wfd5_odb_string("")
{}

WFD5ODB::WFD5ODB(std::string wfd5_odb_string_arg)
    : DataProduct()
    ,wfd5_odb_string(wfd5_odb_string_arg)
{}

WFD5ODB::~WFD5ODB() {}

void WFD5ODB::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "WFD5ODB:" << std::endl;
    oss << wfd5_odb_string << std::endl;
    oss << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}