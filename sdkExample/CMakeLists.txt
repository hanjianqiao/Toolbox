cmake_minimum_required(VERSION 3.14)

project(Example LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


include(../sdk/sdk.cmake)

file(GLOB _SOURCES CONFIGURE_DEPENDS
    *.cpp *.h
)

qt6_add_executable(Example
    MANUAL_FINALIZATION
    ${_SOURCES}
)

target_include_directories(Example PRIVATE
    ${SDK_INCLUDE_BASE_DIR}
)

target_link_directories(Example PRIVATE
    ${SDK_LIB_BASE_DIR}
)

target_link_libraries(Example PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    hqt
    hcompress
    hmisc
    hfontawesome
    qhotkey

    woff2enc
    woff2dec
    woff2common
    brotlicommon
    brotlidec
    brotlienc
)

add_compile_definitions(
    ${SDK_COMPILE_DEFINATIONS}
)

qt_finalize_executable(Example)
