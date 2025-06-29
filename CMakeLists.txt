cmake_minimum_required(VERSION 3.20)
project(IWallpaperChanger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_SOURCES source/osmanager.cpp source/osmanagerfactory.cpp source/main.cpp source/winosmanager.cpp source/gnomeosmanager.cpp source/kdeosmanager.cpp source/xfceosmanager.cpp source/macosmanager.cpp)

message(STATUS "System: ${CMAKE_SYSTEM_NAME}")


if(WIN32)
    add_executable(IWallpaperChangerWindows source/winmain.cpp ${COMMON_SOURCES})
    set_target_properties(IWallpaperChangerWindows PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/windows OUTPUT_NAME "IWallpaperChangerWindows")
    target_include_directories(IWallpaperChangerWindows PRIVATE source)
endif()

if(UNIX AND NOT APPLE)
    add_executable(IWallpaperChangerGnome  source/maingnome.cpp ${COMMON_SOURCES})
    set_target_properties(IWallpaperChangerGnome PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gnome OUTPUT_NAME "IWallpaperChangerGnome")
    target_include_directories(IWallpaperChangerGnome PRIVATE source)

    add_executable(IWallpaperChangerKDE  source/mainkde.cpp ${COMMON_SOURCES})
    set_target_properties(IWallpaperChangerKDE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/kde OUTPUT_NAME "IWallpaperChangerKDE")
    target_include_directories(IWallpaperChangerKDE PRIVATE source)

    add_executable(IWallpaperChangerXFCE  source/mainxfce.cpp ${COMMON_SOURCES})
    set_target_properties(IWallpaperChangerXFCE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/xfce OUTPUT_NAME "IWallpaperChangerXFCE")
    target_include_directories(IWallpaperChangerXFCE PRIVATE source)
endif()

if(APPLE)
    add_executable(IWallpaperChangerApple  source/macmain.cpp ${COMMON_SOURCES})
    set_target_properties(IWallpaperChangerApple PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/macos OUTPUT_NAME "IWallpaperChangerApple")
    target_include_directories(IWallpaperChangerApple PRIVATE source)

endif()

