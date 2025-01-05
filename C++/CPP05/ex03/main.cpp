#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
{
    try{
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
		// (void)rrf;
    }
    catch(const Intern::FormNotFound& e1){
        std::cout << "Exception: " << e1.what() << std::endl;
    }
    std::cout << std::endl;
}
{
    try{
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("presidential pardon", "Arsen Wenger");
        delete rrf;
    }
    catch(const Intern::FormNotFound& e1){
        std::cout << "Exception: " << e1.what() << std::endl;
    }
    std::cout << std::endl;
}

{
    try{
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Piskin");
        delete rrf;
    }
    catch(const Intern::FormNotFound& e1){
        std::cout << "Exception: " << e1.what() << std::endl;
    }
    std::cout << std::endl;
}
{
    try{
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("Wrong name", "EXCEPTIONNNN!");
        delete rrf;
    }
    catch(const Intern::FormNotFound& e1){
        std::cout << "Exception: " << e1.what() << std::endl;
    }
    std::cout << std::endl;
}
   return 0;
}
