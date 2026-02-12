#include "grader.h"
#include "test_case.h"

#include <array>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {

// remove whitespace from string
std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) {
        ++start;
    }

    size_t end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
        --end;
    }

    return str.substr(start, end - start);
}

// run shell command & return output
std::string run_command(const std::string& command) {
    std::array<char, 256> buffer;
    std::string output;
    
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "";
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        output += buffer.data();
    }

    pclose(pipe);
    return output;
}

// try different python commands
std::string detect_python() {
    if (!run_command("python3 --version 2>&1").empty()) {
        return "python3";
    }
    
    if (!run_command("python --version 2>&1").empty()) {
        return "python";
    }

    if (!run_command("py --version 2>&1").empty()) {
        return "py";
    }
    
    return "";
}

// run test case - pipe input to python script
std::string run_test(const std::string& python_cmd, const std::string& script_path, const std::string& input) {
    const std::string temp_file = "temp_input.txt";
    
    FILE* temp = fopen(temp_file.c_str(), "w");
    if (!temp) {
        std::cerr << "Error: Could not create temporary input file\n";
        return "";
    }
    fputs(input.c_str(), temp);
    fclose(temp);

    std::string command = "cat " + temp_file + " | " + python_cmd + " " + script_path + " 2>&1";

    std::string output = run_command(command);

    std::remove(temp_file.c_str());

    return output;
}

} 

// TEST CASES FOR EACH QUESTIONS GO HERE
std::vector<TestCase> get_question_tests(int question_number) {
    switch (question_number) {
        case 1: {
            return {
                {"1 2 3 4 5\n", "15"},
                {"10 20 30\n", "60"},
                {"0 0 0 0\n", "0"},
                {"5\n", "5"},
                {"-1 1\n", "0"}
            };
        }
        case 2: {
            return {};
        }
        case 3: {
            return {};
        }
        case 4: {
            return {};
        }
        case 5: {
            return {};
        }
        case 6: {
            return {};
        }
        case 7: {
            return {};
        }
        case 8: {
            return {};
        }
        case 9: {
            return {};
        }
        case 10: {
            return {};
        }
        default:
            return {};
    }
}

bool run_question(int question_number, const std::string& language) {
    if (question_number < 1 || question_number > 10) {
        std::cerr << "Error: Question number must be between 1 and 10\n";
        return false;
    }
    
    std::string solution_file;
    std::string runtime_cmd;
    
    if (language == "python") {
        std::ostringstream path;
        path << "../questions/q" << question_number << "/solution.py";
        solution_file = path.str();
        
        runtime_cmd = detect_python();
        if (runtime_cmd.empty()) {
            std::cerr << "Error: Python not found. Please install Python and add it to PATH.\n";
            return false;
        }
    } else if (language == "java") {
        std::cerr << "Error: Java support not yet implemented.\n";
        return false;
    } else {
        std::cerr << "Error: Unsupported language: " << language << "\n";
        return false;
    }
    
    std::vector<TestCase> tests = get_question_tests(question_number);
    if (tests.empty()) {
        std::cerr << "Error: No test cases defined for question " << question_number << "\n";
        return false;
    }
    

    std::cout << "\nQuestion " << question_number << " (" << language << ")\n";
    std::cout << "==============================\n\n";
    
    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        const TestCase& test = tests[i];
        std::string output = trim(run_test(runtime_cmd, solution_file, test.input));
        std::string expected = trim(test.expected_output);
        
        if (output == expected) {
            ++passed;
            std::cout << "Test " << (i + 1) << ": PASS\n";
        } else {
            std::cout << "Test " << (i + 1) << ": FAIL (expected "
                      << expected << ", got " << output << ")\n";
        }
    }
    
    std::cout << "\nScore: " << passed << "/" << tests.size() << "\n";
    return true;
}
