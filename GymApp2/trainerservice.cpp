#include "trainerservice.h"
#include <QDate>

TrainerService::TrainerService() : m_id(0), m_userId(0), m_serviceType(TrainerServiceType::Gym), 
                                   m_duration(TrainerServiceDuration::Single), m_cost(0.0), 
                                   m_status(TrainerServiceStatus::Active) {}

TrainerService::TrainerService(int id, int userId, TrainerServiceType serviceType, 
                               TrainerServiceDuration duration, QDate startDate, double cost)
    : m_id(id), m_userId(userId), m_serviceType(serviceType), m_duration(duration), 
      m_startDate(startDate), m_cost(cost) {
    m_endDate = calculateEndDate();
    m_status = (QDate::currentDate() <= m_endDate) ? TrainerServiceStatus::Active : TrainerServiceStatus::Expired;
}

int TrainerService::getId() const {
    return m_id;
}

int TrainerService::getUserId() const {
    return m_userId;
}

TrainerServiceType TrainerService::getServiceType() const {
    return m_serviceType;
}

TrainerServiceDuration TrainerService::getDuration() const {
    return m_duration;
}

QDate TrainerService::getStartDate() const {
    return m_startDate;
}

QDate TrainerService::getEndDate() const {
    return m_endDate;
}

double TrainerService::getCost() const {
    return m_cost;
}

TrainerServiceStatus TrainerService::getStatus() const {
    return m_status;
}

void TrainerService::setId(int id) {
    m_id = id;
}

void TrainerService::setUserId(int userId) {
    m_userId = userId;
}

void TrainerService::setServiceType(TrainerServiceType serviceType) {
    m_serviceType = serviceType;
}

void TrainerService::setDuration(TrainerServiceDuration duration) {
    m_duration = duration;
    // Update end date based on new duration
    m_endDate = calculateEndDate();
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? TrainerServiceStatus::Active : TrainerServiceStatus::Expired;
}

void TrainerService::setStartDate(const QDate& date) {
    m_startDate = date;
    // Update end date based on new start date and duration
    m_endDate = calculateEndDate();
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? TrainerServiceStatus::Active : TrainerServiceStatus::Expired;
}

void TrainerService::setEndDate(const QDate& date) {
    m_endDate = date;
    // Update status based on the new end date
    m_status = (QDate::currentDate() <= m_endDate) ? TrainerServiceStatus::Active : TrainerServiceStatus::Expired;
}

void TrainerService::setCost(double cost) {
    m_cost = cost;
}

void TrainerService::setStatus(TrainerServiceStatus status) {
    m_status = status;
}

bool TrainerService::isActive() const {
    return m_status == TrainerServiceStatus::Active;
}

QDate TrainerService::calculateEndDate() const {
    QDate endDate = m_startDate;
    
    switch (m_duration) {
        case TrainerServiceDuration::Single:
            endDate = m_startDate.addDays(1); // Extend single service by one day
            break;
        case TrainerServiceDuration::Weekly:
            endDate = m_startDate.addDays(7);
            break;
        case TrainerServiceDuration::Monthly:
            endDate = m_startDate.addMonths(1);
            break;
        case TrainerServiceDuration::HalfYear:
            endDate = m_startDate.addMonths(6);
            break;
        case TrainerServiceDuration::Yearly:
            endDate = m_startDate.addYears(1);
            break;
        case TrainerServiceDuration::TwoYears:
            endDate = m_startDate.addYears(2);
            break;
    }
    
    return endDate;
}