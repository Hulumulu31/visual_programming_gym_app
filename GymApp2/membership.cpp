#include "membership.h"
#include <QDate>

Membership::Membership() : m_id(0), m_userId(0), m_duration(MembershipDuration::Single), m_access(MembershipAccess::GymOnly), m_time(MembershipTime::FullDay), m_cost(0.0), m_status(MembershipStatus::Active) {}

Membership::Membership(int id, int userId, MembershipDuration duration, MembershipAccess access, MembershipTime time, QDate startDate, double cost)
    : m_id(id), m_userId(userId), m_duration(duration), m_access(access), m_time(time), m_startDate(startDate), m_cost(cost) {
    m_endDate = calculateEndDate();
    m_status = (QDate::currentDate() <= m_endDate) ? MembershipStatus::Active : MembershipStatus::Expired;
}

int Membership::getId() const {
    return m_id;
}

int Membership::getUserId() const {
    return m_userId;
}

MembershipDuration Membership::getDuration() const {
    return m_duration;
}

MembershipAccess Membership::getAccess() const {
    return m_access;
}

MembershipTime Membership::getTime() const {
    return m_time;
}

QDate Membership::getStartDate() const {
    return m_startDate;
}

QDate Membership::getEndDate() const {
    return m_endDate;
}

double Membership::getCost() const {
    return m_cost;
}

MembershipStatus Membership::getStatus() const {
    return m_status;
}

void Membership::setId(int id) {
    m_id = id;
}

void Membership::setUserId(int userId) {
    m_userId = userId;
}

void Membership::setDuration(MembershipDuration duration) {
    m_duration = duration;
    // Update end date based on new duration
    m_endDate = calculateEndDate();
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? MembershipStatus::Active : MembershipStatus::Expired;
}

void Membership::setAccess(MembershipAccess access) {
    m_access = access;
}

void Membership::setTime(MembershipTime time) {
    m_time = time;
}

void Membership::setStartDate(const QDate& date) {
    m_startDate = date;
    // Update end date based on new start date and duration
    m_endDate = calculateEndDate();
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? MembershipStatus::Active : MembershipStatus::Expired;
}

void Membership::setEndDate(const QDate& date) {
    m_endDate = date;
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? MembershipStatus::Active : MembershipStatus::Expired;
}

void Membership::setCost(double cost) {
    m_cost = cost;
}

void Membership::setStatus(MembershipStatus status) {
    m_status = status;
}

bool Membership::isActive() const {
    return m_status == MembershipStatus::Active;
}

QDate Membership::calculateEndDate() const {
    QDate endDate = m_startDate;
    
    switch (m_duration) {
        case MembershipDuration::Single:
            endDate = m_startDate.addDays(1); // Extend single membership by one day
            break;
        case MembershipDuration::Monthly:
            endDate = m_startDate.addMonths(1);
            break;
        case MembershipDuration::HalfYear:
            endDate = m_startDate.addMonths(6);
            break;
        case MembershipDuration::Yearly:
            endDate = m_startDate.addYears(1);
            break;
        case MembershipDuration::TwoYears:
            endDate = m_startDate.addYears(2);
            break;
    }
    
    return endDate;
}