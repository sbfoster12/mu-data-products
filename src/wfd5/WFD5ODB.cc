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
    ,digitizationFrequencies({})
{
    // First, determine the file type
    // Is 'xml version' in the string?
    if (wfd5_odb_string.find("xml version") != std::string::npos) {
        // This is an XML string, so we can parse it
        fileType = "xml";
        ParseXML();
    } else {
        fileType = "json";
        ParseJSON();
    }
}

void WFD5ODB::ParseXML() {
    std::cout << "-> reco::WFD5ODB: Parsing XML odd." << std::endl;

    // Parse each line of the odb string for the digitization frequencies
    int riderNum = -1;
    double digitizationFreq = 0;
    std::istringstream iss(wfd5_odb_string);
    std::string line;
    while (std::getline(iss, line)) {
        // Check if line contains <dir name="Rider">
        if (line.find("<dir name=\"Rider") != std::string::npos) {
            // std::cout << line << std::endl;
            std::string prefix = "Rider";
            auto pos = line.find(prefix);
            if (pos != std::string::npos) {
                std::string number = line.substr(pos + prefix.size(),
                                                line.find('"', pos) - (pos + prefix.size()));
                riderNum = std::stoi(number); // convert to int
            }
        }
        if (line.find("Digitization") != std::string::npos) {
            // std::cout << line << std::endl;
            auto start = line.find('>');
            auto end   = line.find('<', start + 1);
            std::string value = line.substr(start + 1, end - start - 1);
            // Convert the value to an integer
            int freq = std::stoi(value);
            digitizationFreq = static_cast<double>(freq);
            digitizationFrequencies[riderNum] = digitizationFreq;
        }
        // std::cout << line << std::endl;
    }
}

void WFD5ODB::ParseJSON() {
    std::cout << "-> reco::WFD5ODB: Warning: Parsing JSON odb not implemented yet.." << std::endl;
}

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