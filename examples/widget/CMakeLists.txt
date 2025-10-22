add_executable(qrcode-example-widget
    main.cpp
    MainWindow.cpp
    )

target_link_libraries(qrcode-example-widget
    PRIVATE
    qtqrcode
    )

install(TARGETS qrcode-example-widget
    EXPORT qrcode-example-widget
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
