/*
 * emucpu -- Emulates processors
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "DisassemblySignalsAndSlots.hh"

/* SIGC++ SLOTS */

void
DisassemblySignalsAndSlots::sigcSlotNextInstruction (const std::string &s1, const std::string &s2, const std::string &s3, const std::string &s4) {
	Q_EMIT nextInstruction (s1.c_str (), s2.c_str (), s3.c_str (), s4.c_str ());
}

/* QT SLOTS */
void
DisassemblySignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

