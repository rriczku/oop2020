//
// Created by student on 12/19/20.
//
#include <Time.h>
#pragma once
class TimeImpl:public Time
{
public:

    void create(bool endless) override;
    long long now() const override;

    void flow() override;

private:
    long long year;
    bool endless;
};