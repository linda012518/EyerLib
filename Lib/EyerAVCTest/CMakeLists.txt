add_executable(
        EyerAVCTest
        Main.cpp
        Baseline.hpp NALUReader.hpp)

include_directories (../)


target_link_libraries (EyerAVCTest EyerAVC)
target_link_libraries (EyerAVCTest EyerCore)
target_link_libraries (EyerAVCTest EyerThread)
target_link_libraries (EyerAVCTest gtest)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/demo_video.h264
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/
        )

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/demo_video_176x144.h264
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/
        )

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/demo_video_176x144_baseline.h264
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/
        )


INSTALL(
        TARGETS EyerAVCTest
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)