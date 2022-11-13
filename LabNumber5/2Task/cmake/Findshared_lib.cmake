set(FIND_SHARED_LIB_PATHS F:/Projects/BoAaP/shared_lib/build/Debug
        )

find_library(SHARED_LIB_LIBRARY               # The variable to store where it found the .a files
        NAMES shared_lib                      # The name of the .a file (without the extension and without the 'lib')
       # PATH_SUFFIXES Debug                    # The folder the .a file is in
        PATHS ${FIND_SHARED_LIB_PATHS})
