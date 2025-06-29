#ifdef _WIN32
#pragma once
#include <osmanager.hpp>

class WinOSManager : public OSManager{
    void ChangeWallpaper(std::filesystem::directory_entry _entry) const override;
};
#endif