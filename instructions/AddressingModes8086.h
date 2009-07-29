{ 'A', "Direct address: the instruction has no ModR/M byte; the address of the operand is encoded in the instruction. No base register, index register, or scaling factor can be applied." },
{ 'C', "The reg field of the ModR/M byte selects a control register." },
{ 'D', "The reg field of the ModR/M byte selects a debug register." },
{ 'E', "A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, a displacement." },
{ 'F', "EFLAGS/RFLAGS Register." },
{ 'G', "The reg field of the ModR/M byte selects a general register." },
{ 'I', "Immediate data: the operand value is encoded in subsequent bytes of the instruction." },
{ 'J', "The instruction contains a relative offset to be added to the instruction pointer register." },
{ 'M', "The ModR/M byte may refer only to memory." },
{ 'N', "The R/M field of the ModR/M byte selects a packed-quadword, MMX technology register." },
{ 'O', "The instruction has no ModR/M byte. The offset of the operand is coded as a word or double word (depending on address size attribute) in the instruction. No base register, index register, or scaling factor can be applied." },
{ 'P', "The reg field of the ModR/M byte selects a packed quadword MMX technology register." },
{ 'Q', "A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement." },
{ 'R', "The R/M field of the ModR/M byte may refer only to a general register." },
{ 'S', "The reg field of the ModR/M byte selects a segment register." },
{ 'U', "The R/M field of the ModR/M byte selects a 128-bit XMM register." },
{ 'V', "The reg field of the ModR/M byte selects a 128-bit XMM register." },
{ 'W', "A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement." },
{ 'X', "Memory addressed by the DS:rSI register pair." },
{ 'Y', "Memory addressed by the ES:rDI register pair." },
{ 0, 0 };
