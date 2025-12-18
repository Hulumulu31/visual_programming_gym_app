#ifndef VISITMANAGER_H
#define VISITMANAGER_H

#include <QObject>
#include <QList>
#include <QDateTime>
#include "visit.h"

class VisitManager : public QObject {
    Q_OBJECT

public:
    explicit VisitManager(QObject* parent = nullptr);

    // Add a new visit
    void addVisit(const Visit& visit);
    
    // Get all visits
    QList<Visit> getVisits() const;
    
    // Get visits for a specific user
    QList<Visit> getVisitsForUser(int userId) const;
    
    // Get visits within a date range
    QList<Visit> getVisitsForDateRange(const QDateTime& start, const QDateTime& end) const;
    
    // Mark a visit for a user (create a new visit with current date/time)
    Visit markVisit(int userId);

private:
    QList<Visit> m_visits;
};

#endif // VISITMANAGER_H