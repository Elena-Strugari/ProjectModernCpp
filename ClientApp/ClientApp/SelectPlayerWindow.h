#pragma once  

#ifndef SELECTPLAYERWINDOW_H
#define SELECTPLAYERWINDOW_H

#include <QDialog>
class SelectPlayer : public QDialog
{
	Q_OBJECT
public:
	explicit SelectPlayer(QWidget* parent = nullptr);
protected:
	void keyPressEvent(QKeyEvent* event)override;
};
#endif // SELECTPLAYERWINDOW_H
