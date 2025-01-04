#pragma once

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
    std::string	_target;
    // RobotomyRequestForm();
public:
    static AForm* createObjInHeap(const std::string& target);

    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;

};

