#ifndef WFD5_ODB_HH
#define WFD5_ODB_HH

#include <map>

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class WFD5ODB : public DataProduct {

        public:
            WFD5ODB();

            WFD5ODB(std::string wfd5_odb_String);

            //Destructor
            ~WFD5ODB();

            //odb string
            std::string wfd5_odb_string;

            // file type
            std::string fileType; // "xml" or "json"

            // Digitization freqeuencies
            std::map<int,double> digitizationFrequencies; // Rider number to digitization frequency map

            // Parse XML
            void ParseXML();

            //Parse JSON
            void ParseJSON();

            // Get digitization frequency for a rider
            double GetDigitizationFrequency(int riderNum) const {
                auto it = digitizationFrequencies.find(riderNum);
                if (it != digitizationFrequencies.end()) {
                    return it->second;
                } else {
                    throw std::runtime_error("Digitization frequency for rider " + std::to_string(riderNum) + " not found.");
                }
            }

            void Show() const override;

            ClassDefOverride(WFD5ODB,1)

    };

    typedef std::vector<WFD5ODB> WFD5ODBCollection;

} // namespace dataProducts

#endif // WFD5_ODB_HH