add_executable(qtqrcode-example
    main.cpp
    MainWindow.cpp
    )

target_include_directories(qtqrcode-example
    PUBLIC
    )

target_link_libraries(qtqrcode-example
    PRIVATE
    qtqrcode
    )

install(TARGETS qtqrcode-example
    EXPORT qtqrcode-example
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

