
process_folder_files([ALL]
    atomic_pointer.h
    port.h
    port_example.h
    thread_annotations.h
	port_posix.cc
	port_posix.h
	port_posix_sse.cc
)

process_folder_files([WIN10]
	port_win.cc
	port_win.h
)

process_folder_files([WINRT]
	port_wp8.cc
	port_wp8.h
	port_winrt.cc
	port_winrt.h
)

process_folder_files([UNUSED]
    README
)

process_sub_folders(
    win
)
