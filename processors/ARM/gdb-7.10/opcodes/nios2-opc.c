/* Altera Nios II opcode list.
   Copyright (C) 2012-2015 Free Software Foundation, Inc.
   Contributed by Nigel Gray (ngray@altera.com).
   Contributed by Mentor Graphics, Inc.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include <stdio.h>
#include "opcode/nios2.h"

/* Register string table */

const struct nios2_reg nios2_builtin_regs[] = {
  /* Standard register names.  */
  {"zero", 0, REG_NORMAL},
  {"at", 1, REG_NORMAL},			/* assembler temporary */
  {"r2", 2, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r3", 3, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r4", 4, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r5", 5, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r6", 6, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r7", 7, REG_NORMAL | REG_3BIT | REG_LDWM},
  {"r8", 8, REG_NORMAL | REG_LDWM},
  {"r9", 9, REG_NORMAL | REG_LDWM},
  {"r10", 10, REG_NORMAL | REG_LDWM},
  {"r11", 11, REG_NORMAL | REG_LDWM},
  {"r12", 12, REG_NORMAL | REG_LDWM},
  {"r13", 13, REG_NORMAL | REG_LDWM},
  {"r14", 14, REG_NORMAL | REG_LDWM},
  {"r15", 15, REG_NORMAL | REG_LDWM},
  {"r16", 16, REG_NORMAL | REG_3BIT | REG_LDWM | REG_POP},
  {"r17", 17, REG_NORMAL | REG_3BIT | REG_LDWM | REG_POP},
  {"r18", 18, REG_NORMAL | REG_LDWM | REG_POP},
  {"r19", 19, REG_NORMAL | REG_LDWM | REG_POP},
  {"r20", 20, REG_NORMAL | REG_LDWM | REG_POP},
  {"r21", 21, REG_NORMAL | REG_LDWM | REG_POP},
  {"r22", 22, REG_NORMAL | REG_LDWM | REG_POP},
  {"r23", 23, REG_NORMAL | REG_LDWM | REG_POP},
  {"et", 24, REG_NORMAL},
  {"bt", 25, REG_NORMAL},
  {"gp", 26, REG_NORMAL},			/* global pointer */
  {"sp", 27, REG_NORMAL},			/* stack pointer */
  {"fp", 28, REG_NORMAL | REG_LDWM | REG_POP},	/* frame pointer */
  {"ea", 29, REG_NORMAL},			/* exception return address */
  {"sstatus", 30, REG_NORMAL},			/* saved processor status */
  {"ra", 31, REG_NORMAL | REG_LDWM | REG_POP},	/* return address */

  /* Alternative names for special registers.  */
  {"r0", 0, REG_NORMAL},
  {"r1", 1, REG_NORMAL},
  {"r24", 24, REG_NORMAL},
  {"r25", 25, REG_NORMAL},
  {"r26", 26, REG_NORMAL},
  {"r27", 27, REG_NORMAL},
  {"r28", 28, REG_NORMAL | REG_LDWM | REG_POP},
  {"r29", 29, REG_NORMAL},
  {"r30", 30, REG_NORMAL},
  {"ba", 30, REG_NORMAL},			/* breakpoint return address */
  {"r31", 31, REG_NORMAL | REG_LDWM | REG_POP},

  /* Control register names.  */
  {"status", 0, REG_CONTROL},
  {"estatus", 1, REG_CONTROL},
  {"bstatus", 2, REG_CONTROL},
  {"ienable", 3, REG_CONTROL},
  {"ipending", 4, REG_CONTROL},
  {"cpuid", 5, REG_CONTROL},
  {"ctl6", 6, REG_CONTROL},
  {"exception", 7, REG_CONTROL},
  {"pteaddr", 8, REG_CONTROL},
  {"tlbacc", 9, REG_CONTROL},
  {"tlbmisc", 10, REG_CONTROL},
  {"eccinj", 11, REG_CONTROL},
  {"badaddr", 12, REG_CONTROL},
  {"config", 13, REG_CONTROL},
  {"mpubase", 14, REG_CONTROL},
  {"mpuacc", 15, REG_CONTROL},
  {"ctl16", 16, REG_CONTROL},
  {"ctl17", 17, REG_CONTROL},
  {"ctl18", 18, REG_CONTROL},
  {"ctl19", 19, REG_CONTROL},
  {"ctl20", 20, REG_CONTROL},
  {"ctl21", 21, REG_CONTROL},
  {"ctl22", 22, REG_CONTROL},
  {"ctl23", 23, REG_CONTROL},
  {"ctl24", 24, REG_CONTROL},
  {"ctl25", 25, REG_CONTROL},
  {"ctl26", 26, REG_CONTROL},
  {"ctl27", 27, REG_CONTROL},
  {"ctl28", 28, REG_CONTROL},
  {"ctl29", 29, REG_CONTROL},
  {"ctl30", 30, REG_CONTROL},
  {"ctl31", 31, REG_CONTROL},

  /* Alternative names for special control registers.  */
  {"ctl0", 0, REG_CONTROL},
  {"ctl1", 1, REG_CONTROL},
  {"ctl2", 2, REG_CONTROL},
  {"ctl3", 3, REG_CONTROL},
  {"ctl4", 4, REG_CONTROL},
  {"ctl5", 5, REG_CONTROL},
  {"ctl7", 7, REG_CONTROL},
  {"ctl8", 8, REG_CONTROL},
  {"ctl9", 9, REG_CONTROL},
  {"ctl10", 10, REG_CONTROL},
  {"ctl11", 11, REG_CONTROL},
  {"ctl12", 12, REG_CONTROL},
  {"ctl13", 13, REG_CONTROL},
  {"ctl14", 14, REG_CONTROL},
  {"ctl15", 15, REG_CONTROL},

  /* Coprocessor register names.  */
  {"c0", 0, REG_COPROCESSOR},
  {"c1", 1, REG_COPROCESSOR},
  {"c2", 2, REG_COPROCESSOR},
  {"c3", 3, REG_COPROCESSOR},
  {"c4", 4, REG_COPROCESSOR},
  {"c5", 5, REG_COPROCESSOR},
  {"c6", 6, REG_COPROCESSOR},
  {"c7", 7, REG_COPROCESSOR},
  {"c8", 8, REG_COPROCESSOR},
  {"c9", 9, REG_COPROCESSOR},
  {"c10", 10, REG_COPROCESSOR},
  {"c11", 11, REG_COPROCESSOR},
  {"c12", 12, REG_COPROCESSOR},
  {"c13", 13, REG_COPROCESSOR},
  {"c14", 14, REG_COPROCESSOR},
  {"c15", 15, REG_COPROCESSOR},
  {"c16", 16, REG_COPROCESSOR},
  {"c17", 17, REG_COPROCESSOR},
  {"c18", 18, REG_COPROCESSOR},
  {"c19", 19, REG_COPROCESSOR},
  {"c20", 20, REG_COPROCESSOR},
  {"c21", 21, REG_COPROCESSOR},
  {"c22", 22, REG_COPROCESSOR},
  {"c23", 23, REG_COPROCESSOR},
  {"c24", 24, REG_COPROCESSOR},
  {"c25", 25, REG_COPROCESSOR},
  {"c26", 26, REG_COPROCESSOR},
  {"c27", 27, REG_COPROCESSOR},
  {"c28", 28, REG_COPROCESSOR},
  {"c29", 29, REG_COPROCESSOR},
  {"c30", 30, REG_COPROCESSOR},
  {"c31", 31, REG_COPROCESSOR},
};

#define NIOS2_NUM_REGS \
       ((sizeof nios2_builtin_regs) / (sizeof (nios2_builtin_regs[0])))
const int nios2_num_builtin_regs = NIOS2_NUM_REGS;

/* This is not const in order to allow for dynamic extensions to the
   built-in instruction set.  */
struct nios2_reg *nios2_regs = (struct nios2_reg *) nios2_builtin_regs;
int nios2_num_regs = NIOS2_NUM_REGS;
#undef NIOS2_NUM_REGS

/* This is the opcode table used by the Nios II GNU as, disassembler
   and GDB.  */
const struct nios2_opcode nios2_r1_opcodes[] =
{
  /* { name, args, args_test, num_args, size, format,
       match, mask, pinfo, overflow } */
  {"add", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_ADD, MASK_R1_ADD, 0, no_overflow},
  {"addi", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_ADDI, MASK_R1_ADDI, 0, signed_immed16_overflow},
  {"and", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_AND, MASK_R1_AND, 0, no_overflow},
  {"andhi", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_ANDHI, MASK_R1_ANDHI, 0, unsigned_immed16_overflow},
  {"andi", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_ANDI, MASK_R1_ANDI, 0, unsigned_immed16_overflow},
  {"beq", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BEQ, MASK_R1_BEQ, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bge", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BGE, MASK_R1_BGE, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgeu", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BGEU, MASK_R1_BGEU, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgt", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BGT, MASK_R1_BGT,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgtu", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BGTU, MASK_R1_BGTU,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"ble", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BLE, MASK_R1_BLE,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bleu", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BLEU, MASK_R1_BLEU,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"blt", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BLT, MASK_R1_BLT, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bltu", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BLTU, MASK_R1_BLTU, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bne", "s,t,o", "s,t,o,E", 3, 4, iw_i_type,
   MATCH_R1_BNE, MASK_R1_BNE, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"br", "o", "o,E", 1, 4, iw_i_type,
   MATCH_R1_BR, MASK_R1_BR, NIOS2_INSN_UBRANCH, branch_target_overflow},
  {"break", "j", "j,E", 1, 4, iw_r_type,
   MATCH_R1_BREAK, MASK_R1_BREAK, NIOS2_INSN_OPTARG, no_overflow},
  {"bret", "", "E", 0, 4, iw_r_type,
   MATCH_R1_BRET, MASK_R1_BRET, 0, no_overflow},
  {"call", "m", "m,E", 1, 4, iw_j_type,
   MATCH_R1_CALL, MASK_R1_CALL, NIOS2_INSN_CALL, call_target_overflow},
  {"callr", "s", "s,E", 1, 4, iw_r_type,
   MATCH_R1_CALLR, MASK_R1_CALLR, 0, no_overflow},
  {"cmpeq", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPEQ, MASK_R1_CMPEQ, 0, no_overflow},
  {"cmpeqi", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPEQI, MASK_R1_CMPEQI, 0, signed_immed16_overflow},
  {"cmpge", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPGE, MASK_R1_CMPGE, 0, no_overflow},
  {"cmpgei", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPGEI, MASK_R1_CMPGEI, 0, signed_immed16_overflow},
  {"cmpgeu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPGEU, MASK_R1_CMPGEU, 0, no_overflow},
  {"cmpgeui", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_CMPGEUI, MASK_R1_CMPGEUI, 0, unsigned_immed16_overflow},
  {"cmpgt", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPGT, MASK_R1_CMPGT, NIOS2_INSN_MACRO, no_overflow},
  {"cmpgti", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPGTI, MASK_R1_CMPGTI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"cmpgtu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPGTU, MASK_R1_CMPGTU, NIOS2_INSN_MACRO, no_overflow},
  {"cmpgtui", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_CMPGTUI, MASK_R1_CMPGTUI,
   NIOS2_INSN_MACRO, unsigned_immed16_overflow},
  {"cmple", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPLE, MASK_R1_CMPLE, NIOS2_INSN_MACRO, no_overflow},
  {"cmplei", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPLEI, MASK_R1_CMPLEI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"cmpleu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPLEU, MASK_R1_CMPLEU, NIOS2_INSN_MACRO, no_overflow},
  {"cmpleui", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_CMPLEUI, MASK_R1_CMPLEUI,
   NIOS2_INSN_MACRO, unsigned_immed16_overflow},
  {"cmplt", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPLT, MASK_R1_CMPLT, 0, no_overflow},
  {"cmplti", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPLTI, MASK_R1_CMPLTI, 0, signed_immed16_overflow},
  {"cmpltu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPLTU, MASK_R1_CMPLTU, 0, no_overflow},
  {"cmpltui", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_CMPLTUI, MASK_R1_CMPLTUI, 0, unsigned_immed16_overflow},
  {"cmpne", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_CMPNE, MASK_R1_CMPNE, 0, no_overflow},
  {"cmpnei", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_CMPNEI, MASK_R1_CMPNEI, 0, signed_immed16_overflow},
  {"custom", "l,d,s,t", "l,d,s,t,E", 4, 4, iw_custom_type,
   MATCH_R1_CUSTOM, MASK_R1_CUSTOM, 0, custom_opcode_overflow},
  {"div", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_DIV, MASK_R1_DIV, 0, no_overflow},
  {"divu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_DIVU, MASK_R1_DIVU, 0, no_overflow},
  {"eret", "", "E", 0, 4, iw_r_type,
   MATCH_R1_ERET, MASK_R1_ERET, 0, no_overflow},
  {"flushd", "i(s)", "i(s),E", 2, 4, iw_i_type,
   MATCH_R1_FLUSHD, MASK_R1_FLUSHD, 0, address_offset_overflow},
  {"flushda", "i(s)", "i(s),E", 2, 4, iw_i_type,
   MATCH_R1_FLUSHDA, MASK_R1_FLUSHDA, 0, address_offset_overflow},
  {"flushi", "s", "s,E", 1, 4, iw_r_type,
   MATCH_R1_FLUSHI, MASK_R1_FLUSHI, 0, no_overflow},
  {"flushp", "", "E", 0, 4, iw_r_type,
   MATCH_R1_FLUSHP, MASK_R1_FLUSHP, 0, no_overflow},
  {"initd", "i(s)", "i(s),E", 2, 4, iw_i_type,
   MATCH_R1_INITD, MASK_R1_INITD, 0, address_offset_overflow},
  {"initda", "i(s)", "i(s),E", 2, 4, iw_i_type,
   MATCH_R1_INITDA, MASK_R1_INITDA, 0, address_offset_overflow},
  {"initi", "s", "s,E", 1, 4, iw_r_type,
   MATCH_R1_INITI, MASK_R1_INITI, 0, no_overflow},
  {"jmp", "s", "s,E", 1, 4, iw_r_type,
   MATCH_R1_JMP, MASK_R1_JMP, 0, no_overflow},
  {"jmpi", "m", "m,E", 1, 4, iw_j_type,
   MATCH_R1_JMPI, MASK_R1_JMPI, 0, call_target_overflow},
  {"ldb", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDB, MASK_R1_LDB, 0, address_offset_overflow},
  {"ldbio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDBIO, MASK_R1_LDBIO, 0, address_offset_overflow},
  {"ldbu", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDBU, MASK_R1_LDBU, 0, address_offset_overflow},
  {"ldbuio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDBUIO, MASK_R1_LDBUIO, 0, address_offset_overflow},
  {"ldh", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDH, MASK_R1_LDH, 0, address_offset_overflow},
  {"ldhio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDHIO, MASK_R1_LDHIO, 0, address_offset_overflow},
  {"ldhu", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDHU, MASK_R1_LDHU, 0, address_offset_overflow},
  {"ldhuio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDHUIO, MASK_R1_LDHUIO, 0, address_offset_overflow},
  {"ldw", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDW, MASK_R1_LDW, 0, address_offset_overflow},
  {"ldwio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_LDWIO, MASK_R1_LDWIO, 0, address_offset_overflow},
  {"mov", "d,s", "d,s,E", 2, 4, iw_r_type,
   MATCH_R1_MOV, MASK_R1_MOV, NIOS2_INSN_MACRO_MOV, no_overflow},
  {"movhi", "t,u", "t,u,E", 2, 4, iw_i_type,
   MATCH_R1_MOVHI, MASK_R1_MOVHI,
   NIOS2_INSN_MACRO_MOVI, unsigned_immed16_overflow},
  {"movi", "t,i", "t,i,E", 2, 4, iw_i_type,
   MATCH_R1_MOVI, MASK_R1_MOVI, NIOS2_INSN_MACRO_MOVI, signed_immed16_overflow},
  {"movia", "t,o", "t,o,E", 2, 4, iw_i_type,
   MATCH_R1_ORHI, MASK_R1_ORHI, NIOS2_INSN_MACRO_MOVIA, no_overflow},
  {"movui", "t,u", "t,u,E", 2, 4, iw_i_type,
   MATCH_R1_MOVUI, MASK_R1_MOVUI,
   NIOS2_INSN_MACRO_MOVI, unsigned_immed16_overflow},
  {"mul", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_MUL, MASK_R1_MUL, 0, no_overflow},
  {"muli", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_MULI, MASK_R1_MULI, 0, signed_immed16_overflow},
  {"mulxss", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_MULXSS, MASK_R1_MULXSS, 0, no_overflow},
  {"mulxsu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_MULXSU, MASK_R1_MULXSU, 0, no_overflow},
  {"mulxuu", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_MULXUU, MASK_R1_MULXUU, 0, no_overflow},
  {"nextpc", "d", "d,E", 1, 4, iw_r_type,
   MATCH_R1_NEXTPC, MASK_R1_NEXTPC, 0, no_overflow},
  {"nop", "", "E", 0, 4, iw_r_type,
   MATCH_R1_NOP, MASK_R1_NOP, NIOS2_INSN_MACRO_MOV, no_overflow},
  {"nor", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_NOR, MASK_R1_NOR, 0, no_overflow},
  {"or", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_OR, MASK_R1_OR, 0, no_overflow},
  {"orhi", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_ORHI, MASK_R1_ORHI, 0, unsigned_immed16_overflow},
  {"ori", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_ORI, MASK_R1_ORI, 0, unsigned_immed16_overflow},
  {"rdctl", "d,c", "d,c,E", 2, 4, iw_r_type,
   MATCH_R1_RDCTL, MASK_R1_RDCTL, 0, no_overflow},
  {"rdprs", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_RDPRS, MASK_R1_RDPRS, 0, signed_immed16_overflow},
  {"ret", "", "E", 0, 4, iw_r_type,
   MATCH_R1_RET, MASK_R1_RET, 0, no_overflow},
  {"rol", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_ROL, MASK_R1_ROL, 0, no_overflow},
  {"roli", "d,s,j", "d,s,j,E", 3, 4, iw_r_type,
   MATCH_R1_ROLI, MASK_R1_ROLI, 0, unsigned_immed5_overflow},
  {"ror", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_ROR, MASK_R1_ROR, 0, no_overflow},
  {"sll", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_SLL, MASK_R1_SLL, 0, no_overflow},
  {"slli", "d,s,j", "d,s,j,E", 3, 4, iw_r_type,
   MATCH_R1_SLLI, MASK_R1_SLLI, 0, unsigned_immed5_overflow},
  {"sra", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_SRA, MASK_R1_SRA, 0, no_overflow},
  {"srai", "d,s,j", "d,s,j,E", 3, 4, iw_r_type,
   MATCH_R1_SRAI, MASK_R1_SRAI, 0, unsigned_immed5_overflow},
  {"srl", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_SRL, MASK_R1_SRL, 0, no_overflow},
  {"srli", "d,s,j", "d,s,j,E", 3, 4, iw_r_type,
   MATCH_R1_SRLI, MASK_R1_SRLI, 0, unsigned_immed5_overflow},
  {"stb", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STB, MASK_R1_STB, 0, address_offset_overflow},
  {"stbio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STBIO, MASK_R1_STBIO, 0, address_offset_overflow},
  {"sth", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STH, MASK_R1_STH, 0, address_offset_overflow},
  {"sthio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STHIO, MASK_R1_STHIO, 0, address_offset_overflow},
  {"stw", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STW, MASK_R1_STW, 0, address_offset_overflow},
  {"stwio", "t,i(s)", "t,i(s),E", 3, 4, iw_i_type,
   MATCH_R1_STWIO, MASK_R1_STWIO, 0, address_offset_overflow},
  {"sub", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_SUB, MASK_R1_SUB, 0, no_overflow},
  {"subi", "t,s,i", "t,s,i,E", 3, 4, iw_i_type,
   MATCH_R1_SUBI, MASK_R1_SUBI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"sync", "", "E", 0, 4, iw_r_type,
   MATCH_R1_SYNC, MASK_R1_SYNC, 0, no_overflow},
  {"trap", "j", "j,E", 1, 4, iw_r_type,
   MATCH_R1_TRAP, MASK_R1_TRAP, NIOS2_INSN_OPTARG, no_overflow},
  {"wrctl", "c,s", "c,s,E", 2, 4, iw_r_type,
   MATCH_R1_WRCTL, MASK_R1_WRCTL, 0, no_overflow},
  {"wrprs", "d,s", "d,s,E", 2, 4, iw_r_type,
   MATCH_R1_WRPRS, MASK_R1_WRPRS, 0, no_overflow},
  {"xor", "d,s,t", "d,s,t,E", 3, 4, iw_r_type,
   MATCH_R1_XOR, MASK_R1_XOR, 0, no_overflow},
  {"xorhi", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_XORHI, MASK_R1_XORHI, 0, unsigned_immed16_overflow},
  {"xori", "t,s,u", "t,s,u,E", 3, 4, iw_i_type,
   MATCH_R1_XORI, MASK_R1_XORI, 0, unsigned_immed16_overflow}
};

#define NIOS2_NUM_R1_OPCODES \
       ((sizeof nios2_r1_opcodes) / (sizeof (nios2_r1_opcodes[0])))
const int nios2_num_r1_opcodes = NIOS2_NUM_R1_OPCODES;


const struct nios2_opcode nios2_r2_opcodes[] =
{
  /* { name, args, args_test, num_args, size, format,
       match, mask, pinfo, overflow } */
  {"add", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_ADD, MASK_R2_ADD, 0, no_overflow},
  {"addi", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ADDI, MASK_R2_ADDI, 0, signed_immed16_overflow},
  {"add.n", "D,S,T", "D,S,T,E", 3, 2, iw_T3X1_type,
   MATCH_R2_ADD_N, MASK_R2_ADD_N, 0, no_overflow},
  {"addi.n", "D,S,e", "D,S,e,E", 3, 2, iw_T2X1I3_type,
   MATCH_R2_ADDI_N, MASK_R2_ADDI_N, 0, enumeration_overflow},
  {"and", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_AND, MASK_R2_AND, 0, no_overflow},
  {"andchi", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ANDCHI, MASK_R2_ANDCHI, 0, unsigned_immed16_overflow},
  {"andci", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ANDCI, MASK_R2_ANDCI, 0, unsigned_immed16_overflow},
  {"andhi", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ANDHI, MASK_R2_ANDHI, 0, unsigned_immed16_overflow},
  {"andi", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ANDI, MASK_R2_ANDI, 0, unsigned_immed16_overflow},
  {"andi.n", "T,S,g", "T,S,g,E", 3, 2, iw_T2I4_type,
   MATCH_R2_ANDI_N, MASK_R2_ANDI_N, 0, enumeration_overflow},
  {"and.n", "D,S,T", "D,S,T,E", 3, 2, iw_T2X3_type,
   MATCH_R2_AND_N, MASK_R2_AND_N, 0, no_overflow},
  {"beq", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BEQ, MASK_R2_BEQ, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"beqz.n", "S,P", "S,P,E", 2, 2, iw_T1I7_type,
   MATCH_R2_BEQZ_N, MASK_R2_BEQZ_N, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bge", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BGE, MASK_R2_BGE, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgeu", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BGEU, MASK_R2_BGEU, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgt", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BGT, MASK_R2_BGT,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bgtu", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BGTU, MASK_R2_BGTU,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"ble", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BLE, MASK_R2_BLE,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bleu", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BLEU, MASK_R2_BLEU,
   NIOS2_INSN_MACRO|NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"blt", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BLT, MASK_R2_BLT, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bltu", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BLTU, MASK_R2_BLTU, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bne", "s,t,o", "s,t,o,E", 3, 4, iw_F2I16_type,
   MATCH_R2_BNE, MASK_R2_BNE, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"bnez.n", "S,P", "S,P,E", 2, 2, iw_T1I7_type,
   MATCH_R2_BNEZ_N, MASK_R2_BNEZ_N, NIOS2_INSN_CBRANCH, branch_target_overflow},
  {"br", "o", "o,E", 1, 4, iw_F2I16_type,
   MATCH_R2_BR, MASK_R2_BR, NIOS2_INSN_UBRANCH, branch_target_overflow},
  {"break", "j", "j,E", 1, 4, iw_F3X6L5_type,
   MATCH_R2_BREAK, MASK_R2_BREAK, NIOS2_INSN_OPTARG, no_overflow},
  {"break.n", "j", "j,E", 1, 2, iw_X2L5_type,
   MATCH_R2_BREAK_N, MASK_R2_BREAK_N, NIOS2_INSN_OPTARG, no_overflow},
  {"bret", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_BRET, MASK_R2_BRET, 0, no_overflow},
  {"br.n", "O", "O,E", 1, 2, iw_I10_type,
   MATCH_R2_BR_N, MASK_R2_BR_N, NIOS2_INSN_UBRANCH, branch_target_overflow},
  {"call", "m", "m,E", 1, 4, iw_L26_type,
   MATCH_R2_CALL, MASK_R2_CALL, NIOS2_INSN_CALL, call_target_overflow},
  {"callr", "s", "s,E", 1, 4, iw_F3X6_type,
   MATCH_R2_CALLR, MASK_R2_CALLR, 0, no_overflow},
  {"callr.n", "s", "s,E", 1, 2, iw_F1X1_type,
   MATCH_R2_CALLR_N, MASK_R2_CALLR_N, 0, no_overflow},
  {"cmpeq", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPEQ, MASK_R2_CMPEQ, 0, no_overflow},
  {"cmpeqi", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPEQI, MASK_R2_CMPEQI, 0, signed_immed16_overflow},
  {"cmpge", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPGE, MASK_R2_CMPGE, 0, no_overflow},
  {"cmpgei", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPGEI, MASK_R2_CMPGEI, 0, signed_immed16_overflow},
  {"cmpgeu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPGEU, MASK_R2_CMPGEU, 0, no_overflow},
  {"cmpgeui", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPGEUI, MASK_R2_CMPGEUI, 0, unsigned_immed16_overflow},
  {"cmpgt", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPGT, MASK_R2_CMPGT, NIOS2_INSN_MACRO, no_overflow},
  {"cmpgti", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPGTI, MASK_R2_CMPGTI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"cmpgtu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPGTU, MASK_R2_CMPGTU, NIOS2_INSN_MACRO, no_overflow},
  {"cmpgtui", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPGTUI, MASK_R2_CMPGTUI,
   NIOS2_INSN_MACRO, unsigned_immed16_overflow},
  {"cmple", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPLE, MASK_R2_CMPLE, NIOS2_INSN_MACRO, no_overflow},
  {"cmplei", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPLEI, MASK_R2_CMPLEI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"cmpleu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPLEU, MASK_R2_CMPLEU, NIOS2_INSN_MACRO, no_overflow},
  {"cmpleui", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPLEUI, MASK_R2_CMPLEUI,
   NIOS2_INSN_MACRO, unsigned_immed16_overflow},
  {"cmplt", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPLT, MASK_R2_CMPLT, 0, no_overflow},
  {"cmplti", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPLTI, MASK_R2_CMPLTI, 0, signed_immed16_overflow},
  {"cmpltu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPLTU, MASK_R2_CMPLTU, 0, no_overflow},
  {"cmpltui", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPLTUI, MASK_R2_CMPLTUI, 0, unsigned_immed16_overflow},
  {"cmpne", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_CMPNE, MASK_R2_CMPNE, 0, no_overflow},
  {"cmpnei", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_CMPNEI, MASK_R2_CMPNEI, 0, signed_immed16_overflow},
  {"custom", "l,d,s,t", "l,d,s,t,E", 4, 4, iw_F3X8_type,
   MATCH_R2_CUSTOM, MASK_R2_CUSTOM, 0, custom_opcode_overflow},
  {"div", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_DIV, MASK_R2_DIV, 0, no_overflow},
  {"divu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_DIVU, MASK_R2_DIVU, 0, no_overflow},
  {"eni", "j", "j,E", 1, 4, iw_F3X6L5_type,
   MATCH_R2_ENI, MASK_R2_ENI, NIOS2_INSN_OPTARG, no_overflow},
  {"eret", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_ERET, MASK_R2_ERET, 0, no_overflow},
  {"extract", "t,s,j,k", "t,s,j,k,E", 4, 4, iw_F2X6L10_type,
   MATCH_R2_EXTRACT, MASK_R2_EXTRACT, 0, no_overflow},
  {"flushd", "I(s)", "I(s),E", 2, 4, iw_F1X4I12_type,
   MATCH_R2_FLUSHD, MASK_R2_FLUSHD, 0, address_offset_overflow},
  {"flushda", "I(s)", "I(s),E", 2, 4, iw_F1X4I12_type,
   MATCH_R2_FLUSHDA, MASK_R2_FLUSHDA, 0, address_offset_overflow},
  {"flushi", "s", "s,E", 1, 4, iw_F3X6_type,
   MATCH_R2_FLUSHI, MASK_R2_FLUSHI, 0, no_overflow},
  {"flushp", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_FLUSHP, MASK_R2_FLUSHP, 0, no_overflow},
  {"initd", "I(s)", "I(s),E", 2, 4, iw_F1X4I12_type,
   MATCH_R2_INITD, MASK_R2_INITD, 0, address_offset_overflow},
  {"initda", "I(s)", "I(s),E", 2, 4, iw_F1X4I12_type,
   MATCH_R2_INITDA, MASK_R2_INITDA, 0, address_offset_overflow},
  {"initi", "s", "s,E", 1, 4, iw_F3X6_type,
   MATCH_R2_INITI, MASK_R2_INITI, 0, no_overflow},
  {"insert", "t,s,j,k", "t,s,j,k,E", 4, 4, iw_F2X6L10_type,
   MATCH_R2_INSERT, MASK_R2_INSERT, 0, no_overflow},
  {"jmp", "s", "s,E", 1, 4, iw_F3X6_type,
   MATCH_R2_JMP, MASK_R2_JMP, 0, no_overflow},
  {"jmpi", "m", "m,E", 1, 4, iw_L26_type,
   MATCH_R2_JMPI, MASK_R2_JMPI, 0, call_target_overflow},
  {"jmpr.n", "s", "s,E", 1, 2, iw_F1X1_type,
   MATCH_R2_JMPR_N, MASK_R2_JMPR_N, 0, no_overflow},
  {"ldb", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_LDB, MASK_R2_LDB, 0, address_offset_overflow},
  {"ldbio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_LDBIO, MASK_R2_LDBIO, 0, signed_immed12_overflow},
  {"ldbu", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_LDBU, MASK_R2_LDBU, 0, address_offset_overflow},
  {"ldbuio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_LDBUIO, MASK_R2_LDBUIO, 0, signed_immed12_overflow},
  {"ldbu.n", "T,Y(S)", "T,Y(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_LDBU_N, MASK_R2_LDBU_N, 0, address_offset_overflow},
  {"ldex", "d,(s)", "d,(s),E", 2, 4, iw_F3X6_type,
   MATCH_R2_LDEX, MASK_R2_LDEX, 0, no_overflow},
  {"ldh", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_LDH, MASK_R2_LDH, 0, address_offset_overflow},
  {"ldhio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_LDHIO, MASK_R2_LDHIO, 0, signed_immed12_overflow},
  {"ldhu", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_LDHU, MASK_R2_LDHU, 0, address_offset_overflow},
  {"ldhuio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_LDHUIO, MASK_R2_LDHUIO, 0, signed_immed12_overflow},
  {"ldhu.n", "T,X(S)", "T,X(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_LDHU_N, MASK_R2_LDHU_N, 0, address_offset_overflow},
  {"ldsex", "d,(s)", "d,(s),E", 2, 4, iw_F3X6_type,
   MATCH_R2_LDSEX, MASK_R2_LDSEX, 0, no_overflow},
  {"ldw", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_LDW, MASK_R2_LDW, 0, address_offset_overflow},
  {"ldwio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_LDWIO, MASK_R2_LDWIO, 0, signed_immed12_overflow},
  {"ldwm", "R,B", "R,B,E", 2, 4, iw_F1X4L17_type,
   MATCH_R2_LDWM, MASK_R2_LDWM, 0, no_overflow},
  {"ldw.n", "T,W(S)", "T,W(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_LDW_N, MASK_R2_LDW_N, 0, address_offset_overflow},
  {"ldwsp.n", "t,V(s)", "t,V(s),E", 3, 2, iw_F1I5_type,
   MATCH_R2_LDWSP_N, MASK_R2_LDWSP_N, 0, address_offset_overflow},
  {"merge", "t,s,j,k", "t,s,j,k,E", 4, 4, iw_F2X6L10_type,
   MATCH_R2_MERGE, MASK_R2_MERGE, 0, no_overflow},
  {"mov", "d,s", "d,s,E", 2, 4, iw_F3X6_type,
   MATCH_R2_MOV, MASK_R2_MOV, NIOS2_INSN_MACRO_MOV, no_overflow},
  {"mov.n", "d,s", "d,s,E", 2, 2, iw_F2_type,
   MATCH_R2_MOV_N, MASK_R2_MOV_N, 0, no_overflow},
  {"movi.n", "D,h", "D,h,E", 2, 2, iw_T1I7_type,
   MATCH_R2_MOVI_N, MASK_R2_MOVI_N, 0, enumeration_overflow},
  {"movhi", "t,u", "t,u,E", 2, 4, iw_F2I16_type,
   MATCH_R2_MOVHI, MASK_R2_MOVHI,
   NIOS2_INSN_MACRO_MOVI, unsigned_immed16_overflow},
  {"movi", "t,i", "t,i,E", 2, 4, iw_F2I16_type,
   MATCH_R2_MOVI, MASK_R2_MOVI, NIOS2_INSN_MACRO_MOVI, signed_immed16_overflow},
  {"movia", "t,o", "t,o,E", 2, 4, iw_F2I16_type,
   MATCH_R2_ORHI, MASK_R2_ORHI, NIOS2_INSN_MACRO_MOVIA, no_overflow},
  {"movui", "t,u", "t,u,E", 2, 4, iw_F2I16_type,
   MATCH_R2_MOVUI, MASK_R2_MOVUI,
   NIOS2_INSN_MACRO_MOVI, unsigned_immed16_overflow},
  {"mul", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_MUL, MASK_R2_MUL, 0, no_overflow},
  {"muli", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_MULI, MASK_R2_MULI, 0, signed_immed16_overflow},
  {"mulxss", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_MULXSS, MASK_R2_MULXSS, 0, no_overflow},
  {"mulxsu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_MULXSU, MASK_R2_MULXSU, 0, no_overflow},
  {"mulxuu", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_MULXUU, MASK_R2_MULXUU, 0, no_overflow},
  /* The encoding of the neg.n operands is backwards, not
     the interpretation -- the first operand is still the
     destination and the second the source.  */
  {"neg.n", "S,D", "S,D,E", 2, 2, iw_T2X3_type,
   MATCH_R2_NEG_N, MASK_R2_NEG_N, 0, no_overflow},
  {"nextpc", "d", "d,E", 1, 4, iw_F3X6_type,
   MATCH_R2_NEXTPC, MASK_R2_NEXTPC, 0, no_overflow},
  {"nop", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_NOP, MASK_R2_NOP, NIOS2_INSN_MACRO_MOV, no_overflow},
  {"nop.n", "", "E", 0, 2, iw_F2_type,
   MATCH_R2_NOP_N, MASK_R2_NOP_N, NIOS2_INSN_MACRO_MOV, no_overflow},
  {"nor", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_NOR, MASK_R2_NOR, 0, no_overflow},
  {"not.n", "D,S", "D,S,E", 2, 2, iw_T2X3_type,
   MATCH_R2_NOT_N, MASK_R2_NOT_N, 0, no_overflow},
  {"or", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_OR, MASK_R2_OR, 0, no_overflow},
  {"orhi", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ORHI, MASK_R2_ORHI, 0, unsigned_immed16_overflow},
  {"ori", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_ORI, MASK_R2_ORI, 0, unsigned_immed16_overflow},
  {"or.n", "D,S,T", "D,S,T,E", 3, 2, iw_T2X3_type,
   MATCH_R2_OR_N, MASK_R2_OR_N, 0, no_overflow},
  {"pop.n", "R,W", "R,W,E", 2, 2, iw_L5I4X1_type,
   MATCH_R2_POP_N, MASK_R2_POP_N, NIOS2_INSN_OPTARG, no_overflow},
  {"push.n", "R,W", "R,W,E", 2, 2, iw_L5I4X1_type,
   MATCH_R2_PUSH_N, MASK_R2_PUSH_N, NIOS2_INSN_OPTARG, no_overflow},
  {"rdctl", "d,c", "d,c,E", 2, 4, iw_F3X6L5_type,
   MATCH_R2_RDCTL, MASK_R2_RDCTL, 0, no_overflow},
  {"rdprs", "t,s,I", "t,s,I,E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_RDPRS, MASK_R2_RDPRS, 0, signed_immed12_overflow},
  {"ret", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_RET, MASK_R2_RET, 0, no_overflow},
  {"ret.n", "", "E", 0, 2, iw_X2L5_type,
   MATCH_R2_RET_N, MASK_R2_RET_N, 0, no_overflow},
  {"rol", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_ROL, MASK_R2_ROL, 0, no_overflow},
  {"roli", "d,s,j", "d,s,j,E", 3, 4, iw_F3X6L5_type,
   MATCH_R2_ROLI, MASK_R2_ROLI, 0, unsigned_immed5_overflow},
  {"ror", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_ROR, MASK_R2_ROR, 0, no_overflow},
  {"sll", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_SLL, MASK_R2_SLL, 0, no_overflow},
  {"slli", "d,s,j", "d,s,j,E", 3, 4, iw_F3X6L5_type,
   MATCH_R2_SLLI, MASK_R2_SLLI, 0, unsigned_immed5_overflow},
  {"sll.n", "D,S,T", "D,S,T,E", 3, 2, iw_T2X3_type,
   MATCH_R2_SLL_N, MASK_R2_SLL_N, 0, no_overflow},
  {"slli.n", "D,S,f", "D,S,f,E", 3, 2, iw_T2X1L3_type,
   MATCH_R2_SLLI_N, MASK_R2_SLLI_N, 0, enumeration_overflow},
  {"spaddi.n", "D,U", "D,U,E", 2, 2, iw_T1I7_type,
   MATCH_R2_SPADDI_N, MASK_R2_SPADDI_N, 0, address_offset_overflow},
  {"spdeci.n", "U", "U,E", 1, 2, iw_X1I7_type,
   MATCH_R2_SPDECI_N, MASK_R2_SPDECI_N, 0, address_offset_overflow},
  {"spinci.n", "U", "U,E", 1, 2, iw_X1I7_type,
   MATCH_R2_SPINCI_N, MASK_R2_SPINCI_N, 0, address_offset_overflow},
  {"sra", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_SRA, MASK_R2_SRA, 0, no_overflow},
  {"srai", "d,s,j", "d,s,j,E", 3, 4, iw_F3X6L5_type,
   MATCH_R2_SRAI, MASK_R2_SRAI, 0, unsigned_immed5_overflow},
  {"srl", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_SRL, MASK_R2_SRL, 0, no_overflow},
  {"srli", "d,s,j", "d,s,j,E", 3, 4, iw_F3X6L5_type,
   MATCH_R2_SRLI, MASK_R2_SRLI, 0, unsigned_immed5_overflow},
  {"srl.n", "D,S,T", "D,S,T,E", 3, 2, iw_T2X3_type,
   MATCH_R2_SRL_N, MASK_R2_SRL_N, 0, no_overflow},
  {"srli.n", "D,S,f", "D,S,f,E", 3, 2, iw_T2X1L3_type,
   MATCH_R2_SRLI_N, MASK_R2_SRLI_N, 0, enumeration_overflow},
  {"stb", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_STB, MASK_R2_STB, 0, address_offset_overflow},
  {"stbio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_STBIO, MASK_R2_STBIO, 0, signed_immed12_overflow},
  {"stb.n", "T,Y(S)", "T,Y(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_STB_N, MASK_R2_STB_N, 0, address_offset_overflow},
  {"stbz.n", "t,M(S)", "t,M(S),E", 3, 2, iw_T1X1I6_type,
   MATCH_R2_STBZ_N, MASK_R2_STBZ_N, 0, address_offset_overflow},
  {"stex", "d,t,(s)", "d,t,(s),E", 3, 4, iw_F3X6_type,
   MATCH_R2_STEX, MASK_R2_STEX, 0, no_overflow},
  {"sth", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_STH, MASK_R2_STH, 0, address_offset_overflow},
  {"sthio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_STHIO, MASK_R2_STHIO, 0, signed_immed12_overflow},
  {"sth.n", "T,X(S)", "T,X(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_STH_N, MASK_R2_STH_N, 0, address_offset_overflow},
  {"stsex", "d,t,(s)", "d,t,(s),E", 3, 4, iw_F3X6_type,
   MATCH_R2_STSEX, MASK_R2_STSEX, 0, no_overflow},
  {"stw", "t,i(s)", "t,i(s),E", 3, 4, iw_F2I16_type,
   MATCH_R2_STW, MASK_R2_STW, 0, address_offset_overflow},
  {"stwio", "t,I(s)", "t,I(s),E", 3, 4, iw_F2X4I12_type,
   MATCH_R2_STWIO, MASK_R2_STWIO, 0, signed_immed12_overflow},
  {"stwm", "R,B", "R,B,E", 2, 4, iw_F1X4L17_type,
   MATCH_R2_STWM, MASK_R2_STWM, 0, no_overflow},
  {"stwsp.n", "t,V(s)", "t,V(s),E", 3, 2, iw_F1I5_type,
   MATCH_R2_STWSP_N, MASK_R2_STWSP_N, 0, address_offset_overflow},
  {"stw.n", "T,W(S)", "T,W(S),E", 3, 2, iw_T2I4_type,
   MATCH_R2_STW_N, MASK_R2_STW_N, 0, address_offset_overflow},
  {"stwz.n", "t,N(S)", "t,N(S),E", 3, 2, iw_T1X1I6_type,
   MATCH_R2_STWZ_N, MASK_R2_STWZ_N, 0, address_offset_overflow},
  {"sub", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_SUB, MASK_R2_SUB, 0, no_overflow},
  {"subi", "t,s,i", "t,s,i,E", 3, 4, iw_F2I16_type,
   MATCH_R2_SUBI, MASK_R2_SUBI, NIOS2_INSN_MACRO, signed_immed16_overflow},
  {"sub.n", "D,S,T", "D,S,T,E", 3, 2, iw_T3X1_type,
   MATCH_R2_SUB_N, MASK_R2_SUB_N, 0, no_overflow},
  {"subi.n", "D,S,e", "D,S,e,E", 3, 2, iw_T2X1I3_type,
   MATCH_R2_SUBI_N, MASK_R2_SUBI_N, 0, enumeration_overflow},
  {"sync", "", "E", 0, 4, iw_F3X6_type,
   MATCH_R2_SYNC, MASK_R2_SYNC, 0, no_overflow},
  {"trap", "j", "j,E", 1, 4, iw_F3X6L5_type,
   MATCH_R2_TRAP, MASK_R2_TRAP, NIOS2_INSN_OPTARG, no_overflow},
  {"trap.n", "j", "j,E", 1, 2, iw_X2L5_type,
   MATCH_R2_TRAP_N, MASK_R2_TRAP_N, NIOS2_INSN_OPTARG, no_overflow},
  {"wrctl", "c,s", "c,s,E", 2, 4, iw_F3X6L5_type,
   MATCH_R2_WRCTL, MASK_R2_WRCTL, 0, no_overflow},
  {"wrpie", "d,s", "d,s,E", 2, 4, iw_F3X6L5_type,
   MATCH_R2_WRPIE, MASK_R2_WRPIE, 0, no_overflow},
  {"wrprs", "d,s", "d,s,E", 2, 4, iw_F3X6_type,
   MATCH_R2_WRPRS, MASK_R2_WRPRS, 0, no_overflow},
  {"xor", "d,s,t", "d,s,t,E", 3, 4, iw_F3X6_type,
   MATCH_R2_XOR, MASK_R2_XOR, 0, no_overflow},
  {"xorhi", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_XORHI, MASK_R2_XORHI, 0, unsigned_immed16_overflow},
  {"xori", "t,s,u", "t,s,u,E", 3, 4, iw_F2I16_type,
   MATCH_R2_XORI, MASK_R2_XORI, 0, unsigned_immed16_overflow},
  {"xor.n", "D,S,T", "D,S,T,E", 3, 2, iw_T2X3_type,
   MATCH_R2_XOR_N, MASK_R2_XOR_N, 0, no_overflow},
};

#define NIOS2_NUM_R2_OPCODES \
       ((sizeof nios2_r2_opcodes) / (sizeof (nios2_r2_opcodes[0])))
const int nios2_num_r2_opcodes = NIOS2_NUM_R2_OPCODES;

/* Default to using the R1 instruction tables.  */
struct nios2_opcode *nios2_opcodes = (struct nios2_opcode *) nios2_r1_opcodes;
int nios2_num_opcodes = NIOS2_NUM_R1_OPCODES;
#undef NIOS2_NUM_R1_OPCODES
#undef NIOS2_NUM_R2_OPCODES

/* Decodings for R2 asi.n (addi.n/subi.n) immediate values.  */
unsigned int nios2_r2_asi_n_mappings[] =
  {1, 2, 4, 8, 16, 32, 64, 128};
const int nios2_num_r2_asi_n_mappings = 8;

/* Decodings for R2 shi.n (slli.n/srli.n) immediate values.  */
unsigned int nios2_r2_shi_n_mappings[] =
  {1, 2, 3, 8, 12, 16, 24, 31};
const int nios2_num_r2_shi_n_mappings = 8;

/* Decodings for R2 andi.n immediate values.  */
unsigned int nios2_r2_andi_n_mappings[] =
  {1, 2, 3, 4, 8, 0xf, 0x10, 0x1f,
   0x20, 0x3f, 0x7f, 0x80, 0xff, 0x7ff, 0xff00, 0xffff};
const int nios2_num_r2_andi_n_mappings = 16;

/* Decodings for R2 3-bit register fields.  */
int nios2_r2_reg3_mappings[] =
  {16, 17, 2, 3, 4, 5, 6, 7};
const int nios2_num_r2_reg3_mappings = 8;

/* Decodings for R2 push.n/pop.n REG_RANGE value list.  */
unsigned long nios2_r2_reg_range_mappings[] = {
  0x00010000,
  0x00030000,
  0x00070000,
  0x000f0000,
  0x001f0000,
  0x003f0000,
  0x007f0000,
  0x00ff0000
};
const int nios2_num_r2_reg_range_mappings = 8;
