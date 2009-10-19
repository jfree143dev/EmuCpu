/**
@file DisassemblyWidget.hh
@brief Widget for displaying the disassembly.
*/

#ifndef JAF__DISASSEMBLY_WIDGET_HH
#define JAF__DISASSEMBLY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_DisassemblyWidget.h"

/**
@class DisassemblyWidget
@brief Widget for displaying the disassembly
*/
class DisassemblyWidget : public QWidget, protected Ui::DisassemblyWidget {
	Q_OBJECT

public:
	/** */
	DisassemblyWidget (QWidget *parent = 0);

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void addNextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode);

signals:
	/** */
	void enableDisable (bool b);

}; //end class DisassemblyWidget

#endif //JAF__DISASSEMBLY_WIDGET_HH

