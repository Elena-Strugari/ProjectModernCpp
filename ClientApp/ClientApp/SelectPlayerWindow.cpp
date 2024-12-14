#include "SelectPlayerWindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QKeyEvent>
#include <QMessageBox>
#include <QLabel>
#include <QString>

SelectPlayer::SelectPlayer(QWidget* parent) : QDialog(parent),background(new QLabel(this)) {
    setWindowTitle("Select Player");
    setFixedSize(1000, 800);
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        background->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    background->setGeometry(0, 0, width(), height()); 
    background->lower();
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* instructions = new QLabel("Press 1,2,3 or 4 to select your player:", this);
    instructions->setAlignment(Qt::AlignCenter);
    instructions->setStyleSheet("font-size: 20px; font-family: Poster; font-weight: bold; color: blue;");
    layout->addWidget(instructions);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setVerticalSpacing(12); 
    gridLayout->setHorizontalSpacing(20);
    layout->addLayout(gridLayout);

    const QString playerNames[4] = { "Astronaut Solaris", "Astronaut Skyler", "Astronaut Amethyst", "Astronaut Reya" };

    for (int i = 0; i < 4; i++)
    {    
        QLabel* playerLabel = new QLabel(this);
        QPixmap pixmap(":/selectPlayers/resources/" + QString("Astronaut_") + QString::number(i + 1) + ".png");
        playerLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));
        playerLabel->setAlignment(Qt::AlignCenter);

        QLabel* nameLabel = new QLabel(playerNames[i], this);
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setStyleSheet("font-size: 16px; font-family: Arial; font-weight: bold; color: white;"); 

        gridLayout->addWidget(playerLabel, 0, i);  
        gridLayout->addWidget(nameLabel, 1, i);   
    }
}

void SelectPlayer::keyPressEvent(QKeyEvent* event) {
	int key = event->key();
	if (key >= Qt::Key_1 && key <= Qt::Key_4) {
		int playerIndex = key - Qt::Key_1;
		const QString playerNames[4] = { "Astronaut Solaris", "Astronaut Skyler", "Astronaut Amethyst", "Astronaut Reya" };
		QMessageBox::information(this, "Player Selected", "You selected " + playerNames[playerIndex] + ".");
	}
	else {
		QDialog::keyPressEvent(event);
	}
}
