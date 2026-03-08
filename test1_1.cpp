#include "iotest.hpp"
#include <iostream>

using namespace std;

void test1(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("���") != string::npos && result.find("����") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

void test2(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("���") != string::npos && result.find("���") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

void test3(string input, string expected) {
    string result = run_with_input(input);

    if ((result.find("���") != string::npos || result.find("��") != string::npos)
      && result.find("����") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

void test4(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("���") != string::npos && result.find("����") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

void test5(string input, string expected) {
    string result = run_with_input(input);

    if ((result.find("���") != string::npos || result.find("���") != string::npos)
      && result.find("����") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

void test6(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("���") != string::npos && result.find("����") != string::npos) {
        cout << "����: " << "�������\n";
    }
    else {
        cout << "����: " << "������: ";
        cout << "��������� \'" << expected << "\', ";
        cout << "�������� \'" << result << "\', ";
        cout << "������� \'" << input << "\'\n";
    }
}

int main() {
    test1("1984", "��� ������� �����");
    test2("1785", "��� ����� ����");
    test3("1996", "��� ������ �����");
    test4("1995", "��� ������� ������");
    test5("0",    "��� ������ ��������");
    test6("2044", "��� ������� �����");
    test_contains("-1",   "������");

    return 0;
}
