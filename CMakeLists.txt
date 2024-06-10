cmake_minimum_required(VERSION 3.5)

project(QGalleryWidget VERSION 0.1 LANGUAGES CXX)

set(QGALLERYWIDGET_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/galleryphotowidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/galleryphotowidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gallerywidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gallerywidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interactivebuttonbase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interactivebuttonbase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/waterzoombutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/waterzoombutton.h
    CACHE INTERNAL "PQGalleryWidget sources"
)

set(QGALLERYWIDGET_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    CACHE INTERNAL "PQGalleryWidget include"
)
