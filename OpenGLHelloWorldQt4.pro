QT += opengl

win32: LIBS += $$PWD/libs/glew32.lib

INCLUDEPATH += $$PWD/includes
DEPENDPATH += $$PWD/includes

RCC_DIR     = $$_PRO_FILE_PWD_/build/tmp/rcc
UI_DIR      = $$_PRO_FILE_PWD_/build/tmp/ui
MOC_DIR     = $$_PRO_FILE_PWD_/build/tmp/moc
OBJECTS_DIR = $$_PRO_FILE_PWD_/build/tmp/obj

CONFIG(debug, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/build/release
}

SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/window.cpp

HEADERS += \
    src/ui/mainwindow.h \
    src/ui/window.h

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    resources/shaders/simple.vert \
    resources/shaders/simple.frag
