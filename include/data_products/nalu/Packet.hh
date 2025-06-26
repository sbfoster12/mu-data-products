#ifndef NALU_PACKET_HH
#define NALU_PACKET_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class Packet
     * @brief Represents the nalu packet for a NALU event.
     *
     * Inherits from DataProduct.
     */
    class Packet : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            Packet();

            /**
             * @brief Constructor with event index.
             * @param event_index Index of the event.
             */
            Packet(
                 uint64_t channel_num
                ,uint64_t window_position
                ,std::vector<short> trace
            );

            /**
             * @brief Destructor.
             */
            ~Packet();

            /**
             * @brief Channel of this packet.
             */
            uint64_t channel_num;

            /**
             * @brief Window position of this packet.
             */
            uint64_t window_position;

            /**
             * @brief Trace associated with this packet.
             */
            std::vector<short> trace;

            /**
             * @brief Display the contents of the Packet.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(Packet,1)
    };

    /**
     * @typedef PacketCollection
     * @brief A collection (vector) of Packet objects.
     */
    typedef std::vector<Packet> PacketCollection;

} // namespace data_products::nalu

#endif // NALU_PACKET_HH
