#include "data_products/common/RecoConfig.hh"

using namespace dataProducts;

RecoConfig::RecoConfig()
    : DataProduct(),
    jsonString("")
{}

RecoConfig::RecoConfig(const std::string& jsonStringArg, int runArg, int subrunArg) : DataProduct(),
    jsonString(jsonStringArg),
    run(runArg),
    subrun(subrunArg)
{}

RecoConfig::~RecoConfig() {};

void RecoConfig::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "RecoConfig: " << std::endl;
    oss << "    jsonString: " << jsonString << std::endl;
    oss << "    run: " << run << std::endl;
    oss << "    subrun: " << subrun << std::endl;
    std::cout << oss.str();
}