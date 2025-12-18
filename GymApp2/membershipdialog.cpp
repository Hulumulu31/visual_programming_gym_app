#include "membershipdialog.h"
#include "ui_membershipdialog.h"
#include <QMessageBox>

MembershipDialog::MembershipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MembershipDialog),
    m_editMode(false)
{
    ui->setupUi(this);
    setWindowTitle("Добавить абонемент");
}

MembershipDialog::MembershipDialog(const Membership& membership, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MembershipDialog),
    m_membership(membership),
    m_editMode(true)
{
    ui->setupUi(this);
    setWindowTitle("Редактировать абонемент");
    
    // Fill the form with existing membership data
    ui->durationComboBox->setCurrentIndex(static_cast<int>(m_membership.getDuration()));
    ui->accessComboBox->setCurrentIndex(static_cast<int>(m_membership.getAccess()));
    ui->timeComboBox->setCurrentIndex(static_cast<int>(m_membership.getTime()));
    ui->startDateEdit->setDate(m_membership.getStartDate());
    ui->costLineEdit->setText(QString::number(m_membership.getCost()));
}

MembershipDialog::~MembershipDialog()
{
    delete ui;
}

void MembershipDialog::on_buttonBox_accepted()
{
    // Validate input
    bool ok;
    double cost = ui->costLineEdit->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Неверная стоимость");
        return; // Don't accept the dialog if validation fails
    }
    
    // Additional validation - check if cost is positive
    if (cost <= 0) {
        QMessageBox::warning(this, "Ошибка", "Стоимость должна быть положительной");
        return; // Don't accept the dialog if validation fails
    }
    
    // Create or update membership
    MembershipDuration duration = static_cast<MembershipDuration>(ui->durationComboBox->currentIndex());
    MembershipAccess access = static_cast<MembershipAccess>(ui->accessComboBox->currentIndex());
    MembershipTime time = static_cast<MembershipTime>(ui->timeComboBox->currentIndex());
    
    if (m_editMode) {
        // Update existing membership
        m_membership.setDuration(duration);
        m_membership.setAccess(access);
        m_membership.setTime(time);
        m_membership.setStartDate(ui->startDateEdit->date());
        m_membership.setCost(cost);
    } else {
        // Create new membership
        // The ID will be set by the data manager when adding to the list
        m_membership = Membership(0, 0, duration, access, time, ui->startDateEdit->date(), cost);
    }
    
    // Accept the dialog to return QDialog::Accepted
    accept();
}

void MembershipDialog::on_buttonBox_rejected()
{
    // Close the dialog with QDialog::Rejected result
    reject();
}

Membership MembershipDialog::getMembership() const
{
    return m_membership;
}