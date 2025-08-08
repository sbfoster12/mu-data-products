#include "data_products/wfd5/RFWaveformFit.hh"
#include "TRef.h"
#include <numeric>


using namespace dataProducts;

RFWaveformFit::RFWaveformFit()
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
    ,clockCounter(0)
{
}

RFWaveformFit::RFWaveformFit(WFD5Waveform* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,crateNum(wf->crateNum)
    ,amcNum(wf->amcNum)
    ,channelTag(wf->channelTag)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,length(wf->length)
    ,pedestalLevel(wf->pedestalLevel)
    ,converged(false)
    ,chi2(-1)
    ,ndf(1)
    ,frequency(0)
    ,amplitude(0)
    ,phase(0)
    ,pedestal(0)
    ,waveform(wf)
    ,detectorSystem(wf->detectorSystem)
    ,subdetector(wf->subdetector)
    ,clockCounter(wf->clockCounter)
{
}

RFWaveformFit::RFWaveformFit(RFWaveformFit* prev_fit) : DataProduct()
    ,runNum(prev_fit->runNum)
    ,subRunNum(prev_fit->subRunNum)
    ,crateNum(prev_fit->crateNum)
    ,amcNum(prev_fit->amcNum)
    ,channelTag(prev_fit->channelTag)
    ,eventNum(prev_fit->eventNum)
    ,waveformIndex(prev_fit->waveformIndex)
    ,length(prev_fit->length)
    ,pedestalLevel(prev_fit->pedestalLevel)
    ,converged(prev_fit->converged)
    ,chi2(prev_fit->chi2)
    ,ndf(prev_fit->ndf)
    ,frequency(prev_fit->frequency)
    ,amplitude(prev_fit->amplitude)
    ,phase(prev_fit->phase)
    ,pedestal(prev_fit->pedestal)
    ,waveform(prev_fit->waveform)
    ,detectorSystem(prev_fit->detectorSystem)
    ,subdetector(prev_fit->subdetector)
    ,clockCounter(prev_fit->clockCounter)
{
}

void RFWaveformFit::SetFitFunc(const TF1& func) {
    fitFunc = func;
}

RFWaveformFit::~RFWaveformFit() {}

ChannelID RFWaveformFit::GetID() const {
    return std::make_tuple(crateNum, amcNum, channelTag);
}

void RFWaveformFit::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "RFWaveformFit:" << std::endl;
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
    oss << "    frequency: " << frequency << std::endl;
    oss << "    amplitude: " << amplitude << std::endl;
    oss << "    phase: " << phase << std::endl; 
    oss << "    pedestal: " << pedestal << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}
