#include "data_products/wfd5/ODB.hh"
#include <numeric>

using namespace data_products::wfd5;

ODB::ODB()
    : DataProduct()
    ,wfd5_odb_string("")
{}

ODB::ODB(std::string wfd5_odb_string_arg)
    : DataProduct()
    ,wfd5_odb_string(wfd5_odb_string_arg)
{}

ODB::~ODB() {}

void ODB::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "ODB:" << std::endl;
    oss << wfd5_odb_string << std::endl;
    oss << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}