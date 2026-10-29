#include "book.h"

#include <stdexcept>
#include <limits>
#include <iomanip>

namespace {
    int readInt(const std::string& prompt) {
        int value;

        while (true) {
            std::cout << prompt;

            if (std::cin >> value) {
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );
                return value;
            }

            std::cout << "Ошибка: необходимо ввести целое число."
                      << std::endl;

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
        }
    }

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
                std::cout << "Ошибка: необходимо ввести число."
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

Book::Book()
    : Base(),
      title("Не указано"),
      author("Не указан"),
      year(2000),
      annotation("Не указана"),
      genre("Не указан"),
      pages(1),
      price(0.0) {
    std::cout << "[Конструктор по умолчанию] Book."
              << std::endl;
}

Book::Book(
    const std::string& title,
    const std::string& author,
    int year,
    const std::string& annotation,
    const std::string& genre,
    int pages,
    double price
)
    : Base(),
      title(title),
      author(author),
      year(year),
      annotation(annotation),
      genre(genre),
      pages(pages),
      price(price) {
    setTitle(title);
    setAuthor(author);
    setYear(year);
    setAnnotation(annotation);
    setGenre(genre);
    setPages(pages);
    setPrice(price);

    std::cout << "[Конструктор с параметрами] Book: "
              << this->title << std::endl;
}

Book::Book(const Book& other)
    : Base(other),
      title(other.title),
      author(other.author),
      year(other.year),
      annotation(other.annotation),
      genre(other.genre),
      pages(other.pages),
      price(other.price) {
    std::cout << "[Конструктор копирования] Book: "
              << title << std::endl;
}

Book::~Book() {
    std::cout << "[Деструктор] Book: "
              << title << std::endl;
}

std::string Book::getType() const {
    return "BOOK";
}

void Book::print() const {
    std::cout << "\nТип: Книга"
              << "\nНазвание: " << title
              << "\nАвтор: " << author
              << "\nГод издания: " << year
              << "\nАннотация: " << annotation
              << "\nЖанр: " << genre
              << "\nКоличество страниц: " << pages
              << "\nЦена: " << std::fixed << std::setprecision(2)
              << price << std::endl;
}

void Book::edit() {
    std::cout << "\nРедактирование книги\n";

    setTitle(readString("Новое название: "));
    setAuthor(readString("Новый автор: "));
    setYear(readInt("Новый год издания: "));
    setAnnotation(readString("Новая аннотация: "));
    setGenre(readString("Новый жанр: "));
    setPages(readInt("Новое количество страниц: "));
    setPrice(readDouble("Новая цена: "));

    std::cout << "Данные книги изменены." << std::endl;
}

void Book::save(std::ofstream& file) const {
    file << title << '\n'
         << author << '\n'
         << year << '\n'
         << annotation << '\n'
         << genre << '\n'
         << pages << '\n'
         << price << '\n';
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

std::string Book::getAnnotation() const {
    return annotation;
}

std::string Book::getGenre() const {
    return genre;
}

int Book::getPages() const {
    return pages;
}

double Book::getPrice() const {
    return price;
}

void Book::setTitle(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Название книги не может быть пустым.");
    }
    title = value;
}

void Book::setAuthor(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Автор не может быть пустым.");
    }
    author = value;
}

void Book::setYear(int value) {
    if (value < 0 || value > 2100) {
        throw std::out_of_range("Некорректный год издания.");
    }
    year = value;
}

void Book::setAnnotation(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Аннотация не может быть пустой.");
    }
    annotation = value;
}

void Book::setGenre(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Жанр не может быть пустым.");
    }
    genre = value;
}

void Book::setPages(int value) {
    if (value <= 0) {
        throw std::out_of_range(
            "Количество страниц должно быть положительным."
        );
    }
    pages = value;
}

void Book::setPrice(double value) {
    if (value < 0) {
        throw std::out_of_range("Цена не может быть отрицательной.");
    }
    price = value;
}