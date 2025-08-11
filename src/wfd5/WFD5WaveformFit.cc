#include "data_products/wfd5/WFD5WaveformFit.hh"
#include "TRef.h"
#include <numeric>


using namespace dataProducts;

SplineHolder::SplineHolder() : DataProduct(), 
    laser_1_splines({}),
    laser_2_splines({})
{

}

SplineHolder::~SplineHolder(){}

WaveformFit::WaveformFit()
    : DataProduct()
    ,crateNum(0)
    ,amcNum(0)
    ,channelTag(0)
    ,eventNum(0)
    ,waveformIndex(0)
    ,length(0)
    ,pedestalLevel(0.)
    ,runNum(0)
    ,subRunNum(0)
    ,detectorSystem("")
    ,subdetector("")
    ,detectorNum(0)
    ,is_time_calibrated(false)
    ,is_normalized(false)
    ,is_energy_calibrated(false)
    ,time_shift(-1e10)
    ,time_scale(-1e10)
    ,norm_scale({})
    ,triggerDoubleIndex(0)
    ,clockCounters({})
    ,fillTypes({})
    ,pulse_time_ordering_({})
{
}

WaveformFit::WaveformFit(WFD5Waveform* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,crateNum(wf->crateNum)
    ,amcNum(wf->amcNum)
    ,channelTag(wf->channelTag)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,length(wf->length)
    ,pedestalLevel(wf->pedestalLevel)
    ,waveforms({})
    ,chi2(-1)
    ,converged(false)
    ,ndf(1)
    ,nfit(0)
    ,times({})
    ,amplitudes({})
    ,which_splines({})
    ,detectorSystem(wf->detectorSystem)
    ,subdetector(wf->subdetector)
    ,is_time_calibrated(false)
    ,is_normalized(false)
    ,is_energy_calibrated(false)
    ,time_shift(-1e10)
    ,time_scale(-1e10)
    ,norm_scale({})
    ,clockCounters({wf->clockCounter})
    ,fillTypes({-1})
    ,pulse_time_ordering_({})
{
    // the only thing we do here is add a TRef, which technically does edit the object... But it should be ok?
    // WFD5Waveform* wf_mut = const_cast<WFD5Waveform*>(wf); 
    waveforms.push_back(TRef(wf));
}

WaveformFit::WaveformFit(WaveformFit* prev_fit) : DataProduct()
    ,runNum(prev_fit->runNum)
    ,subRunNum(prev_fit->subRunNum)
    ,crateNum(prev_fit->crateNum)
    ,amcNum(prev_fit->amcNum)
    ,channelTag(prev_fit->channelTag)
    ,eventNum(prev_fit->eventNum)
    ,waveformIndex(prev_fit->waveformIndex)
    ,length(prev_fit->length)
    ,pedestalLevel(prev_fit->pedestalLevel)
    ,waveforms(prev_fit->waveforms)
    ,chi2(prev_fit->chi2)
    ,converged(prev_fit->converged)
    ,ndf(prev_fit->ndf)
    ,nfit(prev_fit->nfit)
    ,times(prev_fit->times)
    ,amplitudes(prev_fit->amplitudes)
    ,which_splines(prev_fit->which_splines)
    ,detectorSystem(prev_fit->detectorSystem)
    ,subdetector(prev_fit->subdetector)
    // ,detectorNum(prev_fit->detectorNum)
    // ,uncalibrated_fit(prev_fit)
    ,is_time_calibrated(false)
    ,is_normalized(false)
    ,is_energy_calibrated(false)
    ,time_shift(-1e10)
    ,time_scale(-1e10)
    ,norm_scale({})
    // ,triggerDoubleIndex(prev_fit->triggerDoubleIndex)
    ,clockCounters(prev_fit->clockCounters)
    ,fillTypes(prev_fit->fillTypes)
    ,pulse_time_ordering_(prev_fit->pulse_time_ordering_)
{
    uncalibrated_fit = TRef(prev_fit);
}

WaveformFit::~WaveformFit() {}

void WaveformFit::TimeAlign(double ref_time, double scale)
{
    // std::cout << "Aligning fit in time. Shifting by: " << ref_time << "ns and scaling by " << scale << "ct/ns" << std::endl;
    for (unsigned int i = 0; i < times.size(); i++)
    {
        times[i] = times[i]*scale + ref_time;
    }

    time_scale = scale;
    time_shift = ref_time;

    is_time_calibrated = true;
}

void WaveformFit::Normalize(WaveformFit* fit, bool debug)
{
    // std::cout << "Normalizing fit" << std::endl;
    norm_fit = fit;
    norm_scale.clear();
    if (nfit != fit->nfit)
    {
        if (debug) std::cout << "Warning: normalization fit number mismatch (" << nfit << " vs " << fit->nfit << ") in AMC/Channel " << amcNum << " / " << channelTag << std::endl;
        // return;
    }
    // for each fit in the current fit, loop over and find the fit which is closest in energy

    for (size_t i = 0; i < amplitudes.size(); ++i) {
        double minTimeDiff = std::numeric_limits<double>::max();
        double closestAmplitude = 1.0;  // Default in case no match is found
        
        for (size_t j = 0; j < fit->times.size(); ++j) {
            double timeDiff = std::abs(times[i] - fit->times[j]);
            if (timeDiff < minTimeDiff) {
                minTimeDiff = timeDiff;
                closestAmplitude = fit->amplitudes[j];
            }
        }
        
        // Normalize amplitude by the closest one from object2
        if (closestAmplitude != 0.0) {
            amplitudes[i] /= closestAmplitude;
        }
        norm_scale.push_back(closestAmplitude);
    }
    is_normalized = true;

}

double WaveformFit::GetPulseTime(int index)
{
    if (index >= times.size() || index < 0 || times.size() == 0) 
    {
        throw;
    }
    else if (times.size() == 1)
    {
        return times.at(0);
    }
    else
    {
        if (pulse_time_ordering_.size() != times.size()) CalculatePulseTimeOrdering();
        auto this_index = std::find(pulse_time_ordering_.begin(), pulse_time_ordering_.end(), index);
        if (this_index != pulse_time_ordering_.end()) return times.at(
            std::distance(pulse_time_ordering_.begin(), this_index)
        );
        else throw;
    }
}

double WaveformFit::GetPulseAmplitude(int index)
{
    if (index >= times.size() || index < 0 || times.size() == 0) 
    {
        throw;
    }
    else if (times.size() == 1)
    {
        return amplitudes.at(0);
    }
    else
    {
        if (pulse_time_ordering_.size() != times.size()) CalculatePulseTimeOrdering();
        auto this_index = std::find(pulse_time_ordering_.begin(), pulse_time_ordering_.end(), index);
        if (this_index != pulse_time_ordering_.end()) return amplitudes.at(
            std::distance(pulse_time_ordering_.begin(), this_index)
        );
        else throw;
    }
}

void WaveformFit::CalculatePulseTimeOrdering()
{
    pulse_time_ordering_.clear();
    for (size_t i = 0; i < times.size(); ++i) {
        pulse_time_ordering_.push_back(i);
    }

    // Sort indices based on corresponding values in 'times'
    if (times.size() > 0)
        std::sort(pulse_time_ordering_.begin(), pulse_time_ordering_.end(), [this](int i1, int i2) {
            return this->times[i1] < this->times[i2];
        });
}

int WaveformFit::GetClosestPulseIndex(double time)
{
    // return the unsorted index for the value which is closest in time
    double time_diff = 1e12;
    double min_time_diff = 1e12;
    int min_index = -1;
    bool found = false;

    if (nfit < 1) 
    {
        std::cerr << "Warning: trying to access times where none are present" << std::endl;
        throw;
    }

    for (unsigned int i = 0; i < times.size(); i++)
    {
        time_diff = std::abs(time - times[i]);
        if (time_diff < min_time_diff)
        {
            min_time_diff = time_diff;
            min_index = i;
            found = true;
        }
    }

    if (!found)
    {
        std::cerr << "No min index found..." << std::endl;
        throw;
    }

    return min_index;
}

double WaveformFit::GetClosestPulseTime(double time)
{
    return times[GetClosestPulseIndex(time)];
}

double WaveformFit::GetClosestPulseAmplitude(double time)
{
    return amplitudes[GetClosestPulseIndex(time)];
}

void WaveformFit::CalibrateEnergies(double scale)
{
    for (int i = 0; i < amplitudes.size(); i++)
    {
        amplitudes[i] *= scale;
    }
    calibration_factor = scale;
    is_energy_calibrated = true;
};


ChannelID WaveformFit::GetID() const {
    return std::make_tuple(crateNum, amcNum, channelTag);
}

void WaveformFit::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "WaveformFit:" << std::endl;
    oss << "    run: " << runNum << std::endl;
    oss << "    subrun: " << subRunNum << std::endl;
    oss << "    crateNum: " << crateNum << std::endl;
    oss << "    amcSlot: " << amcNum << std::endl;
    oss << "    detectorSystem: " << detectorSystem << std::endl;
    oss << "    detectorNum: " << detectorNum << std::endl;
    oss << "    channelTag: " << channelTag << std::endl;
    oss << "    eventNum: " << eventNum << std::endl;
    oss << "    waveformIndex: " << waveformIndex << std::endl;
    oss << "    pedestalLevel: " << pedestalLevel << std::endl;
    oss << "    converged: " << converged << std::endl;
    oss << "    chi2: " << chi2 << std::endl;
    oss << "    ndf: " << ndf << std::endl;
    oss << "    nfit: " << nfit << std::endl;
    // if ((nfit > 0) && (pulse_time_ordering_.size() != times.size())) CalculatePulseTimeOrdering();
    for (int i = 0; i < nfit; i++)
    {
        oss << "   -> pulse " << i+1 << " energy/time = " << amplitudes.at(i) << " / " << times.at(i) << " at time-ordered position " << pulse_time_ordering_.at(i) << std::endl;
    }
    oss << std::endl;
    std::cout << oss.str();
}
