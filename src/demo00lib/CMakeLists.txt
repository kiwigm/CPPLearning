project(demo00lib)

ADD_SUBDIRECTORY(./add)

AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin)


ADD_EXECUTABLE(demo00lib
        ${DIR_LIB_SRCS}
        )

TARGET_LINK_LIBRARIES(demo00lib
        add
)