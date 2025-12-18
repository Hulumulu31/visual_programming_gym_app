#include "datamanager.h"
#include <QDebug>

const QString DataManager::USERS_FILE = "users.json";
const QString DataManager::MEMBERSHIPS_FILE = "memberships.json";
const QString DataManager::VISITS_FILE = "visits.json";
const QString DataManager::TRAINER_SERVICES_FILE = "trainerservices.json";

DataManager::DataManager(QObject* parent) : QObject(parent) {
}

bool DataManager::loadData() {
    m_users = m_jsonManager.loadUsers(USERS_FILE);
    m_memberships = m_jsonManager.loadMemberships(MEMBERSHIPS_FILE);
    m_visits = m_jsonManager.loadVisits(VISITS_FILE);
    m_trainerServices = m_jsonManager.loadTrainerServices(TRAINER_SERVICES_FILE);
    
    return true; // In a real implementation, you would check if loading was successful
}

bool DataManager::saveData() {
    bool usersSaved = m_jsonManager.saveUsers(m_users, USERS_FILE);
    bool membershipsSaved = m_jsonManager.saveMemberships(m_memberships, MEMBERSHIPS_FILE);
    bool visitsSaved = m_jsonManager.saveVisits(m_visits, VISITS_FILE);
    bool trainerServicesSaved = m_jsonManager.saveTrainerServices(m_trainerServices, TRAINER_SERVICES_FILE);
    
    // For debugging: print if saving failed
    if (!usersSaved) qDebug() << "Failed to save users to" << USERS_FILE;
    if (!membershipsSaved) qDebug() << "Failed to save memberships to" << MEMBERSHIPS_FILE;
    if (!visitsSaved) qDebug() << "Failed to save visits to" << VISITS_FILE;
    if (!trainerServicesSaved) qDebug() << "Failed to save trainer services to" << TRAINER_SERVICES_FILE;
    
    return usersSaved && membershipsSaved && visitsSaved && trainerServicesSaved;
}

QList<User>& DataManager::getUsers() {
    return m_users;
}

QList<Membership>& DataManager::getMemberships() {
    return m_memberships;
}

QList<Visit>& DataManager::getVisits() {
    return m_visits;
}

QList<TrainerService>& DataManager::getTrainerServices() {
    return m_trainerServices;
}

QList<User> DataManager::getUsers() const {
    return m_users;
}

QList<Membership> DataManager::getMemberships() const {
    return m_memberships;
}

QList<Visit> DataManager::getVisits() const {
    return m_visits;
}

QList<TrainerService> DataManager::getTrainerServices() const {
    return m_trainerServices;
}

void DataManager::setUsers(const QList<User>& users) {
    m_users = users;
    m_jsonManager.saveUsers(m_users, USERS_FILE);
}

void DataManager::setMemberships(const QList<Membership>& memberships) {
    m_memberships = memberships;
    m_jsonManager.saveMemberships(m_memberships, MEMBERSHIPS_FILE);
}

void DataManager::setVisits(const QList<Visit>& visits) {
    m_visits = visits;
    m_jsonManager.saveVisits(m_visits, VISITS_FILE);
}

void DataManager::setTrainerServices(const QList<TrainerService>& services) {
    m_trainerServices = services;
    m_jsonManager.saveTrainerServices(m_trainerServices, TRAINER_SERVICES_FILE);
}

void DataManager::addUser(const User& user) {
    // Find the highest ID in the current list to generate a new unique ID
    int newId = 1;
    for (const auto& u : m_users) {
        if (u.getId() >= newId) {
            newId = u.getId() + 1;
        }
    }
    
    // Create a copy of the user with the new ID
    User newUser = user;
    newUser.setId(newId);
    
    m_users.append(newUser);
    qDebug() << "Adding user:" << newUser.getName() << "with ID:" << newUser.getId() << "Total users now:" << m_users.size();
    bool saveResult = m_jsonManager.saveUsers(m_users, USERS_FILE);
    qDebug() << "Save users result:" << saveResult << "to file:" << USERS_FILE;
    if (!saveResult) {
        qDebug() << "Error details: Failed to save users to file";
    }
}

void DataManager::addMembership(const Membership& membership) {
    // Find the highest ID in the current list to generate a new unique ID
    int newId = 1;
    for (const auto& m : m_memberships) {
        if (m.getId() >= newId) {
            newId = m.getId() + 1;
        }
    }
    
    // Create a copy of the membership with the new ID
    Membership newMembership = membership;
    newMembership.setId(newId);
    
    m_memberships.append(newMembership);
    m_jsonManager.saveMemberships(m_memberships, MEMBERSHIPS_FILE);
}

void DataManager::addVisit(const Visit& visit) {
    // Find the highest ID in the current list to generate a new unique ID
    int newId = 1;
    for (const auto& v : m_visits) {
        if (v.getId() >= newId) {
            newId = v.getId() + 1;
        }
    }
    
    // Create a copy of the visit with the new ID
    Visit newVisit = visit;
    newVisit.setId(newId);
    
    m_visits.append(newVisit);
    m_jsonManager.saveVisits(m_visits, VISITS_FILE);
}

void DataManager::addTrainerService(const TrainerService& service) {
    // Find the highest ID in the current list to generate a new unique ID
    int newId = 1;
    for (const auto& s : m_trainerServices) {
        if (s.getId() >= newId) {
            newId = s.getId() + 1;
        }
    }
    
    // Create a copy of the service with the new ID
    TrainerService newService = service;
    newService.setId(newId);
    
    m_trainerServices.append(newService);
    m_jsonManager.saveTrainerServices(m_trainerServices, TRAINER_SERVICES_FILE);
}