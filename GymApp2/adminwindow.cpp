#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "membershipdialog.h"
#include <QMessageBox>
#include <QInputDialog>

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    setupUI();
    
    // Load initial data and populate tables
    m_dataManager.loadData();
    populateMembershipsTable();
    populateTrainerServicesTable();
    populateVisitsTable();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::setupUI() {
    // Connect buttons to their respective slots
    connect(ui->addMembershipButton, &QPushButton::clicked, this, &AdminWindow::onAddMembershipClicked);
    connect(ui->editMembershipButton, &QPushButton::clicked, this, &AdminWindow::onEditMembershipClicked);
    connect(ui->deleteMembershipButton, &QPushButton::clicked, this, &AdminWindow::onDeleteMembershipClicked);
    connect(ui->deleteTrainerServiceButton, &QPushButton::clicked, this, &AdminWindow::onDeleteTrainerServiceClicked);
    connect(ui->attendanceReportButton, &QPushButton::clicked, this, &AdminWindow::onAttendanceReportClicked);
    connect(ui->revenueReportButton, &QPushButton::clicked, this, &AdminWindow::onRevenueReportClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &AdminWindow::onSearchClicked);
    connect(ui->searchFieldComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AdminWindow::onSearchFieldChanged);
    
    // Initialize tables
    populateMembershipsTable();
    populateTrainerServicesTable();
    populateVisitsTable();
    
    // Initialize search field and filters
    onSearchFieldChanged(ui->searchFieldComboBox->currentIndex());
}

void AdminWindow::onAddMembershipClicked() {
    // Create a template membership (not assigned to any user)
    MembershipDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Membership newMembership = dialog.getMembership();
        // Set userId to 0 to indicate this is a template/available membership
        newMembership.setUserId(0);
        // Add to the data manager and save to file
        m_dataManager.addMembership(newMembership);
        bool saveResult = m_dataManager.saveData(); // Ensure all data is saved to files
        populateMembershipsTable();
        if (saveResult) {
            QMessageBox::information(this, "Успех", "Шаблон абонемента успешно добавлен");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить абонемент");
        }
    }
}

void AdminWindow::onEditMembershipClicked() {
    int currentRow = ui->membershipsTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите абонемент для редактирования");
        return;
    }
    
    // Get the membership ID from the selected row
    QTableWidgetItem* idItem = ui->membershipsTable->item(currentRow, 0);
    if (!idItem) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить ID абонемента");
        return;
    }
    
    int membershipId = idItem->text().toInt();
    
    // Find the membership in the data manager
    QList<Membership> memberships = m_dataManager.getMemberships();
    Membership* membershipToEdit = nullptr;
    for (auto& membership : memberships) {
        if (membership.getId() == membershipId) {
            membershipToEdit = &membership;
            break;
        }
    }
    
    if (!membershipToEdit) {
        QMessageBox::warning(this, "Ошибка", "Абонемент не найден");
        return;
    }
    
    MembershipDialog dialog(*membershipToEdit, this);
    if (dialog.exec() == QDialog::Accepted) {
        *membershipToEdit = dialog.getMembership();
        // Update the membership in the data manager
        m_dataManager.setMemberships(memberships);
        m_dataManager.saveData(); // Save changes to file
        populateMembershipsTable();
        QMessageBox::information(this, "Успех", "Абонемент успешно отредактирован");
    }
}

void AdminWindow::onDeleteMembershipClicked() {
    int currentRow = ui->membershipsTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите абонемент для удаления");
        return;
    }
    
    // Get the membership ID from the selected row
    QTableWidgetItem* idItem = ui->membershipsTable->item(currentRow, 0);
    if (!idItem) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить ID абонемента");
        return;
    }
    
    int membershipId = idItem->text().toInt();
    
    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение",
        "Вы действительно хотите удалить абонемент с ID " + QString::number(membershipId) + "?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Remove the membership from the data manager
        QList<Membership> memberships = m_dataManager.getMemberships();
        for (int i = 0; i < memberships.size(); ++i) {
            if (memberships[i].getId() == membershipId) {
                memberships.removeAt(i);
                break;
            }
        }
        
        // Update the data manager and save
        m_dataManager.setMemberships(memberships);
        m_dataManager.saveData(); // Save changes to file
        
        populateMembershipsTable();
        QMessageBox::information(this, "Успех", "Абонемент успешно удален");
    }
}

