#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout  << name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
	return name;
}

const std::string& Warlock::getTitle() const
{
	return title;
}

void    Warlock::setTitle(const std::string& title)
{
	this->title = title;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" <<std::endl;
}

void    Warlock::learnSpell(ASpell* ob)
{
	// vec.push_back(ob);
	spellBook.learnSpell(ob);
}


void    Warlock::forgetSpell(std::string name)
{
	spellBook.forgetSpell(name);
}

void    Warlock::launchSpell(std::string SpellName, ATarget& ob)
{
	ASpell* aspel = spellBook.createSpell(SpellName);
	if (aspel)
		aspel->launch(ob);
}
