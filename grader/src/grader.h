#ifndef GRADER_H
#define GRADER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "test_case.h"

std::vector<TestCase> get_question_tests(int question_number);

bool run_question(int question_number, const std::string& language);

#endif 