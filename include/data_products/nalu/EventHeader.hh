#ifndef EVENTHEADER_HH   
#define EVENTHEADER_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class EventHeader
     * @brief Represents the header information for a NALU event.
     *
     * Inherits from DataProduct. Stores metadata such as the event index and number of packets.
     */
    class EventHeader : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            EventHeader();

            /**
             * @brief Constructor with event index.
             * @param ...
             */
            EventHeader(
                 uint16_t event_header
                ,uint16_t event_info
                ,uint32_t event_index
                ,uint32_t event_reference_time
                ,uint16_t packet_size
                ,uint64_t channel_mask
                ,uint16_t num_windows
                ,uint16_t num_packets);

            /**
             * @brief Destructor.
             */
            ~EventHeader();

            /**
             * @brief Event header.
             */
            uint16_t event_header;

            /**
             * @brief Event info.
             */
            uint16_t event_info;

            /**
             * @brief Index of the event.
             */
            uint32_t event_index;

            /**
             * @brief Event reference time.
             */
            uint32_t event_reference_time;

            /**
             * @brief Packet size.
             */
            uint16_t packet_size;

            /**
             * @brief Channel mask
             */
            uint64_t channel_mask;

            /**
             * @brief Number of windows
             */
            uint16_t num_windows;

            /**
             * @brief Number of packets.
             */
            uint16_t num_packets;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the EventHeader.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(EventHeader,1)
    };

    /**
     * @typedef EventHeaderCollection
     * @brief A collection (vector) of EventHeader objects.
     */
    typedef std::vector<EventHeader> EventHeaderCollection;

} // namespace data_products::nalu

#endif // EVENTHEADER_HH
