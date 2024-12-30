#pragma once

#define HIGHEST_POSSIBLE_GRADE 1
#define LOWEST_POSSIBLE_GRADE 150
#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;
    Bureaucrat();
public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	struct GradeTooHighException :public std::exception
	{
	// public:
	const char* what() const throw();
	};
	class GradeTooLowException :public std::exception
	{
	public:
		const char* what() const throw();
	};
	/////getters
	std::string getName() const;
	int 		getGrade() const;

	void	setGrade(int grade);
	void    increment_grade();
	void    decrement_grade();
	void	signForm(Form& form);//?
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);