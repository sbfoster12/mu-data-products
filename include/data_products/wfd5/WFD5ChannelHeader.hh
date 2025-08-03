#ifndef WFD5_CHANNELHEADER_HH
#define WFD5_CHANNELHEADER_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class WFD5ChannelHeader : public DataProduct {

        public:
            WFD5ChannelHeader();

            WFD5ChannelHeader(unsigned int crateNumArg
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
            ~WFD5ChannelHeader();

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

            // Member variable pointer for defining iterations (none for channel header)
            static constexpr int WFD5ChannelHeader::* iterMemb = nullptr;

            void Show() const override;

            ClassDefOverride(WFD5ChannelHeader,1)
    };

    typedef std::vector<WFD5ChannelHeader> WFD5ChannelHeaderCollection;

} // namespace dataProducts

#endif // WFD5_CHANNELHEADER_HH