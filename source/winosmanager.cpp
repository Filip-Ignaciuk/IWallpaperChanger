#ifdef _WIN32
#include <windows.h>
#include "winosmanager.hpp"



void WinOSManager::ChangeWallpaper(std::filesystem::directory_entry _entry) const{
    // Setting wallpaper with Windows API
    std::wstring wideString = _entry.path().wstring();

    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0,  (void*)widePath.c_str(),  SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
}
#endif