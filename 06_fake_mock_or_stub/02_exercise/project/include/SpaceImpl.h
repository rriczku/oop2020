//
// Created by student on 12/19/20.
//
#pragma once
#include "Space.h"
class SpaceImpl:public Space{
public:

    void create(unsigned int dimensions) override;
    unsigned int dimensions() const override;

private:
    unsigned int dimensionsCount;
    std::vector<Point> points;

};