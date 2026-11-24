#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {
public:
    Base();
    Base(const Base& other);
    virtual ~Base();

    // Получение типа объекта
    virtual std::string getType() const = 0;

    // Вывод информации об объекте
    virtual void print() const = 0;
};

#endif