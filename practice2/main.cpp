#include <clocale>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Array_1.h"
#include "Array_2.h"
#include "Array_3.h"

static void setupUtf8Console() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
}

int main() {
    setupUtf8Console();
    const int size = 10;

    Array_1 tmp1(size);
    Array_2 tmp2(size);
    Array_3 tmp3(size);

    ArrayBase* arr[] = {
        new Array_1(),
        new Array_1(size),
        new Array_1(tmp1),

        new Array_2(),
        new Array_2(size),
        new Array_2(tmp2),

        new Array_3(),
        new Array_3(size),
        new Array_3(tmp3),
    };

    const int count = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < count; ++i) {
        std::cout << "\n=== Object #" << i + 1 << " ===" << std::endl;
        arr[i]->printAuthor();
        arr[i]->print();
        arr[i]->solve();
    }

    for (int i = 0; i < count; ++i) {
        delete arr[i];
    }

    return 0;
}
