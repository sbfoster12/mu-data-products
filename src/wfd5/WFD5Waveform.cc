#include "data_products/wfd5/WFD5Waveform.hh"
#include <numeric>

using namespace dataProducts;

WFD5Waveform::WFD5Waveform()
    : DataProduct(),
    crateNum(0),
    amcNum(0), 
    channelTag(0),
    eventNum(0),
    waveformIndex(0),
    length(0),
    pedestalLevel(0),
    pedestalStdev(0),
    pedestalSamples({}),
    pedestalStartSample(0),
    firstSampleNum(0),
    clockCounter(0),
    digitizationShift(0),
    preTriggerLength(0),
    trace({}),
    detectorSystem(""),
    subdetector("")
{}

WFD5Waveform::WFD5Waveform(int crateNumArg
    ,int amcNumArg
    ,int channelTagArg
    ,int eventNumArg
    ,int waveformIndexArg
    ,unsigned int lengthArg
    ,double pedestalLevelArg
    ,double pedestalStdevArg
    ,int firstSampleNumArg
    ,unsigned long clockCounterArg
    ,int preTriggerLengthArg
    ,int runNumArg
    ,int subRunNumArg
    ,std::vector<short> traceArg
    ) : DataProduct()
    ,crateNum(crateNumArg)
    ,amcNum(amcNumArg)
    ,channelTag(channelTagArg)
    ,eventNum(eventNumArg)
    ,waveformIndex(waveformIndexArg)
    ,length(lengthArg)
    ,pedestalLevel(pedestalLevelArg)
    ,pedestalStdev(pedestalStdevArg)
    ,pedestalSamples({})
    ,pedestalStartSample(0)
    ,firstSampleNum(firstSampleNumArg)
    ,clockCounter(clockCounterArg)
    ,preTriggerLength(preTriggerLengthArg)
    ,digitizationShift(0)
    ,customOffsetClockTicks(0.0)
    ,runNum(runNumArg)
    ,subRunNum(subRunNumArg)
    ,x(0.0)
    ,y(0.0)
    ,is_clipping(false)
    ,trace(traceArg)
    ,detectorSystem("")
    ,subdetector("")
    ,digitizationFrequency(1.0)
{}

WFD5Waveform::WFD5Waveform(WFD5Waveform* w) : DataProduct()
    ,runNum(w->runNum)
    ,subRunNum(w->subRunNum)
    ,crateNum(w->crateNum)
    ,amcNum(w->amcNum)
    ,channelTag(w->channelTag)
    ,eventNum(w->eventNum)
    ,waveformIndex(w->waveformIndex)
    ,length(w->length)
    ,pedestalLevel(w->pedestalLevel)
    ,pedestalStdev(w->pedestalStdev)
    ,pedestalSamples(w->pedestalSamples)
    ,pedestalStartSample(w->pedestalStartSample)
    ,firstSampleNum(w->firstSampleNum)
    ,clockCounter(w->clockCounter)
    ,preTriggerLength(w->preTriggerLength)
    ,digitizationShift(w->digitizationShift)
    ,customOffsetClockTicks(w->customOffsetClockTicks)
    ,trace(w->trace)
    ,raw(w)
    ,x(w->x)
    ,y(w->y)
    ,is_clipping(w->is_clipping)
    ,detectorSystem(w->detectorSystem)
    ,subdetector(w->subdetector)
    ,digitizationFrequency(w->digitizationFrequency)
{
}


WFD5Waveform::~WFD5Waveform() {}

void WFD5Waveform::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "WFD5Waveform:" << std::endl;
    oss << "    runNum: " << runNum << std::endl;
    oss << "    subRunNum: " << subRunNum << std::endl;
    oss << "    crateNum: " << crateNum << std::endl;
    oss << "    amcSlot: " << amcNum << std::endl;
    oss << "    channelTag: " << channelTag << std::endl;
    oss << "    detectorSystem: " << detectorSystem << std::endl;
    oss << "    subdetector: " << subdetector << std::endl;
    oss << "    eventNum: " << eventNum << std::endl;
    oss << "    waveformIndex: " << waveformIndex << std::endl;
    oss << "    pedestalLevel: " << pedestalLevel << std::endl;
    oss << "    pedestalStdev: " << pedestalStdev << std::endl;
    oss << "    pedestalSamples.size: " << pedestalSamples.size() << std::endl;
    oss << "    pedestalStartSample: " << pedestalStartSample << std::endl;
    oss << "    first sample number: " << firstSampleNum << std::endl;
    oss << "    clock counter: " << clockCounter << std::endl;
    oss << "    preTriggerLength: " << preTriggerLength << std::endl;
    oss << "    digitizationFrequency: " << digitizationFrequency << std::endl;
    oss << "    digitizationShift: " << digitizationShift << std::endl;
    oss << "    trace.size(): " << trace.size() << std::endl;
    oss << "        trace: ";
    for (const auto & sample : trace) {
        oss << sample << ", ";
    }
    oss << std::endl;
    std::cout << oss.str();
}

