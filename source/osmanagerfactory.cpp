#include "osmanagerfactory.hpp"
#include "osmanager.hpp"
#include "winosmanager.hpp"
#include "gnomeosmanager.hpp"
#include "kdeosmanager.hpp"
#include "xfceosmanager.hpp"
#include "macosmanager.hpp"

OSManager* OSManagerFactory::CreateOSManager(std::string type){
    
    #ifdef _WIN32
    if (type == "WINDOWS"){
        return new WinOSManager();
    }
    #endif

    #ifdef __linux__
    if (type == "GNOME"){
        return new GnomeOSManager();
    }
    else if (type == "KDE"){
        return new KDEOSManager();
    }
    else if (type == "XFCE"){
        return new XFCEOSManager();
    }
    else if (type == "FEH")
    {

    }
    #endif

    #ifdef __APPLE__
    if (type == "MACOS"){
        return new MACOSManager();
    }
    #endif

    return nullptr;
}