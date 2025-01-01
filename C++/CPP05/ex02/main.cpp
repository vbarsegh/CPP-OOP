#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
// {
//     try {
//         ShrubberyCreationForm form("home1");
//         Bureaucrat alice("AxAlisaAlisa", 1);
//         // AForm importantForm("ImportantForm", 40, 20);

//         alice.signForm(form);


//         form.execute(alice);
//         // std::cout << form << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }
// {
//      try {
//         ShrubberyCreationForm form("home2");
//         Bureaucrat alice("balalala", 149);
//         // AForm importantForm("ImportantForm", 40, 20);

//         alice.signForm(form);


//         form.execute(alice);
//         // std::cout << form << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }
// {
//      try {
//         ShrubberyCreationForm form("home2");
//         Bureaucrat alice("balalala", 149);
//         // AForm importantForm("ImportantForm", 40, 20);

//         alice.signForm(form);


//         // form.execute(alice);//esi anun enq cherez Bureaucrat alice-i ognutyamb
//         alice.executeForm(form);//dusa galu catch(const AForm::FormNotSignedException& e)-ic
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
    // std::cout << std::endl;
// }
// {
//      try {
//         ShrubberyCreationForm form("home2");
//         Bureaucrat alice("balalala", 139);
//         // AForm importantForm("ImportantForm", 40, 20);

//         alice.signForm(form);


//         // form.execute(alice);//esi anun enq cherez Bureaucrat alice-i ognutyamb
//         alice.executeForm(form);//dusa galu catch(const AForm::GradeTooLowException& e)-ic
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
    // std::cout << std::endl;
// }
{
 try {
        Bureaucrat john("John", 40); // Уровень достаточно высокий
        RobotomyRequestForm form("Alice");

        form.beSigned(john); // Подписание формы
        john.executeForm(form); // Попытка выполнить форму
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}
{
    std::cout << "\033[0;32m" << "Testing PresidentialPardonForm execution with sufficient grade" << "\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur Dent");
		Bureaucrat zaphod("Zaphod", 1); // High grade, sufficient for execution
		zaphod.signForm(form);
		zaphod.executeForm(form); // Should succeed
}
   return 0;
}
