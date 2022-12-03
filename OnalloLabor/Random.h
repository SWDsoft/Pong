#pragma once

#include <iostream>
#include <array>
#include <random>
class Random
{

private:

    static std::shared_ptr < Random > instance;

public:
    int getRandom(int from, int to);


    static std::shared_ptr < Random > getInstance();

};