void AdminWindow::onDeleteTrainerServiceClicked() {
    int currentRow = ui->trainerServicesTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите тренерскую услугу для удаления");
        return;
    }
    
    // Get the trainer service ID from the selected row
    QTableWidgetItem* idItem = ui->trainerServicesTable->item(currentRow, 0);
    if (!idItem) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить ID тренерской услуги");
        return;
    }
    
    int serviceId = idItem->text().toInt();
    
    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение",
        "Вы действительно хотите удалить тренерскую услугу с ID " + QString::number(serviceId) + "?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Remove the trainer service from the data manager
        QList<TrainerService> services = m_dataManager.getTrainerServices();
        for (int i = 0; i < services.size(); ++i) {
            if (services[i].getId() == serviceId) {
                services.removeAt(i);
                break;
            }
        }
        
        // Update the data manager and save
        m_dataManager.setTrainerServices(services);
        m_dataManager.saveData(); // Save changes to file
        
        populateTrainerServicesTable();
        QMessageBox::information(this, "Успех", "Тренерская услуга успешно удалена");
    }
}

void AdminWindow::onAttendanceReportClicked() {
    // Load all visits from the data manager
    QList<Visit> visits = m_dataManager.getVisits();
    // Generate and display attendance report for all visits
    QString report = m_reportManager.generateAttendanceReport(visits);
    ui->attendanceReportText->setText(report);
}

void AdminWindow::onRevenueReportClicked() {
    // Load memberships and trainer services from the data manager
    QList<Membership> memberships = m_dataManager.getMemberships();
    QList<TrainerService> services = m_dataManager.getTrainerServices();
    // Get the selected date from the date edit
    QDate selectedDate = ui->revenueReportDate->date();
    // Generate and display revenue report for the selected date
    QString report = m_reportManager.generateRevenueReportForDate(memberships, services, selectedDate);
    ui->revenueReportText->setText(report);
}

void AdminWindow::onSearchFieldChanged(int) {
    QString field = ui->searchFieldComboBox->currentText();
    
    // Скрываем оба фильтра по умолчанию
    ui->statusFilterComboBox->setVisible(false);
    ui->typeFilterComboBox->setVisible(false);
    ui->filterLabel->setVisible(false);
    
    // Показываем нужный фильтр в зависимости от выбранного поля поиска
    if (field == "Типу абонемента") {
        ui->statusFilterComboBox->setVisible(true);
        ui->filterLabel->setText("Статус:");
        ui->filterLabel->setVisible(true);
    } else if (field == "Тренерским услугам") {
        ui->typeFilterComboBox->setVisible(true);
        ui->filterLabel->setText("Тип услуги:");
        ui->filterLabel->setVisible(true);
    } else {
        // Для поиска по клиенту и дате фильтры не нужны
        ui->filterLabel->setVisible(false);
    }
}

