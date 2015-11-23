#include "vector.cpp"
#include <iostream>

int main() {
    Vector<int> v;
    for (int i=0; i < 150; i++) {
        v.add(i);
        //std::cout << v[i] << std::endl;
        // v[i] += 1;
        // std::cout << v[i] << std::endl;
    }
    for (int i=0; i < 40; i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
    v.remove(5);
    for (int i=0; i < 40; i++) {
        std::cout << v[i] << ", ";
    }
    return 0;
}