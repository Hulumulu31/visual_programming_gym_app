#ifndef VISIT_H
#define VISIT_H

#include <QDateTime>

class Visit {
public:
    Visit();
    Visit(int id, int userId, const QDateTime& dateTime);

    int getId() const;
    int getUserId() const;
    QDateTime getDateTime() const;

    void setId(int id);
    void setUserId(int userId);
    void setDateTime(const QDateTime& dateTime);

private:
    int m_id;
    int m_userId;
    QDateTime m_dateTime;
};

#endif // VISIT_H