#include "chancellery.h"

#include <stdexcept>
#include <limits>
#include <iomanip>

namespace {
    double readDouble(const std::string& prompt) {
        double value;

        while (true) {
            std::cout << prompt;

            if (std::cin >> value) {
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                if (value >= 0) {
                    return value;
                }

                std::cout << "Ошибка: цена не может быть отрицательной."
                          << std::endl;
            } else {
                std::cout << "Ошибка: введите число."
                          << std::endl;

                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );
            }
        }
    }

    std::string readString(const std::string& prompt) {
        std::string value;

        while (true) {
            std::cout << prompt;
            std::getline(std::cin, value);

            if (!value.empty()) {
                return value;
            }

            std::cout << "Ошибка: поле не должно быть пустым."
                      << std::endl;
        }
    }
}

Chancellery::Chancellery()
    : Base(),
      itemType("Не указан"),
      color("Не указан"),
      purpose("Не указано"),
      price(0.0) {
    std::cout << "[Конструктор по умолчанию] Chancellery."
              << std::endl;
}

Chancellery::Chancellery(
    const std::string& itemType,
    const std::string& color,
    const std::string& purpose,
    double price
)
    : Base(),
      itemType(itemType),
      color(color),
      purpose(purpose),
      price(price) {
    setItemType(itemType);
    setColor(color);
    setPurpose(purpose);
    setPrice(price);

    std::cout << "[Конструктор с параметрами] Chancellery: "
              << this->itemType << std::endl;
}

Chancellery::Chancellery(const Chancellery& other)
    : Base(other),
      itemType(other.itemType),
      color(other.color),
      purpose(other.purpose),
      price(other.price) {
    std::cout << "[Конструктор копирования] Chancellery: "
              << itemType << std::endl;
}

Chancellery::~Chancellery() {
    std::cout << "[Деструктор] Chancellery: "
              << itemType << std::endl;
}

std::string Chancellery::getType() const {
    return "CHANCELLERY";
}

void Chancellery::print() const {
    std::cout << "\nТип: Канцелярский товар"
              << "\nВид товара: " << itemType
              << "\nЦвет: " << color
              << "\nНазначение: " << purpose
              << "\nЦена: " << std::fixed << std::setprecision(2)
              << price << std::endl;
}

void Chancellery::edit() {
    std::cout << "\nРедактирование канцелярского товара\n";

    setItemType(readString("Новый тип товара: "));
    setColor(readString("Новый цвет: "));
    setPurpose(readString("Новое назначение: "));
    setPrice(readDouble("Новая цена: "));

    std::cout << "Данные канцелярского товара изменены."
              << std::endl;
}

void Chancellery::save(std::ofstream& file) const {
    file << itemType << '\n'
         << color << '\n'
         << purpose << '\n'
         << price << '\n';
}

std::string Chancellery::getItemType() const {
    return itemType;
}

std::string Chancellery::getColor() const {
    return color;
}

std::string Chancellery::getPurpose() const {
    return purpose;
}

double Chancellery::getPrice() const {
    return price;
}

void Chancellery::setItemType(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Тип товара не может быть пустым.");
    }
    itemType = value;
}

void Chancellery::setColor(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Цвет не может быть пустым.");
    }
    color = value;
}

void Chancellery::setPurpose(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Назначение не может быть пустым.");
    }
    purpose = value;
}

void Chancellery::setPrice(double value) {
    if (value < 0) {
        throw std::out_of_range("Цена не может быть отрицательной.");
    }
    price = value;
}