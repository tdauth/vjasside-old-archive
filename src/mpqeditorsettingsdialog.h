#ifndef MPQEDITORSETTINGSDIALOG_H
#define MPQEDITORSETTINGSDIALOG_H

#include <QDialog>

namespace vjasside {

class MpqEditor;

class MpqEditorSettingsDialog : public QDialog
{
public:
    MpqEditorSettingsDialog(MpqEditor *mpqEditor);
};

}

#endif // MPQEDITORSETTINGSDIALOG_H
