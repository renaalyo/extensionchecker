#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
    fs::path folderPath("C:/Users/azathd/Downloads");
    std::string extension(".rbxl");
    fs::path destinationPath("C:/Users/azathd/Documents/ROBLOX");

    /*if (argc == 3 && argc != 1) {
        std::string argfolderPath = argv[1];
        std::string argdestinationPath = argv[2];
        std::string extension = argv[3];

        folderPath = argfolderPath;
        destinationPath = argdestinationPath;
    }*/
    setlocale(LC_ALL, "Russian");

    if (!fs::exists(folderPath)) {
        std::cerr << "Folder doesn`t exist" << "\n";
        return -1;
    }

    if (!fs::exists(destinationPath)) {
        std::cerr << "Destination folder doesn`t exist" << "\n";
        return -1;
    }

    fs::directory_iterator it = fs::directory_iterator(folderPath);
    fs::directory_iterator end = fs::directory_iterator();
    fs::path lastFile;

    time_t lastModTime = 0;
    //finding last modified file by time
    while (it != end) {
        if (fs::is_regular_file(*it)) {
            time_t ModTime = fs::last_write_time(*it);
            if (ModTime > lastModTime) {
                lastModTime = ModTime;
                lastFile = *it;
            }
        }
        it++;
    }
    if (!lastFile.empty() && lastFile.extension() == extension) {
        fs::path newFilePath = destinationPath / lastFile.filename();
        if (fs::exists(newFilePath)) {
            newFilePath.replace_filename("copy of " + lastFile.filename().string());
        }
        fs::rename(lastFile, newFilePath);

        std::cout << "File SUCCESSFULLY moved " << lastFile.filename() << " to " << destinationPath << "\n";
    }
    else {
        std::cout << "File " << lastFile.filename() << " doesn`t have this extension " << extension << "\n";
    }
    return 0;

}
