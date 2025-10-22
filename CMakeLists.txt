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

find_package(Qt5 COMPONENTS Core Gui Svg Quick QuickControls2 Qml CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(examples)

write_basic_package_version_file(
    QtQrcodeVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
    )
configure_file(QtQrcode.cmake.in QtQrcode.cmake @ONLY)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/QtQrcode.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/QtQrcodeVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QtQrcode
    )

install(EXPORT QtQrcodeExport
    FILE QtQrcodeTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QtQrcode
    )

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
