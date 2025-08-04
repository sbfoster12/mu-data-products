#include "data_products/common/RecoConfig.hh"

using namespace dataProducts;

RecoConfig::RecoConfig()
    : DataProduct(),
    jsonString("")
{}

RecoConfig::RecoConfig(const std::string& jsonStringArg) : DataProduct(),
    jsonString(jsonStringArg)
{}

RecoConfig::~RecoConfig() {};

void RecoConfig::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "RecoConfig: " << std::endl;
    oss << "    jsonString: " << jsonString << std::endl;
    std::cout << oss.str();
}