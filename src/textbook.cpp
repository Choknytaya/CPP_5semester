#include "textbook.h"

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

            std::cout << "Ошибка: введите целое число."
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

Textbook::Textbook()
    : Base(),
      title("Не указано"),
      author("Не указан"),
      year(2000),
      institution("Не указано"),
      studyYear(1),
      pages(1),
      price(0.0) {
    std::cout << "[Конструктор по умолчанию] Textbook."
              << std::endl;
}

Textbook::Textbook(
    const std::string& title,
    const std::string& author,
    int year,
    const std::string& institution,
    int studyYear,
    int pages,
    double price
)
    : Base(),
      title(title),
      author(author),
      year(year),
      institution(institution),
      studyYear(studyYear),
      pages(pages),
      price(price) {
    setTitle(title);
    setAuthor(author);
    setYear(year);
    setInstitution(institution);
    setStudyYear(studyYear);
    setPages(pages);
    setPrice(price);

    std::cout << "[Конструктор с параметрами] Textbook: "
              << this->title << std::endl;
}

Textbook::Textbook(const Textbook& other)
    : Base(other),
      title(other.title),
      author(other.author),
      year(other.year),
      institution(other.institution),
      studyYear(other.studyYear),
      pages(other.pages),
      price(other.price) {
    std::cout << "[Конструктор копирования] Textbook: "
              << title << std::endl;
}

Textbook::~Textbook() {
    std::cout << "[Деструктор] Textbook: "
              << title << std::endl;
}

std::string Textbook::getType() const {
    return "TEXTBOOK";
}

void Textbook::print() const {
    std::cout << "\nТип: Учебник"
              << "\nНазвание: " << title
              << "\nАвтор: " << author
              << "\nГод издания: " << year
              << "\nУчебное заведение: " << institution
              << "\nГод обучения: " << studyYear
              << "\nКоличество страниц: " << pages
              << "\nЦена: " << std::fixed << std::setprecision(2)
              << price << std::endl;
}

void Textbook::edit() {
    std::cout << "\nРедактирование учебника\n";

    setTitle(readString("Новое название: "));
    setAuthor(readString("Новый автор: "));
    setYear(readInt("Новый год издания: "));
    setInstitution(readString("Учебное заведение: "));
    setStudyYear(readInt("Год обучения: "));
    setPages(readInt("Количество страниц: "));
    setPrice(readDouble("Цена: "));

    std::cout << "Данные учебника изменены." << std::endl;
}

void Textbook::save(std::ofstream& file) const {
    file << title << '\n'
         << author << '\n'
         << year << '\n'
         << institution << '\n'
         << studyYear << '\n'
         << pages << '\n'
         << price << '\n';
}

std::string Textbook::getTitle() const {
    return title;
}

std::string Textbook::getAuthor() const {
    return author;
}

int Textbook::getYear() const {
    return year;
}

std::string Textbook::getInstitution() const {
    return institution;
}

int Textbook::getStudyYear() const {
    return studyYear;
}

int Textbook::getPages() const {
    return pages;
}

double Textbook::getPrice() const {
    return price;
}

void Textbook::setTitle(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument(
            "Название учебника не может быть пустым."
        );
    }
    title = value;
}

void Textbook::setAuthor(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Автор не может быть пустым.");
    }
    author = value;
}

void Textbook::setYear(int value) {
    if (value < 0 || value > 2100) {
        throw std::out_of_range("Некорректный год издания.");
    }
    year = value;
}

void Textbook::setInstitution(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument(
            "Название учебного заведения не может быть пустым."
        );
    }
    institution = value;
}

void Textbook::setStudyYear(int value) {
    if (value < 1 || value > 20) {
        throw std::out_of_range(
            "Год обучения должен находиться в диапазоне от 1 до 20."
        );
    }
    studyYear = value;
}

void Textbook::setPages(int value) {
    if (value <= 0) {
        throw std::out_of_range(
            "Количество страниц должно быть положительным."
        );
    }
    pages = value;
}

void Textbook::setPrice(double value) {
    if (value < 0) {
        throw std::out_of_range("Цена не может быть отрицательной.");
    }
    price = value;
}