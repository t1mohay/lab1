#include <iostream>

int main() {
    int values[3] = {1, 2, 3};

    // Ошибка №1 (выход за границы массива) УЖЕ ИСПРАВЛЕНА.
    std::cout << "values[2] = " << values[2] << '\n';

    // НАМЕРЕННАЯ ОШИБКА №2: целочисленное переполнение знакового int (UB).
    // UndefinedBehaviorSanitizer это обнаружит на Linux.
    int big = 2147483647;  // INT_MAX
    big = big + 1;         // signed integer overflow
    std::cout << "big = " << big << '\n';

    return 0;
}