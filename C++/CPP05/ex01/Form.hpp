#pragma once

#define FORM_LOWEST_GRADE 150
#define FORM_HIGHEST_GRADE 1
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_is_signed;
	Form();


public:
	Form(const std::string& name, const int grade_to_sign, const int grade_to_execute);//subjectgum asuma vor stexcveluc en bool-@ false dnem
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	// exception classes
	class GradeTooHighException: public std::exception//why public???
	{
		public:
			const char* what() const throw();
	};
	struct GradeTooLowException: public std::exception
	{
		// public:
			const char* what() const throw();
	};
/////////////getters/////////////
	std::string get_name() const;
	int			get_grade_to_sign() const;
	int			get_grade_to_execute() const;
	bool		get_is_signed() const;

	void	check_grade(int);
	void	beSigned(const Bureaucrat& brcrt);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

