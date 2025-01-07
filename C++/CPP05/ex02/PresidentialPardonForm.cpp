#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm()
// {
//     std::cout << "PresidentialPardonForm default ctor is called" << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm ctor with param is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy ctor is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm op= is called" << std::endl;
    if (this != &other)
    {
		AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm dtor is called" << std::endl;
}