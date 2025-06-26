#include "data_products/nalu/EventFooter.hh"

using namespace data_products::nalu;

/**
 * @brief Default constructor for EventFooter.
 *
 * Initializes the event footer to 0.
 */
EventFooter::EventFooter()
    : DataProduct(),
      event_footer(0)
{}

/**
 * @brief Constructor with footer value.
 *
 * @param event_footer_arg 32-bit unsigned integer representing the event footer value.
 */
EventFooter::EventFooter(
    uint32_t event_footer_arg
    )
    : DataProduct(),
      event_footer(event_footer_arg)
{}

/**
 * @brief Destructor for EventFooter.
 */
EventFooter::~EventFooter() {}

/**
 * @brief Make a string of the contents of the class
 *
 * Displays the event footer value in hexadecimal format.
 */
std::string EventFooter::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "data_products::nalu::EventFooter: " << std::endl;
    oss << "    event_footer: " << std::hex << "0x" << event_footer << std::endl;
    return oss.str();
}

/**
 * @brief Print the contents of the EventFooter to standard output.
 *
 * Displays the class as a string
 */
void EventFooter::Show() const { 
    std::cout << this->String();
}
