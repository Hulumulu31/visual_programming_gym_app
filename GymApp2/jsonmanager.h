#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QList>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include "user.h"
#include "membership.h"
#include "visit.h"
#include "trainerservice.h"

class JsonManager {
public:
    JsonManager();

    // User operations
    bool saveUsers(const QList<User>& users, const QString& filename);
    QList<User> loadUsers(const QString& filename);

    // Membership operations
    bool saveMemberships(const QList<Membership>& memberships, const QString& filename);
    QList<Membership> loadMemberships(const QString& filename);

    // Visit operations
    bool saveVisits(const QList<Visit>& visits, const QString& filename);
    QList<Visit> loadVisits(const QString& filename);

    // Trainer service operations
    bool saveTrainerServices(const QList<TrainerService>& services, const QString& filename);
    QList<TrainerService> loadTrainerServices(const QString& filename);

private:
    // Helper methods to convert objects to/from JSON
    QJsonObject userToJson(const User& user);
    User jsonToUser(const QJsonObject& json);
    
    QJsonObject membershipToJson(const Membership& membership);
    Membership jsonToMembership(const QJsonObject& json);
    
    QJsonObject visitToJson(const Visit& visit);
    Visit jsonToVisit(const QJsonObject& json);
    
    QJsonObject trainerServiceToJson(const TrainerService& service);
    TrainerService jsonToTrainerService(const QJsonObject& json);
    
};

#endif // JSONMANAGER_H