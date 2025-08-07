#ifndef WaveformFit_HH 
#define WaveformFit_HH

// #include "DataProduct.hh"
#include "data_products/common/DataProduct.hh"

#include "WFD5Waveform.hh"
#include "TSpline.h"
#include <string>
// #include <format>
#include <iostream>
#include "TString.h"
#include "TFile.h"
#include "CubicSpline.hh"
#include "TH2.h"


namespace dataProducts {


    class SplineHolder : public DataProduct {
        public:
            SplineHolder();
            ~SplineHolder();

            void SetSpline(ChannelID id, TSpline3* sp, int which_spline)
            {
                if (which_spline == 0)
                {
                    // laser_1_splines[id] = sp;
                    laser_1_splines[id] = sp;
                }
                else if(which_spline == 1)
                {
                    // laser_2_splines[id] = sp;
                    laser_2_splines[id] = sp;
                }
                else
                {
                    throw;
                }

            };

            // TSpline3* GetSpline(ChannelID id, int which_spline)
            fitter::CubicSpline* GetSpline(ChannelID id, int which_spline)
            {
                if (which_spline == 0)
                {
                    return buildCubicSpline( laser_1_splines[id] );
                }
                else if(which_spline == 1)
                {
                    return buildCubicSpline( laser_2_splines[id] );
                }
                else
                {
                    throw;
                }
            }

            TSpline3* GetTSpline(ChannelID id, int which_spline)
            {
                if (which_spline == 0)
                {
                    return laser_1_splines[id];
                }
                else if(which_spline == 1)
                {
                    return laser_2_splines[id];
                }
                else
                {
                    throw;
                }
            }

            void LoadSplines(int which_spline, std::string infile)
            {
                std::cout << "Loading splines from: " << infile << " into position " << which_spline << std::endl;
                TFile *this_file = new TFile(infile.c_str(),"OPEN");
                for (int crate : {7,8})
                {
                    for (int amcNum = 1; amcNum < 13; amcNum ++)
                    {
                        for (int channel = 0; channel < 5; channel ++)
                        {
                            std::string keyName = TString::Format("crate_%i_amc_%i_channel_%i",crate,amcNum, channel).Data();
                            if (this_file->GetKey(keyName.c_str())) {
                                TSpline3* this_spline = (TSpline3*)this_file->Get(keyName.c_str());
                                SetSpline({crate,amcNum,channel}, this_spline, which_spline);
                            }
                            std::string alternateKeyName = TString::Format("crate_%i_amc_%i_channel_%i_laser_%i",crate,amcNum,channel,which_spline+1).Data();
                            if (this_file->GetKey(alternateKeyName.c_str())) {
                                TSpline3* this_spline = (TSpline3*)this_file->Get(alternateKeyName.c_str());
                                SetSpline({crate,amcNum,channel}, this_spline, which_spline);
                            }
                        }
                    }
                }
                this_file->Close();
            }

            std::vector<dataProducts::ChannelID> GetIDs() const
            {
                std::vector<dataProducts::ChannelID> ding = {};
                for (auto &dong:laser_1_splines)
                {
                    ding.push_back(dong.first);
                }
                return ding;
            }

            bool SplinePresent(dataProducts::ChannelID id) const
            {
                return laser_1_splines.count(id);
            }

            fitter::CubicSpline* buildCubicSpline(const TSpline3* tSpline, fitter::CubicSpline::BoundaryType cond  = fitter::CubicSpline::BoundaryType::first) 
            {
                unsigned int nKnots = tSpline->GetNp();

                fitter::CubicSpline::Knots knots(nKnots);

                for (unsigned int i = 0; i < nKnots; ++i) {
                    tSpline->GetKnot(i, knots.xs[i], knots.ys[i]);
                }

                return new fitter::CubicSpline(knots, cond);
            }

        ClassDefOverride(SplineHolder,1)
        

