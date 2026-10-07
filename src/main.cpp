#include <iostream>

int main() {
    int values[3] = {1, 2, 3};

    std::cout << "values[2] = " << values[2] << '\n';

    // ОШИБКА ИСПРАВЛЕНА: инициализируем переменную.
    int x = 0;
    if (x == 42) {
        std::cout << "unreachable\n";
    }

    return 0;
}