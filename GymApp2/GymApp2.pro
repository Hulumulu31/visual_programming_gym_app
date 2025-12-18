QT += core widgets gui sql
CONFIG += c++17
TARGET = GymApp2
TEMPLATE = app
SOURCES += \
    $$PWD/main.cpp \
    $$PWD/user.cpp \
    $$PWD/membership.cpp \
    $$PWD/visit.cpp \
    $$PWD/reportmanager.cpp \
    $$PWD/adminwindow.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/clientwindow.cpp \
    $$PWD/jsonmanager.cpp \
    $$PWD/searchfiltermanager.cpp \
    $$PWD/membershipdialog.cpp \
    $$PWD/visitdialog.cpp \
    $$PWD/registrationdialog.cpp \
    $$PWD/datamanager.cpp \
    $$PWD/observer.cpp \
    $$PWD/strategy.cpp \
    $$PWD/membershipmanager.cpp \
    $$PWD/visitmanager.cpp \
    $$PWD/notificationmanager.cpp \
    $$PWD/trainerservice.cpp \
    $$PWD/trainerservicedialog.cpp

HEADERS += \
    $$PWD/user.h \
    $$PWD/membership.h \
    $$PWD/visit.h \
    $$PWD/reportmanager.h \
    $$PWD/adminwindow.h \
    $$PWD/mainwindow.h \
    $$PWD/clientwindow.h \
    $$PWD/jsonmanager.h \
    $$PWD/searchfiltermanager.h \
    $$PWD/membershipdialog.h \
    $$PWD/visitdialog.h \
    $$PWD/registrationdialog.h \
    $$PWD/datamanager.h \
    $$PWD/observer.h \
    $$PWD/strategy.h \
    $$PWD/membershipmanager.h \
    $$PWD/visitmanager.h \
    $$PWD/notificationmanager.h \
    $$PWD/trainerservice.h \
    $$PWD/trainerservicedialog.h

FORMS += \
    $$PWD/mainwindow.ui \
    $$PWD/adminwindow.ui \
    $$PWD/clientwindow.ui \
    $$PWD/membershipdialog.ui \
    $$PWD/visitdialog.ui \
    $$PWD/registrationdialog.ui \
    $$PWD/trainerservicedialog.ui