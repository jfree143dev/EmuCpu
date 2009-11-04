/*
 * sim8086 -- Emulates an Intel 8086 processor
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


/**
@file BusInterfaceUnit.hh
@brief Manages the segment registers, the instruction pointer, and memory access.
*/

#ifndef JAF__BUS_INTERFACE_UNIT_HH
#define JAF__BUS_INTERFACE_UNIT_HH

#include "Defines.hh"
#include "Memory.hh"
#include "Register.hh"
#include "MemoryAddress.hh"
#include <vector>
#include <iostream>

class CpuComponents;
class BusInterfaceUnitPrivate;

/**
@class BusInterfaceUnit
@brief Manages the segment registers, the instruction pointer, and memory access.
*/
class BusInterfaceUnit {
	BusInterfaceUnitPrivate *p;

	unsigned short m_sregs[Jaf::SREG_COUNT];
	Register<unsigned short> m_seg_regs[Jaf::SREG_COUNT];

#if 0
	unsigned short m_cs;
	unsigned short m_ds;
	unsigned short m_es;
	unsigned short m_ss;
#endif

	unsigned short m_ip;
	unsigned short m_seg_override;

#if 0
	Register<unsigned short> m_sreg_cs;
	Register<unsigned short> m_sreg_ds;
	Register<unsigned short> m_sreg_es;
	Register<unsigned short> m_sreg_ss;
#endif

	Register<unsigned short> m_reg_ip;

	Memory *m_memory;

public:
	/** */
	BusInterfaceUnit ();

	/** */
	BusInterfaceUnit (const BusInterfaceUnit &src);

	/** */
	~BusInterfaceUnit ();

	/** */
	void initialize ();

	/** Create a connection to the CpuComponents */
	void connectTo (CpuComponents &cpu);

	/** */
	Register<unsigned short>& getSegReg (size_t index);

	/** */
	void setSegReg (size_t index, unsigned short val);

	/** */
	Register<unsigned short>& getSegRegCS ();

	/** */
	void setSegRegCS (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegDS ();

	/** */
	void setSegRegDS (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegES ();

	/** */
	void setSegRegES (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegSS ();

	/** */
	void setSegRegSS (unsigned short val);

	/** */
	Register<unsigned short>& getRegIP ();

	/** */
	void setRegIP (unsigned short val);

	/** */
	void setSegOverride (unsigned short val);

	/** */
	template<typename T>
	void getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset, bool override_the_override = false);

	/** */
	template<typename T>
	MemoryAddress<T>*
	getMemoryAddress (unsigned short seg, unsigned short offset, bool override_the_override = false);

	/** Read sizeof(T) bytes starting at IP and then increment IP sizeof(T) bytes */
	template<typename T>
	T getInstructionBytes () {
		size_t m_phys_addr = m_seg_regs[Jaf::SREG_CS] << 4;
		m_phys_addr += m_reg_ip;
		T val;
		m_memory->read (m_phys_addr, val);

		m_reg_ip += sizeof(T);

		return val;
	}
}; //end class BusInterfaceUnit

template<typename T>
void
BusInterfaceUnit::getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset, bool override_the_override) {
	if (!override_the_override && m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	mem_addr = new MemoryAddress<T> (m_memory, seg, offset);
}

template<typename T>
MemoryAddress<T>*
BusInterfaceUnit::getMemoryAddress (unsigned short seg, unsigned short offset, bool override_the_override) {
	if (!override_the_override && m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	return new MemoryAddress<T> (m_memory, seg, offset);
}

#endif //JAF__BUS_INTERFACE_UNIT_HH

