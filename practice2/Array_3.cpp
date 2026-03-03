#include "Array_3.h"

#include <cmath>
#include <iostream>
#include <vector>

Array_3::Array_3() : ArrayBase() {}

Array_3::Array_3(int n) : ArrayBase(n) {}

Array_3::Array_3(const Array_3& other) : ArrayBase(other) {}

Array_3::~Array_3() = default;

Array_3& Array_3::operator=(const Array_3& other) {
    if (this != &other) {
        ArrayBase::operator=(other);
    }
    return *this;
}

void Array_3::solve() {
    if (n == 0 || a == nullptr) {
        std::cout << "[Array_3] Массив пуст." << std::endl;
        return;
    }

    int y;
    std::cout << "[Array_3] Введите Y: ";
    std::cin >> y;

    int maxValue = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    std::vector<int> reordered;
    reordered.reserve(static_cast<std::size_t>(n));

    for (int i = 0; i < n; ++i) {
        if (std::abs(a[i] - maxValue) <= y) {
            reordered.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (std::abs(a[i] - maxValue) > y) {
            reordered.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        a[i] = reordered[static_cast<std::size_t>(i)];
    }

    std::cout << "[Array_3] Массив после перестановки: " << std::endl;
    print();
}
