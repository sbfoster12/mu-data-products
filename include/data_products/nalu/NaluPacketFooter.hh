#ifndef NALU_PACKETFOOTER_HH
#define NALU_PACKETFOOTER_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    /**
     * @class PacketFooter
     * @brief Represents the footer information for a NALU packet.
     *
     * Inherits from DataProduct.
     */
    class NaluPacketFooter : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluPacketFooter();

            /**
             * @brief Constructor with event index.
             * @param parser_index Parser index
             * @param packet_footer Packet footer
             */
            NaluPacketFooter(uint32_t parser_index, uint32_t packet_footer);

            /**
             * @brief Destructor.
             */
            ~NaluPacketFooter();

            /**
             * @brief Parser index.
             */
            uint32_t parser_index;

            /**
             * @brief Packet footer.
             */
            uint32_t packet_footer;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the PacketFooter.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluPacketFooter,1)
    };

    /**
     * @typedef PacketFooterCollection
     * @brief A collection (vector) of PacketFooter objects.
     */
    typedef std::vector<NaluPacketFooter> NaluPacketFooterCollection;

} // namespace dataProducts

#endif // NALU_PACKETFOOTER_HH
