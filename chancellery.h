#ifndef CHANCELLERY_H
#define CHANCELLERY_H

#include "base.h"

class Chancellery : public Base {
private:
    std::string itemType;
    std::string color;
    std::string purpose;
    double price;

public:
    Chancellery();
    Chancellery(
        const std::string& itemType,
        const std::string& color,
        const std::string& purpose,
        double price
    );
    Chancellery(const Chancellery& other);
    ~Chancellery() override;

    std::string getType() const override;
    void print() const override;
    void edit() override;
    void save(std::ofstream& file) const override;

    std::string getItemType() const;
    std::string getColor() const;
    std::string getPurpose() const;
    double getPrice() const;

    void setItemType(const std::string& value);
    void setColor(const std::string& value);
    void setPurpose(const std::string& value);
    void setPrice(double value);
};

#endif