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
	std::pair<std::string, AForm* (*)(const std::string&)> formPairs[DESCENDANTS_COUNT];
	formPairs[0] = std::make_pair("robotomy request", &RobotomyRequestForm::createObjInHeap);
	formPairs[1] = std::make_pair("presidential pardon", &PresidentialPardonForm::createObjInHeap);
	formPairs[2] = std::make_pair("shrubbery creation", &ShrubberyCreationForm::createObjInHeap);

	for (int i = 0; i < DESCENDANTS_COUNT; i++)
	{
		if (formPairs[i].first == nameForm)
		{
			std::cout << "Intern creates " << target << std::endl;
			// return (formPairs[i].second(target));
			AForm *obj = formPairs[i].second(target);
			return (obj);
		}
	}
	throw FormNotFound();
	// std::cout << "Form not found" << std::endl;
	return (NULL);
}

// AForm* Intern::makeForm(const std::string nameForm, const std::string target)
// {
// 	std::pair<std::string, AForm*(*)(const std::string&)> formPairs[DESCENDANTS_COUNT];
// 	formPairs[0] = std::make_pair("robotomy request", &RobotomyRequestForm::createObjInHeap);
// 	formPairs[1] = std::make_pair("presidential request", &PresidentialPardonForm::createObjInHeap);
// 	formPairs[2] = std::make_pair("shrubbery request", &ShrubberyCreationForm::createObjInHeap);
// 	for (int i = 0; i < DESCENDANTS_COUNT; i++)
// 	{
// 		if (formPairs[i].first == nameForm)
// 		{
// 			std::cout << "Intern creates " << nameForm << std::endl;
//  			return formPairs[i].second(target);
// 		}
// 	}
// 	std::cout << "Intern can't create form, because type doesn't match\n";
// 	return NULL;
// }


const char* Intern::FormNotFound::what() const throw()
{
	return "Form not found";
}

Intern::~Intern()
{
    std::cout << "Intern dtor is called" << std::endl;
}