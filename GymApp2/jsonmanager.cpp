#include "jsonmanager.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QTextStream>

JsonManager::JsonManager() {}

// User operations
bool JsonManager::saveUsers(const QList<User>& users, const QString& filename) {
    QJsonArray usersArray;
    for (const auto& user : users) {
        usersArray.append(userToJson(user));
    }
    
    QJsonObject rootObject;
    rootObject["users"] = usersArray;
    
    QJsonDocument doc(rootObject);
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    qint64 bytesWritten = file.write(doc.toJson());
    file.close();
    return bytesWritten != -1;
}

QList<User> JsonManager::loadUsers(const QString& filename) {
    QList<User> users;
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Если файл не существует, создаем его с пустым массивом
        if (!file.exists()) {
            QJsonArray usersArray;
            QJsonObject rootObject;
            rootObject["users"] = usersArray;
            QJsonDocument doc(rootObject);
            
            QFile newFile(filename);
            if (newFile.open(QIODevice::WriteOnly)) {
                newFile.write(doc.toJson());
                newFile.close();
            }
        }
        return users; // Возвращаем пустой список, если не удалось открыть файл
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject rootObject = doc.object();
    QJsonArray usersArray = rootObject["users"].toArray();
    
    for (const auto& value : usersArray) {
        QJsonObject userObject = value.toObject();
        users.append(jsonToUser(userObject));
    }
    
    return users;
}

// Membership operations
bool JsonManager::saveMemberships(const QList<Membership>& memberships, const QString& filename) {
    QJsonArray membershipsArray;
    for (const auto& membership : memberships) {
        membershipsArray.append(membershipToJson(membership));
    }
    
    QJsonObject rootObject;
    rootObject["memberships"] = membershipsArray;
    
    QJsonDocument doc(rootObject);
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    qint64 bytesWritten = file.write(doc.toJson());
    file.close();
    return bytesWritten != -1;
}

QList<Membership> JsonManager::loadMemberships(const QString& filename) {
    QList<Membership> memberships;
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Если файл не существует, создаем его с пустым массивом
        if (!file.exists()) {
            QJsonArray membershipsArray;
            QJsonObject rootObject;
            rootObject["memberships"] = membershipsArray;
            QJsonDocument doc(rootObject);
            
            QFile newFile(filename);
            if (newFile.open(QIODevice::WriteOnly)) {
                newFile.write(doc.toJson());
                newFile.close();
            }
        }
        return memberships; // Возвращаем пустой список, если не удалось открыть файл
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject rootObject = doc.object();
    QJsonArray membershipsArray = rootObject["memberships"].toArray();
    
    for (const auto& value : membershipsArray) {
        QJsonObject membershipObject = value.toObject();
        memberships.append(jsonToMembership(membershipObject));
    }
    
    return memberships;
}

// Visit operations
bool JsonManager::saveVisits(const QList<Visit>& visits, const QString& filename) {
    QJsonArray visitsArray;
    for (const auto& visit : visits) {
        visitsArray.append(visitToJson(visit));
    }
    
    QJsonObject rootObject;
    rootObject["visits"] = visitsArray;
    
    QJsonDocument doc(rootObject);
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    qint64 bytesWritten = file.write(doc.toJson());
    file.close();
    return bytesWritten != -1;
}

QList<Visit> JsonManager::loadVisits(const QString& filename) {
    QList<Visit> visits;
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Если файл не существует, создаем его с пустым массивом
        if (!file.exists()) {
            QJsonArray visitsArray;
            QJsonObject rootObject;
            rootObject["visits"] = visitsArray;
            QJsonDocument doc(rootObject);
            
            QFile newFile(filename);
            if (newFile.open(QIODevice::WriteOnly)) {
                newFile.write(doc.toJson());
                newFile.close();
            }
        }
        return visits; // Возвращаем пустой список, если не удалось открыть файл
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject rootObject = doc.object();
    QJsonArray visitsArray = rootObject["visits"].toArray();
    
    for (const auto& value : visitsArray) {
        QJsonObject visitObject = value.toObject();
        visits.append(jsonToVisit(visitObject));
    }
    
    return visits;
}

// Trainer service operations
bool JsonManager::saveTrainerServices(const QList<TrainerService>& services, const QString& filename) {
    QJsonArray servicesArray;
    for (const auto& service : services) {
        servicesArray.append(trainerServiceToJson(service));
    }
    
    QJsonObject rootObject;
    rootObject["trainerServices"] = servicesArray;
    
    QJsonDocument doc(rootObject);
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    qint64 bytesWritten = file.write(doc.toJson());
    file.close();
    return bytesWritten != -1;
}

