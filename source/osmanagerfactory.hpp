#pragma once
#include "osmanager.hpp"
#include <string>

class OSManagerFactory{
    public:
    static OSManager* CreateOSManager(std::string type);
};