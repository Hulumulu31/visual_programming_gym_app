#include "trainerservicedialog.h"
#include "ui_trainerservicedialog.h"
#include <QMessageBox>

TrainerServiceDialog::TrainerServiceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrainerServiceDialog)
    , m_editMode(false)
{
    ui->setupUi(this);
    // Устанавливаем фиксированные цены в зависимости от длительности
    // Single: 500, Weekly: 200, Monthly: 3500, HalfYear: 5000, Yearly: 7000, TwoYears: 11000
    connect(ui->durationComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
        double cost = 0.0;
        switch (index) {
            case 0: // Single
                cost = 500.0;
                break;
            case 1: // Weekly
                cost = 2000.0;
                break;
            case 2: // Monthly
                cost = 3500.0;
                break;
            case 3: // HalfYear
                cost = 5000.0;
                break;
            case 4: // Yearly
                cost = 7000.0;
                break;
            case 5: // TwoYears
                cost = 11000.0;
                break;
        }
        ui->costLabelValue->setText(QString("%1 руб.").arg(cost));
    });
}

TrainerServiceDialog::TrainerServiceDialog(const TrainerService& service, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrainerServiceDialog)
    , m_service(service)
    , m_editMode(true)
{
    ui->setupUi(this);
    
    // Заполняем поля данными из существующей услуги
    ui->serviceTypeComboBox->setCurrentIndex(static_cast<int>(service.getServiceType()));
    ui->durationComboBox->setCurrentIndex(static_cast<int>(service.getDuration()));
    ui->startDateEdit->setDate(service.getStartDate());
    
    // Устанавливаем цену
    double cost = service.getCost();
    ui->costLabel->setText(QString("Цена: %1 руб.").arg(cost));
}

TrainerServiceDialog::~TrainerServiceDialog()
{
    delete ui;
}

TrainerService TrainerServiceDialog::getTrainerService() const
{
    return m_service;
}

void TrainerServiceDialog::on_buttonBox_accepted()
{
    // Получаем выбранные значения из UI
    int serviceTypeIndex = ui->serviceTypeComboBox->currentIndex();
    int durationIndex = ui->durationComboBox->currentIndex();
    QDate startDate = ui->startDateEdit->date();
    
    // Устанавливаем тип услуги
    TrainerServiceType serviceType;
    switch (serviceTypeIndex) {
        case 0:
            serviceType = TrainerServiceType::Gym;
            break;
        case 1:
            serviceType = TrainerServiceType::GroupTraining;
            break;
        case 2:
            serviceType = TrainerServiceType::Swimming;
            break;
        case 3:
            serviceType = TrainerServiceType::Boxing;
            break;
        default:
            serviceType = TrainerServiceType::Gym;
            break;
    }
    
    // Устанавливаем длительность
    TrainerServiceDuration duration;
    switch (durationIndex) {
        case 0:
            duration = TrainerServiceDuration::Single;
            break;
        case 1:
            duration = TrainerServiceDuration::Weekly;
            break;
        case 2:
            duration = TrainerServiceDuration::Monthly;
            break;
        case 3:
            duration = TrainerServiceDuration::HalfYear;
            break;
        case 4:
            duration = TrainerServiceDuration::Yearly;
            break;
        case 5:
            duration = TrainerServiceDuration::TwoYears;
            break;
        default:
            duration = TrainerServiceDuration::Single;
            break;
    }
    
    // Устанавливаем цену в зависимости от длительности
    double cost = 0.0;
    switch (durationIndex) {
        case 0: // Single
            cost = 500.0;
            break;
        case 1: // Weekly
            cost = 2000.0;
            break;
        case 2: // Monthly
            cost = 3500.0;
            break;
        case 3: // HalfYear
            cost = 5000.0;
            break;
        case 4: // Yearly
            cost = 7000.0;
            break;
        case 5: // TwoYears
            cost = 11000.0;
            break;
    }
    
    // Создаем объект услуги
    m_service = TrainerService(0, 0, serviceType, duration, startDate, cost);
    
    accept();
}

void TrainerServiceDialog::on_buttonBox_rejected()
{
    reject();
}