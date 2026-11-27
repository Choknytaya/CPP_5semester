#include "Train.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <limits>

// Конструктор по умолчанию
TRAIN::TRAIN()
    : Base(),
      destination("Не указан"),
      trainNumber(1),
      departureTime("00:00") {

    std::cout << "[Конструктор по умолчанию] TRAIN."
              << std::endl;
}

// Конструктор с параметрами
TRAIN::TRAIN(
    const std::string& destination,
    int trainNumber,
    const std::string& departureTime
)
    : Base(),
      destination(destination),
      trainNumber(trainNumber),
      departureTime(departureTime) {

    setDestination(destination);
    setTrainNumber(trainNumber);
    setDepartureTime(departureTime);

    std::cout << "[Конструктор с параметрами] TRAIN: "
              << this->trainNumber << std::endl;
}

// Конструктор копирования
TRAIN::TRAIN(const TRAIN& other)
    : Base(other),
      destination(other.destination),
      trainNumber(other.trainNumber),
      departureTime(other.departureTime) {

    std::cout << "[Конструктор копирования] TRAIN: "
              << trainNumber << std::endl;
}

// Деструктор
TRAIN::~TRAIN() {
    std::cout << "[Деструктор] TRAIN: "
              << trainNumber << std::endl;
}

// Получение типа объекта
std::string TRAIN::getType() const {
    return "TRAIN";
}

// Вывод информации
void TRAIN::print() const {
    std::cout << *this << std::endl;
}

// Геттеры
std::string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

std::string TRAIN::getDepartureTime() const {
    return departureTime;
}

// Сеттер названия пункта назначения
void TRAIN::setDestination(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument(
            "Название пункта назначения не может быть пустым."
        );
    }

    destination = value;
}

// Сеттер номера поезда
void TRAIN::setTrainNumber(int value) {
    if (value <= 0) {
        throw std::invalid_argument(
            "Номер поезда должен быть положительным числом."
        );
    }

    trainNumber = value;
}

// Сеттер времени отправления
void TRAIN::setDepartureTime(const std::string& value) {
    if (value.length() != 5 || value[2] != ':') {
        throw std::invalid_argument(
            "Неверный формат времени. Используйте ЧЧ:ММ."
        );
    }

    if (value[0] < '0' || value[0] > '9' ||
        value[1] < '0' || value[1] > '9' ||
        value[3] < '0' || value[3] > '9' ||
        value[4] < '0' || value[4] > '9') {

        throw std::invalid_argument(
            "Время должно содержать только цифры и двоеточие."
        );
    }

    int hours =
        (value[0] - '0') * 10 + (value[1] - '0');

    int minutes =
        (value[3] - '0') * 10 + (value[4] - '0');

    if (hours < 0 || hours > 23 ||
        minutes < 0 || minutes > 59) {

        throw std::out_of_range(
            "Некорректное время. Часы: 00-23, минуты: 00-59."
        );
    }

    departureTime = value;
}

// Перевод времени в минуты
int TRAIN::getTimeInMinutes() const {
    int hours =
        (departureTime[0] - '0') * 10 +
        (departureTime[1] - '0');

    int minutes =
        (departureTime[3] - '0') * 10 +
        (departureTime[4] - '0');

    return hours * 60 + minutes;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, TRAIN& train) {
    std::string destination;
    int trainNumber;
    std::string departureTime;

    std::cout << "Пункт назначения: ";
    std::getline(in >> std::ws, destination);

    std::cout << "Номер поезда: ";
    if (!(in >> trainNumber)) {
        return in;
    }

    std::cout << "Время отправления (ЧЧ:ММ): ";
    in >> departureTime;

    if (!in) {
        return in;
    }

    try {
        train.setDestination(destination);
        train.setTrainNumber(trainNumber);
        train.setDepartureTime(departureTime);
    }
    catch (const std::exception& error) {
        std::cerr << "Ошибка ввода поезда: "
                  << error.what() << std::endl;

        in.setstate(std::ios::failbit);
    }

    return in;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const TRAIN& train) {
    out << "Пункт назначения: " << train.destination
        << "\nНомер поезда: " << train.trainNumber
        << "\nВремя отправления: " << train.departureTime;

    return out;
}