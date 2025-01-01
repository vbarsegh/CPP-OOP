#include "AForm.hpp"


AForm::AForm() : _name("default"), _grade_to_sign(77), _grade_to_execute(77)
{
    std::cout << "Form default ctor is called" << std::endl;
    _is_signed = false;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _grade_to_sign(gradeSign), _grade_to_execute(gradeExecute), _is_signed(false)
{
    std::cout << "AForm ctor with params is called" << std::endl;
    check_grade(_grade_to_sign);
    check_grade(_grade_to_execute);
}

AForm::AForm(const AForm& other) : _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
    std::cout << "AForm copy ctor is called" << std::endl;
    _is_signed = other._is_signed;
    check_grade(_grade_to_sign);
    check_grade(_grade_to_execute);
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm op= is called" << std::endl;
    if (this != &other)
    {
        // const_cast<std::string&>(_name) = other._name;
        _is_signed = other._is_signed;
        // static_cast<int>(_grade_to_sign) = other._grade_to_sign;
        // static_cast<int>(_grade_to_execute) = other._grade_to_execute;
    }
    return (*this);
}



const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed!");
}

const char* AForm::FileCanNotOpenException::what() const throw()
{
	return ("File could not be opened!");
}

std::string AForm::get_name() const
{
    return (_name);
}

int AForm::get_grade_to_sign() const
{
    return (_grade_to_sign);
}

int AForm::get_grade_to_execute() const
{
    return (_grade_to_execute);
}

bool    AForm::get_is_signed() const
{
    return (_is_signed);
}

AForm::~AForm()
{
    std::cout << "AForm dtor is called" << std::endl;
}

void	AForm::check_grade(int grade)
{
    if (grade < AFORM_HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > AFORM_LOWEST_GRADE)
        throw GradeTooLowException();
}

void    AForm::beSigned(const Bureaucrat& brcrt)
{
    if (this->_is_signed == true)
        return ;
    if (brcrt.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

void	AForm::CheckRequirements(Bureaucrat const & executor) const
{
    if (this->get_is_signed() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->get_grade_to_execute())
		throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& out, const AForm& form)
{
      out << form.get_name() << ", form grade to sign " << form.get_grade_to_sign() << ",form grade to execute " << form.get_grade_to_execute() << ",is signed:" << (form.get_is_signed() ? "yes" : "no");
    return out;
}