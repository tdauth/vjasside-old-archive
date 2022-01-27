#include "textview.h"
#include "mainwindow.h"

namespace vjasside {

TextView::TextView(QTabWidget *tabWidget, MainWindow *mainWindow, int tabIndex) : QWidget(mainWindow)
{
    setupUi(this);
}

void TextView::setLineProperties(int blockNumber, int openBlock, int closeBlock) {
}

void TextView::openFile(const QString &filePath) {
}

}
