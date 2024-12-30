#include "Form.hpp"


Form::Form() : _name("default"), _grade_to_sign(77), _grade_to_execute(77)
{
    std::cout << "Form default ctor is called" << std::endl;
    _is_signed = false;
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _grade_to_sign(gradeSign), _grade_to_execute(gradeExecute), _is_signed(false)
{
    std::cout << "Form ctor with params is called" << std::endl;
    check_grade(_grade_to_sign);
    check_grade(_grade_to_execute);
}

Form::Form(const Form& other) : _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
    std::cout << "Form copy ctor is called" << std::endl;
    _is_signed = other._is_signed;
    check_grade(_grade_to_sign);
    check_grade(_grade_to_execute);
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form op= is called" << std::endl;
    if (this != &other)
    {
        // const_cast<std::string&>(_name) = other._name;
        _is_signed = other._is_signed;
        // static_cast<int>(_grade_to_sign) = other._grade_to_sign;
        // static_cast<int>(_grade_to_execute) = other._grade_to_execute;
    }
    return (*this);
}

void	Form::check_grade(int grade)
{
    if (grade < FORM_HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > FORM_LOWEST_GRADE)
        throw GradeTooLowException();
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::string Form::get_name() const
{
    return (_name);
}

int Form::get_grade_to_sign() const
{
    return (_grade_to_sign);
}

int Form::get_grade_to_execute() const
{
    return (_grade_to_execute);
}

bool    Form::get_is_signed() const
{
    return (_is_signed);
}

Form::~Form()
{
    std::cout << "Form dtor is called" << std::endl;
}

void    Form::beSigned(const Bureaucrat& brcrt)
{
    if (this->_is_signed == true)
        return ;
    if (brcrt.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
      out << form.get_name() << ", form grade to sign " << form.get_grade_to_sign() << ",form grade to execute " << form.get_grade_to_execute() << ",is signed:" << (form.get_is_signed() ? "yes" : "no");
    return out;
}