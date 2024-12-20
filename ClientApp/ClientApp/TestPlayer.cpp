#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "PlayerWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr)
        : QMainWindow(parent),
        codeInput(new QLineEdit(this)),
        showButton(new QPushButton("Afișează Imagine", this)),
        imageLabel(new QLabel(this))
    {
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        // Configurăm widget-urile
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setMinimumSize(400, 400); // Dimensiunea minimă pentru afișarea imaginii

        // Adăugăm widget-urile la layout
        layout->addWidget(codeInput);
        layout->addWidget(showButton);
        layout->addWidget(imageLabel);

        // Setăm widget-ul central
        setCentralWidget(centralWidget);

        // Conectăm butonul la funcția de afișare a imaginii
        connect(showButton, &QPushButton::clicked, this, &MainWindow::onShowImageClicked);
    }

private slots:
    void onShowImageClicked()
    {
        // Obținem codul de la utilizator
        QString codeText = codeInput->text();
        int code = codeText.toInt();

        // Apelăm funcția din PlayerWindow pentru a afișa imaginea
        PlayerWindow player;
        player.DisplayPlayerImage(code, imageLabel);
    }

private:
    QLineEdit* codeInput;  // Câmp pentru introducerea codului
    QPushButton* showButton; // Butonul pentru afișarea imaginii
    QLabel* imageLabel;   // Loc pentru afișarea imaginii
};
