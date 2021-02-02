project(experiment06)

AUX_SOURCE_DIRECTORY(./ DIR_LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin)

ADD_EXECUTABLE(experiment06player
        player.cpp
        )
