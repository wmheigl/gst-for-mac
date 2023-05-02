# Flow of Control in 'main.c'

To understand how the implementation of GNU Smalltalk works I traced
the flow of control in 'main.c'. This file provides the entry point
to the program 'gst'.

## What happens in 'main.c'?

Command line option parsing via getopt.h provided by MacOS SDK.

There is an undocumented option '-psn' if __APPLE__ is defined.

Check for environmental variables `SMALLTALK_KERNEL` and `SMALTALK_IMAGE` (deprecated).

Set GST global variables.

Call `gst_initialize(kernel_dir, image_file, flags)` in gstpub.c.
- Call `_gst_initialize(kernel_dir, image_file, flags)` in files.c
    - Call `_gst_init_snprintfv()` in print.c
    - Sets `_gst_user_file_base_path` in files.c
    - Checks that `kernel_dir` and `image_file` paths are readable
    - Retrieves default kernel path from image path, probably because of --prefix option
    - Sets `_gst_image_file_path, _gst_kernel_file_path, _gst_binary_image_name`
    - Sets args passed to Smalltalk
    - Checks if `user_init_file` needs to be loaded
    - Call `_gst_init_sysdep()` in files.c
    - Call `_gst_init_signals()` in interp.c
    - Call `_gst_init_event_loop()` in events.c
    - Call `_gst_init_cfuncs()` in cint.c
    - Call `_gst_init_sockets()` in sockets.c
    - Call `_gst_init_primitives()` in prims.inl
    - Sets some global variables in case of regression testing
    - Checks if image needs to be rebuilt
    - If ok to load image file:
        - Call `_gst_init_interpreter()` in interp.c
        - Call `_gst_init_vmproxy()` in callin.c
    - ElseIf abortOnFailure 
        - abort
    - Else
        - Call `_gst_init_oop_table()` in oop.c 
        - Call `_gst_init_mem_default()` in oop.c
        - Call `_gst_init_dictionary()` in dict.c
        - Call `_gst_init_interpreter()` in interp.c
        - Call `_gst_init_vmproxy()` in callin.c
        - Call `_gst_install_initial_methods()` in comp.c
        - Call `load_standard_files()` in files.c
        - Option: Call `_gst_save_to_file()`
    - kernel is initialized now
    - Call `_gst_invoke_hook()` in comp.c
    - Optional user init file: Call `_gst_process_file()` in input.c
    - Optional readline: Call `_gst_initialize_readline()` in input.c
    
