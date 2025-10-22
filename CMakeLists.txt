cmake_minimum_required(VERSION 3.1)

project(qtqrcode
    LANGUAGES CXX
    VERSION 1.0.0
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(FeatureSummary)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)

find_package(Qt5 COMPONENTS Core Gui Svg CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(example)

