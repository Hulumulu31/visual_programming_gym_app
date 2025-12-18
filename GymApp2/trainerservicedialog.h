#ifndef TRAINERSERVICEDIALOG_H
#define TRAINERSERVICEDIALOG_H

#include <QDialog>
#include "trainerservice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TrainerServiceDialog; }
QT_END_NAMESPACE

class TrainerServiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrainerServiceDialog(QWidget *parent = nullptr);
    explicit TrainerServiceDialog(const TrainerService& service, QWidget *parent = nullptr);
    ~TrainerServiceDialog();

    TrainerService getTrainerService() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::TrainerServiceDialog *ui;
    TrainerService m_service;
    bool m_editMode;
};

#endif // TRAINERSERVICEDIALOG_H