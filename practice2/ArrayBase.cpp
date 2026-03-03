#include "ArrayBase.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

ArrayBase::ArrayBase() : a(nullptr), n(0) {}

ArrayBase::ArrayBase(int n) : a(nullptr), n(n > 0 ? n : 0) {
    if (this->n > 0) {
        a = new int[this->n];

        static bool seeded = false;
        if (!seeded) {
            std::srand(static_cast<unsigned int>(time(nullptr)));
            seeded = true;
        }

        for (int i = 0; i < this->n; ++i) {
            a[i] = std::rand() % 201 - 100;
        }
    }
}

ArrayBase::ArrayBase(const ArrayBase& other) : a(nullptr), n(other.n) {
    if (n > 0) {
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = other.a[i];
        }
    }
}

ArrayBase::~ArrayBase() {
    delete[] a;
}

ArrayBase& ArrayBase::operator=(const ArrayBase& other) {
    if (this == &other) {
        return *this;
    }

    int* newArray = nullptr;
    if (other.n > 0) {
        newArray = new int[other.n];
        for (int i = 0; i < other.n; ++i) {
            newArray[i] = other.a[i];
        }
    }

    delete[] a;
    a = newArray;
    n = other.n;

    return *this;
}

void ArrayBase::printAuthor() const {
    std::cout << "ФИО: Иванов Иван Иванович, группа: ИВТ-00, вариант: 17" << std::endl;
}

void ArrayBase::print() const {
    std::cout << "Массив (n=" << n << "): ";
    if (n == 0 || a == nullptr) {
        std::cout << "<пусто>" << std::endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
}
