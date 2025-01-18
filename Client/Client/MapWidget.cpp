#include "MapWidget.h"
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "NoGreenScreen.h"
MapWidget::MapWidget(QWidget* parent) : QWidget(parent) {
	qDebug() << "MapWidget created:" << this;
}

void MapWidget::setMapData(const QJsonArray& data)
{
	qDebug() << "Am intrat in setMapData.";
	for (const QJsonValue& row : data) {
		//qDebug() << row;
	}
	mapData = data; // Salvează datele
	for (const QJsonValue& row : mapData) {
		//qDebug() << row;
	}

	update();       // Reîmprospătează widget-ul (declanșează paintEvent)
	//paintEvent(this);
}

//void MapWidget::UpdateMapCell(int x, int y, const QString& type) {
//    // Assuming that mapData[x][y] is an array-like structure
//    mapData[x].toArray()[y] = type;
//
//    // Repaint only the updated cell area
//    int rows = mapData.size();
//    int cols = mapData[0].toArray().size();
//
//    const double scaleFactor = 0.9;
//    int cellWidth = width() / cols * scaleFactor;
//    int cellHeight = height() / rows * scaleFactor;
//    int squareSize = qMin(cellWidth, cellHeight);
//
//    // Calculate the area to update
//    int offsetX = (width() - squareSize * cols) / 2;
//    int offsetY = (height() - squareSize * rows) / 2;
//
//    QRect cellRect(offsetX + y * squareSize, offsetY + x * squareSize, squareSize, squareSize);
//    update(cellRect); // Only update the cell area
//}

//void MapWidget::UpdateMapCell(int x, int y, const QString& type) {
//	// Asigură-te că coordonatele sunt valide
//	if (x < 0 || x >= mapData.size() || y < 0 || y >= mapData[0].toArray().size()) {
//		return;  // Ieșim dacă coordonatele sunt invalide
//	}
//
//	// Actualizează celula specificată cu noul tip
//	QJsonArray& row = mapData[x].toArray();
//	row[y] = type;
//
//	// Emită signal-ul pentru a actualiza celula respectivă
//	emit cellUpdated(x, y);
//}

//void MapWidget::onCellUpdated(int x, int y) {
//    // Recalculate the cell's position and size
//    int rows = mapData.size();
//    int cols = mapData[0].toArray().size();
//
//    // Scaling factor for larger cells
//    const double scaleFactor = 0.9;
//
//    // Size of each cell, considering the scaling factor
//    int cellWidth = width() / cols * scaleFactor;
//    int cellHeight = height() / rows * scaleFactor;
//
//    // Determine the minimum size for square cells
//    int squareSize = qMin(cellWidth, cellHeight);
//
//    // Calculate the offset to center the map within the widget
//    int offsetX = (width() - squareSize * cols) / 2;
//    int offsetY = (height() - squareSize * rows) / 2;
//
//    // Update the specific cell area that was changed
//    update(QRect(offsetX + y * squareSize, offsetY + x * squareSize, squareSize, squareSize));
//}


void MapWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (mapData.isEmpty()) {
        qDebug() << "Map data is empty!";
        return;
    }

    int rows = mapData.size();
    int cols = mapData[0].toArray().size();

    // Factor de scalare pentru a face celulele mai mari
    const double scaleFactor = 0.9;

    // Dimensiunea fiecărei celule, luând în considerare factorul de scalare
    int cellWidth = width() / cols * scaleFactor;
    int cellHeight = height() / rows * scaleFactor;

    // Determinăm dimensiunea minimă pentru pătratele celulelor
    int squareSize = qMin(cellWidth, cellHeight);

    // Calculăm un offset pentru a centra harta în widget
    int offsetX = (width() - squareSize * cols) / 2;
    int offsetY = (height() - squareSize * rows) / 2;


    for (int row = 0; row < rows; ++row) {
        QJsonArray rowArray = mapData[row].toArray();
        for (int col = 0; col < rowArray.size(); ++col) {
            int value = rowArray[col].toInt();

            QImage img;


            if (value == 0) { // Verifică dacă valoarea este corectă
                img = QImage();
            }
            else if (value == 1) {
                img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
            }
            else if (value == 2)
            {
                img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
            }
            else if (value == 3)
            {
                img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
            }
            else if (value == 4)
            {
                img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
            }
            else if (value == 5)
            {
                std::srand(static_cast<unsigned>(std::time(nullptr)));
                int randomNumber = 11 + std::rand() % 4;
                switch (randomNumber)
                {
                case 11:
                {
                    img = RemoveGreenScreen(":/PlayersImages/resources/Astronaut_1.png");
                    break;
                };
                case 12:
                {
                    img = RemoveGreenScreen(":/PlayersImages/resources/Astronaut_2.png");
                    break;
                }
                case 13:
                {
                    img = RemoveGreenScreen(":/PlayersImages/resources/Astronaut_3.png");
                    break;
                } case 14:
                {
                    img = RemoveGreenScreen(":/PlayersImages/resources/Astronaut_4.png");
                    break;
                }
                }
            }
            else if (value == 7)
            {
                img = RemoveGreenScreen(":/Border/resources/Border.png");
            }
            else {
                img = QImage(); // Imagine nulă
            }

            //if (img.isNull()) {
            //    qDebug() << "Imaginea nu a putut fi încărcată!";
            //}
            //else {
            //    qDebug() << "Imaginea a fost încărcată cu succes!";
            //}

            //if (img.isNull()) {
            //    qDebug() << "Eroare: Imaginea pentru valoarea" << value << "nu a fost încărcată!";
            //    continue; // Sari peste această celulă
            //}

            // Definire și desenare celulă
            QRect cellRect(offsetX + col * squareSize, offsetY + row * squareSize, squareSize, squareSize);

            // Redimensionează imaginea pentru a se potrivi în celulă
            QImage scaledImg = img.scaled(squareSize, squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            // Desenează imaginea
            painter.drawImage(cellRect, scaledImg);
        }

    }

}

