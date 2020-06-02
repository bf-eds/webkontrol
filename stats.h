//
// Created by human on 02.06.2020.
//

#pragma once


class Stats
{
public:
    Stats() = default;
    ~Stats() = default;
    double Mean();
    double SampleVariance();
    void Add(double x);

private:
    double Variance();

    long long num_ = 0;
    double mean_ = 0.0;
    double sum_ = 0.0;
};


