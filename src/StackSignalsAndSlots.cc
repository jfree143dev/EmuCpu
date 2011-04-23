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


#include "StackSignalsAndSlots.hh"

void
StackSignalsAndSlots::sigcSlotStackPush (unsigned short seg, unsigned short off, unsigned short val) {
	Q_EMIT stackPush (seg, off, val);
}

void
StackSignalsAndSlots::sigcSlotStackPop () {
	Q_EMIT stackPop ();
}

void
StackSignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

