#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}


TargetGenerator::~TargetGenerator(){
    int i = 0;
    while (i < vec.size())
    {
        delete vec[i];
        i++;
    }
    vec.clear();
}

void TargetGenerator::learnTargetType(ATarget* ob)
{
    int i = 0;
    while (i < vec.size())
    {
        if (vec[i]->getType() == ob->getType())
            return ;
        i++;
    }
    vec.push_back(ob->clone());
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
    int i = 0;
    while (i < vec.size())
    {
        if (vec[i]->getType() == targetType)
        {
            delete vec[i];
            vec.erase(vec.begin() + i);
            return ;
        }
        i++;
    }
}

ATarget* TargetGenerator::createTarget(std::string const &targetType)
{
    int i = 0;
    while (i < vec.size())
    {
        if (vec[i]->getType() == targetType)
        {
            return vec[i]->clone();
        }
        i++;
    }
    return (NULL);
}