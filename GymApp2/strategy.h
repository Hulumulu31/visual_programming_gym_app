#ifndef STRATEGY_H
#define STRATEGY_H

#include <QObject>
#include "membership.h"

// Strategy interface for calculating membership cost
class CostCalculationStrategy {
public:
    virtual ~CostCalculationStrategy() = default;
    virtual double calculateCost(double baseCost) = 0;
};

// Concrete strategy for single visit membership
class SingleVisitStrategy : public CostCalculationStrategy {
public:
    double calculateCost(double baseCost) override;
};

// Concrete strategy for monthly membership
class MonthlyMembershipStrategy : public CostCalculationStrategy {
public:
    double calculateCost(double baseCost) override;
};

// Context class that uses the strategy
class MembershipCostCalculator {
public:
    MembershipCostCalculator(CostCalculationStrategy* strategy);
    void setStrategy(CostCalculationStrategy* strategy);
    double calculateCost(double baseCost);

private:
    CostCalculationStrategy* m_strategy;
};

#endif // STRATEGY_H