#ifndef NALU_ODB_HH
#define NALU_ODB_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class NaluODB : public DataProduct {

        public:
            NaluODB();

            NaluODB(std::string NaluODBString);

            //Destructor
            ~NaluODB();

            //Naluodb string
            std::string nalu_odb_string;

            void Show() const override;

            ClassDefOverride(NaluODB,1)

    };

    typedef std::vector<NaluODB> NaluODBCollection;

} // namespace dataProducts

#endif // NALU_ODB_HH