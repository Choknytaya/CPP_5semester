#include "Base.h"

Base::Base() {
    std::cout << "[Конструктор по умолчанию] Base."
              << std::endl;
}

Base::Base(const Base& other) {
    (void)other;

    std::cout << "[Конструктор копирования] Base."
              << std::endl;
}

Base::~Base() {
    std::cout << "[Деструктор] Base."
              << std::endl;
}