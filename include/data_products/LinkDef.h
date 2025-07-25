#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// Common data products
#pragma link C++ class dataProducts::DataProduct+;
#pragma link C++ class std::vector<dataProducts::DataProduct>+;

//WFD5 data products
#pragma link C++ class dataProducts::FC7Header+;
#pragma link C++ class std::vector<dataProducts::FC7Header>+;

#pragma link C++ class dataProducts::WFD5Header+;
#pragma link C++ class std::vector<dataProducts::WFD5Header>+;

#pragma link C++ class dataProducts::WFD5ChannelHeader+;
#pragma link C++ class std::vector<dataProducts::WFD5ChannelHeader>+;

#pragma link C++ class dataProducts::WFD5WaveformHeader+;
#pragma link C++ class std::vector<dataProducts::WFD5WaveformHeader>+;

#pragma link C++ class dataProducts::WFD5Waveform+;
#pragma link C++ class std::vector<dataProducts::WFD5Waveform>+;

#pragma link C++ class dataProducts::WFD5ODB+;
#pragma link C++ class std::vector<dataProducts::WFD5ODB>+;

// NALU data products
#pragma link C++ class dataProducts::NaluEventHeader+;
#pragma link C++ class std::vector<dataProducts::NaluEventHeader>+;

#pragma link C++ class dataProducts::NaluPacketHeader+;
#pragma link C++ class std::vector<dataProducts::NaluPacketHeader>+;

#pragma link C++ class dataProducts::NaluPacket+;
#pragma link C++ class std::vector<dataProducts::NaluPacket>+;

#pragma link C++ class dataProducts::NaluPacketFooter+;
#pragma link C++ class std::vector<dataProducts::NaluPacketFooter>+;

#pragma link C++ class dataProducts::NaluWaveform+;
#pragma link C++ class std::vector<dataProducts::NaluWaveform>+;

#pragma link C++ class dataProducts::NaluEventFooter+;
#pragma link C++ class std::vector<dataProducts::NaluEventFooter>+;

#pragma link C++ class dataProducts::NaluTime+;
#pragma link C++ class std::vector<dataProducts::NaluTime>+;

#pragma link C++ class dataProducts::NaluODB+;
#pragma link C++ class std::vector<dataProducts::NaluODB>+;

#endif
