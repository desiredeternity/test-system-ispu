CXX = g++
CXXFLAGS = -w -std=c++11
INCLUDES = -I/root/test/

# Правило по умолчанию
all: help

# Справка
help:
	@echo "Доступные цели:"
	@echo "  make testX_X  - скомпилировать и запустить тест (X_X - номер задачи, например, test1_3, test2_5)"
	@echo "  make user     - скомпилировать и запустить пользовательский код"
	@echo "  make clean    - удалить объектные файлы и исполняемые файлы"

# Сценарий 1: компиляция с тестированием
test%: msvc_compat.o Windows.o user_code.o iotest.o test%.o
	$(CXX) $^ -o tester.out
	@echo "Запуск теста $*..."
	./tester.out

# Компиляция тестового файла с конкретным номером
test%.o: test%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Сценарий 2: отдельная компиляция пользовательского кода
user: user_code.cpp msvc_compat.o Windows.o
	$(CXX) $(INCLUDES) -include msvc_compat.hpp -include common_headers.hpp $(CXXFLAGS) user_code.cpp msvc_compat.o Windows.o -o user_code.out
	@echo "Запуск пользовательского кода..."
	./user_code.out

# Компиляция объектных файлов
msvc_compat.o: msvc_compat.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

Windows.o: Windows.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

user_code.o: user_code.cpp
	$(CXX) $(INCLUDES) -Dmain=user_main -include msvc_compat.hpp -include common_headers.hpp $(CXXFLAGS) -c $< -o $@

iotest.o: iotest.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Очистка
clean:
	rm -f *.o tester.out user_code.out

.PHONY: all help user clean