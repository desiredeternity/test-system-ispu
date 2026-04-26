#include "iotest.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>
#include <vector>
#include <map>

#define BUFFER_SIZE 1024

extern int user_main();

std::string utf8(std::string cp1251_str) { // Конвертация Windows1251 в UTF8
    std::map<unsigned char, char*> cp1251_map = {
        {0xC0, "А"}, {0xC1, "Б"}, {0xC2, "В"}, {0xC3, "Г"}, {0xC4, "Д"},
        {0xC5, "Е"}, {0xC6, "Ж"}, {0xC7, "З"}, {0xC8, "И"}, {0xC9, "Й"},
        {0xCA, "К"}, {0xCB, "Л"}, {0xCC, "М"}, {0xCD, "Н"}, {0xCE, "О"},
        {0xCF, "П"}, {0xD0, "Р"}, {0xD1, "С"}, {0xD2, "Т"}, {0xD3, "У"},
        {0xD4, "Ф"}, {0xD5, "Х"}, {0xD6, "Ц"}, {0xD7, "Ч"}, {0xD8, "Ш"},
        {0xD9, "Щ"}, {0xDA, "Ъ"}, {0xDB, "Ы"}, {0xDC, "Ь"}, {0xDD, "Э"},
        {0xDE, "Ю"}, {0xDF, "Я"}, {0xE0, "а"}, {0xE1, "б"}, {0xE2, "в"},
        {0xE3, "г"}, {0xE4, "д"}, {0xE5, "е"}, {0xE6, "ж"}, {0xE7, "з"},
        {0xE8, "и"}, {0xE9, "й"}, {0xEA, "к"}, {0xEB, "л"}, {0xEC, "м"},
        {0xED, "н"}, {0xEE, "о"}, {0xEF, "п"}, {0xF0, "р"}, {0xF1, "с"},
        {0xF2, "т"}, {0xF3, "у"}, {0xF4, "ф"}, {0xF5, "х"}, {0xF6, "ц"},
        {0xF7, "ч"}, {0xF8, "ш"}, {0xF9, "щ"}, {0xFA, "ъ"}, {0xFB, "ы"},
        {0xFC, "ь"}, {0xFD, "э"}, {0xFE, "ю"}, {0xFF, "я"},
        {0xA8, "Ё"}, {0xB8, "ё"}
    };

    std::string utf8_result;
    utf8_result.reserve(cp1251_str.size() * 2);

    for (size_t i = 0; i < cp1251_str.length(); i++) {
        unsigned char ch = cp1251_str[i];

        if (ch < 0x80) {
            utf8_result += ch;
        }
        else {
            auto c = cp1251_map.find(ch);
            if (c != cp1251_map.end()) {
                utf8_result += c->second;
            }
            else {
                utf8_result += '?';
            }
        }
    }

    return utf8_result;
}

