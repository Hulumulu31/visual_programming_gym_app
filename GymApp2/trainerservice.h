#ifndef TRAINERSERVICE_H
#define TRAINERSERVICE_H

#include <QString>
#include <QDate>
#include <QObject>

enum class TrainerServiceType {
    Gym,
    GroupTraining,
    Swimming,
    Boxing
};

enum class TrainerServiceDuration {
    Single,
    Weekly,
    Monthly,
    HalfYear,
    Yearly,
    TwoYears
};

enum class TrainerServiceStatus {
    Active,
    Expired
};

class TrainerService {
public:
    TrainerService();
    TrainerService(int id, int userId, TrainerServiceType serviceType, 
                   TrainerServiceDuration duration, QDate startDate, double cost);

    int getId() const;
    int getUserId() const;
    TrainerServiceType getServiceType() const;
    TrainerServiceDuration getDuration() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    double getCost() const;
    TrainerServiceStatus getStatus() const;

    void setId(int id);
    void setUserId(int userId);
    void setServiceType(TrainerServiceType serviceType);
    void setDuration(TrainerServiceDuration duration);
    void setStartDate(const QDate& date);
    void setEndDate(const QDate& date);
    void setCost(double cost);
    void setStatus(TrainerServiceStatus status);

    bool isActive() const;

private:
    int m_id;
    int m_userId;
    TrainerServiceType m_serviceType;
    TrainerServiceDuration m_duration;
    QDate m_startDate;
    QDate m_endDate;
    double m_cost;
    TrainerServiceStatus m_status;
    
    // Helper function to calculate end date based on duration
    QDate calculateEndDate() const;
};

#endif // TRAINERSERVICE_H