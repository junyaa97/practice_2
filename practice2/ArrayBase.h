#ifndef ARRAYBASE_H
#define ARRAYBASE_H

class ArrayBase {
protected:
    int* a;
    int n;

public:
    ArrayBase();
    explicit ArrayBase(int n);
    ArrayBase(const ArrayBase& other);
    virtual ~ArrayBase();
    ArrayBase& operator=(const ArrayBase& other);

    void printAuthor() const;
    void print() const;
    virtual void solve() = 0;
};

#endif 
