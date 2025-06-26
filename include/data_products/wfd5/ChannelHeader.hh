#ifndef WFD5_CHANNELHEADER_HH
#define WFD5_CHANNELHEADER_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::wfd5 {

    class ChannelHeader : public data_products::common::DataProduct {

        public:
            ChannelHeader();

            ChannelHeader(unsigned int crateNumArg
                ,unsigned int amcNumArg
                ,unsigned int waveformCountArg
                ,unsigned int waveformGapArg
                ,unsigned int channelTagArg
                ,unsigned int triggerNumArg
                ,unsigned int fillTypeArg
                ,unsigned int waveformLengthArg
                ,unsigned int DDR3AddressArg
                ,bool passedArg
                ,unsigned int preTriggerLength
                ,unsigned int eventLength
            );

            //Destructor
            ~ChannelHeader();

            //member variables

            // associated crate
            unsigned int crateNum;

            // associated slot
            unsigned int amcNum;

            // 12 bit Waveform Count
            unsigned int waveformCount;

            // 22 bit Waveform Gap
            unsigned int waveformGap;

            // 16 bit Channel Tag
            unsigned int channelTag;

            // 24 bit Trigger Number
            unsigned int triggerNum;

            // 3 bit Fill Type
            unsigned int fillType;

            // 23 bit Waveform Length
            unsigned int waveformLength;

            // 25 bit DDR3 start address
            unsigned int DDR3Address;

            // whether data integrity check passed
            bool passedIntegrityCheck;

            // 16 bit pre trigger length (async mode)
            unsigned int preTriggerLength;

            // 23 bit event length (async mode)
            unsigned int eventLength;

            void Show() const override;

            ClassDefOverride(ChannelHeader,1)
    };

    typedef std::vector<ChannelHeader> ChannelHeaderCollection;

} // namespace data_products::wfd5

#endif // WFD5_CHANNELHEADER_HH