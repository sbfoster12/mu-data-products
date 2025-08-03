#ifndef FC7_HEADER_HH
#define FC7_HEADER_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    class FC7Header : public DataProduct {

        public:
            FC7Header();

            FC7Header(unsigned int crateNumArg
                ,unsigned int amcNumArg
                ,unsigned int triggerNumArg
                ,unsigned long clockCounterArg
                ,unsigned int fillTypeArg
                ,unsigned int boardTypeArg
                ,unsigned int fc7TypeArg
                ,unsigned int boardIDArg
                ,unsigned char xadcAlarmsArg
                ,bool emptyEventArg
                ,unsigned int majorRevisionArg
                ,unsigned int minorRevisionArg
                ,unsigned patchRevisionArg);

            //Destructor
            ~FC7Header();

            //member variables

            // uTCA crate number
            unsigned int crateNum;

            // uTCA slot number (AMCNo)
            unsigned int amcNum;

            // trigger number of this rider
            unsigned int triggerNum;

            unsigned int dataLength;

            // clock counter of this rider ([BXid, OrN])
            unsigned long clockCounter;

            // fill type of this event
            unsigned int fillType;

            // board type of this amc (rider, ccc fc7. tracker fc7)
            unsigned int boardType;

            // fc7 type (encoder, fan out, trigger)
            unsigned int fc7Type;

            // board ID
            unsigned int boardID;

            unsigned char xadcAlarms;

            bool emptyEvent;

            // revision numbers
            unsigned int majorRevision;
            unsigned int minorRevision;
            unsigned int patchRevision;

            // Member variable pointer for defining iterations (none for fc7 header)
            static constexpr int FC7Header::* iterMemb = nullptr;

            void Show() const override;

            ClassDefOverride(FC7Header,1)

    };

    typedef std::vector<FC7Header> FC7HeaderCollection;

} // namespace dataProducts

#endif // FC7_HEADER_HH