#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include <QList>
#include <QString>
#include <QDate>
#include "visit.h"
#include "membership.h"
#include "trainerservice.h"

class ReportManager {
public:
    ReportManager();

    // Generate attendance report
    QString generateAttendanceReport(const QList<Visit>& visits) const;
    
    // Generate revenue report
    QString generateRevenueReport(const QList<Membership>& memberships, const QList<TrainerService>& services) const;
    QString generateRevenueReport(const QList<Membership>& memberships) const; // For backward compatibility
    // Generate revenue report for a specific date
    QString generateRevenueReportForDate(const QList<Membership>& memberships, const QList<TrainerService>& services, const QDate& date) const;

private:
    // Helper methods for report generation
    int calculateTotalVisits(const QList<Visit>& visits) const;
    int calculateVisitsForDate(const QList<Visit>& visits, const QDate& date) const;
    int calculateVisitsForWeek(const QList<Visit>& visits) const;
    int calculateVisitsForMonth(const QList<Visit>& visits) const;
    double calculateTotalRevenue(const QList<Membership>& memberships) const;
    double calculateTotalRevenue(const QList<Membership>& memberships, const QList<TrainerService>& services) const;
    double calculateTotalRevenue(const QList<TrainerService>& services) const;
    double calculateRevenueForMonth(const QList<Membership>& memberships) const;
    double calculateRevenueForMonth(const QList<Membership>& memberships, const QList<TrainerService>& services) const;
    double calculateRevenueForMonth(const QList<TrainerService>& services) const;
    double calculateRevenueForYear(const QList<Membership>& memberships) const;
    double calculateRevenueForYear(const QList<Membership>& memberships, const QList<TrainerService>& services) const;
    double calculateRevenueForYear(const QList<TrainerService>& services) const;
    // Helper methods for date-specific reports
    double calculateRevenueForMonth(const QList<Membership>& memberships, const QDate& date) const;
    double calculateRevenueForMonth(const QList<TrainerService>& services, const QDate& date) const;
    double calculateRevenueForYear(const QList<Membership>& memberships, const QDate& date) const;
    double calculateRevenueForYear(const QList<TrainerService>& services, const QDate& date) const;
};

#endif // REPORTMANAGER_H