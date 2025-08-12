#include "data_products/wfd5/TimeSeed.hh"
#include "TRef.h"
#include <numeric>


using namespace dataProducts;

TimeSeed::TimeSeed()
    : DataProduct()
    ,eventNum(0)
    ,waveformIndex(0)
    ,runNum(0)
    ,subRunNum(0)
    ,time(0)
    ,time_in_ct(true)
    ,is_time_calibrated(false)
    ,time_conversion_factor(1.0)
    ,time_offset(0)
{
}

TimeSeed::TimeSeed(WaveformIntegral* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,time(0)
    ,time_in_ct(true)
    ,is_time_calibrated(false)
    ,time_conversion_factor(1.0)
    ,time_offset(0)
{
    inputs.push_back(wf);
}

TimeSeed::TimeSeed(WaveformFit* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,time(0)
    ,time_in_ct(true)
    ,is_time_calibrated(false)
    ,time_conversion_factor(1.0)
    ,time_offset(0)
{
    inputs.push_back(wf);
}

TimeSeed::TimeSeed(TimeSeed* prev_seed) : DataProduct()
    ,runNum(prev_seed->runNum)
    ,subRunNum(prev_seed->subRunNum)
    ,eventNum(prev_seed->eventNum)
    ,waveformIndex(prev_seed->waveformIndex)
    ,time(prev_seed->time)
    ,time_in_ct(prev_seed->time_in_ct)
    ,is_time_calibrated(prev_seed->is_time_calibrated)
    ,time_conversion_factor(prev_seed->time_conversion_factor)
    ,time_offset(prev_seed->time_offset)
{
    inputs.push_back(prev_seed);
}

TimeSeed::~TimeSeed() {}

void TimeSeed::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "TimeSeed:" << std::endl;
    oss << "    run: " << runNum << std::endl;
    oss << "    subrun: " << subRunNum << std::endl;
    oss << "    eventNum: " << eventNum << std::endl;
    oss << "    waveformIndex: " << waveformIndex << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}
