file(GLOB SOURCES 
    *.cpp
    qrcodegen/*.cpp
    )

file(GLOB HEADER
    *.h
    qrcodegen/*.h
    )

add_library(qtqrcode SHARED
    ${SOURCES}
    ${HEADER}
    )

target_link_libraries(qtqrcode 
    PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Svg
    )

target_include_directories(qtqrcode
    PUBLIC
    $<INSTALL_INTERFACE:include/qtqrcode>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

set_target_properties(qtqrcode PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(qtqrcode PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

generate_export_header(qtqrcode)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qtqrcode_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qtqrcode
    )

export(TARGETS qtqrcode FILE QtQrcode.cmake)
install(TARGETS qtqrcode
    EXPORT QtQrcodeExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(
    FILES ${HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qtqrcode
    )

