
#include "grader.h"
#include "test_case.h"

#include <array>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {

std::string trim(const std::string& value) {
	size_t start = 0;
	while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start]))) {
		++start;
	}

	size_t end = value.size();
	while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1]))) {
		--end;
	}

	return value.substr(start, end - start);
}

std::string run_command(const std::string& command) {
	std::array<char, 256> buffer{};
	std::string output;
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe) {
		return "";
	}

	while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe)) {
		output += buffer.data();
	}

	pclose(pipe);
	return output;
}

std::string run_test(const std::string& python_cmd, const std::string& script_path, const std::string& input) {
	// Write input to temporary file
	const std::string temp_file = "temp_input.txt";
	std::ofstream out(temp_file);
	if (!out) {
		return "";
	}
	out << input;
	out.close();

	// Run python with input redirection
	std::string command = python_cmd + " " + script_path + " < " + temp_file;
	std::string output = run_command(command);

	// Clean up temp file
	std::remove(temp_file.c_str());

	return output;
}

} 

void run_q1(const std::string& language) {
	if (language != "python") {
		std::cout << "Only python is supported for now.\n";
		return;
	}

	// Detect Python command (python3 on Unix, python on Windows typically)
	std::string python_cmd = "python3";
	if (run_command("python3 --version 2>&1").empty()) {
		python_cmd = "python";
	}

	std::vector<TestCase> tests = {
		{"1 2 3 4 5\n", "15"},
		{"10 20 30\n", "60"},
		{"0 0 0 0\n", "0"}
	};

	int passed = 0;
	for (size_t i = 0; i < tests.size(); ++i) {
		const TestCase& test = tests[i];
		std::string output = trim(run_test(python_cmd, "../questions/q1/solution.py", test.input));

		if (output == trim(test.expected_output)) {
			++passed;
			std::cout << "Test " << (i + 1) << ": PASS\n";
		} else {
			std::cout << "Test " << (i + 1) << ": FAIL (expected "
					  << test.expected_output << ", got " << output << ")\n";
		}
	}

	std::cout << "Score: " << passed << "/" << tests.size() << "\n";
}
