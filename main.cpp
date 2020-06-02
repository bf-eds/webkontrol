#include <iostream>
#include <fstream>
#include <set>
#include "stats.h"


int main()
{
    std::string file_name = "../variance_calc.tsv";
    std::set<long long> lines = {1, 100, 1000000, 500000000};
    std::ifstream infile(file_name);

    if (!infile.is_open())
    {
        std::cout << "failed to open " << file_name << std::endl;
    }
    else
    {
        double x;
        long long line = 0;
        Stats stats;

        while (infile >> x)
        {
            line++;
            stats.Add(x);

            if (lines.count(line))
            {
                lines.erase(line);
                std::cout << "Line: " << line << " Value: " << x << " Mean: " << stats.Mean() << " Variance: "
                          << stats.SampleVariance() << std::endl;
            }
        }
    }

    return 0;
}
