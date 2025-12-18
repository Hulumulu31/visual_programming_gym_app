#ifndef VISITDIALOG_H
#define VISITDIALOG_H

#include <QDialog>
#include "visit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VisitDialog; }
QT_END_NAMESPACE

class VisitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VisitDialog(QWidget *parent = nullptr);
    explicit VisitDialog(const Visit& visit, QWidget *parent = nullptr);
    ~VisitDialog();

    Visit getVisit() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::VisitDialog *ui;
    Visit m_visit;
    bool m_editMode;
};

#endif // VISITDIALOG_H