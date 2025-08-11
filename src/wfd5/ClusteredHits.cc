#include "data_products/wfd5/ClusteredHits.hh"
#include "TRef.h"
#include <numeric>


using namespace dataProducts;

ClusteredHits::ClusteredHits()
    : DataProduct()
    ,eventNum(0)
    ,waveformIndex(0)
    ,runNum(0)
    ,subRunNum(0)
    ,detectorSystem("")
    ,subdetector("")
    ,detectorNum(0)
    ,x(-1e9)
    ,y(-1e9)
    ,sigmax(-1e9)
    ,sigmay(-1e9)
    ,fitIndex({})
{
}

ClusteredHits::ClusteredHits(WaveformIntegral* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,detectorSystem(wf->detectorSystem)
    ,subdetector(wf->subdetector)
    ,x(-1e9)
    ,y(-1e9)
    ,sigmax(-1e9)
    ,sigmay(-1e9)
    ,fitIndex({})
{
}

ClusteredHits::ClusteredHits(WaveformFit* wf) : DataProduct()
    ,runNum(wf->runNum)
    ,subRunNum(wf->subRunNum)
    ,eventNum(wf->eventNum)
    ,waveformIndex(wf->waveformIndex)
    ,detectorSystem(wf->detectorSystem)
    ,subdetector(wf->subdetector)
    ,x(-1e9)
    ,y(-1e9)
    ,sigmax(-1e9)
    ,sigmay(-1e9)
    ,fitIndex({})
{
}

ClusteredHits::ClusteredHits(ClusteredHits* prev_fit) : DataProduct()
    ,runNum(prev_fit->runNum)
    ,subRunNum(prev_fit->subRunNum)
    ,eventNum(prev_fit->eventNum)
    ,waveformIndex(prev_fit->waveformIndex)
    ,detectorSystem(prev_fit->detectorSystem)
    ,subdetector(prev_fit->subdetector)
    ,x(prev_fit->x)
    ,y(prev_fit->y)
    ,sigmax(prev_fit->sigmax)
    ,sigmay(prev_fit->sigmay)
    ,fitIndex(prev_fit->fitIndex)
{
}

ClusteredHits::~ClusteredHits() {}

void ClusteredHits::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "ClusteredHits:" << std::endl;
    oss << "    run: " << runNum << std::endl;
    oss << "    subrun: " << subRunNum << std::endl;
    oss << "    detectorSystem: " << detectorSystem << std::endl;
    oss << "    detectorNum: " << detectorNum << std::endl;
    oss << "    eventNum: " << eventNum << std::endl;
    oss << "    waveformIndex: " << waveformIndex << std::endl;
    oss << std::endl;
    std::cout << oss.str();
}
