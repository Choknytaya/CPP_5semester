#ifndef BOOK_H
#define BOOK_H

#include "base.h"

class Book : public Base {
private:
    std::string title;
    std::string author;
    int year;
    std::string annotation;
    std::string genre;
    int pages;
    double price;

public:
    Book();
    Book(
        const std::string& title,
        const std::string& author,
        int year,
        const std::string& annotation,
        const std::string& genre,
        int pages,
        double price
    );
    Book(const Book& other);
    ~Book() override;

    std::string getType() const override;
    void print() const override;
    void edit() override;
    void save(std::ofstream& file) const override;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getAnnotation() const;
    std::string getGenre() const;
    int getPages() const;
    double getPrice() const;

    void setTitle(const std::string& value);
    void setAuthor(const std::string& value);
    void setYear(int value);
    void setAnnotation(const std::string& value);
    void setGenre(const std::string& value);
    void setPages(int value);
    void setPrice(double value);
};

#endif