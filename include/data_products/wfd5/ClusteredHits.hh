#ifndef ClusteredHits_HH 
#define ClusteredHits_HH

// #include "DataProduct.hh"
#include "data_products/common/DataProduct.hh"

#include "WFD5Waveform.hh"
#include "WaveformIntegral.hh"
#include "WFD5WaveformFit.hh"
#include "TF1.h"
#include <string>
// #include <format>
#include <iostream>
#include "TString.h"

namespace dataProducts {

    class ClusteredHits : public DataProduct {

        public:
            ClusteredHits();

            ClusteredHits(WaveformIntegral* waveform);
            ClusteredHits(WaveformFit* waveform);
            ClusteredHits(ClusteredHits* prev_fit);

            //Destructor
            ~ClusteredHits();

            // run/subrun number
            int runNum;
            int subRunNum;

            // Event number
            int eventNum;

            // index of this waveform
            int waveformIndex;

            // TRef waveform;
            std::vector<TRef> inputs;

            //detector type and number
            std::string detectorSystem;
            std::string subdetector;
            int detectorNum;
            
            std::vector<int> fitIndex;

            double x,y;
            double sigmax, sigmay;

            void Cluster(std::vector<double> xs,std::vector<double> ys, int weighting, std::vector<double> weights);

            void Show() const override;

            ClassDefOverride(ClusteredHits,1)

    };

    typedef std::vector<ClusteredHits> ClusteredHitsCollection;
    typedef std::vector<ClusteredHits> CaloHitsCollection;
    typedef std::vector<ClusteredHits> HodoHitsCollection;

}

#endif // ClusteredHits_HH