#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// Common data products
#pragma link C++ class data_products::common::DataProduct+;
#pragma link C++ class std::vector<data_products::common::DataProduct>+;

//WFD5 data products
#pragma link C++ class data_products::wfd5::FC7Header+;
#pragma link C++ class std::vector<data_products::wfd5::FC7Header>+;

#pragma link C++ class data_products::wfd5::WFD5Header+;
#pragma link C++ class std::vector<data_products::wfd5::WFD5Header>+;

#pragma link C++ class data_products::wfd5::ChannelHeader+;
#pragma link C++ class std::vector<data_products::wfd5::ChannelHeader>+;

#pragma link C++ class data_products::wfd5::WaveformHeader+;
#pragma link C++ class std::vector<data_products::wfd5::WaveformHeader>+;

#pragma link C++ class data_products::wfd5::Waveform+;
#pragma link C++ class std::vector<data_products::wfd5::Waveform>+;

#pragma link C++ class data_products::wfd5::ODB+;
#pragma link C++ class std::vector<data_products::wfd5::ODB>+;

// NALU data products
#pragma link C++ class data_products::nalu::EventHeader+;
#pragma link C++ class std::vector<data_products::nalu::EventHeader>+;

#pragma link C++ class data_products::nalu::PacketHeader+;
#pragma link C++ class std::vector<data_products::nalu::PacketHeader>+;

#pragma link C++ class data_products::nalu::Packet+;
#pragma link C++ class std::vector<data_products::nalu::Packet>+;

#pragma link C++ class data_products::nalu::PacketFooter+;
#pragma link C++ class std::vector<data_products::nalu::PacketFooter>+;

#pragma link C++ class data_products::nalu::Waveform+;
#pragma link C++ class std::vector<data_products::nalu::Waveform>+;

#pragma link C++ class data_products::nalu::EventFooter+;
#pragma link C++ class std::vector<data_products::nalu::EventFooter>+;

#pragma link C++ class data_products::nalu::Time+;
#pragma link C++ class std::vector<data_products::nalu::Time>+;

#pragma link C++ class data_products::nalu::ODB+;
#pragma link C++ class std::vector<data_products::nalu::ODB>+;

#endif