std::string cp1251(std::string utf8_str) { // Конвертация UTF8 в Windows1251
    std::map<std::string, unsigned char> utf8_map = {
        {"\xD0\x90", 0xC0}, // А
        {"\xD0\x91", 0xC1}, // Б
        {"\xD0\x92", 0xC2}, // В
        {"\xD0\x93", 0xC3}, // Г
        {"\xD0\x94", 0xC4}, // Д
        {"\xD0\x95", 0xC5}, // Е
        {"\xD0\x96", 0xC6}, // Ж
        {"\xD0\x97", 0xC7}, // З
        {"\xD0\x98", 0xC8}, // И
        {"\xD0\x99", 0xC9}, // Й
        {"\xD0\x9A", 0xCA}, // К
        {"\xD0\x9B", 0xCB}, // Л
        {"\xD0\x9C", 0xCC}, // М
        {"\xD0\x9D", 0xCD}, // Н
        {"\xD0\x9E", 0xCE}, // О
        {"\xD0\x9F", 0xCF}, // П
        {"\xD0\xA0", 0xD0}, // Р
        {"\xD0\xA1", 0xD1}, // С
        {"\xD0\xA2", 0xD2}, // Т
        {"\xD0\xA3", 0xD3}, // У
        {"\xD0\xA4", 0xD4}, // Ф
        {"\xD0\xA5", 0xD5}, // Х
        {"\xD0\xA6", 0xD6}, // Ц
        {"\xD0\xA7", 0xD7}, // Ч
        {"\xD0\xA8", 0xD8}, // Ш
        {"\xD0\xA9", 0xD9}, // Щ
        {"\xD0\xAA", 0xDA}, // Ъ
        {"\xD0\xAB", 0xDB}, // Ы
        {"\xD0\xAC", 0xDC}, // Ь
        {"\xD0\xAD", 0xDD}, // Э
        {"\xD0\xAE", 0xDE}, // Ю
        {"\xD0\xAF", 0xDF}, // Я
        
        {"\xD0\xB0", 0xE0}, // а
        {"\xD0\xB1", 0xE1}, // б
        {"\xD0\xB2", 0xE2}, // в
        {"\xD0\xB3", 0xE3}, // г
        {"\xD0\xB4", 0xE4}, // д
        {"\xD0\xB5", 0xE5}, // е
        {"\xD0\xB6", 0xE6}, // ж
        {"\xD0\xB7", 0xE7}, // з
        {"\xD0\xB8", 0xE8}, // и
        {"\xD0\xB9", 0xE9}, // й
        {"\xD0\xBA", 0xEA}, // к
        {"\xD0\xBB", 0xEB}, // л
        {"\xD0\xBC", 0xEC}, // м
        {"\xD0\xBD", 0xED}, // н
        {"\xD0\xBE", 0xEE}, // о
        {"\xD0\xBF", 0xEF}, // п
        {"\xD1\x80", 0xF0}, // р
        {"\xD1\x81", 0xF1}, // с
        {"\xD1\x82", 0xF2}, // т
        {"\xD1\x83", 0xF3}, // у
        {"\xD1\x84", 0xF4}, // ф
        {"\xD1\x85", 0xF5}, // х
        {"\xD1\x86", 0xF6}, // ц
        {"\xD1\x87", 0xF7}, // ч
        {"\xD1\x88", 0xF8}, // ш
        {"\xD1\x89", 0xF9}, // щ
        {"\xD1\x8A", 0xFA}, // ъ
        {"\xD1\x8B", 0xFB}, // ы
        {"\xD1\x8C", 0xFC}, // ь
        {"\xD1\x8D", 0xFD}, // э
        {"\xD1\x8E", 0xFE}, // ю
        {"\xD1\x8F", 0xFF}, // я
        
        {"\xD0\x81", 0xA8}, // Ё
        {"\xD1\x91", 0xB8}  // ё
    };

    std::string cp1251_result;
    cp1251_result.reserve(utf8_str.length());

    for (size_t i = 0; i < utf8_str.length(); ) {
        unsigned char ch = utf8_str[i];

        if (ch < 0x80) {
            cp1251_result += ch;
            i++;
            continue;
        }

        if (i + 1 < utf8_str.length() && (ch == 0xD0 || ch == 0xD1)) {
            std::string utf8_char = utf8_str.substr(i, 2);
            auto c = utf8_map.find(utf8_char);
            
            if (c != utf8_map.end()) {
                cp1251_result += c->second;
            } else {
                cp1251_result += '?';
            }
            i += 2;
        } else {
            cp1251_result += '?';
            i++;
        }
    }

    return cp1251_result;
}

std::string run_with_input(std::string input) { // Запуск программы пользователя с определёнными входными данными. Используется перенаправление потоков cin/cout и stdin/stdout
    std::streambuf* original_cin = std::cin.rdbuf();
    std::streambuf* original_cout = std::cout.rdbuf();

    FILE* original_stdin = stdin;
    FILE* original_stdout = stdout;

    FILE* temp_input = tmpfile();
    FILE* temp_output = tmpfile();
    
    if (!temp_input || !temp_output) {
        if (temp_input) fclose(temp_input);
        if (temp_output) fclose(temp_output);
        return "Ошибка создания временных файлов";
    }

    std::string input_cp1251 = cp1251(input);
    fwrite(input_cp1251.c_str(), 1, input_cp1251.size(), temp_input);
    rewind(temp_input);

    stdin = temp_input;
    stdout = temp_output;
    
    std::stringstream input_buffer;
    std::stringstream output_buffer;

    std::cin.rdbuf(input_buffer.rdbuf());
    std::cout.rdbuf(output_buffer.rdbuf());

    input_buffer << input_cp1251;

    std::string result;

    try {
        user_main();

        result = output_buffer.str();

        fflush(temp_output);
        rewind(temp_output);

        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        std::string c_output;
        
        while ((bytes_read = fread(buffer, 1, sizeof(buffer) - 1, temp_output)) > 0) {
            buffer[bytes_read] = '\0';
            c_output += buffer;
        }

        if (!c_output.empty()) {
            if (result.empty()) {
                result = c_output;
            } else {
                result = c_output + result;
            }
        }
    }
    catch (const std::exception &e) {
        stdin = original_stdin;
        stdout = original_stdout;

        std::cin.rdbuf(original_cin);
        std::cout.rdbuf(original_cout);

        fclose(temp_input);
        fclose(temp_output);

        return "Исключение: " + std::string(e.what());
    }
    catch (...) {
        stdin = original_stdin;
        stdout = original_stdout;

        std::cin.rdbuf(original_cin);
        std::cout.rdbuf(original_cout);

        fclose(temp_input);
        fclose(temp_output);
        
        return "Неизвестное исключение";
    }

    stdin = original_stdin;
    stdout = original_stdout;

    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);

    fclose(temp_input);
    fclose(temp_output);

    if (!result.empty()) {
        result = utf8(result);
        
        std::replace(result.begin(), result.end(), '\n', ' ');
        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
    }

    return result;
}

