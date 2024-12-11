add_library(database STATIC database.cpp account_db.cpp user_db.cpp)
target_include_directories(database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})