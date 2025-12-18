#include "visitmanager.h"
#include <QDateTime>

VisitManager::VisitManager(QObject* parent) : QObject(parent) {}

void VisitManager::addVisit(const Visit& visit) {
    m_visits.append(visit);
}

QList<Visit> VisitManager::getVisits() const {
    return m_visits;
}

QList<Visit> VisitManager::getVisitsForUser(int userId) const {
    QList<Visit> result;
    for (const auto& visit : m_visits) {
        if (visit.getUserId() == userId) {
            result.append(visit);
        }
    }
    return result;
}

QList<Visit> VisitManager::getVisitsForDateRange(const QDateTime& start, const QDateTime& end) const {
    QList<Visit> result;
    for (const auto& visit : m_visits) {
        if (visit.getDateTime() >= start && visit.getDateTime() <= end) {
            result.append(visit);
        }
    }
    return result;
}

Visit VisitManager::markVisit(int userId) {
    Visit visit(0, userId, QDateTime::currentDateTime());
    addVisit(visit);
    return visit;
}