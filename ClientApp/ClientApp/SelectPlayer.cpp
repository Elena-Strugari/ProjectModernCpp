#include "SelectPlayer.h"
#include<QBoxLayout>
#include<QPixmap>
#include<QKeyEvent>
#include<QMessageBox>
#include<Qlabel>
#include<Qstring>
SelectPlayer::SelectPlayer(QWidget* parent) :QDialog(parent)
{
	setWindowTitle("Select Player");
	setFixedSize(400, 500);
	QBoxLayout *layout = new QBoxLayout(this);
	QLabel *instructions = new QLabel("Press 1,2,3 or 4 to select your player:", this);
	instructions->setAlignment(Qt::AlignCenter);
	layout->addWidget(instructions);

	for (int i = 0; i < 4; i++)
	{
		QLabel* playerLabel = new QLabel(this);
		QPixmap pixmap("...." + QString::number(i + 1) + ".png");
		playerLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
		playerLabel->setAlignment(Qt::AlignCenter);
		QLabel *nameLabel = new QLabel("Player " + QString::number(i + 1), this);
		nameLabel->setAlignment(Qt::AlignCenter);
		layout->addWidget(playerLabel);
		layout->addWidget(nameLabel);
	}

}
