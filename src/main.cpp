
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

namespace {

// ИСПРАВЛЕНО (было ASan: stack-buffer-overflow).
// Было i <= count - цикл читал элемент за концом массива.
int sum_grades(const int* grades, int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += grades[i];
    }
    return sum;
}

void demo_array() {
    int grades[5] = {5, 4, 4, 3, 5};
    std::cout << "Сумма оценок: " << sum_grades(grades, 5) << '\n';
}

// ИСПРАВЛЕНО (было ASan: heap-use-after-free).
// Было чтение после delete[]; std::vector сам освобождает память
// при выходе из функции, когда она уже не нужна.
void demo_use_after_free() {
    std::vector<int> grades{4, 5, 3};
    std::cout << "Последняя оценка: " << grades[2] << '\n';
}

// ИСПРАВЛЕНО (было UBSan: signed integer overflow).
// 13! = 6 227 020 800 не помещается в int, поэтому считаем в long long
// (в него помещается до 20!).
long long permutations(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void demo_overflow() {
    const int students = 13;
    std::cout << "Вариантов рассадить " << students
              << " студентов: " << permutations(students) << '\n';
}

// ИСПРАВЛЕНО (было LeakSanitizer: memory leak).
// Было new int[100] без delete[]; std::vector освобождает память сам.
void demo_leak() {
    std::vector<int> journal(100, 5);
    std::cout << "Первая запись журнала: " << journal[0] << '\n';
}

}  

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  // чтобы кириллица в консоли Windows не ломалась
#endif
    const std::string mode = argc > 1 ? argv[1] : "all";
    const bool all = mode == "all";

    if (all || mode == "array") demo_array();
    if (all || mode == "uaf") demo_use_after_free();
    if (all || mode == "overflow") demo_overflow();
    if (all || mode == "leak") demo_leak();

    return 0;
}
