#ifndef RecoConfig_HH   
#define RecoConfig_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class RecoConfig : public DataProduct {

        public:
            RecoConfig();

            RecoConfig(const std::string& jsonStringArg);

            //Destructor
            ~RecoConfig();

            //member variables

            // json string
            std::string jsonString;

            // Member variable pointer for defining iterations (none for reco config)
            static constexpr int RecoConfig::* iterMemb = nullptr;

            void Show() const override;

            ClassDefOverride(RecoConfig,1)

    };

    typedef std::vector<RecoConfig> RecoConfigCollection;
} // namespace dataProducts

#endif // RecoConfig_HH