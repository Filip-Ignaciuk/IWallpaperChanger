#ifdef __linux__
#include "xfceosmanager.hpp"
#include <iostream>

void XFCEOSManager::ChangeWallpaper(std::filesystem::directory_entry _entry) const{
    // Setting wallpaper with xfconf-query

    std::string path = _entry.path();

    std::string command =
        "xfconf-query --channel xfce4-desktop "
        "--property /backdrop/screen0/monitor0/image-path "
        "--set \"" + path + "\"";

    (void) std::system(command.c_str());

}

#endif