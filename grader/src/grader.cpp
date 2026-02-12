#include "grader.h"
#include "test_case.h"

#include <array>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {

// Trim whitespace from both ends of a string
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

// Execute a shell command and capture its output
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

// Detect available Python command (python3, python, or py)
std::string detect_python() {
    // Try python3 first (Linux/macOS standard)
    if (!run_command("python3 --version 2>&1").empty()) {
        return "python3";
    }
    
    // Try python (common alias)
    if (!run_command("python --version 2>&1").empty()) {
        return "python";
    }
    
    // Try py (Windows launcher)
    if (!run_command("py --version 2>&1").empty()) {
        return "py";
    }
    
    return ""; // Not found
}

// Run a test case by piping input to Python script
std::string run_test(const std::string& python_cmd, const std::string& script_path, const std::string& input) {
    const std::string temp_file = "temp_input.txt";
    
    // Write input to temporary file
    {
        std::ofstream out(temp_file);
        if (!out) {
            std::cerr << "Error: Could not create temporary input file\n";
            return "";
        }
        out << input;
    } // File automatically closed here

    // Build command based on platform
    std::string command;
#ifdef _WIN32
    command = "type " + temp_file + " | " + python_cmd + " " + script_path + " 2>&1";
#else
    command = "cat " + temp_file + " | " + python_cmd + " " + script_path + " 2>&1";
#endif

    std::string output = run_command(command);

    // Clean up temporary file
    std::remove(temp_file.c_str());

    return output;
}

} // anonymous namespace 

void run_q1(const std::string& language) {
    if (language != "python") {
        std::cout << "Error: Only Python is supported for question 1.\n";
        return;
    }

    // Detect Python command
    std::string python_cmd = detect_python();
    if (python_cmd.empty()) {
        std::cerr << "Error: Python not found. Please install Python and add it to PATH.\n";
        return;
    }

    // Define test cases
    const std::vector<TestCase> tests = {
        {"1 2 3 4 5\n", "15"},
        {"10 20 30\n", "60"},
        {"0 0 0 0\n", "0"},
        {"5\n", "5"},
        {"-1 1\n", "0"}
    };

    std::cout << "\nQuestion 1 - Array Sum\n";
    std::cout << "======================\n\n";

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        const TestCase& test = tests[i];
        std::string output = trim(run_test(python_cmd, "../questions/q1/solution.py", test.input));
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
}
