#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
private:
    std::string	_target;
    // PresidentialPardonForm();
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;

};

