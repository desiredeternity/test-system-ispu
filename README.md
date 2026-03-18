# Test system ISPU #

Компиляция кода:
```
g++ -Dmain=user_main -c user_codeX_X.cpp -o user_codeX_X.o
g++ -c iotest.cpp -o iotest.o
g++ -c testX_X.cpp -o testX_X.o
g++ user_codeX_X.o iotest.o testX_X.o -o tester.out
