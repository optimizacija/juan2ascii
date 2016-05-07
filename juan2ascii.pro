TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    edge_detection.cpp \
    show.cpp \
    thresholds.cpp \
    asciiconverter.cpp \
    stopwatch.cpp

LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core

HEADERS += \
    edge_detection.h \
    show.h \
    thresholds.h \
    asciiconverter.h \
    stopwatch.h
