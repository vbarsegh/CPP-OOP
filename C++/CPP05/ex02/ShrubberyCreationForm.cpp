#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm()
// {
//     std::cout << "ShrubberyCreationForm default ctor is called" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm ctor with param is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy ctor is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm op= is called" << std::endl;
    if (this != &other)
    {
		AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	CheckRequirements(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileCanNotOpenException();
	file << "    ###\n"
     << "   #o###\n"
     << " #####o###\n"
     << "#o#\\#|#/###\n"
     << " ###\\|/#o#\n"
     << "  # }|{  #\n"
     << "    }|{\n";
	file.close();
	if (file.fail()) {
        throw std::runtime_error("Failed to close the file properly.");
    }
	std::cout << "ShrubberyCreationForm executed successfully by " 
          << executor.getName() << std::endl;

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm dtor is called" << std::endl;
}