#ifdef __APPLE__
#include "macosmanager.hpp"

void MACOSManager::ChangeWallpaper(std::filesystem::directory_entry _entry) const{

    std::string path = _entry.path();

    std::string command = "osascript -e 'tell application \"Finder\" to set desktop picture to POSIX file \"" + path + "\"'";
    std::system(command.c_str());
}
#endif