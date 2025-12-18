#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registrationdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Initialize the data manager and load existing data
    m_dataManager.loadData();
    
    // Connect the login button to the login slot
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    // Connect the register button to the register slot
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    
    // In a real application, you would validate the user against a database
    // For this example, we'll use a simple check
    if (validateUser(username, password)) {
        // Reload data to ensure we have the latest information
        m_dataManager.loadData();
        // Determine user type and open appropriate window
        if (m_currentUser.getUserType() == UserType::Admin) {
            // Open admin window
            m_adminWindow = new AdminWindow();
            m_adminWindow->show();
            this->hide();
        } else {
            // Open client window
            m_clientWindow = new ClientWindow(m_currentUser);
            m_clientWindow->show();
            this->hide();
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверное имя пользователя или пароль");
    }
}

void MainWindow::onRegisterClicked() {
    RegistrationDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Reload data to ensure we have the latest user list
        m_dataManager.loadData();
        
        User newUser = dialog.getUser();
        
        // Add new user to the data manager
        m_dataManager.addUser(newUser);
        bool saveResult = m_dataManager.saveData(); // Ensure all data is saved to files
        
        if (saveResult) {
            QMessageBox::information(this, "Успех", "Пользователь успешно зарегистрирован");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить данные пользователя");
        }
    }
}

bool MainWindow::validateUser(const QString &username, const QString &password)
{
    // Reload data to ensure we have the latest information
    m_dataManager.loadData();
    
    // In a real application, you would check against a database
    // For this example, we'll create a simple validation
    
    // First, check if the credentials match default/predefined users
    if (username == "admin" && password == "admin") {
        m_currentUser = User(1, "admin", "admin@gym.com", "admin", UserType::Admin);
        return true;
    } else if (username == "client" && password == "client") {
        m_currentUser = User(2, "client", "client@gym.com", "client", UserType::Client);
        return true;
    }
    
    // If not default users, check against users from database
    // Load users from the data manager
    QList<User> users = m_dataManager.getUsers();
    
    for (const auto& user : users) {
        // Check both username and password
        if (user.getName() == username && user.getPassword() == password) {
            m_currentUser = user;
            return true;
        }
    }
    
    return false;
}