#ifndef NALU_ODB_HH
#define NALU_ODB_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    class ODB : public data_products::common::DataProduct {

        public:
            ODB();

            ODB(std::string ODBString);

            //Destructor
            ~ODB();

            //odb string
            std::string odb_string;

            void Show() const override;

            ClassDefOverride(ODB,1)

    };

    typedef std::vector<ODB> ODBCollection;

} // namespace data_products::nalu

#endif // NALU_ODB_HH