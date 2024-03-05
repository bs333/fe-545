#include "StatisticsVariance.h"
#include <cmath>

StatisticsVariance::StatisticsVariance() : RunningSum(0.0), SquaredSum(0.0), PathsDone(0) {}

void StatisticsVariance::DumpOneResult(double result) {
    PathsDone++;
    RunningSum += result;
    SquaredSum += result * result;
}

std::vector<std::vector<double>> StatisticsVariance::GetResultsSoFar() const {
    std::vector<std::vector<double>> Results(1);
    double mean = RunningSum / PathsDone;
    double variance = (SquaredSum - RunningSum * RunningSum / PathsDone) / (PathsDone - 1);
    
    Results[0].resize(2); // Adjusted to store both mean and variance
    Results[0][0] = mean;
    Results[0][1] = variance;

    return Results;
}

StatisticsMC* StatisticsVariance::clone() const {
    return new StatisticsVariance(*this);
}
