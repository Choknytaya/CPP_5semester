#include "base.h"

Base::Base() {
    std::cout << "[Конструктор] Base: создан базовый объект."
              << std::endl;
}

Base::Base(const Base& other) {
    (void)other;
    std::cout << "[Конструктор копирования] Base."
              << std::endl;
}

Base::~Base() {
    std::cout << "[Деструктор] Base: уничтожение базовой части объекта."
              << std::endl;
}