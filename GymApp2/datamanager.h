#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QList>
#include "user.h"
#include "membership.h"
#include "visit.h"
#include "trainerservice.h"
#include "jsonmanager.h"

class DataManager : public QObject {
    Q_OBJECT

public:
    explicit DataManager(QObject* parent = nullptr);
    virtual ~DataManager() = default; // Adding virtual destructor to fix vtable error

    // Load all data from JSON files
    bool loadData();
    
    // Save all data to JSON files
    bool saveData();
    
    // Getters for the data lists
    QList<User>& getUsers();
    QList<Membership>& getMemberships();
    QList<Visit>& getVisits();
    QList<TrainerService>& getTrainerServices();
    
    // Const versions of getters
    QList<User> getUsers() const;
    QList<Membership> getMemberships() const;
    QList<Visit> getVisits() const;
    QList<TrainerService> getTrainerServices() const;

    // Setters for the data lists
    void setUsers(const QList<User>& users);
    void setMemberships(const QList<Membership>& memberships);
    void setVisits(const QList<Visit>& visits);
    void setTrainerServices(const QList<TrainerService>& services);

    // Methods to add new entities and save to file
    void addUser(const User& user);
    void addMembership(const Membership& membership);
    void addVisit(const Visit& visit);
    void addTrainerService(const TrainerService& service);

private:
    QList<User> m_users;
    QList<Membership> m_memberships;
    QList<Visit> m_visits;
    QList<TrainerService> m_trainerServices;
    JsonManager m_jsonManager;
    
    // File paths for data storage
    static const QString USERS_FILE;
    static const QString MEMBERSHIPS_FILE;
    static const QString VISITS_FILE;
    static const QString TRAINER_SERVICES_FILE;
};

#endif // DATAMANAGER_H