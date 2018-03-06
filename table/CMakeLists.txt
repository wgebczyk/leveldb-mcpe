
process_folder_files([ALL]
    table.cc
    block.cc
    merger.cc
    iterator.cc
    block_builder.cc
    iterator_wrapper.h
    merger.h
    table_builder.cc
    block_builder.h
    filter_block.cc
    block.h
    format.cc
    filter_block.h
    two_level_iterator.h
    format.h
    two_level_iterator.cc
)

process_folder_files([ALL][TST]
    filter_block_test.cc
    table_test.cc
)