void AdminWindow::onSearchClicked() {
    // Get search parameters
    QString field = ui->searchFieldComboBox->currentText();
    QString query = ui->searchQueryLineEdit->text();
    
    // Perform search based on selected field
    if (field == "Клиенту") {
        // For client search, we need to search in both memberships and trainer services
        QList<Membership> memberships = m_dataManager.getMemberships();
        QList<TrainerService> trainerServices = m_dataManager.getTrainerServices();
        QList<User> users = m_dataManager.getUsers();
        
        // Search in memberships by client name
        QList<Membership> membershipResults;
        for (const auto& membership : memberships) {
            // Find the user by ID
            for (const auto& user : users) {
                if (user.getId() == membership.getUserId()) {
                    if (user.getName().contains(query, Qt::CaseInsensitive) ||
                        QString::number(user.getId()).contains(query)) {
                        membershipResults.append(membership);
                        break;
                    }
                }
            }
        }
        
        // Search in trainer services by client name
        QList<TrainerService> serviceResults;
        for (const auto& service : trainerServices) {
            // Find the user by ID
            for (const auto& user : users) {
                if (user.getId() == service.getUserId()) {
                    if (user.getName().contains(query, Qt::CaseInsensitive) ||
                        QString::number(user.getId()).contains(query)) {
                        serviceResults.append(service);
                        break;
                    }
                }
            }
        }
        
        // Apply status filter if not "Все"
        QString statusFilter = ui->statusFilterComboBox->currentText();
        if (statusFilter != "Все") {
            if (statusFilter == "Активен") {
                membershipResults = m_searchFilterManager.filterMembershipsByStatus(membershipResults, MembershipStatus::Active);
            } else if (statusFilter == "Истек") {
                membershipResults = m_searchFilterManager.filterMembershipsByStatus(membershipResults, MembershipStatus::Expired);
            }
        }
        
        // Update the search results table - combine memberships and trainer services
        populateSearchResultsTable(membershipResults, serviceResults);
    } else if (field == "Типу абонемента") {
        // Search in memberships by type
        QList<Membership> memberships = m_dataManager.getMemberships();
        auto results = m_searchFilterManager.searchMemberships(memberships, "Тип", query);
        // Apply status filter if not "Все"
        QString statusFilter = ui->statusFilterComboBox->currentText();
        if (statusFilter != "Все") {
            if (statusFilter == "Активен") {
                results = m_searchFilterManager.filterMembershipsByStatus(results, MembershipStatus::Active);
            } else if (statusFilter == "Истек") {
                results = m_searchFilterManager.filterMembershipsByStatus(results, MembershipStatus::Expired);
            }
        }
        // Update the search results table
        populateSearchResultsTable(results, QList<TrainerService>());
    } else if (field == "Дате") {
        // Search in memberships by date
        QList<Membership> memberships = m_dataManager.getMemberships();
        auto results = m_searchFilterManager.searchMemberships(memberships, "Дата", query);
        // Update the search results table
        populateSearchResultsTable(results, QList<TrainerService>());
    } else if (field == "Тренерским услугам") {
        // Search in trainer services by client name
        QList<TrainerService> services = m_dataManager.getTrainerServices();
        QList<User> users = m_dataManager.getUsers();
        QList<TrainerService> results;
        
        // Find trainer services by client name
        for (const auto& service : services) {
            for (const auto& user : users) {
                if (user.getId() == service.getUserId()) {
                    if (user.getName().contains(query, Qt::CaseInsensitive) ||
                        QString::number(user.getId()).contains(query)) {
                        results.append(service);
                        break;
                    }
                }
            }
        }
        
        // Apply type filter if not "Все"
        QString typeFilter = ui->typeFilterComboBox->currentText();
        if (typeFilter != "Все") {
            results = m_searchFilterManager.filterTrainerServicesByType(results, typeFilter);
        }
        // Update the search results table with trainer services
        populateSearchResultsTableForTrainerServices(results);
    }
}

void AdminWindow::populateMembershipsTable() {
    // Clear the table
    ui->membershipsTable->setRowCount(0);
    
    // Load memberships from the data manager
    QList<Membership> memberships = m_dataManager.getMemberships();
    QList<User> users = m_dataManager.getUsers();
    
    // Add data for demonstration
    for (const auto& membership : memberships) {
        int row = ui->membershipsTable->rowCount();
        ui->membershipsTable->insertRow(row);
        
        ui->membershipsTable->setItem(row, 0, new QTableWidgetItem(QString::number(membership.getId())));
        if (membership.getUserId() == 0) {
            ui->membershipsTable->setItem(row, 1, new QTableWidgetItem("Шаблон"));
            ui->membershipsTable->setItem(row, 2, new QTableWidgetItem(""));
        } else {
            ui->membershipsTable->setItem(row, 1, new QTableWidgetItem(QString::number(membership.getUserId())));
            
            // Find the user name based on user ID
            QString userName = "Неизвестный";
            for (const auto& user : users) {
                if (user.getId() == membership.getUserId()) {
                    userName = user.getName();
                    break;
                }
            }
            ui->membershipsTable->setItem(row, 2, new QTableWidgetItem(userName));
        }
        ui->membershipsTable->setItem(row, 3, new QTableWidgetItem(
            membership.getDuration() == MembershipDuration::Single ? "Разовый" :
            membership.getDuration() == MembershipDuration::Monthly ? "Месячный" :
            membership.getDuration() == MembershipDuration::HalfYear ? "Полугодовой" :
            membership.getDuration() == MembershipDuration::Yearly ? "Годовой" :
            "Двухгодовой"));
        ui->membershipsTable->setItem(row, 4, new QTableWidgetItem(membership.getStartDate().toString("dd.MM.yyyy")));
        ui->membershipsTable->setItem(row, 5, new QTableWidgetItem(membership.getEndDate().toString("dd.MM.yyyy")));
        ui->membershipsTable->setItem(row, 6, new QTableWidgetItem(QString::number(membership.getCost())));
        ui->membershipsTable->setItem(row, 7, new QTableWidgetItem(
            membership.getStatus() == MembershipStatus::Active ? "Активен" : "Истек"));
    }
}

