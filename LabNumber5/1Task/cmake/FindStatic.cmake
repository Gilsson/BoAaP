set(FIND_STATIC_PATHS
        F:/Projects/BoAaP/LabNumber5/1Task/static
        )

find_path(STATIC_INCLUDE_DIR                  # The variable to store the path in and the name of the header files
           PATH_SUFFIXES include              # The folder name containing the header files
            PATHS ${FIND_STATIC_PATHS})       # Where to look (defined above)

find_path(STATIC_LIBRARY                      # The variable to store where it found the .a files
        NAMES static                          # The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES cmake-build-debug       # The folder the .a file is in
        PATHS ${FIND_STATIC_PATHS})           # Where to look (defined above)