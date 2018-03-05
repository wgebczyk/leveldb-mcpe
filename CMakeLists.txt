
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
    LEVELDB_PLATFORM_POSIX
    POSIX
	OS_MACOSX
)

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
