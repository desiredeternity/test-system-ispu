#pragma once

#ifndef IOTEST_H
#define IOTEST_H

#include <string>
#include <vector>

std::string utf8(std::string cp1251_str);

std::string cp1251(std::string utf8_str);

std::string run_with_input(std::string input);

std::vector<double> dfromstr(std::string str);

void test_exact(std::string input, std::string expected);

void test_num_array(std::string input, std::string expected);

void test_contains(std::string input, std::string expected);

#endif
