#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include <QTextEdit>

#include "ui_textview.h"

namespace vjasside {

class MainWindow;

class TextView : public QWidget,  public Ui::TextView
{
public:
    TextView(QTabWidget *tabWidget, MainWindow *mainWindow, int tabIndex);

    MainWindow* mainWindow() const;

    void setLineProperties(int blockNumber, int openBlock, int closeBlock);
    void openFile(const QString &filePath);

private:
    MainWindow *m_mainWindow;
};

inline MainWindow* TextView::mainWindow() const {
    return m_mainWindow;
}

}

#endif // TEXTVIEW_H
