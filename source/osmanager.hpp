#pragma once
#include <filesystem>

class OSManager{
    public:
        virtual void ChangeWallpaper(std::filesystem::directory_entry _entry) const = 0;
        virtual ~OSManager() = default;

};
