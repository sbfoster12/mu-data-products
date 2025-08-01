#ifndef NALU_TIME_HH   
#define NALU_TIME_HH

#include "data_products/common/DataProduct.hh"

namespace dataProducts {

    /**
     * @class Time
     * @brief Represents the footer information for a NALU event.
     *
     * Inherits from DataProduct. 
     */
    class NaluTime : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluTime();

            /**
             * @brief Constructor with event_footer index.
             * @param event_footer 2 byte word in the footer
             */
            NaluTime(
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
            ~NaluTime();

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
            ClassDefOverride(NaluTime,1)
    };

    /**
     * @typedef TimeCollection
     * @brief A collection (vector) of Time objects.
     */
    typedef std::vector<NaluTime> NaluTimeCollection;

} // namespace dataProducts

#endif // NALU_TIME_HH
