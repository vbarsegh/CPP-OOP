#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm()
// {
//     std::cout << "RobotomyRequestForm default ctor is called" << std::endl;
// }

AForm* RobotomyRequestForm::createObjInHeap(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm ctor with param is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy ctor is called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm op= is called" << std::endl;
    if (this != &other)
    {
		AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "BZZZZZZZZZZ... drilling noises..." << std::endl;

    srand(time(NULL)); // Инициализация генератора случайных чисел с использованием времени
    int random_value = rand() % 2; // Генерация случайного числа 0 или 1

    if (random_value == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
    // int static counter;
    // if (counter % 2 == 0) {
    //     std::cout << _target << " has been robotomized successfully!" << std::endl;
    // } else {
    //     std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    // }
    // counter++;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm dtor is called" << std::endl;
}