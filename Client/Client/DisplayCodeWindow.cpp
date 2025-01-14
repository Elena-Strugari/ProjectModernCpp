#include "DisplayCodeWindow.h"
#include <QLabel>
#include <QVBoxLayout>

DisplayCodeWindow::DisplayCodeWindow(QWidget* parent)
    : QWidget(parent),
    layout(new QVBoxLayout(this)),
    messageLabel(new QLabel("Code :", this))
{

    setWindowTitle("Game Code");
    setFixedSize(300, 100);
    setStyleSheet("background-color: white;");
    QFont font;
    font.setPointSize(25);  // Dimensiunea fontului
    font.setBold(true);     // Font gros (bold)
    messageLabel->setFont(font);
    messageLabel->setStyleSheet("color: black;");  // Text negru
    messageLabel->setAlignment(Qt::AlignCenter);   // Centrare text
    messageLabel->setText(" ");
    messageLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    messageLabel->setWordWrap(true);

    layout->addWidget(messageLabel);

    setLayout(layout);
}

DisplayCodeWindow::~DisplayCodeWindow() {}

void DisplayCodeWindow::setMessage(const QString& message) {
    messageLabel->setText(message);
}
