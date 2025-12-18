#include "visitdialog.h"
#include "ui_visitdialog.h"
#include <QMessageBox>

VisitDialog::VisitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitDialog),
    m_editMode(false)
{
    ui->setupUi(this);
    setWindowTitle("Добавить посещение");
}

VisitDialog::VisitDialog(const Visit& visit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitDialog),
    m_visit(visit),
    m_editMode(true)
{
    ui->setupUi(this);
    setWindowTitle("Редактировать посещение");
    
    // Fill the form with existing visit data
    ui->userIdLineEdit->setText(QString::number(m_visit.getUserId()));
    ui->dateTimeEdit->setDateTime(m_visit.getDateTime());
}

VisitDialog::~VisitDialog()
{
    delete ui;
}

void VisitDialog::on_buttonBox_accepted()
{
    // Validate input
    bool ok;
    int userId = ui->userIdLineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Неверный ID пользователя");
        return;
    }
    
    // Create or update visit
    if (m_editMode) {
        // Update existing visit
        m_visit.setUserId(userId);
        m_visit.setDateTime(ui->dateTimeEdit->dateTime());
    } else {
        // Create new visit
        int newId = 1; // In a real app, this would be generated properly
        m_visit = Visit(newId, userId, ui->dateTimeEdit->dateTime());
    }
}

Visit VisitDialog::getVisit() const
{
    return m_visit;
}