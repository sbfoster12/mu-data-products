#include "data_products/nalu/ODB.hh"

using namespace data_products::nalu;

ODB::ODB()
    : DataProduct()
    ,odb_string("")
{}

ODB::ODB(std::string odb_string_arg)
    : DataProduct()
    ,odb_string(odb_string_arg)
{}

ODB::~ODB() {}

void ODB::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "ODB:" << std::endl;
    oss << odb_string << std::endl;
    oss << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}