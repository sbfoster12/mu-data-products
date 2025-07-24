#ifndef NALU_WAVEFORM_HH 
#define NALU_WAVEFORM_HH

#include "data_products/nalu/NaluPacket.hh"

namespace dataProducts {

    /**
     * @class Waveform
     * @brief Represents the waveform information for a NALU event.
     *
     * Inherits from DataProduct. Stores the waveforms.
     */
    class NaluWaveform : public DataProduct {

        public:

            /**
             * @brief Default constructor.
             */
            NaluWaveform();

            /**
             * @brief Constructor with packet collection.
             * @param packets A collection of packets
             */
            NaluWaveform(NaluPacketCollection packets);

            /**
             * @brief Destructor.
             */
            ~NaluWaveform();

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
            ClassDefOverride(NaluWaveform,1)

    };

    /**
     * @typedef WaveformCollection
     * @brief A collection (vector) of Waveform objects.
     */
    typedef std::vector<NaluWaveform> NaluWaveformCollection;

} // namespace dataProducts

#endif // NALU_WAVEFORM_HH