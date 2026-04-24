CXX = g++
CXXFLAGS = -w -std=c++17
INCLUDES = -Iinclude

# Пути к исходникам и объектным файлам
SRC_DIR = src
INCLUDE_DIR = include
TESTS_DIR = tests
OBJ_DIR = obj

# Список объектных файлов
COMMON_OBJ = $(OBJ_DIR)/msvc_compat.o $(OBJ_DIR)/Windows.o $(OBJ_DIR)/iotest.o
USER_OBJ = $(OBJ_DIR)/user_code.o
TEST_OBJ_PREFIX = $(OBJ_DIR)/test
USER_MAIN_OBJ = $(OBJ_DIR)/user_code_main.o

# Правило по умолчанию
all: help

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Справка
help:
	@echo "Доступные цели:"
	@echo "  make testX_X  - скомпилировать и запустить тест (X_X - номер задачи, например, test1_3, test2_5)"
	@echo "  make user     - скомпилировать и запустить пользовательский код"
	@echo "  make clean    - удалить объектные файлы и исполняемые файлы"

# Сценарий 1: компиляция с тестированием
test%: $(OBJ_DIR) $(COMMON_OBJ) $(USER_OBJ) $(OBJ_DIR)/test%.o
	$(CXX) $(COMMON_OBJ) $(USER_OBJ) $(OBJ_DIR)/test$*.o -o tester.out
	@./tester.out

# Компиляция тестового файла с конкретным номером
$(OBJ_DIR)/test%.o: $(TESTS_DIR)/test%.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

# Сценарий 2: отдельная компиляция пользовательского кода
user: $(OBJ_DIR)
	$(CXX) $(INCLUDES) -include common_headers.hpp $(CXXFLAGS) $(SRC_DIR)/user_code.cpp $(SRC_DIR)/Windows.cpp $(SRC_DIR)/msvc_compat.cpp -o user_code.out
	@./user_code.out

# Компиляция объектных файлов
$(OBJ_DIR)/msvc_compat.o: $(SRC_DIR)/msvc_compat.cpp $(INCLUDE_DIR)/msvc_compat.hpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

$(OBJ_DIR)/Windows.o: $(SRC_DIR)/Windows.cpp $(INCLUDE_DIR)/Windows.h | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

$(OBJ_DIR)/user_code.o: $(SRC_DIR)/user_code.cpp $(INCLUDE_DIR)/common_headers.hpp $(INCLUDE_DIR)/msvc_compat.hpp | $(OBJ_DIR)
	$(CXX) $(INCLUDES) -include common_headers.hpp -include msvc_compat.hpp -Dmain=user_main $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/user_code_main.o: $(SRC_DIR)/user_code.cpp $(INCLUDE_DIR)/common_headers.hpp $(INCLUDE_DIR)/msvc_compat.hpp | $(OBJ_DIR)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/iotest.o: $(SRC_DIR)/iotest.cpp $(INCLUDE_DIR)/iotest.hpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

# Очистка
clean:
	rm -f *.o *.out tester.out user_code.out
	rm -rf $(OBJ_DIR)

.PHONY: all help user clean