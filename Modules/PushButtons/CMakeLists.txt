# Search for all source files in the current directory
# and save the names to the DIR_PushButton_SRCS variable
aux_source_directory(. DIR_PushButtons_SRCS)

include_directories(../Config)

# Generate link library
add_library(PushButtons ${DIR_PushButtons_SRCS})
target_link_libraries(PushButtons PUBLIC Config)