void AdminWindow::populateTrainerServicesTable() {
    // Clear the table
    ui->trainerServicesTable->setRowCount(0);
    
    // Load trainer services from the data manager
    QList<TrainerService> services = m_dataManager.getTrainerServices();
    QList<User> users = m_dataManager.getUsers();
    
    // Add data for demonstration
    for (const auto& service : services) {
        int row = ui->trainerServicesTable->rowCount();
        ui->trainerServicesTable->insertRow(row);
        
        ui->trainerServicesTable->setItem(row, 0, new QTableWidgetItem(QString::number(service.getId())));
        ui->trainerServicesTable->setItem(row, 1, new QTableWidgetItem(QString::number(service.getUserId())));
        
        // Find the user name based on user ID
        QString userName = "Неизвестный";
        for (const auto& user : users) {
            if (user.getId() == service.getUserId()) {
                userName = user.getName();
                break;
            }
        }
        ui->trainerServicesTable->setItem(row, 2, new QTableWidgetItem(userName));
        
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
        ui->trainerServicesTable->setItem(row, 3, new QTableWidgetItem(typeStr));
        
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
        ui->trainerServicesTable->setItem(row, 4, new QTableWidgetItem(durationStr));
        
        ui->trainerServicesTable->setItem(row, 5, new QTableWidgetItem(service.getStartDate().toString("dd.MM.yyyy")));
        ui->trainerServicesTable->setItem(row, 6, new QTableWidgetItem(service.getEndDate().toString("dd.MM.yyyy")));
        ui->trainerServicesTable->setItem(row, 7, new QTableWidgetItem(QString::number(service.getCost())));
        ui->trainerServicesTable->setItem(row, 8, new QTableWidgetItem(
            service.getStatus() == TrainerServiceStatus::Active ? "Активна" : "Истекла"));
    }
}

void AdminWindow::populateVisitsTable() {
    // Clear the table
    ui->visitsTable->setRowCount(0);
    
    // Load visits from the data manager
    QList<Visit> visits = m_dataManager.getVisits();
    QList<User> users = m_dataManager.getUsers();
    
    // Add data for demonstration
    for (const auto& visit : visits) {
        int row = ui->visitsTable->rowCount();
        ui->visitsTable->insertRow(row);
        
        ui->visitsTable->setItem(row, 0, new QTableWidgetItem(QString::number(visit.getId())));
        ui->visitsTable->setItem(row, 1, new QTableWidgetItem(QString::number(visit.getUserId())));
        
        // Find the user name based on user ID
        QString userName = "Неизвестный";
        for (const auto& user : users) {
            if (user.getId() == visit.getUserId()) {
                userName = user.getName();
                break;
            }
        }
        ui->visitsTable->setItem(row, 2, new QTableWidgetItem(userName));
        ui->visitsTable->setItem(row, 3, new QTableWidgetItem(visit.getDateTime().toString("dd.MM.yyyy hh:mm")));
    }
}

