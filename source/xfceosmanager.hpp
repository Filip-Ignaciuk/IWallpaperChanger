#ifdef __linux__
#pragma once
#include <osmanager.hpp>

class XFCEOSManager : public OSManager{
    void ChangeWallpaper(std::filesystem::directory_entry _entry) const override;
};

#endif