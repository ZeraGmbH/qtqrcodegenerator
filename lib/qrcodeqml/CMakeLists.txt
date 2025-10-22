file(GLOB SOURCES
    *.cpp
    )

file(GLOB HEADER
    *.h
    qrcodegen/*.h
    )

add_library(qrcode-qml SHARED
    ${SOURCES}
    ${HEADER}
    )

target_link_libraries(qrcode-qml
    PUBLIC
    qtqrcode
    Qt5::Quick
    )

target_include_directories(qrcode-qml
    PUBLIC
    $<INSTALL_INTERFACE:include/qtqrcode>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

set_target_properties(qrcode-qml PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(qrcode-qml PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

generate_export_header(qrcode-qml)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qrcode-qml_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qtqrcode
    )

export(TARGETS qrcode-qml FILE QtQrcode.cmake)
install(TARGETS qrcode-qml
    EXPORT QtQrcodeExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(
    FILES ${HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qtqrcode
    )

