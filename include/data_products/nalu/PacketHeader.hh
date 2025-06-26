#ifndef NALU_PACKETHEADER_HH   
#define NALU_PACKETHEADER_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class PacketHeader
     * @brief Represents the header information for a NALU packet.
     *
     * Inherits from DataProduct.
     */
    class PacketHeader : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            PacketHeader();

            /**
             * @brief Constructor with event index.
             * @param packet_header
             */
            PacketHeader(
                 uint16_t packet_header
                ,uint16_t packet_info
                ,uint16_t channel
                ,uint32_t trigger_time
                ,uint16_t logical_position
                ,uint16_t window_position
            );

            /**
             * @brief Destructor.
             */
            ~PacketHeader();

            /**
             * @brief Packet header.
             */
            uint16_t packet_header;

            /**
             * @brief Packet info
             */
            uint16_t packet_info;

            /**
             * @brief Channel
             */
            uint16_t channel;

            /**
             * @brief Trigger time
             */
            uint32_t trigger_time;

            /**
             * @brief Logical position
             */
            uint16_t logical_position;

            /**
             * @brief Window position
             */
            uint16_t window_position;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the PacketHeader.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(PacketHeader,1)
    };

    /**
     * @typedef PacketHeaderCollection
     * @brief A collection (vector) of PacketHeader objects.
     */
    typedef std::vector<PacketHeader> PacketHeaderCollection;

} // namespace data_products::nalu

#endif // NALU_PACKETHEADER_HH
