#pragma once

#include <utility>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define DESCENDANTS_COUNT 3
class Intern
{
private:
    /* data */
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    AForm* makeForm(const std::string nameForm, const std::string target);
    ~Intern();
};
