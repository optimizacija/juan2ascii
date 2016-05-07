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

LIBS += /usr/local/lib/libopencv_calib3d.so
LIBS += /usr/local/lib/libopencv_core.so
LIBS += /usr/local/lib/libopencv_features2d.so
LIBS += /usr/local/lib/libopencv_flann.so
LIBS += /usr/local/lib/libopencv_highgui.so
LIBS += /usr/local/lib/libopencv_imgcodecs.so
LIBS += /usr/local/lib/libopencv_imgproc.so
LIBS += /usr/local/lib/libopencv_ml.so
LIBS += /usr/local/lib/libopencv_objdetect.so
LIBS += /usr/local/lib/libopencv_photo.so
LIBS += /usr/local/lib/libopencv_shape.so
LIBS += /usr/local/lib/libopencv_stitching.so
LIBS += /usr/local/lib/libopencv_superres.so
LIBS += /usr/local/lib/libopencv_ts.a
LIBS += /usr/local/lib/libopencv_video.so
LIBS += /usr/local/lib/libopencv_videoio.so
LIBS += /usr/local/lib/libopencv_videostab.so

HEADERS += \
    edge_detection.h \
    show.h \
    thresholds.h \
    asciiconverter.h \
    stopwatch.h
