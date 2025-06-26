#ifndef NALU_PACKETFOOTER_HH
#define NALU_PACKETFOOTER_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class PacketFooter
     * @brief Represents the footer information for a NALU packet.
     *
     * Inherits from DataProduct.
     */
    class PacketFooter : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            PacketFooter();

            /**
             * @brief Constructor with event index.
             * @param parser_index Parser index
             * @param packet_footer Packet footer
             */
            PacketFooter(uint32_t parser_index, uint32_t packet_footer);

            /**
             * @brief Destructor.
             */
            ~PacketFooter();

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
            ClassDefOverride(PacketFooter,1)
    };

    /**
     * @typedef PacketFooterCollection
     * @brief A collection (vector) of PacketFooter objects.
     */
    typedef std::vector<PacketFooter> PacketFooterCollection;

} // namespace data_products::nalu

#endif // NALU_PACKETFOOTER_HH
