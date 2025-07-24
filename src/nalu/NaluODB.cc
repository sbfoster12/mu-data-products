#include "data_products/nalu/NaluODB.hh"

using namespace dataProducts;

NaluODB::NaluODB()
    : DataProduct()
    ,nalu_odb_string("")
{}

NaluODB::NaluODB(std::string nalu_odb_string_arg)
    : DataProduct()
    ,nalu_odb_string(nalu_odb_string_arg)
{}

NaluODB::~NaluODB() {}

void NaluODB::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluODB:" << std::endl;
    oss << nalu_odb_string << std::endl;
    oss << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}