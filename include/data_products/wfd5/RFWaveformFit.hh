#ifndef RFWAVEFORMFIT_HH 
#define RFWAVEFORMFIT_HH

// #include "DataProduct.hh"
#include "data_products/common/DataProduct.hh"

#include "WFD5Waveform.hh"
#include "TF1.h"
#include <string>
// #include <format>
#include <iostream>
#include "TString.h"

namespace dataProducts {

    class RFWaveformFit : public DataProduct {

        public:
            RFWaveformFit();

            RFWaveformFit(WFD5Waveform* waveform);
            RFWaveformFit(RFWaveformFit* prev_fit);

            //Destructor
            ~RFWaveformFit();

            // Crate number
            int crateNum;

            // run/subrun number
            int runNum;
            int subRunNum;

            // AMC slot number
            int amcNum;

            // Channel tag
            int channelTag;

            // Event number
            int eventNum;

            // index of this waveform
            int waveformIndex;

            // Number of samples in the RFWaveformFit
            unsigned int length;

            // ADC count of pedestal level
            double pedestalLevel;

            // fitter specific
            bool converged;
            double chi2;
            int ndf;
            double frequency;
            double amplitude;
            double phase;
            double pedestal;

            // Fit function
            TF1 fitFunc;

            // TRef waveform;
            TRef waveform;

            //detector type and number
            std::string detectorSystem;
            std::string subdetector;
            int detectorNum;

            long unsigned int clockCounter;

            void SetFitFunc(const TF1& func);

            void Show() const override;
            ChannelID GetID() const;

            ClassDefOverride(RFWaveformFit,15)

    };

    typedef std::vector<RFWaveformFit> RFWaveformFitCollection;

}

#endif // RFWAVEFORMFIT_HH