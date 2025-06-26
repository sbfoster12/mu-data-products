#include "data_products/nalu/PacketFooter.hh"

using namespace data_products::nalu;

PacketFooter::PacketFooter()
    : DataProduct(),
    parser_index(0),
    packet_footer(0)
{}

PacketFooter::PacketFooter(
    uint32_t parser_index_arg,
    uint32_t packet_footer_arg
    )
    : DataProduct(),
    parser_index(parser_index_arg),
    packet_footer(packet_footer_arg)
{}

PacketFooter::~PacketFooter() {};

std::string PacketFooter::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "PacketFooter: " << std::endl;
    oss << "    parser_index: " << std::dec << parser_index << std::endl;
    oss << "    packet_footer: " << std::hex << "0x" << packet_footer << std::endl;
    return oss.str();
}

void PacketFooter::Show() const { 
    std::cout << this->String();
}