file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(leveldb STATIC ${SOURCES} ${HEADERS})
target_link_libraries(leveldb PRIVATE Core OpenSSL)

target_compile_definitions(leveldb PUBLIC MCE_USE_OPENSSL)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_include_directories(leveldb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