void AdminWindow::populateSearchResultsTable(const QList<Membership>& memberships, const QList<TrainerService>& services) {
    // Clear the table and set headers
    ui->searchResultsTable->setRowCount(0);
    ui->searchResultsTable->setHorizontalHeaderLabels(QStringList() << "ID" << "ID клиента" << "Имя клиента" << "Тип" << "Статус" << "Начало" << "Конец");
    
    // Load users to get client names
    QList<User> users = m_dataManager.getUsers();
    
    // Populate with membership search results
    for (const auto& membership : memberships) {
        int row = ui->searchResultsTable->rowCount();
        ui->searchResultsTable->insertRow(row);
        
        ui->searchResultsTable->setItem(row, 0, new QTableWidgetItem(QString::number(membership.getId())));
        
        // Find the client name based on user ID
        QString clientName = "Шаблон";
        QString clientId = QString::number(membership.getUserId());
        if (membership.getUserId() != 0) {
            for (const auto& user : users) {
                if (user.getId() == membership.getUserId()) {
                    clientName = user.getName();
                    break;
                }
            }
        } else {
            clientId = "";
        }
        ui->searchResultsTable->setItem(row, 1, new QTableWidgetItem(clientId));
        ui->searchResultsTable->setItem(row, 2, new QTableWidgetItem(clientName));
        
        ui->searchResultsTable->setItem(row, 3, new QTableWidgetItem(
            membership.getDuration() == MembershipDuration::Single ? "Разовый" :
            membership.getDuration() == MembershipDuration::Monthly ? "Месячный" :
            membership.getDuration() == MembershipDuration::HalfYear ? "Полугодовой" :
            membership.getDuration() == MembershipDuration::Yearly ? "Годовой" :
            "Двухгодовой"));
        ui->searchResultsTable->setItem(row, 4, new QTableWidgetItem(
            membership.getStatus() == MembershipStatus::Active ? "Активен" : "Истек"));
        // Add start and end dates as additional columns
        ui->searchResultsTable->setItem(row, 5, new QTableWidgetItem(membership.getStartDate().toString("dd.MM.yyyy")));
        ui->searchResultsTable->setItem(row, 6, new QTableWidgetItem(membership.getEndDate().toString("dd.MM.yyyy")));
    }
    
    // Populate with trainer service search results
    for (const auto& service : services) {
        int row = ui->searchResultsTable->rowCount();
        ui->searchResultsTable->insertRow(row);
        
        ui->searchResultsTable->setItem(row, 0, new QTableWidgetItem(QString::number(service.getId())));
        
        // Find the client name based on user ID
        QString clientName = "Неизвестный";
        QString clientId = QString::number(service.getUserId());
        for (const auto& user : users) {
            if (user.getId() == service.getUserId()) {
                clientName = user.getName();
                break;
            }
        }
        ui->searchResultsTable->setItem(row, 1, new QTableWidgetItem(clientId));
        ui->searchResultsTable->setItem(row, 2, new QTableWidgetItem(clientName));
        
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
        ui->searchResultsTable->setItem(row, 3, new QTableWidgetItem(typeStr));
        ui->searchResultsTable->setItem(row, 4, new QTableWidgetItem(
            service.getStatus() == TrainerServiceStatus::Active ? "Активна" : "Истекла"));
        // Add start and end dates as additional columns
        ui->searchResultsTable->setItem(row, 5, new QTableWidgetItem(service.getStartDate().toString("dd.MM.yyyy")));
        ui->searchResultsTable->setItem(row, 6, new QTableWidgetItem(service.getEndDate().toString("dd.MM.yyyy")));
    }
}

void AdminWindow::populateSearchResultsTableForTrainerServices(const QList<TrainerService>& results) {
    // Clear the table and set headers
    ui->searchResultsTable->setRowCount(0);
    ui->searchResultsTable->setHorizontalHeaderLabels(QStringList() << "ID" << "ID клиента" << "Имя клиента" << "Тип" << "Статус" << "Начало" << "Конец");
    
    // Load users to get client names
    QList<User> users = m_dataManager.getUsers();
    
    // Populate with search results
    for (const auto& service : results) {
        int row = ui->searchResultsTable->rowCount();
        ui->searchResultsTable->insertRow(row);
        
        ui->searchResultsTable->setItem(row, 0, new QTableWidgetItem(QString::number(service.getId())));
        
        // Find the client name based on user ID
        QString clientName = "Неизвестный";
        QString clientId = QString::number(service.getUserId());
        for (const auto& user : users) {
            if (user.getId() == service.getUserId()) {
                clientName = user.getName();
                break;
            }
        }
        ui->searchResultsTable->setItem(row, 1, new QTableWidgetItem(clientId));
        ui->searchResultsTable->setItem(row, 2, new QTableWidgetItem(clientName));
        
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
        ui->searchResultsTable->setItem(row, 3, new QTableWidgetItem(typeStr));
        ui->searchResultsTable->setItem(row, 4, new QTableWidgetItem(
            service.getStatus() == TrainerServiceStatus::Active ? "Активна" : "Истекла"));
        // Add start and end dates as additional columns
        ui->searchResultsTable->setItem(row, 5, new QTableWidgetItem(service.getStartDate().toString("dd.MM.yyyy")));
        ui->searchResultsTable->setItem(row, 6, new QTableWidgetItem(service.getEndDate().toString("dd.MM.yyyy")));
    }
}