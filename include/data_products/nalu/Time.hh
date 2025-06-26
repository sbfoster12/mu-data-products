#ifndef NALU_TIME_HH   
#define NALU_TIME_HH

#include "data_products/common/DataProduct.hh"

namespace data_products::nalu {

    /**
     * @class Time
     * @brief Represents the footer information for a NALU event.
     *
     * Inherits from DataProduct. 
     */
    class Time : public data_products::common::DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            Time();

            /**
             * @brief Constructor with event_footer index.
             * @param event_footer 2 byte word in the footer
             */
            Time(
                 uint64_t collection_cycle_index
                ,uint64_t collection_cycle_timestamp_ns
                ,double udp_time
                ,double parse_time
                ,double event_time
                ,double total_time
                ,uint64_t data_processed
                ,double data_rate
            );

            /**
             * @brief Destructor.
             */
            ~Time();

            /**
             * @brief Collection cycle index
             */
            uint64_t collection_cycle_index;

            /**
             * @brief Collection cycle timestamp in ns
             */
            uint64_t collection_cycle_timestamp_ns;

            /**
             * @brief upd time
             */
            double udp_time;

            /**
             * @brief Parse time
             */
            double parse_time;

            /**
             * @brief Event time
             */
            double event_time;

            /**
             * @brief Total time
             */
            double total_time;

            /**
             * @brief Data processed
             */
            uint64_t data_processed;

            /**
             * @brief Data rate
             */
            double data_rate;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the Time.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(Time,1)
    };

    /**
     * @typedef TimeCollection
     * @brief A collection (vector) of Time objects.
     */
    typedef std::vector<Time> TimeCollection;

} // namespace data_products::nalu

#endif // NALU_TIME_HH
