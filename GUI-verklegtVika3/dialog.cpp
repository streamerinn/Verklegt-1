#include "dialog.h"

dialog::dialog(Qwidget* parent, Qt::WindowFlags f) :: QDialog(parent, f)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

