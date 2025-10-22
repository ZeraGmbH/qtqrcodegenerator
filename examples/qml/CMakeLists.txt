add_executable(qrcode-example-qml
    main.cpp
    qml.qrc
    )

target_link_libraries(qrcode-example-qml
    PRIVATE
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Qml
    qrcode-qml
    )

install(TARGETS qrcode-example-qml
    EXPORT qrcode-example-qml
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
