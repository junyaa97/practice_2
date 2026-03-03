#include "Array_2.h"

#include <cmath>
#include <iostream>

Array_2::Array_2() : ArrayBase() {}

Array_2::Array_2(int n) : ArrayBase(n) {}

Array_2::Array_2(const Array_2& other) : ArrayBase(other) {}

Array_2::~Array_2() = default;

Array_2& Array_2::operator=(const Array_2& other) {
    if (this != &other) {
        ArrayBase::operator=(other);
    }
    return *this;
}

void Array_2::solve() {
    if (n == 0 || a == nullptr) {
        std::cout << "[Array_2] Массив пуст." << std::endl;
        return;
    }

    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (std::abs(a[i]) > std::abs(a[idx])) {
            idx = i;
        }
    }

    if (idx == n - 1) {
        std::cout << "[Array_2] Элементов после максимального по модулю нет." << std::endl;
        return;
    }

    long long product = 1;
    for (int i = idx + 1; i < n; ++i) {
        product *= a[i];
    }

    std::cout << "[Array_2] Произведение элементов после максимального по модулю: "
        << product << std::endl;
}
