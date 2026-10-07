#include <iostream>

int main() {
    int values[3] = {1, 2, 3};

    // Ошибка №1 (выход за границы массива) УЖЕ ИСПРАВЛЕНА.
    std::cout << "values[2] = " << values[2] << '\n';

    // НАМЕРЕННАЯ ОШИБКА №2: чтение неинициализированной переменной (UB).
    // UndefinedBehaviorSanitizer это обнаружит на Linux.
    int x;
    if (x == 42) {
        std::cout << "unreachable\n";
    }

    return 0;
}