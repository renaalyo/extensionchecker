# extensionchecker
File Mover Project

Overview

This C++ project uses the Boost Filesystem library to monitor a directory for new files with a specific extension (e.g. .exe) and move them to a designated destination directory. If a file with the same name already exists in the destination directory, the project renames the new file to avoid conflicts.

Features

Monitors a specified directory for new files with a specific extension (e.g. .exe)
Moves new files to a designated destination directory
Checks for file name conflicts in the destination directory and renames files if necessary

Requirements

C++ compiler (e.g. GCC)
Boost Filesystem library

Usage

Compile the project using g++ or your preferred C++ compiler.
Run the executable, providing the source directory, destination directory, and file extension as command-line arguments (e.g. ./file_mover /path/to/source /path/to/destination.exe).

The program will monitor the source directory for new files with the specified extension and move them to the destination directory.

Example Use Case
Suppose you want to move all new .exe files from /path/to/source to /path/to/destination. You can run the program like this:

	./file_mover /path/to/source /path/to/destination.exe
		
The program will move any new .exe files from /path/to/source to /path/to/destination, renaming any files that would conflict with existing files in the destination directory.

Notes

This project uses the Boost Filesystem library, which provides a portable way to interact with the file system.
The program assumes that the source and destination directories exist and are writable.
The program does not handle errors that may occur during file operations (e.g. permission errors). You may want to add error handling depending on your specific use case.

I hope this helps! Let me know if you have any questions or need further modifications.
