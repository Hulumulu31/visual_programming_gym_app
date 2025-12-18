#include "searchfiltermanager.h"
#include <QString>
#include <QDate>
#include <QStringList>

SearchFilterManager::SearchFilterManager(QObject* parent) : QObject(parent) {}

// Search functions
QList<User> SearchFilterManager::searchUsers(const QList<User>& users, const QString& query) {
    QList<User> result;
    for (const auto& user : users) {
        if (matchesUser(user, query)) {
            result.append(user);
        }
    }
    return result;
}

QList<Membership> SearchFilterManager::searchMemberships(const QList<Membership>& memberships, const QString& field, const QString& query) {
    QList<Membership> result;
    for (const auto& membership : memberships) {
        if (matchesMembership(membership, field, query)) {
            result.append(membership);
        }
    }
    return result;
}

QList<Visit> SearchFilterManager::searchVisits(const QList<Visit>& visits, const QDate& date) {
    QList<Visit> result;
    for (const auto& visit : visits) {
        if (matchesVisit(visit, date)) {
            result.append(visit);
        }
    }
    return result;
}

QList<TrainerService> SearchFilterManager::searchTrainerServices(const QList<TrainerService>& services, const QString& field, const QString& query) {
    QList<TrainerService> result;
    for (const auto& service : services) {
        if (matchesTrainerService(service, field, query)) {
            result.append(service);
        }
    }
    return result;
}

QList<TrainerService> SearchFilterManager::filterTrainerServicesByType(const QList<TrainerService>& services, const QString& type) {
    QList<TrainerService> result;
    for (const auto& service : services) {
        if (matchesTrainerServiceType(service, type)) {
            result.append(service);
        }
    }
    return result;
}

// Filter functions
QList<Membership> SearchFilterManager::filterMembershipsByStatus(const QList<Membership>& memberships, MembershipStatus status) {
    QList<Membership> result;
    for (const auto& membership : memberships) {
        if (membership.getStatus() == status) {
            result.append(membership);
        }
    }
    return result;
}

QList<Membership> SearchFilterManager::filterMembershipsByDuration(const QList<Membership>& memberships, MembershipDuration duration) {
    QList<Membership> result;
    for (const auto& membership : memberships) {
        if (membership.getDuration() == duration) {
            result.append(membership);
        }
    }
    return result;
}

QList<Visit> SearchFilterManager::filterVisitsByUser(const QList<Visit>& visits, int userId) {
    QList<Visit> result;
    for (const auto& visit : visits) {
        if (visit.getUserId() == userId) {
            result.append(visit);
        }
    }
    return result;
}

// Helper functions
bool SearchFilterManager::matchesUser(const User& user, const QString& query) {
    return user.getName().contains(query, Qt::CaseInsensitive) ||
           user.getEmail().contains(query, Qt::CaseInsensitive);
}

bool SearchFilterManager::matchesMembership(const Membership& membership, const QString& field, const QString& query) {
    if (field == "Тип") {
        QString durationStr;
        switch (membership.getDuration()) {
            case MembershipDuration::Single:
                durationStr = "Разовый";
                break;
            case MembershipDuration::Monthly:
                durationStr = "Месячный";
                break;
            case MembershipDuration::HalfYear:
                durationStr = "Полугодовой";
                break;
            case MembershipDuration::Yearly:
                durationStr = "Годовой";
                break;
            case MembershipDuration::TwoYears:
                durationStr = "Двухгодовой";
                break;
        }
        return durationStr.contains(query, Qt::CaseInsensitive);
    } else if (field == "Клиент") {
        // Search by client name instead of ID
        // This requires access to the user data, which we don't have here
        // We'll return false for now and handle client search in the AdminWindow
        return false;
    } else if (field == "Дата") {
        return membership.getStartDate().toString("yyyy-MM-dd").contains(query) ||
               membership.getEndDate().toString("yyyy-MM-dd").contains(query);
    }
    // Add more fields as needed
    return false;
}

bool SearchFilterManager::matchesVisit(const Visit& visit, const QDate& date) {
    return visit.getDateTime().date() == date;
}

bool SearchFilterManager::matchesTrainerService(const TrainerService& service, const QString& field, const QString& query) {
    if (field == "Тип") {
        QString typeStr;
        switch (service.getServiceType()) {
            case TrainerServiceType::Gym:
                typeStr = "Тренажерный зал";
                break;
            case TrainerServiceType::GroupTraining:
                typeStr = "Групповые тренировки";
                break;
            case TrainerServiceType::Swimming:
                typeStr = "Плавание";
                break;
            case TrainerServiceType::Boxing:
                typeStr = "Бокс";
                break;
        }
        return typeStr.contains(query, Qt::CaseInsensitive);
    } else if (field == "Клиент") {
        // Search by client name instead of ID
        // This requires access to the user data, which we don't have here
        // We'll return false for now and handle client search in the AdminWindow
        return false;
    }
    // Add more fields as needed
    return false;
}

bool SearchFilterManager::matchesTrainerServiceType(const TrainerService& service, const QString& type) {
    QString typeStr;
    switch (service.getServiceType()) {
        case TrainerServiceType::Gym:
            typeStr = "Тренажерный зал";
            break;
        case TrainerServiceType::GroupTraining:
            typeStr = "Групповые тренировки";
            break;
        case TrainerServiceType::Swimming:
            typeStr = "Плавание";
            break;
        case TrainerServiceType::Boxing:
            typeStr = "Бокс";
            break;
    }
    return typeStr == type || type == "Все";
}
