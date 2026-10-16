#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "base.h"

class Textbook : public Base {
private:
    std::string title;
    std::string author;
    int year;
    std::string institution;
    int studyYear;
    int pages;
    double price;

public:
    Textbook();
    Textbook(
        const std::string& title,
        const std::string& author,
        int year,
        const std::string& institution,
        int studyYear,
        int pages,
        double price
    );
    Textbook(const Textbook& other);
    ~Textbook() override;

    std::string getType() const override;
    void print() const override;
    void edit() override;
    void save(std::ofstream& file) const override;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getInstitution() const;
    int getStudyYear() const;
    int getPages() const;
    double getPrice() const;

    void setTitle(const std::string& value);
    void setAuthor(const std::string& value);
    void setYear(int value);
    void setInstitution(const std::string& value);
    void setStudyYear(int value);
    void setPages(int value);
    void setPrice(double value);
};

#endif