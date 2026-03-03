#include <clocale>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Array_1.h"
#include "Array_2.h"
#include "Array_3.h"

static void setupUtf8Console() {
    std::setlocale(LC_ALL, "");
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
}

int main() {
    setupUtf8Console();

    const int size = 10;

    Array_1 a1NoParam;
    Array_1 a1WithParam(size);
    Array_1 a1Copy(a1WithParam);

    Array_2 a2NoParam;
    Array_2 a2WithParam(size);
    Array_2 a2Copy(a2WithParam);

    Array_3 a3NoParam;
    Array_3 a3WithParam(size);
    Array_3 a3Copy(a3WithParam);

    ArrayBase* arr[] = {
        new Array_1(a1NoParam),
        new Array_1(a1WithParam),
        new Array_1(a1Copy),
        new Array_2(a2NoParam),
        new Array_2(a2WithParam),
        new Array_2(a2Copy),
        new Array_3(a3NoParam),
        new Array_3(a3WithParam),
        new Array_3(a3Copy)
    };

    const int count = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < count; ++i) {
        std::cout << "\n=== Объект #" << i + 1 << " ===" << std::endl;
        arr[i]->printAuthor();
        arr[i]->print();
        arr[i]->solve();
    }

    for (int i = 0; i < count; ++i) {
        delete arr[i];
    }

    return 0;
}
