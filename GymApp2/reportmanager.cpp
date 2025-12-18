#include "reportmanager.h"
#include <QString>
#include <QList>
#include <QDate>

ReportManager::ReportManager() {}

QString ReportManager::generateAttendanceReport(const QList<Visit>& visits) const {
    int totalVisits = calculateTotalVisits(visits);
    int visitsToday = calculateVisitsForDate(visits, QDate::currentDate());
    int visitsThisWeek = calculateVisitsForWeek(visits);
    int visitsThisMonth = calculateVisitsForMonth(visits);
    
    QString report = QString("Отчет по посещаемости:\n");
    report += QString("Общее количество посещений: %1\n").arg(totalVisits);
    report += QString("Посещений сегодня: %1\n").arg(visitsToday);
    report += QString("Посещений на этой неделе: %1\n").arg(visitsThisWeek);
    report += QString("Посещений в этом месяце: %1\n").arg(visitsThisMonth);
    return report;
}

QString ReportManager::generateRevenueReport(const QList<Membership>& memberships, const QList<TrainerService>& services) const {
    double totalMembershipRevenue = calculateTotalRevenue(memberships);
    double totalServiceRevenue = calculateTotalRevenue(services);
    double totalRevenue = totalMembershipRevenue + totalServiceRevenue;
    
    double revenueThisMonthMemberships = calculateRevenueForMonth(memberships);
    double revenueThisMonthServices = calculateRevenueForMonth(services);
    double revenueThisMonth = revenueThisMonthMemberships + revenueThisMonthServices;
    
    double revenueThisYearMemberships = calculateRevenueForYear(memberships);
    double revenueThisYearServices = calculateRevenueForYear(services);
    double revenueThisYear = revenueThisYearMemberships + revenueThisYearServices;
    
    QString report = QString("Отчет по доходам:\n");
    report += QString("Общий доход: %1 руб.\n").arg(totalRevenue, 0, 'f', 2);
    report += QString("Доход от абонементов: %1 руб.\n").arg(totalMembershipRevenue, 0, 'f', 2);
    report += QString("Доход от тренерских услуг: %1 руб.\n").arg(totalServiceRevenue, 0, 'f', 2);
    report += QString("Доход в этом месяце: %1 руб.\n").arg(revenueThisMonth, 0, 'f', 2);
    report += QString("Доход от абонементов в этом месяце: %1 руб.\n").arg(revenueThisMonthMemberships, 0, 'f', 2);
    report += QString("Доход от тренерских услуг в этом месяце: %1 руб.\n").arg(revenueThisMonthServices, 0, 'f', 2);
    report += QString("Доход в этом году: %1 руб.\n").arg(revenueThisYear, 0, 'f', 2);
    report += QString("Доход от абонементов в этом году: %1 руб.\n").arg(revenueThisYearMemberships, 0, 'f', 2);
    report += QString("Доход от тренерских услуг в этом году: %1 руб.\n").arg(revenueThisYearServices, 0, 'f', 2);
    return report;
}

QString ReportManager::generateRevenueReportForDate(const QList<Membership>& memberships, const QList<TrainerService>& services, const QDate& date) const {
    double totalMembershipRevenue = calculateTotalRevenue(memberships);
    double totalServiceRevenue = calculateTotalRevenue(services);
    double totalRevenue = totalMembershipRevenue + totalServiceRevenue;
    
    double revenueThisMonthMemberships = calculateRevenueForMonth(memberships, date);
    double revenueThisMonthServices = calculateRevenueForMonth(services, date);
    double revenueThisMonth = revenueThisMonthMemberships + revenueThisMonthServices;
    
    double revenueThisYearMemberships = calculateRevenueForYear(memberships, date);
    double revenueThisYearServices = calculateRevenueForYear(services, date);
    double revenueThisYear = revenueThisYearMemberships + revenueThisYearServices;
    
    QString report = QString("Отчет по доходам:\n");
    report += QString("Общий доход: %1 руб.\n").arg(totalRevenue, 0, 'f', 2);
    report += QString("Доход от абонементов: %1 руб.\n").arg(totalMembershipRevenue, 0, 'f', 2);
    report += QString("Доход от тренерских услуг: %1 руб.\n").arg(totalServiceRevenue, 0, 'f', 2);
    report += QString("Доход в этом месяце: %1 руб.\n").arg(revenueThisMonth, 0, 'f', 2);
    report += QString("Доход от абонементов в этом месяце: %1 руб.\n").arg(revenueThisMonthMemberships, 0, 'f', 2);
    report += QString("Доход от тренерских услуг в этом месяце: %1 руб.\n").arg(revenueThisMonthServices, 0, 'f', 2);
    report += QString("Доход в этом году: %1 руб.\n").arg(revenueThisYear, 0, 'f', 2);
    report += QString("Доход от абонементов в этом году: %1 руб.\n").arg(revenueThisYearMemberships, 0, 'f', 2);
    report += QString("Доход от тренерских услуг в этом году: %1 руб.\n").arg(revenueThisYearServices, 0, 'f', 2);
    return report;
}

QString ReportManager::generateRevenueReport(const QList<Membership>& memberships) const {
    double totalRevenue = calculateTotalRevenue(memberships);
    double revenueThisMonth = calculateRevenueForMonth(memberships);
    double revenueThisYear = calculateRevenueForYear(memberships);
    
    QString report = QString("Отчет по доходам:\n");
    report += QString("Общий доход: %1 руб.\n").arg(totalRevenue, 0, 'f', 2);
    report += QString("Доход в этом месяце: %1 руб.\n").arg(revenueThisMonth, 0, 'f', 2);
    report += QString("Доход в этом году: %1 руб.\n").arg(revenueThisYear, 0, 'f', 2);
    return report;
}

