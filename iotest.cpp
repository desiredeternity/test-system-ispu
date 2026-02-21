#include "iotest.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>
#include <vector>

#define BUFFER_SIZE 1024

extern int user_main();

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

    fwrite(input.c_str(), 1, input.size(), temp_input);
    rewind(temp_input);

    stdin = temp_input;
    stdout = temp_output;
    
    std::stringstream input_buffer;
    std::stringstream output_buffer;

    std::cin.rdbuf(input_buffer.rdbuf());
    std::cout.rdbuf(output_buffer.rdbuf());

    input_buffer << input;

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

    std::cin.rdbuf(original_cout);
    std::cout.rdbuf(original_cout);

    fclose(temp_input);
    fclose(temp_output);

    if (result.back() == '\n' || result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

std::vector<double> dfromstr(std::string str) {
    std::vector<double> numbers;
    double num;

    std::stringstream ss(str);

    while (ss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

void test_exact(std::string input, std::string expected) { // Тестирование на полное сходство ожидаемого и реального вывода программы
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

void test_num_array(std::string input, std::string expected) { // Тестирование на наличие необходимых чисел в выводе программы, порядок не важен
    std::string result = run_with_input(input);
    std::vector<double> num_result = dfromstr(result);
    std::vector<double> num_expected = dfromstr(expected);

    std::sort(num_result.begin(), num_result.end());
    std::sort(num_expected.begin(), num_expected.end());

    if (num_result == num_expected) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'";
        for (size_t i = 0; i < num_expected.size(); i++) {
            if (i > 0) std::cout << " ";
            std::cout << num_expected[i];
        }
        std::cout <<"\', ";
        std::cout << "получено \'";
        for (size_t i = 0; i < num_result.size(); i++) {
            if (i > 0) std::cout << " ";
            std::cout << num_result[i];
        }
        std::cout <<"\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test_contains(std::string input, std::string expected) { // Тестирование на наличие определённой подстроки в выводе программы
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