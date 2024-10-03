#include "ClapTrap.hpp"

int main()
{
    // ClapTrap obj("Philanthropist");
    // obj.attack("Manukyan");
    // Создаем объект ClapTrap по умолчанию
    ClapTrap robot1;
    
    // Создаем объект ClapTrap с именем
    ClapTrap robot2("RoboWarrior");

    // Атака
    std::cout << "\n=== Attack Test ===" << std::endl;
    robot1.attack("Enemy1");
    robot2.attack("Enemy2");

    // Получение урона
    std::cout << "\n=== Take Damage Test ===" << std::endl;
    robot1.takeDamage(5); // Удар на 5 единиц
    robot1.takeDamage(20); // Попытка нанести слишком большой урон

std::cout << "\n=== Attack Test ===" << std::endl;
    robot1.attack("Enemy1");
    robot2.attack("Enemy2");

    // Восстановление здоровья
    std::cout << "\n=== Repair Test ===" << std::endl;
    robot1.beRepaired(5); // Восстановление на 5 единиц
    robot2.beRepaired(100); // Восстановление с превышением

    // Пограничные случаи
    std::cout << "\n=== Edge Cases ===" << std::endl;
    robot2.takeDamage(10); // Урон, равный текущим очкам здоровья
    robot2.takeDamage(1000); // Смертельный урон
    robot2.beRepaired(50); // Попытка восстановиться с нулевым здоровьем

    // Проверка окончания энергии
    std::cout << "\n=== Energy Test ===" << std::endl;
    ClapTrap robot3("EnergyLessBot");
    for (int i = 0; i < 12; ++i) {
        robot3.attack("Target"); // Пробуем атаковать больше раз, чем у нас энергии
    }

    return 0;

}