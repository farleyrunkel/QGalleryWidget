cmake_minimum_required(VERSION 3.5)

project(QGalleryWidget VERSION 0.1 LANGUAGES CXX)

set(PQGALLERYWIDGET_SOURCES
    src/galleryphotowidget.cpp
    src/galleryphotowidget.h
    src/gallery/gallerywidget.h
    src/interactivebuttonbase.cpp
    src/interactivebuttonbase.h
    src/waterzoombutton.cpp
    src/waterzoombutton.h
    CACHE INTERNAL "PQGalleryWidget sources"
)
