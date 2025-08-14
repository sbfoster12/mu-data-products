#ifndef WFD5_WAVEFORM_HH
#define WFD5_WAVEFORM_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    struct WaveformPeaks{
        int npeaks;
        std::vector<int> peak_times;
        std::vector<double> peak_amplitudes;
    };

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
            double customOffsetClockTicks; // set shift relative to t0 in terms of a number of 1.25 ns (800 MS/s) clock ticks
            double GetTime(double time, bool ct_to_ns = false);
            double GetFirstSampleTime(bool ct_to_ns = false) { return GetTime(0.0, ct_to_ns); };
            std::vector<double> GetTimes(bool ct_to_ns = false);
            void SetTimeOffset(double offset) {customOffsetClockTicks = -1.0*offset;};
            void SetTimeOffset(WFD5Waveform* wf, double offset=0.0) {SetTimeOffset(wf->GetTime(offset));};

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

            WaveformPeaks FindPeaks(int averaging_window = 1, double n_stdev = 3.0, 
                                    int samples_before = 15, int samples_after = 25, 
                                    int dead_time = 25);

            void JitterCorrect(int evenOddDiff);

            double PeakToPeak();
            double PeakToPeak(int b1, int b2);
            int GetPeakIndex();
            int GetPeakIndexInBounds(int b1, int b2);

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