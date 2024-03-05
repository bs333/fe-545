#ifndef StatisticsVariance_h
#define StatisticsVariance_h

#include <vector>
#include "MCStatistics.h"

class StatisticsVariance : public StatisticsMC {
public:
    StatisticsVariance();
    virtual void DumpOneResult(double result) override;
    virtual std::vector<std::vector<double>> GetResultsSoFar() const override;
    virtual StatisticsMC* clone() const override;

private:
    double RunningSum;
    double SquaredSum;
    unsigned long PathsDone;
};

#endif /* StatisticsVariance_h */