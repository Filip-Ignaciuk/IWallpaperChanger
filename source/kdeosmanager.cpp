#ifdef __linux__
#include "kdeosmanager.hpp"
#include <iostream>

KDEOSManager::KDEOSManager() {}

void KDEOSManager::ChangeWallpaper(std::filesystem::directory_entry _entry) const{
    // Setting wallpaper with qdbus

    std::string path = _entry.path();

    std::string command = 
    "qdbus org.kde.plasmashell /PlasmaShell org.kde.PlasmaShell.evaluateScript \""
    "var allDesktops = desktops();"
    "for (i in allDesktops) {"
    "d = allDesktops[i];"
    "d.wallpaperPlugin = 'org.kde.image';"
    "d.currentConfigGroup = Array('Wallpaper', 'org.kde.image', 'General');"
    "d.writeConfig('Image', 'file://" + path + "');"
    "}\"";
    std::cout << "Running command:\n" << command << "\n";

    (void) std::system(command.c_str());

    
}

#endif