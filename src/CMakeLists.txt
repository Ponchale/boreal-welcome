set(SRC main.cpp
    welcome.cpp
    welcome.h)

qtquick_compiler_add_resources(RESOURCES qml/boreal-welcome.qrc)

add_executable(boreal-welcome ${SRC} ${RESOURCES})

target_link_libraries(boreal-welcome
	Qt5::Gui
	Qt5::Qml
	Qt5::Quick
        Qt5::DBus
        Boreal::App)

install(TARGETS boreal-welcome RUNTIME
	DESTINATION ${CMAKE_INSTALL_BINDIR})
