#pragma once
#include "ATarget.hpp"
#include <vector>
class TargetGenerator
{
private:
    std::vector<ATarget*> vec;
    TargetGenerator(const TargetGenerator& other);
    TargetGenerator& operator=(const TargetGenerator& other);
public:
    TargetGenerator();
    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);
    ~TargetGenerator();
};