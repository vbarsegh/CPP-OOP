#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
{
    try {
        // Создаём бюрократа с нормальным уровнем
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
		std::cout << "stugenq tenanq copy_alice-@ chishta exe`" << std::endl;
		Bureaucrat copy_alice(alice);
        std::cout << copy_alice << std::endl;

		std::cout << &alice << std::endl;
		std::cout << &copy_alice << std::endl;


        // Создаём форму с допустимыми уровнями подписания и выполнения
        Form importantForm("ImportantForm", 40, 20);
        std::cout << importantForm << std::endl;

        // Пытаемся подписать форму (не хватит уровня)
        alice.signForm(importantForm);
        std::cout << importantForm << std::endl;

        // Повышаем уровень бюрократа
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade();
        // alice.increment_grade(); // Уровень Alice: 40
        // std::cout << alice << std::endl;

        // alice.signForm(importantForm);
        // std::cout << importantForm << std::endl;

		copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade();
        copy_alice.increment_grade(); // Уровень Alice: 40
        std::cout << copy_alice << std::endl;
        // Пытаемся подписать форму (должно сработать)
        copy_alice.signForm(importantForm);

        std::cout << importantForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;
}

{
    try {
        // Создаём бюрократа с минимальным уровнем
        Bureaucrat bob("Bob", 99);
        std::cout << bob << std::endl;

        // Создаём форму с недостижимым уровнем подписания для Bob
        Form anotherForm("HardForm", 100, 50);
        std::cout << anotherForm << std::endl;
		Form copy_anotherForm(anotherForm);
		std::cout << "stugenq tenanq copy_anotherForm-@ chishta exe`" << std::endl;
        std::cout << copy_anotherForm << std::endl;


		std::cout << &anotherForm << std::endl;
		std::cout << &copy_anotherForm << std::endl;

        // Bob пытается подписать форму
        // bob.signForm(anotherForm);
        // std::cout << anotherForm << std::endl;
		bob.signForm(copy_anotherForm);
        std::cout << copy_anotherForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
    }
	std::cout << std::endl;
}

{
	try {
	Bureaucrat bob("Bob", 160);
	std::cout << bob << std::endl;

	// Создаём форму с недостижимым уровнем подписания для Bob
	Form anotherForm("HardForm", 100, 50);
	std::cout << anotherForm << std::endl;

	// Bob пытается подписать форму
	bob.signForm(anotherForm);
	std::cout << anotherForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
    }
	std::cout << std::endl;
}

{
	try {
	Bureaucrat bob("Bob", 150);
	std::cout << bob << std::endl;

	// Создаём форму с недостижимым уровнем подписания для Bob
	Form anotherForm("HardForm", 10, 0);
	std::cout << anotherForm << std::endl;

	// Bob пытается подписать форму
	bob.signForm(anotherForm);
	std::cout << anotherForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
    }
}

    return 0;
}
