# Search for all source files in the current directory
# and save the names to the DIR_Entry_SRCS variable
aux_source_directory(. DIR_Entry_SRCS)

# Add header file directory
include_directories(../../Modules/Config)
include_directories(../../Modules/GUI)
include_directories(../../Modules/PushButtons)
include_directories(../../Modules/LCD)
include_directories(../Wallpaper)

# Generate link library
add_library(Entry ${DIR_Entry_SRCS})
target_link_libraries(Entry PUBLIC Config)