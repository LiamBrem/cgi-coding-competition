#include <iostream>
#include <string>
#include <cstdlib>

#include "grader.h"

void print_usage() {
    std::cout << "Usage: ./grader --question <number> --lang <python|java>\n";
    std::cout << "\nOptions:\n";
    std::cout << "  --question <number>  Question number (1-10)\n";
    std::cout << "  --lang <language>    Programming language (python or java)\n";
    std::cout << "\nExample:\n";
    std::cout << "  ./grader --question 1 --lang python\n";
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        print_usage();
        return 1;
    }

    int question_number = -1;
    std::string language;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--question" && i + 1 < argc) {
            try {
                question_number = std::stoi(argv[++i]);
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid question number\n";
                return 1;
            }
        } else if (arg == "--lang" && i + 1 < argc) {
            language = argv[++i];
        } else if (arg == "--help" || arg == "-h") {
            print_usage();
            return 0;
        } else {
            std::cerr << "Error: Unknown argument: " << arg << "\n\n";
            print_usage();
            return 1;
        }
    }

    // Validate arguments
    if (question_number < 0 || language.empty()) {
        std::cerr << "Error: Missing required arguments\n\n";
        print_usage();
        return 1;
    }

    if (question_number < 1 || question_number > 10) {
        std::cerr << "Error: Question number must be between 1 and 10\n";
        return 1;
    }

    // Route to appropriate question handler
    switch (question_number) {
        case 1:
            run_q1(language);
            break;
        default:
            std::cerr << "Error: Question " << question_number << " not implemented yet\n";
            return 1;
    }

    return 0;
}