#ifndef ARRAY_2_H
#define ARRAY_2_H

#include "ArrayBase.h"

class Array_2 : public ArrayBase {
public:
    Array_2();
    explicit Array_2(int n);
    Array_2(const Array_2& other);
    ~Array_2() override;
    Array_2& operator=(const Array_2& other);

    void solve() override;
};

#endif // ARRAY_2_H