QList<TrainerService> JsonManager::loadTrainerServices(const QString& filename) {
    QList<TrainerService> services;
    
    // Создаем директории при необходимости
    QFileInfo fileInfo(filename);
    QDir dir;
    if (!dir.exists(fileInfo.absolutePath())) {
        dir.mkpath(fileInfo.absolutePath());
    }
    
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Если файл не существует, создаем его с пустым массивом
        if (!file.exists()) {
            QJsonArray servicesArray;
            QJsonObject rootObject;
            rootObject["trainerServices"] = servicesArray;
            QJsonDocument doc(rootObject);
            
            QFile newFile(filename);
            if (newFile.open(QIODevice::WriteOnly)) {
                newFile.write(doc.toJson());
                newFile.close();
            }
        }
        return services; // Возвращаем пустой список, если не удалось открыть файл
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject rootObject = doc.object();
    QJsonArray servicesArray = rootObject["trainerServices"].toArray();
    
    for (const auto& value : servicesArray) {
        QJsonObject serviceObject = value.toObject();
        services.append(jsonToTrainerService(serviceObject));
    }
    
    return services;
}

// Helper methods
QJsonObject JsonManager::userToJson(const User& user) {
    QJsonObject obj;
    obj["id"] = user.getId();
    obj["name"] = user.getName();
    obj["email"] = user.getEmail();
    obj["password"] = user.getPassword(); // Store password in JSON
    obj["type"] = static_cast<int>(user.getUserType());
    return obj;
}

User JsonManager::jsonToUser(const QJsonObject& json) {
    int id = json["id"].toInt();
    QString name = json["name"].toString();
    QString email = json["email"].toString();
    QString password = json["password"].toString(); // Load password from JSON
    UserType type = static_cast<UserType>(json["type"].toInt());
    return User(id, name, email, password, type);
}

QJsonObject JsonManager::membershipToJson(const Membership& membership) {
    QJsonObject obj;
    obj["id"] = membership.getId();
    obj["userId"] = membership.getUserId();
    obj["duration"] = static_cast<int>(membership.getDuration());
    obj["access"] = static_cast<int>(membership.getAccess());
    obj["time"] = static_cast<int>(membership.getTime());
    obj["startDate"] = membership.getStartDate().toString("yyyy-MM-dd");
    obj["endDate"] = membership.getEndDate().toString("yyyy-MM-dd");
    obj["cost"] = membership.getCost();
    obj["status"] = static_cast<int>(membership.getStatus());
    return obj;
}

Membership JsonManager::jsonToMembership(const QJsonObject& json) {
    int id = json["id"].toInt();
    int userId = json["userId"].toInt();
    MembershipDuration duration = static_cast<MembershipDuration>(json["duration"].toInt());
    MembershipAccess access = static_cast<MembershipAccess>(json["access"].toInt());
    MembershipTime time = static_cast<MembershipTime>(json["time"].toInt());
    QDate startDate = QDate::fromString(json["startDate"].toString(), "yyyy-MM-dd");
    double cost = json["cost"].toDouble();
    MembershipStatus status = static_cast<MembershipStatus>(json["status"].toInt());
    Membership membership(id, userId, duration, access, time, startDate, cost);
    membership.setStatus(status);
    return membership;
}

QJsonObject JsonManager::visitToJson(const Visit& visit) {
    QJsonObject obj;
    obj["id"] = visit.getId();
    obj["userId"] = visit.getUserId();
    obj["dateTime"] = visit.getDateTime().toString("yyyy-MM-dd hh:mm:ss");
    return obj;
}

Visit JsonManager::jsonToVisit(const QJsonObject& json) {
    int id = json["id"].toInt();
    int userId = json["userId"].toInt();
    QDateTime dateTime = QDateTime::fromString(json["dateTime"].toString(), "yyyy-MM-dd hh:mm:ss");
    return Visit(id, userId, dateTime);
}

QJsonObject JsonManager::trainerServiceToJson(const TrainerService& service) {
    QJsonObject obj;
    obj["id"] = service.getId();
    obj["userId"] = service.getUserId();
    obj["serviceType"] = static_cast<int>(service.getServiceType());
    obj["duration"] = static_cast<int>(service.getDuration());
    obj["startDate"] = service.getStartDate().toString("yyyy-MM-dd");
    obj["endDate"] = service.getEndDate().toString("yyyy-MM-dd");
    obj["cost"] = service.getCost();
    obj["status"] = static_cast<int>(service.getStatus());
    return obj;
}

TrainerService JsonManager::jsonToTrainerService(const QJsonObject& json) {
    int id = json["id"].toInt();
    int userId = json["userId"].toInt();
    TrainerServiceType serviceType = static_cast<TrainerServiceType>(json["serviceType"].toInt());
    TrainerServiceDuration duration = static_cast<TrainerServiceDuration>(json["duration"].toInt());
    QDate startDate = QDate::fromString(json["startDate"].toString(), "yyyy-MM-dd");
    double cost = json["cost"].toDouble();
    TrainerServiceStatus status = static_cast<TrainerServiceStatus>(json["status"].toInt());
    TrainerService service(id, userId, serviceType, duration, startDate, cost);
    service.setStatus(status);
    return service;
}
