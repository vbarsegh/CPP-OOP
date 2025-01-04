#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default ctor is called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
    std::cout << "Intern copy ctor is called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
    std::cout << "Intern operator= is called" << std::endl;
	return (*this);
}

AForm* Intern::makeForm(const std::string nameForm, const std::string target)
{
	std::pair<const std::string, AForm* (*)(const std::string&)> formPairs[DESCENDANTS_COUNT] = {
		{"robotomy request",&PresidentialPardonForm::createObjInHeap},
		{"shrubbery creation", &RobotomyRequestForm::createObjInHeap},
		{"presidential pardon", &ShrubberyCreationForm::createObjInHeap},
	};
	// formPairs[0] = {"robotomy request", [](const std::string& target) {return new RobotomyRequestForm(target);}};
	// formPairs[1] = {"shrubbery creation", [](const std::string& target) { return new ShrubberyCreationForm(target);}};
    // formPairs[2] = {"presidential pardon", [](const std::string& target) { return new PresidentialPardonForm(target);}};

	for (int i = 0; i < DESCENDANTS_COUNT; i++)
	{
		if (formPairs[i].first == nameForm)
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return (formPairs[i].second(target));
		}
	}
	std::cout << "Form not found" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
    std::cout << "Intern dtor is called" << std::endl;
}