#ifndef TRAIN_H
#define TRAIN_H

#include "Base.h"

class TRAIN : public Base {
private:
    std::string destination;
    int trainNumber;
    std::string departureTime;

public:
    // Конструктор по умолчанию
    TRAIN();

    // Конструктор с параметрами
    TRAIN(
        const std::string& destination,
        int trainNumber,
        const std::string& departureTime
    );

    // Конструктор копирования
    TRAIN(const TRAIN& other);

    // Деструктор
    ~TRAIN() override;

    // Получение типа объекта
    std::string getType() const override;

    // Вывод информации
    void print() const override;

    // Геттеры
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    // Сеттеры
    void setDestination(const std::string& value);
    void setTrainNumber(int value);
    void setDepartureTime(const std::string& value);

    // Перевод времени в минуты
    int getTimeInMinutes() const;

    // Перегрузка операторов ввода и вывода
    friend std::istream& operator>>(std::istream& in, TRAIN& train);
    friend std::ostream& operator<<(std::ostream& out, const TRAIN& train);
};

#endif