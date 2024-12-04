find_path(PQXX_INCLUDE_DIR pqxx/pqxx)
find_library(PQXX_LIBRARY pqxx)

if (PQXX_INCLUDE_DIR AND PQXX_LIBRARY)
    set(PQXX_FOUND TRUE)
    message(STATUS "Found libpqxx: ${PQXX_LIBRARY}")
else()
    set(PQXX_FOUND FALSE)
    message(FATAL_ERROR "Could not find libpqxx")
endif()

mark_as_advanced(PQXX_INCLUDE_DIR PQXX_LIBRARY)
