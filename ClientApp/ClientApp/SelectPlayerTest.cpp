#include <QApplication>
#include "MainWindow.h"
#include "SelectPlayerWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Creează și afișează fereastra SelectPlayer
    SelectPlayer selectPlayer;
    if (selectPlayer.exec() == QDialog::Accepted) {
        // Dacă selecția s-a realizat cu succes, continuă cu fereastra principală
        MainWindow mainWindow;
        mainWindow.show();

        return app.exec();
    }

    // Dacă utilizatorul închide fereastra SelectPlayer, termină aplicația
    return 0;
}
