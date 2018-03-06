process_folder_files([UNUSED]
    LICENSE
    AUTHORS
    Makefile
    build_detect_platform
    TODO
    README.md
    NEWS
    CONTRIBUTING.md
)

process_folder_defines([ALL]
    DLLX=
)

if(APPLE)
    process_folder_defines([ALL]
        LEVELDB_PLATFORM_POSIX
        POSIX
        OS_MACOSX
    )
endif()

if(WIN32)
    process_folder_defines_internal([ALL]
        WIN32
        OS_WIN
    )
endif()

process_sub_folders(
    util
    include
    table
    db
    port
    issues
    helpers
)

process_folder_includes([ALL]
    .
)

process_libraries([ALL]
    zlib
)