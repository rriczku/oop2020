TEMPLATE = subdirs

SUBDIRS += \
    acceleration \
    displacement \
    speed
    
acceleration.depends = utils
displacement.depends = utils
speed.depends = utils

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../utils/release/ -lutils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../utils/debug/ -lutils
else:unix: LIBS += -L$$OUT_PWD/../utils/ -lutils

INCLUDEPATH += $$PWD/../utils
DEPENDPATH += $$PWD/../utils
