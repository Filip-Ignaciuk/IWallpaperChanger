#ifdef __linux__
#pragma once
#include <osmanager.hpp>

class GnomeOSManager : public OSManager{
    void ChangeWallpaper(std::filesystem::directory_entry _entry) const override;
};

#endif