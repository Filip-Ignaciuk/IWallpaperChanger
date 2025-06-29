#ifdef __APPLE__
#pragma once
#include <osmanager.hpp>

class MACOSManager : public OSManager{
    void ChangeWallpaper(std::filesystem::directory_entry _entry) const override;
};
#endif