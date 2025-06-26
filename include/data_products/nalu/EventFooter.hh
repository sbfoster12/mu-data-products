#ifndef NALU_EVENTFOOTER_HH
#define NALU_EVENTFOOTER_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class EventFooter
     * @brief Represents the footer information for a NALU event.
     *
     * Inherits from DataProduct. 
     */
    class EventFooter : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            EventFooter();

            /**
             * @brief Constructor with event_footer index.
             * @param event_footer 2 byte word in the footer
             */
            EventFooter(uint32_t event_footer);

            /**
             * @brief Destructor.
             */
            ~EventFooter();

            /**
             * @brief Index of the event.
             */
            unsigned int event_footer;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the EventFooter.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(EventFooter,1)
    };

    /**
     * @typedef EventFooterCollection
     * @brief A collection (vector) of EventFooter objects.
     */
    typedef std::vector<EventFooter> EventFooterCollection;

} // namespace data_products::nalu

#endif // NALU_EVENTFOOTER_HH
