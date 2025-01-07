#pragma once

#define AFORM_LOWEST_GRADE 150
#define AFORM_HIGHEST_GRADE 1
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
private:
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_is_signed;
	AForm();
public:
	/////Orthodox
	AForm(const std::string& name, const int grade_to_sign, const int grade_to_execute);//subjectgum asuma vor stexcveluc en bool-@ false dnem
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
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
	class FormNotSignedException : public std::exception { public: const char* what() const throw(); };
	class FileCanNotOpenException : public std::exception { public: const char* what() const throw(); }; 
/////////////getters/////////////
	std::string get_name() const;
	int			get_grade_to_sign() const;
	int			get_grade_to_execute() const;
	bool		get_is_signed() const;

	void	check_grade(int);
	void	beSigned(const Bureaucrat& brcrt);
	// void	CheckRequirements(Bureaucrat const & executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);