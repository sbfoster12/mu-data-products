#ifndef WFD5_ODB_HH
#define WFD5_ODB_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::wfd5 {

    class ODB : public data_products::common::DataProduct {

        public:
            ODB();

            ODB(std::string wfd5_odb_String);

            //Destructor
            ~ODB();

            //odb string
            std::string wfd5_odb_string;

            void Show() const override;

            ClassDefOverride(ODB,1)

    };

    typedef std::vector<ODB> ODBCollection;

} // namespace data_products::wfd5

#endif // WFD5_ODB_HH