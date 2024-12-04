cmake_minimum_required(VERSION 3.30)
project(PFM)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS core base)
if (NOT wxWidgets_FOUND)
    message(FATAL_ERROR "wxWidgets not found. Please install wxWidgets and try again.")
endif()
include(${wxWidgets_USE_FILE})


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(PQXX REQUIRED)
include_directories(${PQXX_INCLUDE_DIR} include)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${PQXX_LIBRARY})