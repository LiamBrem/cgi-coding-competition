
#include "grader.h"
#include "test_case.h"

#include <array>
#include <cctype>
#include <cstdio>
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

std::string shell_escape_single_quotes(const std::string& value) {
	std::string escaped;
	for (char ch : value) {
		if (ch == '\'') {
			escaped += "'\"'\"'";
		} else {
			escaped += ch;
		}
	}
	return escaped;
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

} 

void run_q1(const std::string& language) {
	if (language != "python") {
		std::cout << "Only python is supported for now.\n";
		return;
	}

	std::vector<TestCase> tests = {
		{"1 2 3 4 5\n", "15"},
		{"10 20 30\n", "60"},
		{"0 0 0 0\n", "0"}
	};

	int passed = 0;
	for (size_t i = 0; i < tests.size(); ++i) {
		const TestCase& test = tests[i];
		std::string input = shell_escape_single_quotes(test.input);
		std::string command = "printf '" + input + "' | python3 ../questions/q1/solution.py";
		std::string output = trim(run_command(command));

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