int ReportManager::calculateTotalVisits(const QList<Visit>& visits) const {
    return visits.size();
}

int ReportManager::calculateVisitsForDate(const QList<Visit>& visits, const QDate& date) const {
    int count = 0;
    for (const auto& visit : visits) {
        if (visit.getDateTime().date() == date) {
            count++;
        }
    }
    return count;
}

int ReportManager::calculateVisitsForWeek(const QList<Visit>& visits) const {
    int count = 0;
    QDate currentDate = QDate::currentDate();
    QDate weekAgo = currentDate.addDays(-7);
    
    for (const auto& visit : visits) {
        QDate visitDate = visit.getDateTime().date();
        if (visitDate >= weekAgo && visitDate <= currentDate) {
            count++;
        }
    }
    return count;
}

int ReportManager::calculateVisitsForMonth(const QList<Visit>& visits) const {
    int count = 0;
    QDate currentDate = QDate::currentDate();
    QDate monthAgo = currentDate.addMonths(-1);
    
    for (const auto& visit : visits) {
        QDate visitDate = visit.getDateTime().date();
        if (visitDate >= monthAgo && visitDate <= currentDate) {
            count++;
        }
    }
    return count;
}

double ReportManager::calculateTotalRevenue(const QList<Membership>& memberships) const {
    double total = 0.0;
    for (const auto& membership : memberships) {
        total += membership.getCost();
    }
    return total;
}

double ReportManager::calculateTotalRevenue(const QList<Membership>& memberships, const QList<TrainerService>& services) const {
    double totalMembershipRevenue = calculateTotalRevenue(memberships);
    double totalServiceRevenue = calculateTotalRevenue(services);
    return totalMembershipRevenue + totalServiceRevenue;
}

double ReportManager::calculateTotalRevenue(const QList<TrainerService>& services) const {
    double total = 0.0;
    for (const auto& service : services) {
        total += service.getCost();
    }
    return total;
}

double ReportManager::calculateRevenueForMonth(const QList<Membership>& memberships) const {
    double total = 0.0;
    QDate currentDate = QDate::currentDate();
    QDate monthAgo = currentDate.addMonths(-1);
    
    for (const auto& membership : memberships) {
        QDate startDate = membership.getStartDate();
        if (startDate >= monthAgo && startDate <= currentDate) {
            total += membership.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForMonth(const QList<Membership>& memberships, const QList<TrainerService>& services) const {
    double totalMembershipRevenue = calculateRevenueForMonth(memberships);
    double totalServiceRevenue = calculateRevenueForMonth(services);
    return totalMembershipRevenue + totalServiceRevenue;
}

double ReportManager::calculateRevenueForMonth(const QList<TrainerService>& services) const {
    double total = 0.0;
    QDate currentDate = QDate::currentDate();
    QDate monthAgo = currentDate.addMonths(-1);
    
    for (const auto& service : services) {
        QDate startDate = service.getStartDate();
        if (startDate >= monthAgo && startDate <= currentDate) {
            total += service.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForMonth(const QList<Membership>& memberships, const QDate& date) const {
    double total = 0.0;
    QDate monthStart = QDate(date.year(), date.month(), 1);
    QDate monthEnd = monthStart.addMonths(1).addDays(-1);
    
    for (const auto& membership : memberships) {
        QDate startDate = membership.getStartDate();
        if (startDate >= monthStart && startDate <= monthEnd) {
            total += membership.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForMonth(const QList<TrainerService>& services, const QDate& date) const {
    double total = 0.0;
    QDate monthStart = QDate(date.year(), date.month(), 1);
    QDate monthEnd = monthStart.addMonths(1).addDays(-1);
    
    for (const auto& service : services) {
        QDate startDate = service.getStartDate();
        if (startDate >= monthStart && startDate <= monthEnd) {
            total += service.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForYear(const QList<Membership>& memberships, const QDate& date) const {
    double total = 0.0;
    QDate yearStart = QDate(date.year(), 1, 1);
    QDate yearEnd = QDate(date.year(), 12, 31);
    
    for (const auto& membership : memberships) {
        QDate startDate = membership.getStartDate();
        if (startDate >= yearStart && startDate <= yearEnd) {
            total += membership.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForYear(const QList<TrainerService>& services, const QDate& date) const {
    double total = 0.0;
    QDate yearStart = QDate(date.year(), 1, 1);
    QDate yearEnd = QDate(date.year(), 12, 31);
    
    for (const auto& service : services) {
        QDate startDate = service.getStartDate();
        if (startDate >= yearStart && startDate <= yearEnd) {
            total += service.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForYear(const QList<Membership>& memberships) const {
    double total = 0.0;
    QDate currentDate = QDate::currentDate();
    QDate yearAgo = currentDate.addYears(-1);
    
    for (const auto& membership : memberships) {
        QDate startDate = membership.getStartDate();
        if (startDate >= yearAgo && startDate <= currentDate) {
            total += membership.getCost();
        }
    }
    return total;
}

double ReportManager::calculateRevenueForYear(const QList<Membership>& memberships, const QList<TrainerService>& services) const {
    double totalMembershipRevenue = calculateRevenueForYear(memberships);
    double totalServiceRevenue = calculateRevenueForYear(services);
    return totalMembershipRevenue + totalServiceRevenue;
}

double ReportManager::calculateRevenueForYear(const QList<TrainerService>& services) const {
    double total = 0.0;
    QDate currentDate = QDate::currentDate();
    QDate yearAgo = currentDate.addYears(-1);
    
    for (const auto& service : services) {
        QDate startDate = service.getStartDate();
        if (startDate >= yearAgo && startDate <= currentDate) {
            total += service.getCost();
        }
    }
    return total;
}