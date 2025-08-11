#ifndef WaveformIntegral_HH 
#define WaveformIntegral_HH

#include "data_products/common/DataProduct.hh"
#include "data_products/wfd5/WFD5Waveform.hh"
#include <numeric>
#include <string>

namespace dataProducts {

    struct SeededIntegralConfig{
        int trigger_low;
        int trigger_high;
    };

    class WaveformIntegral : public DataProduct {

        public:
            WaveformIntegral();

            WaveformIntegral(WFD5Waveform* waveform, double nsigma=10.0, int search_method=0, std::tuple<int,int> presample_config={10,250}, int seed_index=-1, int seeded_search_window=-1);
            WaveformIntegral(WaveformIntegral* uncalibrated);

            //Destructor
            ~WaveformIntegral();

            // run/subrun
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

            // Number of samples in the WaveformIntegral
            unsigned int length;

            // ADC count of pedestal level
            double pedestalLevel;
            double pedestalStdev;

            // amplitude of peak relative to pedestal
            double amplitude;

            // number of sigma above the pedestal to start/end the restructed integration window.
            double nsigma;

            // search method
            int search_method;

            // ADC count of each sample
            // std::vector<short> trace;
            double integral;
            double peak_time;
            std::pair<int,int> integration_window;

            double fullintegral;
            double x,y;
            bool is_clipping;
            bool clipped_integration_window;

            TRef raw;
            TRef parent;

            //detector type and number
            std::string detectorSystem;
            std::string subdetector;


            ChannelID GetID() const;
            void Show() const override;
            void DoIntegration(std::tuple<int,int> presample_config, int seed_index = -1, int seeded_search_window=-1);
            float IntegralAroundPeak(int nPresamples, int nPostsamples, bool subtract_pedestal = true);

            // float GetTime(float time, bool ct_to_ns=false){ return ((WFD5Waveform*)raw.GetObject())->GetTime(time, ct_to_ns);};
            // std::vector<float> GetTimes(bool ct_to_ns=false){ return ((WFD5Waveform*)raw.GetObject())->GetTimes(ct_to_ns);};

            bool is_time_corrected;
            int time_shift;
            int time_scale;
            void CorrectTimes();

            bool is_energy_calibrated;
            double calibration_factor;
            void CalibrateEnergies(double scale);
            
            ClassDefOverride(WaveformIntegral,2)

    };

    typedef std::vector<WaveformIntegral> WaveformIntegralCollection;
    typedef std::vector<WaveformIntegral> SeededWaveformIntegralCollection;

}

#endif // WaveformIntegral_HH