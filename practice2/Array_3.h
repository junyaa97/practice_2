#ifndef ARRAY_3_H
#define ARRAY_3_H

#include "ArrayBase.h"

class Array_3 : public ArrayBase {
public:
    Array_3();
    explicit Array_3(int n);
    Array_3(const Array_3& other);
    ~Array_3() override;
    Array_3& operator=(const Array_3& other);

    void reorderByY(int Y);
    void solve() override;
};

#endif 
