#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <QString>
#include <QDate>
#include <QObject>

enum class MembershipDuration {
    Single,
    Monthly,
    HalfYear,
    Yearly,
    TwoYears
};

enum class MembershipAccess {
    GymOnly,
    GroupTraining,
    Pool,
    Boxing,
    FullAccess
};

enum class MembershipTime {
    Morning,
    Daytime,
    Evening,
    FullDay
};

enum class MembershipStatus {
    Active,
    Expired
};

class Membership {
public:
    Membership();
    Membership(int id, int userId, MembershipDuration duration, MembershipAccess access, MembershipTime time, QDate startDate, double cost);

    int getId() const;
    int getUserId() const;
    MembershipDuration getDuration() const;
    MembershipAccess getAccess() const;
    MembershipTime getTime() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    double getCost() const;
    MembershipStatus getStatus() const;

    void setId(int id);
    void setUserId(int userId);
    void setDuration(MembershipDuration duration);
    void setAccess(MembershipAccess access);
    void setTime(MembershipTime time);
    void setStartDate(const QDate& date);
    void setEndDate(const QDate& date);
    void setCost(double cost);
    void setStatus(MembershipStatus status);

    bool isActive() const;

private:
    int m_id;
    int m_userId;
    MembershipDuration m_duration;
    MembershipAccess m_access;
    MembershipTime m_time;
    QDate m_startDate;
    QDate m_endDate;
    double m_cost;
    MembershipStatus m_status;
    
    // Helper function to calculate end date based on duration
    QDate calculateEndDate() const;
};

#endif // MEMBERSHIP_H