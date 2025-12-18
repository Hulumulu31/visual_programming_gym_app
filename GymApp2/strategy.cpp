#include "strategy.h"

double SingleVisitStrategy::calculateCost(double baseCost) {
    // For single visit, we charge the base cost
    return baseCost;
}

double MonthlyMembershipStrategy::calculateCost(double baseCost) {
    // For monthly membership, we might offer a discount or fixed price
    // For example, let's say monthly is 30 times the single visit but with 10% discount
    return baseCost * 30 * 0.9; // 10% discount for monthly membership
}

MembershipCostCalculator::MembershipCostCalculator(CostCalculationStrategy* strategy)
    : m_strategy(strategy) {}

void MembershipCostCalculator::setStrategy(CostCalculationStrategy* strategy) {
    m_strategy = strategy;
}

double MembershipCostCalculator::calculateCost(double baseCost) {
    return m_strategy->calculateCost(baseCost);
}