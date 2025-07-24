#ifndef WFD5_ODB_HH
#define WFD5_ODB_HH

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

            void Show() const override;

            ClassDefOverride(WFD5ODB,1)

    };

    typedef std::vector<WFD5ODB> WFD5ODBCollection;

} // namespace dataProducts

#endif // WFD5_ODB_HH