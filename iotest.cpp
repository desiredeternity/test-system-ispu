#include "iotest.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>
#include <vector>

#define BUFFER_SIZE 1024

using namespace std;

extern int user_main();

string run_with_input(string input) { // Запуск программы пользователя с определёнными входными данными. Используется перенаправление потоков cin/cout и stdin/stdout
    streambuf* original_cin = cin.rdbuf();
    streambuf* original_cout = cout.rdbuf();

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
    
    stringstream input_buffer;
    stringstream output_buffer;

    cin.rdbuf(input_buffer.rdbuf());
    cout.rdbuf(output_buffer.rdbuf());

    input_buffer << input;

    string result;

    try {
        user_main();

        result = output_buffer.str();

        fflush(temp_output);
        rewind(temp_output);

        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        string c_output;
        
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
    catch (const exception &e) {
        stdin = original_stdin;
        stdout = original_stdout;

        cin.rdbuf(original_cin);
        cout.rdbuf(original_cout);

        fclose(temp_input);
        fclose(temp_output);

        return "Исключение: " + string(e.what());
    }
    catch (...) {
        stdin = original_stdin;
        stdout = original_stdout;

        cin.rdbuf(original_cin);
        cout.rdbuf(original_cout);

        fclose(temp_input);
        fclose(temp_output);
        
        return "Неизвестное исключение";
    }

    stdin = original_stdin;
    stdout = original_stdout;

    cin.rdbuf(original_cout);
    cout.rdbuf(original_cout);

    fclose(temp_input);
    fclose(temp_output);

    if (result.back() == '\n' || result.back() == ' ') {
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

void test_exact(string input, string expected) { // Тестирование на полное сходство ожидаемого и реального вывода программы
    string result = run_with_input(input);

    if (result == expected) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }

}

void test_num_array(string input, string expected) { // Тестирование на наличие необходимых чисел в выводе программы, порядок не важен
    string result = run_with_input(input);
    vector<double> num_result = dfromstr(result);
    vector<double> num_expected = dfromstr(expected);

    sort(num_result.begin(), num_result.end());
    sort(num_expected.begin(), num_expected.end());

    if (num_result == num_expected) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'";
        for (size_t i = 0; i < num_expected.size(); i++) {
            if (i > 0) cout << " ";
            cout << num_expected[i];
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

void test_contains(std::string input, std::string expected) { // Тестирование на наличие определённой подстроки в выводе программы
    string result = run_with_input(input);

    if (result.find(expected) != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}
