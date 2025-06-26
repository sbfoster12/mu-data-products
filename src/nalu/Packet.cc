#include "data_products/nalu/Packet.hh"

using namespace data_products::nalu;

Packet::Packet()
    : DataProduct(),
    channel_num(-1),
    window_position(-1),
    trace({})
{}

Packet::Packet(
    uint64_t channel_num_arg,
    uint64_t window_position_arg,
    std::vector<short> trace_arg)
    : DataProduct(),
    channel_num(channel_num_arg),
    window_position(window_position_arg),
    trace(trace_arg)
{}

Packet::~Packet() {};

void Packet::Show() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "Packet: " << std::endl;
    oss << "    channel_num: " << channel_num << std::endl;
    oss << "    window_position: " << window_position << std::endl;
    oss << "    trace.size(): " << trace.size() << std::endl;
    std::cout << oss.str();
}