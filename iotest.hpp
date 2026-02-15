#ifndef IOTEST_H
#define IOTEST_H

#include <string>
#include <vector>

std::string run_with_input(std::string input);

std::vector<double> dfromstr(std::string string);

void test_exact(std::string input, std::string expected_output);

void test_num_array(std::string input, std::string expected_output);

void test_contains(std::string input, std::string expected_output);

#endif
