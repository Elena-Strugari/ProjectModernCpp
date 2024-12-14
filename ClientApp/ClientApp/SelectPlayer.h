#pragma once  

#ifndef SELECTPLAYER_H
#define SELECTPLAYR_H

#include <QDialog>
class SelectPlayer : public QDialog
{
	Q_OBJECT
public:
	explicit SelectPlayer(QWidget* parent = nullptr);
protected:
	void keyPressEvent(QKeyEvent* event)override;
};
#endif SELECTPLAYER.H
