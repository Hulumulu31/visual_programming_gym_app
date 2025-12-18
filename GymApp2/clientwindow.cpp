#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QMessageBox>

ClientWindow::ClientWindow(const User& user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
    , m_user(user)
{
    ui->setupUi(this);
    setupUI();
    checkMembershipExpiration();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::setupUI() {
    // Load data from DataManager
    m_dataManager.loadData();
    populateProfileTab();
    populateMembershipTab();
    populateAvailableMembershipsTab();
    populateTrainerServicesTab();
    populateVisitsTab();
}

void ClientWindow::populateProfileTab() {
    // Fill profile information
    ui->nameValueLabel->setText(m_user.getName());
    ui->emailValueLabel->setText(m_user.getEmail());
}

void ClientWindow::populateMembershipTab() {
    // Clear the table
    ui->membershipTable->setRowCount(0);
    
    // Load memberships from the data manager
    QList<Membership> allMemberships = m_dataManager.getMemberships();
    
    // Add memberships for this user
    for (const auto& membership : allMemberships) {
        if (membership.getUserId() == m_user.getId()) {
            int row = ui->membershipTable->rowCount();
            ui->membershipTable->insertRow(row);
            
            QString durationStr;
            switch (membership.getDuration()) {
                case MembershipDuration::Single:
                    durationStr = "Разовый";
                    break;
                case MembershipDuration::Monthly:
                    durationStr = "Месячный";
                    break;
                case MembershipDuration::HalfYear:
                    durationStr = "Полугодовой";
                    break;
                case MembershipDuration::Yearly:
                    durationStr = "Годовой";
                    break;
                case MembershipDuration::TwoYears:
                    durationStr = "Двухгодовой";
                    break;
            }
            
            ui->membershipTable->setItem(row, 0, new QTableWidgetItem(durationStr));
            ui->membershipTable->setItem(row, 1, new QTableWidgetItem(membership.getStartDate().toString("dd.MM.yyyy")));
            ui->membershipTable->setItem(row, 2, new QTableWidgetItem(membership.getEndDate().toString("dd.MM.yyyy")));
            ui->membershipTable->setItem(row, 3, new QTableWidgetItem(QString::number(membership.getCost())));
            ui->membershipTable->setItem(row, 4, new QTableWidgetItem(
                membership.getStatus() == MembershipStatus::Active ? "Активен" : "Истек"));
        }
    }
}

void ClientWindow::populateAvailableMembershipsTab() {
    // Get the available memberships table from the UI (assuming we'll add this in the .ui file)
    QTableWidget* availableMembershipsTable = ui->availableMembershipsTable;
    if (!availableMembershipsTable) return; // Skip if the table doesn't exist in UI yet
    
    // Clear the table
    availableMembershipsTable->setRowCount(0);
    
    // Load memberships from the data manager
    QList<Membership> allMemberships = m_dataManager.getMemberships();
    
    // Add memberships that are not assigned to any user (userId == 0) - these are templates
    for (const auto& membership : allMemberships) {
        if (membership.getUserId() == 0) { // Assuming unassigned memberships have userId = 0
            int row = availableMembershipsTable->rowCount();
            availableMembershipsTable->insertRow(row);
            
            QString durationStr;
            switch (membership.getDuration()) {
                case MembershipDuration::Single:
                    durationStr = "Разовый";
                    break;
                case MembershipDuration::Monthly:
                    durationStr = "Месячный";
                    break;
                case MembershipDuration::HalfYear:
                    durationStr = "Полугодовой";
                    break;
                case MembershipDuration::Yearly:
                    durationStr = "Годовой";
                    break;
                case MembershipDuration::TwoYears:
                    durationStr = "Двухгодовой";
                    break;
            }
            
            availableMembershipsTable->setItem(row, 0, new QTableWidgetItem(durationStr));
            availableMembershipsTable->setItem(row, 1, new QTableWidgetItem(membership.getStartDate().toString("dd.MM.yyyy")));
            availableMembershipsTable->setItem(row, 2, new QTableWidgetItem(membership.getEndDate().toString("dd.MM.yyyy")));
            availableMembershipsTable->setItem(row, 3, new QTableWidgetItem(QString::number(membership.getCost())));
        }
    }
}

void ClientWindow::populateTrainerServicesTab() {
    // Clear the table
    ui->trainerServicesTable->setRowCount(0);
    
    // Load trainer services from the data manager
    QList<TrainerService> allTrainerServices = m_dataManager.getTrainerServices();
    
    // Add trainer services for this user
    for (const auto& service : allTrainerServices) {
        if (service.getUserId() == m_user.getId()) {
            int row = ui->trainerServicesTable->rowCount();
            ui->trainerServicesTable->insertRow(row);
            
            QString typeStr;
            switch (service.getServiceType()) {
                case TrainerServiceType::Gym:
                    typeStr = "Тренажерный зал";
                    break;
                case TrainerServiceType::GroupTraining:
                    typeStr = "Групповые тренировки";
                    break;
                case TrainerServiceType::Swimming:
                    typeStr = "Плавание";
                    break;
                case TrainerServiceType::Boxing:
                    typeStr = "Бокс";
                    break;
            }
            
            QString durationStr;
            switch (service.getDuration()) {
                case TrainerServiceDuration::Single:
                    durationStr = "Разовая";
                    break;
                case TrainerServiceDuration::Weekly:
                    durationStr = "Неделя";
                    break;
                case TrainerServiceDuration::Monthly:
                    durationStr = "Месяц";
                    break;
                case TrainerServiceDuration::HalfYear:
                    durationStr = "Полгода";
                    break;
                case TrainerServiceDuration::Yearly:
                    durationStr = "Год";
                    break;
                case TrainerServiceDuration::TwoYears:
                    durationStr = "Два года";
                    break;
            }
            
            ui->trainerServicesTable->setItem(row, 0, new QTableWidgetItem(typeStr));
            ui->trainerServicesTable->setItem(row, 1, new QTableWidgetItem(durationStr));
            ui->trainerServicesTable->setItem(row, 2, new QTableWidgetItem(service.getStartDate().toString("dd.MM.yyyy")));
            ui->trainerServicesTable->setItem(row, 3, new QTableWidgetItem(service.getEndDate().toString("dd.MM.yyyy")));
            ui->trainerServicesTable->setItem(row, 4, new QTableWidgetItem(QString::number(service.getCost())));
            ui->trainerServicesTable->setItem(row, 5, new QTableWidgetItem(
                service.getStatus() == TrainerServiceStatus::Active ? "Активна" : "Истекла"));
        }
    }
}

void ClientWindow::populateVisitsTab() {
    // Clear the table
    ui->visitsTable->setRowCount(0);
    
    // Load visits from the data manager
    QList<Visit> allVisits = m_dataManager.getVisits();
    
    // Add visits for this user
    for (const auto& visit : allVisits) {
        if (visit.getUserId() == m_user.getId()) {
            int row = ui->visitsTable->rowCount();
            ui->visitsTable->insertRow(row);
            
            ui->visitsTable->setItem(row, 0, new QTableWidgetItem(visit.getDateTime().toString("dd.MM.yyyy hh:mm")));
        }
    }
}

void ClientWindow::on_buyMembershipButton_clicked() {
    // Get the selected row in the available memberships table
    int currentRow = ui->availableMembershipsTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите абонемент для покупки");
        return;
    }

    // Get the cost from the selected row to identify which membership to buy
    QTableWidgetItem* costItem = ui->availableMembershipsTable->item(currentRow, 3);
    if (!costItem) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить информацию об абонементе");
        return;
    }

    double cost = costItem->text().toDouble();

    // Load all memberships to find the one we want to purchase
    QList<Membership> allMemberships = m_dataManager.getMemberships();
    Membership* membershipToBuy = nullptr;

    for (auto& membership : allMemberships) {
        // Find an unassigned membership with the matching cost
        if (membership.getUserId() == 0 && qFuzzyCompare(membership.getCost(), cost)) {
            membershipToBuy = &membership;
            break;
        }
    }

    if (!membershipToBuy) {
        QMessageBox::warning(this, "Ошибка", "Выбранный абонемент больше не доступен");
        return;
    }

    // Update the membership to assign it to the current user
    membershipToBuy->setUserId(m_user.getId());
    membershipToBuy->setStartDate(QDate::currentDate()); // Start from today

    // Update the data manager and save
    m_dataManager.setMemberships(allMemberships);
    m_dataManager.saveData();

    // Refresh both tables to show the changes
    populateMembershipTab();
    populateAvailableMembershipsTab();

    QMessageBox::information(this, "Успех", "Абонемент успешно приобретен!");
}

