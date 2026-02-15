#include "iotest.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>
#include <vector>

using namespace std;

extern int user_main();

string run_with_input(string input) { // Запуск программы пользователя с определёнными входными данными
    streambuf* original_cin = cin.rdbuf();
    streambuf* original_cout = cout.rdbuf();
    
    stringstream input_buffer;
    stringstream output_buffer;

    cin.rdbuf(input_buffer.rdbuf());
    cout.rdbuf(output_buffer.rdbuf());

    input_buffer << input;

    try {
        user_main();
    }
    catch (const exception &e) {
        cin.rdbuf(original_cin);
        cout.rdbuf(original_cout);

        return "Исключение: " + string(e.what());
    }
    catch (...) {
        cin.rdbuf(original_cin);
        cout.rdbuf(original_cout);
        
        return "Неизвестное исключение";
    }

    string result = output_buffer.str();

    cin.rdbuf(original_cout);
    cout.rdbuf(original_cout);

    if (result.back() == '\n') {
        result.pop_back();
    }

    return result;
}

vector<double> dfromstr(string str) {
    vector<double> numbers;
    double num;

    stringstream ss(str);

    while (ss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

void test_exact(string input, string expected_output) { // Тестирование на полное сходство ожидаемого и реального вывода программы
    string result = run_with_input(input);

    if (result == expected_output) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected_output << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }

}

void test_num_array(string input, string expected_output) { // Тестирование на наличие необходимых чисел в выводе программы, порядок не важен
    string result = run_with_input(input);
    vector<double> num_result = dfromstr(result);
    vector<double> num_expected_output = dfromstr(expected_output);

    sort(num_result.begin(), num_result.end());
    sort(num_expected_output.begin(), num_expected_output.end());

    if (num_result == num_expected_output) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'";
        for (size_t i = 0; i < num_expected_output.size(); i++) {
            if (i > 0) cout << " ";
            cout << num_expected_output[i];
        }
        cout <<"\', ";
        cout << "получено \'";
        for (size_t i = 0; i < num_result.size(); i++) {
            if (i > 0) cout << " ";
            cout << num_result[i];
        }
        cout <<"\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test_contains(std::string input, std::string expected_output) { // Тестирование на наличие определённой подстроки в выводе программы
    string result = run_with_input(input);

    if (result.find(expected_output) != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected_output << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}
