#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0)
{
    std::cout << "Bureaucrat default ctor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Bureaucrat ctor with params is called" << std::endl;
	_grade = grade;
	if (_grade < HIGHEST_POSSIBLE_GRADE)
		throw GradeTooHighException();
	if (_grade > LOWEST_POSSIBLE_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    std::cout << "Bureaucrat copy ctor is called" << std::endl;
	this->_grade = other._grade;
	// this->_name = other._name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat operator= is called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
		const_cast<std::string&>(this->_name) = other._name;
	}
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return(this->_grade);
}

void    Bureaucrat::decrement_grade()
{
	if (this->_grade + 1 > LOWEST_POSSIBLE_GRADE)
		throw GradeTooLowException();
	this->_grade++;
}

void    Bureaucrat::increment_grade()
{
	if (this->_grade - 1 < HIGHEST_POSSIBLE_GRADE)
		throw GradeTooHighException();
	this->_grade--;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat dtor is called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
