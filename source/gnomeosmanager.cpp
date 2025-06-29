#ifdef __linux__
#include "gnomeosmanager.hpp"
#include <iostream>

void GnomeOSManager::ChangeWallpaper(std::filesystem::directory_entry _entry) const{
    // Setting wallpaper with gsettings

    std::string path = _entry.path();

    std::string commanddefault = "gsettings set org.gnome.desktop.background picture-uri 'file://" + path + "'";
    std::string commanddark = "gsettings set org.gnome.desktop.background picture-uri-dark 'file://" + path + "'";
    (void) std::system(commanddefault.c_str());
    (void) std::system(commanddark.c_str());

}

#endif