        private:
            std::map<ChannelID, TSpline3*> laser_1_splines;
            std::map<ChannelID, TSpline3*> laser_2_splines;

    };

    class WaveformFit : public DataProduct {

        public:
            WaveformFit();

            WaveformFit(const WFD5Waveform* waveform);
            WaveformFit(WaveformFit* prev_fit);

            //Destructor
            ~WaveformFit();

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

            // Number of samples in the WaveformFit
            unsigned int length;

            // ADC count of pedestal level
            double pedestalLevel;

            // fitter specific
            bool converged;
            double chi2;
            int ndf;
            int nfit; // number of pulses fit 
            std::vector<double> times;
            std::vector<double> amplitudes;
            std::vector<int> which_splines;

            // TRef waveform;
            // TRef spline1;
            // TRef spline2;
            std::vector<TRef> waveforms;
            std::vector<TRef> splines;
            TRef uncalibrated_fit;
            TRef norm_fit;


            //detector type and number
            std::string detectorSystem;
            std::string subdetector;
            int detectorNum;
            float fitTime;
            bool timeout;
            bool is_time_calibrated;
            bool is_normalized;

            float time_shift;
            float time_scale;
            std::vector<float> norm_scale;

            int triggerDoubleIndex;
            std::vector<long unsigned int> clockCounters;
            std::vector<int> fillTypes;

            void Show() const override;
            ChannelID GetID() const;
            void TimeAlign(double ref_time, double scale=1.0);
            void Normalize(WaveformFit* fit, bool debug = false);

            double GetPulseTime(int index = 0);
            double GetPulseAmplitude(int index = 0);
            void CalculatePulseTimeOrdering();
            std::vector<int> pulse_time_ordering_;

            int GetClosestPulseIndex(double time = 0);
            double GetClosestPulseTime(double time = 0);
            double GetClosestPulseAmplitude(double time = 0);

            ClassDefOverride(WaveformFit,15)

    };

    typedef std::vector<WaveformFit> WaveformFitCollection;

    class DoubledWaveformFit : public DataProduct {
        public:
            DoubledWaveformFit()
            {
                first_set = false; 
                second_set = false; 
                odb_time_offset_ns=0;
                clockCounterDifference=0;
            };

            DoubledWaveformFit(WaveformFit* fit1, WaveformFit* fit2)
            {
                odb_time_offset_ns = 0;
                first = WaveformFit(fit1);
                second = WaveformFit(fit2);
                first_set = true; 
                second_set = true;
                SetClockCounter();
            };

            ~DoubledWaveformFit(){};

            WaveformFit first;
            WaveformFit second;
            long unsigned int clockCounterDifference;
            int odb_time_offset_ns;

            void SetFirst(WaveformFit* fit)
            {
                first_set = true;
                first = WaveformFit(fit);

            };

            void SetSecond(WaveformFit* fit)
            {
                second_set = true;
                second = WaveformFit(fit);
            };

            void SetClockCounter()
            {
                // WaveformFit* fit1 = (WaveformFit*)first.GetObject();
                // WaveformFit* fit2 = (WaveformFit*)second.GetObject();
                // clockCounterDifference = 
                long unsigned int cc1 = first.clockCounters[0] ;
                long unsigned int cc2 = second.clockCounters[0] ;

                // std::cout << "Setting clock counter difference: " << cc2 << " - " << cc1 << " = " << cc2 - cc1 << std::endl;

                clockCounterDifference = cc2 - cc1;
            };

            bool IsComplete() { return first_set && second_set; };

            double DeltaT()
            {
                return second.times[0] - first.times[0] + odb_time_offset_ns;
            };

            double DeltaT_clockcounter()
            {
                return second.times[0] - first.times[0] + clockCounterDifference * 25.0;
            };
        

        ClassDefOverride(DoubledWaveformFit,2)

        private:
            bool first_set;
            bool second_set;

    };
    typedef std::vector<DoubledWaveformFit> DoubledWaveformFitCollection;


}

#endif // WaveformFit_HH