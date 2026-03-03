#ifndef ARRAY_1_H
#define ARRAY_1_H

#include "ArrayBase.h"

class Array_1 : public ArrayBase {
public:
    Array_1();
    explicit Array_1(int n);
    Array_1(const Array_1& other);
    ~Array_1() override;
    Array_1& operator=(const Array_1& other);

    int countGreaterThan(int D) const;
    void solve() override;
};

#endif // ARRAY_1_H
