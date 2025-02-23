#pragma once

#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);
public:
    const std::string& getName() const;
    const std::string& getTitle() const;
    void    setTitle(const std::string& title);
    Warlock(std::string  name, std::string title);
    // ~Warlock();
    void introduce() const;
};