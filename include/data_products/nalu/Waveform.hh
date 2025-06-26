#ifndef NALU_WAVEFORM_HH 
#define NALU_WAVEFORM_HH

#include "data_products/nalu/Packet.hh"

namespace data_products::nalu {

    /**
     * @class Waveform
     * @brief Represents the waveform information for a NALU event.
     *
     * Inherits from DataProduct. Stores the waveforms.
     */
    class Waveform : public data_products::common::DataProduct {

        public:

            /**
             * @brief Default constructor.
             */
            Waveform();

            /**
             * @brief Constructor with packet collection.
             * @param packets A collection of packets
             */
            Waveform(PacketCollection packets);

            /**
             * @brief Destructor.
             */
            ~Waveform();

            /**
             * @brief Index of the event.
             */
            uint64_t channel_num;

            /**
             * @brief Trace for this channel
             */
            std::vector<short> trace;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the Waveform.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(Waveform,1)

    };

    /**
     * @typedef WaveformCollection
     * @brief A collection (vector) of Waveform objects.
     */
    typedef std::vector<Waveform> WaveformCollection;

} // namespace data_products::nalu

#endif // NALU_WAVEFORM_HH