void ClientWindow::on_buyTrainerServiceButton_clicked() {
    // Open the trainer service dialog
    TrainerServiceDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        TrainerService newService = dialog.getTrainerService();
        // Assign the service to the current user
        newService.setUserId(m_user.getId());
        // Add to the data manager and save to file
        m_dataManager.addTrainerService(newService);
        bool saveResult = m_dataManager.saveData();
        
        if (saveResult) {
            // Refresh the trainer services table to show the new service
            populateTrainerServicesTab();
            QMessageBox::information(this, "Успех", "Тренерская услуга успешно приобретена!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить тренерскую услугу");
        }
    }
}

void ClientWindow::on_markVisitButton_clicked() {
    // Create a new visit for the current user with current date/time
    Visit newVisit(0, m_user.getId(), QDateTime::currentDateTime());
    
    // Add to the data manager and save to file
    m_dataManager.addVisit(newVisit);
    bool saveResult = m_dataManager.saveData();
    
    if (saveResult) {
        // Refresh the visits table to show the new visit
        populateVisitsTab();
        QMessageBox::information(this, "Успех", "Посещение успешно отмечено");
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить посещение");
    }
}

void ClientWindow::checkMembershipExpiration() {
    // Load memberships from the data manager
    QList<Membership> allMemberships = m_dataManager.getMemberships();
    bool hasExpiredMembership = false;
    QString expiredMessage = "Ваш абонемент истек: ";
    
    // Check all memberships for this user
    for (const auto& membership : allMemberships) {
        if (membership.getUserId() == m_user.getId()) {
            QDate endDate = membership.getEndDate();
            QDate currentDate = QDate::currentDate();
            
            // If current date is past the membership end date, it's expired
            if (currentDate > endDate) {
                hasExpiredMembership = true;
                QString durationStr;
                switch (membership.getDuration()) {
                    case MembershipDuration::Single:
                        durationStr = "Разовый";
                        break;
                    case MembershipDuration::Monthly:
                        durationStr = "Месячный";
                        break;
                    case MembershipDuration::HalfYear:
                        durationStr = "Полугодовой";
                        break;
                    case MembershipDuration::Yearly:
                        durationStr = "Годовой";
                        break;
                    case MembershipDuration::TwoYears:
                        durationStr = "Двухгодовой";
                        break;
                }
                expiredMessage += QString("\n- %1 (окончание: %2)").arg(durationStr, endDate.toString("dd.MM.yyyy"));
            }
        }
    }
    
    if (hasExpiredMembership) {
        QMessageBox::information(this, "Истекший абонемент", expiredMessage);
    }
}