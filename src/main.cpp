#include <iostream>

int main() {
    int values[3] = {1, 2, 3};
    std::cout << "values[2] = " << values[2] << '\n';

    // ОШИБКА ИСПРАВЛЕНА: используем long long вместо int,
    // чтобы избежать signed integer overflow.
    long long big = 2147483647LL;
    big = big + 1;
    std::cout << "big = " << big << '\n';

    return 0;
}