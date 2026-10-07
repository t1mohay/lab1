#include <iostream>

int main() {
    int values[3] = {1, 2, 3};

    // ОШИБКА ИСПРАВЛЕНА: обращаемся к корректному индексу.
    std::cout << "values[2] = " << values[2] << '\n';

    // Ошибка с неинициализированной переменной временно закомментирована,
    // покажем её отдельно на Linux через UBSan.
    // int x;
    // if (x == 42) { std::cout << "unreachable\n"; }

    return 0;
}