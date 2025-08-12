#ifndef TimeSeed_HH 
#define TimeSeed_HH

// #include "DataProduct.hh"
#include "WaveformIntegral.hh"
#include "WFD5WaveformFit.hh"
#include "data_products/common/DataProduct.hh"

#include "TF1.h"
#include <string>
// #include <format>
#include <iostream>
#include "TString.h"

namespace dataProducts {

    class TimeSeed : public DataProduct {

        public:
            TimeSeed();

            TimeSeed(WaveformIntegral* waveform);
            TimeSeed(WaveformFit* fiti);
            TimeSeed(TimeSeed* prev_fit);

            //Destructor
            ~TimeSeed();

            // run/subrun number
            int runNum;
            int subRunNum;

            // Event number
            int eventNum;

            // index of this waveform
            int waveformIndex;

            double time;
            bool time_in_ct; //if true, time is in ct, else in ns (c.t. * conversion_factor + offset)
            bool is_time_calibrated;
            double time_conversion_factor;
            double time_offset;
            // double 

            // TRef waveform;
            std::vector<TRef> inputs;

            void SetSeed(
                double input_time, 
                bool input_time_in_ct = true, 
                bool input_is_time_calibrated = false, 
                double input_time_conversion_factor = 1.0, 
                double input_time_offset = 0.0
            )
            {
                time = input_time;
                time_in_ct = input_time_in_ct;
                is_time_calibrated = input_is_time_calibrated;
                time_conversion_factor = input_time_conversion_factor;
                time_offset = input_time_offset;
            }

            double GetTimeSeed()
            {
                return time; //TODO: adjust this to add calibration factors as applicable
            }

            void Show() const override;

            ClassDefOverride(TimeSeed,1)

    };

    typedef std::vector<TimeSeed> TimeSeedCollection;

}

#endif // TimeSeed_HH