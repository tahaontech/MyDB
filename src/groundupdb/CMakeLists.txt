# Sources and Headers
set(LIBRARY_SOURCES 
    "groundupdb.cc" 
    "database.cc"
    )
set(LIBRARY_HEADERS 
    "groundupdb.h" 
    "database.h"
    )
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

# MyLib Library
add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_INCLUDES})

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIBRARY_NAME} ENABLE ON AS_ERROR ON)
endif()

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} optimized)
endif()
