#include "data_products/nalu/Waveform.hh"
#include <numeric>

using namespace data_products::nalu;

Waveform::Waveform()
    : DataProduct()
{}

Waveform::Waveform(PacketCollection packets
    ) : DataProduct()
{

    if (packets.size() != 0) {
        channel_num = packets.at(0).channel_num;
    }

    for (const auto& nalu_packet : packets) {
        trace.insert(trace.end(),nalu_packet.trace.begin(),nalu_packet.trace.end());
    }
}

Waveform::~Waveform() {}

std::string Waveform::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "Waveform:" << std::endl;
    oss << "    channel_num: " << channel_num << std::endl;
    oss << "    trace: ";
    for (const auto & sample : trace) {
        oss << sample << ", ";
    }
    oss << std::endl;
    return oss.str();
}

void Waveform::Show() const { 
    std::cout << this->String();
}