void WFD5Waveform::JitterCorrect(int evenOddDiff)
{
    // copied from g-2 code
    
    unsigned int startOffset = firstSampleNum % 2;
    // // we want to correct odd samples if diff > 0, even otherwise
    startOffset = (startOffset + (evenOddDiff > 0)) % 2;
    short absDiff = std::abs(evenOddDiff);
    for (unsigned int i = startOffset; i < trace.size(); i+=2){
        if(std::abs(trace[i]) < 2045){// don't correct saturated samples
        trace[i] += absDiff;    
        }
    }
}

double WFD5Waveform::PeakToPeak()
{
    // return the peak to peak difference between the min/max amplitude sample
    short mini = *std::min_element(trace.begin(), trace.end());
    short maxi = *std::max_element(trace.begin(), trace.end());
    // short diff = maxi - mini;
    // std::cout << "   calculating peak to peak: " << mini << " / " << maxi << " -> " << diff << std::endl;
    // return std::static_cast<double>(diff);
    return maxi - mini;
}

double WFD5Waveform::PeakToPeak(int b1, int b2)
{
    // return the peak to peak difference between the min/max amplitude sample
    if (b2 >= trace.size()) 
    {
        // throw std::runtime_error("Attempting to search outside of the bounds of the waveform")
        std::cout << "Warning: attempting to search outside the bounds of the waveform, setting end to trace end" << std::endl;
        b2 = trace.size() - 1;
    }
    if (b1 < 0)
    {
        std::cout << "Warning: attempting to search outside the bounds of the waveform, setting end to trace end" << std::endl;
        b1 = 0;
    }


    short mini = *std::min_element(trace.begin() + b1, trace.begin() + b2);
    short maxi = *std::max_element(trace.begin() + b1, trace.begin() + b2);
    // short diff = maxi - mini;
    // std::cout << "   calculating peak to peak: " << mini << " / " << maxi << " -> " << diff << std::endl;
    // return std::static_cast<double>(diff);
    return maxi - mini;
}

int WFD5Waveform::GetPeakIndex()
{
    auto maxIt = std::max_element(trace.begin(), trace.end());
    return std::distance(trace.begin(), maxIt);
}

int WFD5Waveform::GetPeakIndexInBounds(int b1, int b2)
{
    if (b2 >= trace.size()) 
    {
        // throw std::runtime_error("Attempting to search outside of the bounds of the waveform")
        std::cout << "Warning: attempting to search outside the bounds of the waveform, setting end to trace end" << std::endl;
        b2 = trace.size() - 1;
    }
    if (b1 < 0)
    {
        std::cout << "Warning: attempting to search outside the bounds of the waveform, setting end to trace end" << std::endl;
        b1 = 0;
    }
    auto maxIt = std::max_element(trace.begin() + b1, trace.begin() + b2);
    return std::distance(trace.begin(), maxIt);
}

void WFD5Waveform::InvertPulse()
{
    // inverts the pulse shape by a simple *-1
    for (int i = 0; i < trace.size(); i++)
    {
        trace.at(i) = trace.at(i) * -1.0;
    }
}

double WFD5Waveform::GetTime(double time, bool ct_to_ns)
{
    double digitization_freq_mhz = digitizationFrequency;
    double conversion_factor = 800./digitization_freq_mhz; 
    double custom_time_offset = customOffsetClockTicks;
    if(ct_to_ns)
    {
        conversion_factor *= 1.25; 
        custom_time_offset *= 1.25;
    }
    double presample_time = preTriggerLength * conversion_factor;
    return time * conversion_factor + digitizationShift * digitization_freq_mhz/40. - presample_time + custom_time_offset;

}

std::vector<double> WFD5Waveform::GetTimes(bool ct_to_ns)
{
    // uses the digitization rate and number of presamples from the odb to get the time relative to the trigger
    // returns time in ns if ct_to_ns is true
    std::vector<double> times;
    times.reserve(trace.size());
    for (unsigned int i = 0; i < trace.size(); i++)
    {
        times.push_back( GetTime(i) );
    }
    return times;
}