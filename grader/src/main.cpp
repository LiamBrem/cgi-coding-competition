#include <iostream>
#include <string>
#include <cstdlib>

#include "grader.h"

void print_usage() {
    std::cout << "Usage: ./grader --question <number> --lang <python|java>\n";
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

    // Run the question
    if (!run_question(question_number, language)) {
        return 1;
    }

    return 0;
}