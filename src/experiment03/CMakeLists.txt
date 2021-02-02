project(experiment03)

AUX_SOURCE_DIRECTORY(./ DIR_LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin)

ADD_EXECUTABLE(experiment03point point.cpp

        )

ADD_EXECUTABLE(experiment03snake snake.cpp

        )