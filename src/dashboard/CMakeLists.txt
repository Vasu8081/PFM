add_library(dashboard STATIC home.cpp)
target_include_directories(dashboard PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})