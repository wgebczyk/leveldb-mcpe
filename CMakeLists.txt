file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/db/log_writer.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/zlib_compressor.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/db_impl.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/filename.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/table_cache.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/log_reader.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/write_batch.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/builder.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/version_edit.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/dbformat.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/zopfli_compressor.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/version_set.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/dumpfile.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/snappy_compressor.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/db_iter.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/repair.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/zstd_compressor.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/db/memtable.cc"

    "${CMAKE_CURRENT_SOURCE_DIR}/table/table.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/block.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/merger.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/iterator.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/block_builder.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/table_builder.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/filter_block.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/format.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/table/two_level_iterator.cc"

    "${CMAKE_CURRENT_SOURCE_DIR}/util/testutil.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/status.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/arena.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/bloom.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/hash.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/filter_policy.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/histogram.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/crc32c.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/cache.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/logging.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/options.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/comparator.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/coding.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/util/env.cc"

    "${CMAKE_CURRENT_SOURCE_DIR}/port/port_posix.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/port/port_posix.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/port/port_posix_sse.cc"
)

if(WIN32)
	list(APPEND SOURCES
		${CMAKE_CURRENT_SOURCE_DIR}/port/port_win.cc
		${CMAKE_CURRENT_SOURCE_DIR}/util/win_logger.cc
		${CMAKE_CURRENT_SOURCE_DIR}/util/env_win.cc
	)
elseif(APPLE)
	list(APPEND SOURCES
		${CMAKE_CURRENT_SOURCE_DIR}/util/env_posix.cc
	)
endif()

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(leveldb STATIC ${SOURCES} ${HEADERS})
target_link_libraries(leveldb PRIVATE Core OpenSSL mc-zlib boost)

target_compile_definitions(leveldb PUBLIC DLLX=)

if(WIN32)
    target_compile_definitions(leveldb PUBLIC WIN32 OS_WIN)
elseif(APPLE)
	target_compile_definitions(leveldb PUBLIC LEVELDB_PLATFORM_POSIX POSIX OS_MACOSX)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_include_directories(leveldb PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(leveldb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
