#ifndef MEMBERSHIPDIALOG_H
#define MEMBERSHIPDIALOG_H

#include <QDialog>
#include "membership.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MembershipDialog; }
QT_END_NAMESPACE

class MembershipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MembershipDialog(QWidget *parent = nullptr);
    explicit MembershipDialog(const Membership& membership, QWidget *parent = nullptr);
    ~MembershipDialog();

    Membership getMembership() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::MembershipDialog *ui;
    Membership m_membership;
    bool m_editMode;
};

#endif // MEMBERSHIPDIALOG_H