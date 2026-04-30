#pragma once

#ifndef IOTEST_H
#define IOTEST_H

#include <string>
#include <vector>

constexpr bool IGNORE_ORDER = true;
constexpr bool KEEP_ORDER = false;

constexpr bool REQUIRED = true;
constexpr bool OPTIONAL = false;

std::string utf8(std::string cp1251_str);

std::string cp1251(std::string utf8_str);

std::string run_with_input(std::string input);

std::vector<double> dfromstr(std::string str);

void test_exact(std::string input, const char* expected, bool is_required = true);
void test_exact(std::string input, std::vector<std::string> expected_list, bool is_required = true);

void test_num_array(std::string input, const char* expected, bool ignore_order = true, bool is_required = true);
void test_num_array(std::string input, std::vector<std::string> expected_list, bool ignore_order = true, bool is_required = true);

void test_contains(std::string input, const char* expected, bool is_required = true);
void test_contains(std::string input, std::vector<std::string> expected_list, bool is_required = true);

#endif
