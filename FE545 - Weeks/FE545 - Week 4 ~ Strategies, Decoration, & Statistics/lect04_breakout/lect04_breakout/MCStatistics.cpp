//
//  MCStatisitcs.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//
#include <cmath>
#include "MCStatistics.h"
using namespace std;

StatisticsMean::StatisticsMean(): RunningSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

// called only once per simulation
vector<vector<double>> StatisticsMean::GetResultsSoFar()const
{
    vector<vector<double>> Results(1);
    
    Results[0].resize(1); // first vector length = 1
    Results[0][0]=RunningSum/PathsDone; // store mean

    return Results;
}

StatisticsMC* StatisticsMean::clone()const
{
    return new StatisticsMean(*this);
}

// Second moment of the sample
StatisticsVariance::StatisticsVariance(): SquaredSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsVariance::DumpOneResult(double result)
{
    PathsDone++;
    //TODO
}

// called only once per simulation
vector<vector<double>> StatisticsVariance::GetResultsSoFar()const
{
    vector<vector<double>> Results(1);
    
    Results[0].resize(1); // first vector length = 1
    Results[0][0]=SquaredSum/PathsDone; // store mean

    return Results;
}

StatisticsMC* StatisticsVariance::clone()const
{
    return new StatisticsVariance(*this);
}



