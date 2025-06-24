# Glob the source files together
file(GLOB SOURCE_FILES
    common/*.cc
    nalu/*.cc
)

# Make an object file
add_library(data_products SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(data_products
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${ROOT_INCLUDE_DIRS}
)

# Libraries
target_link_libraries(data_products
    PUBLIC
        ${ROOT_LIBRARIES}
)

#These are the data products for which we make root dictionary
set(DataProducts 
    ${PROJECT_SOURCE_DIR}/include/common/*.hh
    ${PROJECT_SOURCE_DIR}/include/nalu/*.hh
)

# Make the ROOT dictionary
root_generate_dictionary(DataProductDictionary
    ${DataProducts} 
    MODULE data_products
    LINKDEF ${PROJECT_SOURCE_DIR}/include/LinkDef.h
)

# Install the ROOT dictionary
install(FILES
            ${PROJECT_BINARY_DIR}/src/libdata_products_rdict.pcm
            ${PROJECT_BINARY_DIR}/src/libdata_products.rootmap
        DESTINATION lib
)

# Install the library
install(TARGETS 
            data_products
        LIBRARY DESTINATION lib
)

# Install the headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include
)  