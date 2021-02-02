project(experiment05)

AUX_SOURCE_DIRECTORY(./ DIR_LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin)

ADD_EXECUTABLE(experiment05player
        player.cpp
        )

ADD_EXECUTABLE(experiment05attack
        attack.cpp
)

