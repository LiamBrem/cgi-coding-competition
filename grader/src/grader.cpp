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

namespace
{

    // remove whitespace from string
    std::string trim(const std::string &str)
    {
        size_t start = 0;
        while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
        {
            ++start;
        }

        size_t end = str.size();
        while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        {
            --end;
        }

        return str.substr(start, end - start);
    }

    // run shell command & return output
    std::string run_command(const std::string &command)
    {
        std::array<char, 256> buffer;
        std::string output;

        FILE *pipe = popen(command.c_str(), "r");
        if (!pipe)
        {
            return "";
        }

        while (fgets(buffer.data(), buffer.size(), pipe) != nullptr)
        {
            output += buffer.data();
        }

        pclose(pipe);
        return output;
    }

    // try different python commands
    std::string detect_python()
    {
        if (!run_command("python3 --version 2>&1").empty())
        {
            return "python3";
        }

        if (!run_command("python --version 2>&1").empty())
        {
            return "python";
        }

        if (!run_command("py --version 2>&1").empty())
        {
            return "py";
        }

        return "";
    }

    // check if java is available
    bool detect_java()
    {
        return !run_command("javac -version 2>&1").empty() && 
               !run_command("java -version 2>&1").empty();
    }

    // compile java file
    bool compile_java(const std::string &java_file)
    {
        std::string compile_cmd = "javac " + java_file + " 2>&1";
        std::string output = run_command(compile_cmd);
        
        // If output contains "error", compilation failed
        if (output.find("error") != std::string::npos || 
            output.find("Error") != std::string::npos)
        {
            std::cerr << "Compilation error:\n" << output << "\n";
            return false;
        }
        
        return true;
    }

    // run test case - pipe input to python script
    std::string run_test_python(const std::string &python_cmd, const std::string &script_path, const std::string &input)
    {
        const std::string temp_file = "temp_input.txt";

        FILE *temp = fopen(temp_file.c_str(), "w");
        if (!temp)
        {
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

    // run test case - pipe input to java program
    std::string run_test_java(const std::string &class_name, const std::string &input)
    {
        const std::string temp_file = "temp_input.txt";

        FILE *temp = fopen(temp_file.c_str(), "w");
        if (!temp)
        {
            std::cerr << "Error: Could not create temporary input file\n";
            return "";
        }
        fputs(input.c_str(), temp);
        fclose(temp);

        // Run with classpath pointing to questions directory
        std::string command = "cat " + temp_file + " | java -cp ../questions " + class_name + " 2>&1";

        std::string output = run_command(command);

        std::remove(temp_file.c_str());

        return output;
    }

}

bool run_question(int question_number, const std::string &language)
{
    if (question_number < 1 || question_number > 10)
    {
        std::cerr << "Error: Question number must be between 1 and 10\n";
        return false;
    }

    std::string solution_file;
    std::string runtime_cmd;
    std::string class_name;

    if (language == "python")
    {
        std::ostringstream path;
        path << "../questions/q" << question_number << "/solution.py";
        solution_file = path.str();

        runtime_cmd = detect_python();
        if (runtime_cmd.empty())
        {
            std::cerr << "Error: Python not found. Please install Python and add it to PATH.\n";
            return false;
        }
    }
    else if (language == "java")
    {
        if (!detect_java())
        {
            std::cerr << "Error: Java not found. Please install JDK and add javac/java to PATH.\n";
            return false;
        }

        std::ostringstream path;
        path << "../questions/q" << question_number << "/Solution.java";
        solution_file = path.str();

        // Compile the Java file
        std::cout << "Compiling Java solution...\n";
        if (!compile_java(solution_file))
        {
            std::cerr << "Error: Compilation failed for " << solution_file << "\n";
            return false;
        }
        std::cout << "Compilation successful!\n\n";

        // Class name is q<number>.Solution
        std::ostringstream cn;
        cn << "q" << question_number << ".Solution";
        class_name = cn.str();
    }
    else
    {
        std::cerr << "Error: Unsupported language: " << language << "\n";
        return false;
    }

    std::vector<TestCase> tests = get_question_tests(question_number);
    if (tests.empty())
    {
        std::cerr << "Error: No test cases defined for question " << question_number << "\n";
        return false;
    }

    std::cout << "Question " << question_number << " (" << language << ")\n";
    std::cout << "==============================\n\n";

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i)
    {
        const TestCase &test = tests[i];
        std::string output;
        
        if (language == "python")
        {
            output = trim(run_test_python(runtime_cmd, solution_file, test.input));
        }
        else if (language == "java")
        {
            output = trim(run_test_java(class_name, test.input));
        }
        
        std::string expected = trim(test.expected_output);

        if (output == expected)
        {
            ++passed;
            std::cout << "Test " << (i + 1) << ": PASS\n";
        }
        else
        {
            std::cout << "Test " << (i + 1) << ": FAIL (expected "
                      << expected << ", got " << output << ")\n";
        }
    }

    std::cout << "\nScore: " << passed << "/" << tests.size() << "\n";
    return true;
}
