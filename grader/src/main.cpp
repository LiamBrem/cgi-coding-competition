#include <iostream>
#include <string>

#include "grader.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Usage: ./grader --question <number> --lang <python|java>\n";
        return 1;
    }

    int question_number = -1;
    std::string language;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--question" && i + 1 < argc) {
            question_number = std::stoi(argv[++i]);
        } else if (arg == "--lang" && i + 1 < argc) {
            language = argv[++i];
        } else {
            std::cout << "Usage: ./grader --question <number> --lang <python|java>\n";
            return 1;
        }
    }

    if (question_number < 0 || language.empty()) {
        std::cout << "Usage: ./grader --question <number> --lang <python|java>\n";
        return 1;
    }

    if (question_number == 1) {
        run_q1(language);
    } else {
        std::cout << "not implemented yet\n";
    }

    return 0;
}