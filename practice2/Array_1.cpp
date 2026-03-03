#include "Array_1.h"

#include <iostream>

Array_1::Array_1() : ArrayBase() {}

Array_1::Array_1(int n) : ArrayBase(n) {}

Array_1::Array_1(const Array_1& other) : ArrayBase(other) {}

Array_1::~Array_1() = default;

Array_1& Array_1::operator=(const Array_1& other) {
    if (this != &other) {
        ArrayBase::operator=(other);
    }
    return *this;
}

void Array_1::solve() {
    int d;
    std::cout << "[Array_1] Введите D: ";
    std::cin >> d;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > d) {
            ++count;
        }
    }

    std::cout << "[Array_1] Количество элементов больше D: " << count << std::endl;
}
