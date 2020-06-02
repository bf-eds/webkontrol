//
// Created by human on 02.06.2020.
//

#include <cmath>
#include "stats.h"

double Stats::Mean()
{
    return mean_;
}

double Stats::Variance()
{
    return (num_ > 1) ? sum_ / ((double) num_ - 1.0) : 0.0;
}

double Stats::SampleVariance()
{
    return sqrt(Variance());
}

void Stats::Add(double x)
{
    double delta;
    double delta_n;

    num_++;
    delta = x - mean_;
    delta_n = delta / (double) num_;
    mean_ += delta_n;
    sum_ += delta * delta_n * ((double) num_ - 1);
}
