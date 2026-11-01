// Лабораторная работа №1: CMake Presets, санитайзеры, GitHub Actions.
// Программа "Журнал оценок" с НАМЕРЕННЫМИ ошибками для демонстрации
// AddressSanitizer, LeakSanitizer и UndefinedBehaviorSanitizer.
//
// Запуск: lab1 <сценарий>, где сценарий: array | uaf | overflow | leak | all

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

namespace {

// ОШИБКА 1 (ASan: stack-buffer-overflow).
// Условие i <= count заставляет цикл прочитать элемент за концом массива.
int sum_grades(const int* grades, int count) {
    int sum = 0;
    for (int i = 0; i <= count; ++i) {
        sum += grades[i];
    }
    return sum;
}

void demo_array() {
    int grades[5] = {5, 4, 4, 3, 5};
    std::cout << "Сумма оценок: " << sum_grades(grades, 5) << '\n';
}

// ОШИБКА 2 (ASan: heap-use-after-free).
// Память освобождается, а затем из неё читается последняя оценка.
void demo_use_after_free() {
    int* grades = new int[3]{4, 5, 3};
    delete[] grades;
    std::cout << "Последняя оценка: " << grades[2] << '\n';
}

// ОШИБКА 3 (UBSan: signed integer overflow).
// 13! = 6 227 020 800 не помещается в int (максимум 2 147 483 647).
int permutations(int n) {
    int result = 1;
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

// ОШИБКА 4 (LeakSanitizer: memory leak).
// Выделенный массив не освобождается.
void demo_leak() {
    int* journal = new int[100];
    for (int i = 0; i < 100; ++i) {
        journal[i] = 5;
    }
    std::cout << "Первая запись журнала: " << journal[0] << '\n';
}

}  // namespace

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
