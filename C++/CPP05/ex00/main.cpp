#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.increment_grade(); // Повышаем до 1
        std::cout << b1 << std::endl;

        b1.increment_grade(); // Попытка повысить выше 1 — выброс исключения
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrement_grade(); // Понижаем до 150
        std::cout << b2 << std::endl;

        b2.decrement_grade(); // Попытка понизить ниже 150 — выброс исключения
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
