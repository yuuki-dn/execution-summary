#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: run.exe <command>" << std::endl;
        return 1;
    }

    // Concatenate all the arguments into one string to form the command
    std::string command;
    for (int i = 1; i < argc; i++) {
        command += argv[i];
        if (i < argc - 1) {
            command += " ";
        }
    }

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Execute the command
    int result = std::system(command.c_str());

    // Stop the timer
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << std::endl << "====================================" << std::endl;

    // If exit code = 0 print green color, red if exit code < 256, else print yellow color
    if (result == 0) std::cout << "\033[1;32m"; 
    else if (result < 256) std::cout << "\033[1;31m";
    else std::cout << "\033[1;33m";

    std::cout << "Exit code: " << result;
    std::cout << "\033[0m" << " | ";

    // Print the time taken
    std::cout.precision(3);
    std::cout << "\033[1;36m" << "Time taken: " << std::fixed << 1.0 * duration.count() / 1000000.0 << "s" << "\033[0m";
    
    std::cout << std::endl << "====================================" << std::endl;

    return 0;
}
