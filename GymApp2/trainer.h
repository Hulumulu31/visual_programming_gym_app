#ifndef TRAINER_H
#define TRAINER_H

#include <QString>

class Trainer {
public:
    Trainer();
    Trainer(int id, const QString& name, const QString& specialization);

    int getId() const;
    QString getName() const;
    QString getSpecialization() const;

    void setId(int id);
    void setName(const QString& name);
    void setSpecialization(const QString& specialization);

private:
    int m_id;
    QString m_name;
    QString m_specialization;
};

#endif // TRAINER_H