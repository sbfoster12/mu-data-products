#include "data_products/nalu/Time.hh"

using namespace data_products::nalu;

/**
 * @brief Default constructor for Time.
 *
 * Initializes the event footer to 0.
 */
Time::Time()
    : DataProduct()
    ,collection_cycle_index(0)
    ,collection_cycle_timestamp_ns(0)
    ,udp_time(0)
    ,parse_time(0)
    ,event_time(0)
    ,total_time(0)
    ,data_processed(0)
    ,data_rate(0)
{}

/**
 * @brief Constructor
 *
 * @param
 */
Time::Time(
     uint64_t collection_cycle_index_arg
    ,uint64_t collection_cycle_timestamp_ns_arg
    ,double udp_time_arg
    ,double parse_time_arg
    ,double event_time_arg
    ,double total_time_arg
    ,uint64_t data_processed_arg
    ,double data_rate_arg
    )
    : DataProduct()
    ,collection_cycle_index(collection_cycle_index_arg)
    ,collection_cycle_timestamp_ns(collection_cycle_timestamp_ns_arg)
    ,udp_time(udp_time_arg)
    ,parse_time(parse_time_arg)
    ,event_time(event_time_arg)
    ,total_time(total_time_arg)
    ,data_processed(data_processed_arg)
    ,data_rate(data_rate_arg)
{}

/**
 * @brief Destructor for Time.
 */
Time::~Time() {}

/**
 * @brief Make a string of the contents of the class
 *
 * Displays the event footer value in hexadecimal format.
 */
std::string Time::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "Time: " << std::endl;
    oss << "    collection_cycle_index:         " << collection_cycle_index << std::endl;
    oss << "    collection_cycle_timestamp_ns:  " << collection_cycle_timestamp_ns << std::endl;
    oss << "    udp_time:                       " << udp_time << std::endl;
    oss << "    parse_time:                     " << parse_time << std::endl;
    oss << "    event_time:                     " << event_time << std::endl;
    oss << "    total_time:                     " << total_time << std::endl;
    oss << "    data_processed:                 " << data_processed << std::endl;
    oss << "    data_rate:                      " << data_rate << std::endl;
    return oss.str();
}

/**
 * @brief Print the contents of the Time to standard output.
 *
 * Displays the class as a string
 */
void Time::Show() const { 
    std::cout << this->String();
}
