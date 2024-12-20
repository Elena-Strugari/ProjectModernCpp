#include "PlayerWindow.h"

PlayerWindow::PlayerWindow(QWidget* parent) : QWidget(parent), m_imageLabel(new QLabel(this))
{
	m_imageLabel->setAlignment(Qt::AlignCenter);
	m_imageLabel->resize(400, 400);
}
void PlayerWindow::DisplayPlayerImage(int code)
{
	QString imagePath;
	switch (code)
	{

	}
	ShowImage(imagePath);
}
void PlayerWindow::ShowImage(const QString& imagePath)
{
	QPixmap pixmap(imagePath);

	if (pixmap.isNull())
	{
		qDebug() << "Imaginea nu a putut fi încărcată: " << imagePath;
		return;
	}

	m_imageLabel->setPixmap(pixmap.scaled(m_imageLabel->size(), Qt::KeepAspectRatio));
}