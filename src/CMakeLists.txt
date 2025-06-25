# Glob the source files together
file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nalu/*.cc
)

# Make an object file
add_library(data_products SHARED ${SOURCE_FILES})

add_library(DataProducts::data_products ALIAS data_products)

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
    ${PROJECT_SOURCE_DIR}/include/data_products/common/*.hh
    ${PROJECT_SOURCE_DIR}/include/data_products/nalu/*.hh
)

# Make the ROOT dictionary
root_generate_dictionary(DataProductDictionary
    ${DataProducts} 
    MODULE data_products
    LINKDEF ${PROJECT_SOURCE_DIR}/include/data_products/LinkDef.h
)

# Install the ROOT dictionary
install(FILES
            ${PROJECT_BINARY_DIR}/src/libdata_products_rdict.pcm
            ${PROJECT_BINARY_DIR}/src/libdata_products.rootmap
        DESTINATION lib
)

# Install the library
install(TARGETS data_products
        EXPORT DataProductsTargets
        LIBRARY DESTINATION lib
)

# Install the headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include
)

# Export
install(EXPORT DataProductsTargets
  FILE DataProductsTargets.cmake
  NAMESPACE DataProducts::
  DESTINATION lib/cmake/DataProducts
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/DataProductsConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/DataProductsConfig.cmake"
  INSTALL_DESTINATION lib/cmake/DataProducts
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/DataProductsConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/DataProductsConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/DataProductsConfigVersion.cmake"
  DESTINATION lib/cmake/DataProducts
)