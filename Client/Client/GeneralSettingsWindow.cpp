#include "GeneralSettingsWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

GeneralSettingsWindow::GeneralSettingsWindow(QWidget* parent)
    : QWidget(parent),
    musicVolumeSlider(new QSlider(Qt::Horizontal, this)),
    controlSettingsButton(new QPushButton("Edit Controls", this)),
    logoutButton(new QPushButton("Logout", this)),
    saveButton(new QPushButton("Save Settings", this)),
    deleteButton(new QPushButton("Delete Account", this))
{
    setWindowTitle("General Settings");
    resize(800, 600);

    setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint); // Asigură-te că fereastra apare deasupra celorlalte

    // Debugging - verifică dacă fereastra este vizibilă și activă
    /*qDebug() << "GameWindow visibility:" << isVisible();
    qDebug() << "gameWindow isActiveWindow:" << isActiveWindow();*/

    // Mută și aduce fereastra în prim-plan
    //move(100, 100);      // Mută fereastra într-o poziție clar vizibilă
    activateWindow();    // Forțează activarea ferestrei
    raise();

    // Initializează fundalul
   BackgroundHelper:: InitializeBackground(this);

    // Configurare slider de volum
    musicVolumeSlider->setRange(0, 100);
    musicVolumeSlider->setValue(50);
    musicVolumeSlider->setFixedWidth(400);

    // Stil butoane
    QString buttonStyle =
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    controlSettingsButton->setStyleSheet(buttonStyle);
    logoutButton->setStyleSheet(buttonStyle);
    saveButton->setStyleSheet(buttonStyle);
    deleteButton->setStyleSheet(buttonStyle);
    

    // Setăm dimensiuni fixe pentru butoane
    QSize buttonSize(150, 40);
    controlSettingsButton->setFixedSize(buttonSize);
    logoutButton->setFixedSize(buttonSize);
    saveButton->setFixedSize(buttonSize);
    deleteButton->setFixedSize(buttonSize);

    // Layout pentru slider-ul de volum
    QVBoxLayout* slidersLayout = new QVBoxLayout();
    QLabel* musicLabel = new QLabel("Music Volume", this);
    musicLabel->setAlignment(Qt::AlignCenter);
    musicLabel->setStyleSheet("font-size: 18px; color: white;");

    slidersLayout->addWidget(musicLabel);
    slidersLayout->addWidget(musicVolumeSlider);
    slidersLayout->setAlignment(Qt::AlignCenter);

    // Layout pentru butoane
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(controlSettingsButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(logoutButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addStretch();

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* titleLabel = new QLabel("General Settings", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: white;");
    titleLabel->setContentsMargins(0, 20, 0, 10);

    mainLayout->addWidget(titleLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(slidersLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conexiuni
    connect(saveButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onSaveSettings);
    connect(controlSettingsButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onEditControls);
    connect(logoutButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onLogout);
    connect(deleteButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onDelete);
}

void GeneralSettingsWindow::onSaveSettings()
{
    qDebug() << "Save settings clicked.";
    QMessageBox::information(this, "Save", "Save Settings clicked.");
    emit SaveSettings(musicVolumeSlider->value());

}

void GeneralSettingsWindow::onEditControls()
{
    QMessageBox::information(this, "Edit Controls", "Edit Controls button clicked.");
    emit EditControls();
}

void GeneralSettingsWindow::onLogout()
{
    QMessageBox::information(this, "Log out", "Log out button clicked.");
    emit Logout();
}
void GeneralSettingsWindow::onDelete()
{
    QMessageBox::information(this, "Delete Account", "Delete Account button clicked.");
    emit Delete();
}
void GeneralSettingsWindow::resizeEvent(QResizeEvent* event)
{
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}
