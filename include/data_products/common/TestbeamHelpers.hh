#ifndef DATAPRODUCT_HH  
#define DATAPRODUCT_HH

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>

#include <TH1.h>
#include <TObject.h>
#include <TRef.h>
#include <TRefArray.h>

// #include "TestbeamHelpers.hh"

namespace dataProducts {

    typedef std::tuple<int,int,int> ChannelID;
    typedef std::vector<ChannelID> ChannelList;
    template <typename T> ChannelID GetID(T *x){
        return std::make_tuple(x->crateNum, x->amcNum, x->channelTag);
    };
} // namespace dataProducts

#endif // DATAPRODUCT_HH