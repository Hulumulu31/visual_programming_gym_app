#ifndef SEARCHFILTERMANAGER_H
#define SEARCHFILTERMANAGER_H

#include <QObject>
#include <QList>
#include <QDate>
#include "user.h"
#include "membership.h"
#include "visit.h"
#include "trainerservice.h"

class SearchFilterManager : public QObject {
    Q_OBJECT

public:
    explicit SearchFilterManager(QObject* parent = nullptr);

    // Search functions
    QList<User> searchUsers(const QList<User>& users, const QString& query);
    QList<Membership> searchMemberships(const QList<Membership>& memberships, const QString& field, const QString& query);
    QList<Visit> searchVisits(const QList<Visit>& visits, const QDate& date);
    QList<TrainerService> searchTrainerServices(const QList<TrainerService>& services, const QString& field, const QString& query);
    
    // Filter functions
    QList<Membership> filterMembershipsByStatus(const QList<Membership>& memberships, MembershipStatus status);
    QList<Membership> filterMembershipsByDuration(const QList<Membership>& memberships, MembershipDuration duration);
    QList<Visit> filterVisitsByUser(const QList<Visit>& visits, int userId);
    QList<TrainerService> filterTrainerServicesByType(const QList<TrainerService>& services, const QString& type);

private:
    // Helper functions for searching
    bool matchesUser(const User& user, const QString& query);
    bool matchesMembership(const Membership& membership, const QString& field, const QString& query);
    bool matchesVisit(const Visit& visit, const QDate& date);
    bool matchesTrainerService(const TrainerService& service, const QString& field, const QString& query);
    bool matchesTrainerServiceType(const TrainerService& service, const QString& type);
};

#endif // SEARCHFILTERMANAGER_H