#include "trainer.h"

Trainer::Trainer() : m_id(0) {}

Trainer::Trainer(int id, const QString& name, const QString& specialization)
    : m_id(id), m_name(name), m_specialization(specialization) {}

int Trainer::getId() const {
    return m_id;
}

QString Trainer::getName() const {
    return m_name;
}

QString Trainer::getSpecialization() const {
    return m_specialization;
}

void Trainer::setId(int id) {
    m_id = id;
}

void Trainer::setName(const QString& name) {
    m_name = name;
}

void Trainer::setSpecialization(const QString& specialization) {
    m_specialization = specialization;
}