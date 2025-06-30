#include <chrono>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "main.hpp"
#include "osmanagerfactory.hpp"



int Main::run(std::string _platform){

    const char* weekdays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::vector<std::filesystem::directory_entry> selectedImages;
    std::string lastPhoto;
    std::filesystem::directory_entry image;


    // Obtaining the current day
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::sys_days today = std::chrono::floor<std::chrono::days>(now);
    std::chrono::weekday weekday{today};
    int currentDayValue = weekday.c_encoding();
    std::string currentDay = weekdays[currentDayValue];

    const std::filesystem::path currentDirectory = std::filesystem::current_path();
    const std::filesystem::path currentDayDirectory = currentDirectory / weekdays[currentDayValue];
    std::string ending = (std::string)weekdays[currentDayValue] + ".txt";
    const std::filesystem::path TxtPath = currentDayDirectory / ending;


    // Check if files are present and/or creating them
    for (int i = 0; i < 7; i++){
        std::filesystem::path newPath = currentDirectory / weekdays[i];
        std::filesystem::create_directory(newPath);
        std::string ending = (std::string)weekdays[i] + ".txt";
        const std::filesystem::path newTxtPath = newPath / ending;
        if(!std::filesystem::exists(newTxtPath)){
            std::ofstream file(newTxtPath);
            file << "null.null" << std::endl;
            file.close();
        }
    }

    // Obtaining last photo that was displayed on that weekday and the date it was displayed
    std::ifstream readFile(TxtPath);
    std::getline(readFile, lastPhoto);
    readFile.close();

    // Obtaining all photos within the current day
    bool isLastImageReal = false;
    if(std::filesystem::exists(currentDayDirectory) && std::filesystem::is_directory(currentDayDirectory)){
        for(const std::filesystem::directory_entry entry : std::filesystem::directory_iterator(currentDayDirectory)){
            if ((std::string)entry.path().extension().string() == ".jpg" || (std::string)entry.path().extension().string() == ".jpeg" || (std::string)entry.path().extension().string() == ".png"){
                selectedImages.emplace_back(entry);
                if (lastPhoto == entry.path().filename()){
                    isLastImageReal = true;
                }
            }
        }
    }

    if (selectedImages.size() == 0)
    {
        return 0;
    }
    
    

    // Finding next image to display

    if(lastPhoto != "null.null" && isLastImageReal){
        bool next = false;
        for(std::filesystem::directory_entry item : selectedImages){
            if (next)
            {
                image = item;
                break;
            }
            std::string filename = (std::string)item.path().filename().string();
            if (lastPhoto == filename){
                if(selectedImages.back() == item)
                {
                    image = selectedImages[0];
                    break;
                }
                next = true;
            }
        }
    }
    else{
        if(selectedImages.size() != 0)
        {
            image = selectedImages[0];
        }
        lastPhoto = "null.null";
    }

    // Passing image to be displayed
    OSManagerFactory* factory = new OSManagerFactory();
    OSManager* manager = factory->CreateOSManager(_platform);
    manager->ChangeWallpaper(image);

    // Setting last image display as current image
    std::string filename = (std::string)image.path().filename().c_str();
    std::ofstream writeFile(TxtPath);
    writeFile.clear();
    writeFile << filename << std::endl;
    writeFile.close();
    

    return 1;


}