std::vector<double> dfromstr(std::string str) { // Парсинг чисел double из string
    std::vector<double> numbers;
    std::string current_num;
    
    for (char ch : str) {
        if (std::isdigit(ch) || ch == '.' || ch == '-' || ch == '+') {
            current_num += ch;
        } else if (!current_num.empty()) {
            char* end;
            double num = std::strtod(current_num.c_str(), &end);
            if (end != current_num.c_str()) {
                numbers.push_back(num);
            }
            current_num.clear();
        }
    }
    
    if (!current_num.empty()) {
        char* end;
        double num = std::strtod(current_num.c_str(), &end);
        if (end != current_num.c_str()) {
            numbers.push_back(num);
        }
    }
    
    return numbers;
}

void test_exact(std::string input, const char* expected) { // Тестирование на полное сходство ожидаемого и реального вывода программы
    std::string result = run_with_input(input);

    if (result == expected) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_exact(std::string input, std::vector<std::string> expected_list) { // Тестирование на полное сходство ожидаемого и реального вывода программы, несколько возможных вариантов
    std::string result = run_with_input(input);
    
    bool passed = false;
    for (size_t i = 0; i < expected_list.size(); i++) {
        if (result == expected_list[i]) {
            passed = true;
            break;
        }
    }

    if (passed) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось одно из: ";
        for (size_t i = 0; i < expected_list.size(); i++) {
            if (i > 0) std::cout << " или ";
            std::cout << "\'" << expected_list[i] << "\'";
        }
        std::cout << ", получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_num_array(std::string input, const char* expected, bool ignore_order) { // Тестирование на наличие необходимых чисел в выводе программы, сохранение порядка может быть выбрано
    std::string result = run_with_input(input);
    std::vector<double> num_result = dfromstr(result);
    std::vector<double> num_expected = dfromstr(expected);

    if (ignore_order) {
        std::sort(num_result.begin(), num_result.end());
        std::sort(num_expected.begin(), num_expected.end());
    }

    if (num_result == num_expected) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_num_array(std::string input, std::vector<std::string> expected_list, bool ignore_order) { // Тестирование на наличие необходимых чисел в выводе программы, сохранение порядка может быть выбрано, несколько возможных вариантов
    std::string result = run_with_input(input);
    std::vector<double> num_result = dfromstr(result);

    if (ignore_order) {
        std::sort(num_result.begin(), num_result.end());
    }
    
    std::vector<std::vector<double>> num_expected;
    for (size_t i = 0; i < expected_list.size(); i++) {
        std::vector<double> parsed_expected = dfromstr(expected_list[i]);
        if (ignore_order) {
            std::sort(parsed_expected.begin(), parsed_expected.end());
        }
        num_expected.push_back(parsed_expected);
    }

    bool passed = false;
    for (size_t i = 0; i < num_expected.size(); i++) {        
        if (num_result == num_expected[i]) {
            passed = true;
            break;
        }
    }
    
    if (passed) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось одно из: ";
        for (size_t i = 0; i < expected_list.size(); i++) {
            if (i > 0) std::cout << " или ";
            std::cout << "\'";
            std::cout << expected_list[i];
            std::cout << "\'";
        }
        std::cout << ", получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_contains(std::string input, const char* expected) { // Тестирование на наличие определённой подстроки в выводе программы
    std::string result = run_with_input(input);

    if (result.find(expected) != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_contains(std::string input, std::vector<std::string> expected_list) { // Тестирование на наличие хотя бы одной из подстрок в выводе программы
    std::string result = run_with_input(input);
    
    bool passed = false;
    
    for (size_t i = 0; i < expected_list.size(); i++) {
        if (result.find(expected_list[i]) != std::string::npos) {
            passed = true;
            break;
        }
    }
    
    if (passed) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалась одно из: ";
        for (size_t i = 0; i < expected_list.size(); i++) {
            if (i > 0) std::cout << " или ";
            std::cout << "\'" << expected_list[i] << "\'";
        }
        std::cout << ", получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}