//void MapWidget::paintEvent(QPaintEvent* event) {
//    Q_UNUSED(event);
//
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);
//
//    if (mapData.isEmpty()) {
//        qDebug() << "Map data is empty!";
//        return;
//    }
//
//    int rows = mapData.size();
//    int cols = mapData[0].toArray().size();
//
//    // Scaling factor for larger cells
//    const double scaleFactor = 0.9;
//
//    // Size of each cell, considering the scaling factor
//    int cellWidth = width() / cols * scaleFactor;
//    int cellHeight = height() / rows * scaleFactor;
//
//    // Determine the minimum size for square cells
//    int squareSize = qMin(cellWidth, cellHeight);
//
//    // Calculate the offset to center the map within the widget
//    int offsetX = (width() - squareSize * cols) / 2;
//    int offsetY = (height() - squareSize * rows) / 2;
//
//    if (event->rect().isEmpty()) {
//        // Repaint the whole map if no specific update area (rect) is provided
//        for (int row = 0; row < rows; ++row) {
//            QJsonArray rowArray = mapData[row].toArray();
//            for (int col = 0; col < rowArray.size(); ++col) {
//                int value = rowArray[col].toInt();
//                QImage img = GetImageForValue(value); // Your logic to return the image based on the value.
//
//                // Calculate the cell's position and size
//                QRect cellRect(offsetX + col * squareSize, offsetY + row * squareSize, squareSize, squareSize);
//
//                // Resize image to fit in the cell
//                QImage scaledImg = img.scaled(squareSize, squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//
//                // Draw the image for each cell
//                painter.drawImage(cellRect, scaledImg);
//            }
//        }
//    }
//    else {
//        // If it's a specific cell update (not the whole map), repaint only that cell
//        QRect cellRect = event->rect(); // Get the specific area that needs to be updated
//
//        // Update the cell inside the event's rect
//        int row = (cellRect.top() - offsetY) / squareSize;
//        int col = (cellRect.left() - offsetX) / squareSize;
//        int value = mapData[row].toArray()[col].toInt();
//        QImage img = GetImageForValue(value);
//
//        // Resize image to fit in the updated cell
//        QImage scaledImg = img.scaled(cellRect.width(), cellRect.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//
//        // Paint the updated cell image
//        painter.drawImage(cellRect, scaledImg);
//    }
//}
//
//QImage MapWidget::GetImageForValue(int value) {
//    QImage img;
//    // Add logic to return the appropriate image for each value
//    if (value == 0) {
//        img = QImage();
//    }
//    else if (value == 1) {
//        img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
//    }
//    else if (value == 2) {
//        img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
//    }
//    else if (value == 3) {
//        img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
//    }
//    else if (value == 4) {
//        img = RemoveGreenScreen(":/Wall/resources/Asteroid.png");
//    }
//    else if (value == 5) {
//        img = RemoveGreenScreen(":/PlayersImages/resources/Astronaut_1.png");
//    }
//    else if (value == 7) {
//        img = RemoveGreenScreen(":/Border/resources/Border.png");
//    }
//    else {
//        img = QImage(); // Empty image
//    }
//    return img;
//}
