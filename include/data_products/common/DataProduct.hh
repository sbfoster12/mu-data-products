#ifndef DATAPRODUCT_HH  
#define DATAPRODUCT_HH

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>

#include <TH1.h>
#include <TObject.h>
#include <TRef.h>
#include <TRefArray.h>

namespace data_products::common {

    class DataProduct : public TObject {

        public:
            DataProduct();

            //Destructor
            virtual ~DataProduct();

            virtual void Show() const;

            ClassDef(DataProduct,1)
    };

    typedef std::vector<DataProduct> DataProductCollection;
    typedef std::vector<std::shared_ptr<DataProduct>> DataProductPtrCollection;
} // namespace data_products::common

#endif // DATAPRODUCT_HH