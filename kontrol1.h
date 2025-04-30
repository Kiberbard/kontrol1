#ifndef KONTROL1_H
#define KONTROL1_H
#include <iostream>
#include <vector>
#include <memory>

// Прототипы функций
bool noRandomMass(std::vector<int>& array_in, size_t size_in);
void writeArray(std::vector<int>& array_in, size_t size_in);

class Massive {
public:
    void setParams(const std::vector<int>& array_in); 
    void printArr() const;

    // Геттер для доступа к данным (нужен для стратегий)
    const std::vector<int>& getData() const { return data; }
    std::vector<int>& getData() { return data; } // Не-const версия для модификации

private:
    std::vector<int> data; 
};


int clientCode();

#endif // KONTROL1_H
