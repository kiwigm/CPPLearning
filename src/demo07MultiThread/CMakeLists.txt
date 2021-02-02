project(demo07MultiThread)

AUX_SOURCE_DIRECTORY(./ DIR_LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin)

ADD_EXECUTABLE(demo07MultiThread
        ${DIR_LIB_SRCS}
        )

TARGET_LINK_LIBRARIES(demo07MultiThread
        pthread
        )