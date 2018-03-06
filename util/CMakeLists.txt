
process_folder_files([ALL]
    testutil.cc
    status.cc
    arena.cc
    bloom.cc
    hash.cc
    coding.h
    logging.h
    filter_policy.cc
    histogram.cc
    crc32c.cc
    mutexlock.h
    cache.cc
    histogram.h
    crc32c.h
    Filepath.h
    logging.cc
    options.cc
    arena.h
    comparator.cc
    coding.cc
    hash.h
    random.h
    env.cc
)


process_folder_files([ALL][TST]
    testharness.cc
    testharness.h
    testutil.h
    arena_test.cc
    coding_test.cc
    env_test.cc
    crc32c_test.cc
    bloom_test.cc
    hash_test.cc
    cache_test.cc
)

process_folder_files([WINDOWS]
    win_logger.cc
    win_logger.h
)

process_folder_files([WIN10] 
    env_win.cc
)

process_folder_files([WINRT] 
    env_winrt.cc
)

process_folder_files([MAC]
    env_posix.cc
    posix_logger.h
)

process_folder_files([MAC][TST]
    env_posix_test.cc
    env_posix_test_helper.h
)

process_folder_files([UNUSED]
    env_boost.cc
)