#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

class Base {
public:
    Base();
    Base(const Base& other);
    virtual ~Base();

    // Получение названия типа объекта
    virtual std::string getType() const = 0;

    // Вывод информации об объекте
    virtual void print() const = 0;

    // Редактирование объекта
    virtual void edit() = 0;

    // Сохранение объекта в файл
    virtual void save(std::ofstream& file) const = 0;
};

#endif