#ifdef __linux__
#pragma once
#include <osmanager.hpp>

class KDEOSManager : public OSManager{
    public:
        KDEOSManager();
        void ChangeWallpaper(std::filesystem::directory_entry _entry) const override;
};

#endif