
file(GLOB cpps RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

#process_folder_files([ALL]
#    ${cpps}
#    ${headers}
#)

#process_sub_folders(
#    include
#    src
#)

process_folder_includes([ALL] include)
process_folder_defines([ALL] DLLX=)
