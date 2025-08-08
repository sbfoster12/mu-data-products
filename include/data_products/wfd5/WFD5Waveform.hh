#ifndef WFD5_WAVEFORM_HH
#define WFD5_WAVEFORM_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class WFD5Waveform : public DataProduct {

        public:
            WFD5Waveform();

            WFD5Waveform(int crateNum
                ,int amcNum
                ,int channelTag
                ,int eventNum
                ,int waveformIndex
                ,unsigned int length
                ,double pedestalLevel
                ,double pedestalStdev
                ,int firstSampleNum
                ,unsigned long clockCounter
                ,int preTriggerLength 
                ,int runNum
                ,int subRunNum
                ,std::vector<short> trace
            );

            WFD5Waveform(WFD5Waveform* w);

            //Destructor
            ~WFD5Waveform();

            // run/subrun number
            int runNum;
            int subRunNum;

            // Crate number
            int crateNum;

            // AMC slot number
            int amcNum;

            // Channel tag
            int channelTag;

            // Event number
            int eventNum;

            // index of this waveform
            int waveformIndex;

            // Number of samples in the waveform
            unsigned int length;

            // ADC count of pedestal level
            double pedestalLevel;
            double pedestalStdev;
            std::vector<short> pedestalSamples;
            int pedestalStartSample;

            double x,y;
            bool is_clipping;

            // first sample number of the trace
            int firstSampleNum;

            // 40 MHz TTC trigger timestamp
            unsigned long clockCounter;

            // pre trigger length
            int preTriggerLength;
            double digitizationFrequency;
            int digitizationShift; //number of 40 MHz clock cycles to shift this by, relative to the T0 trigger

            // ADC count of each sample
            std::vector<short> trace;

            //detector system and subdetector
            std::string detectorSystem;
            std::string subdetector;
            
            // visualization utilities
            void Show() const override;

            void SetDetectorSystem(const std::string& system) {
                detectorSystem = system;
            }
            void SetSubdetector(const std::string& subdet) {
                subdetector = subdet;
            }

            void JitterCorrect(int evenOddDiff);

            double PeakToPeak();
            int GetPeakIndex();
            void InvertPulse();
            void SetRunSubrun(int run, int subrun) {runNum=run; subRunNum=subrun;};

            dataProducts::ChannelID GetID() const { return {crateNum, amcNum, channelTag}; }

            TRef raw;

            // Member variable pointer for defining iterations
            static constexpr auto iterMemb = &WFD5Waveform::waveformIndex;

            ClassDefOverride(WFD5Waveform,4)

    };

    typedef std::vector<WFD5Waveform> WFD5WaveformCollection;
} // namespace dataProducts

#endif // WFD5_WAVEFORM_HH