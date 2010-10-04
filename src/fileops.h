/* sd2snes - SD card based universal cartridge for the SNES
   Copyright (C) 2009-2010 Maximilian Rehkopf <otakon@gmx.net>
   AVR firmware portion

   Inspired by and based on code from sd2iec, written by Ingo Korb et al.
   See sdcard.c|h, config.h.

   FAT file system access based on code by ChaN, Jim Brain, Ingo Korb,
   see ff.c|h.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License only.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   fileops.h: simple file access functions
*/

#ifndef FILEOPS_H
#define FILEOPS_H
#include <arm/NXP/LPC17xx/LPC17xx.h>
#include "ff.h"

BYTE file_buf[512];
FATFS fatfs;
FIL file_handle;
FRESULT file_res;
uint8_t file_lfn[258];

void file_init(void);
void file_open(uint8_t* filename, BYTE flags);
void file_open_by_filinfo(FILINFO* fno);
void file_close(void);
UINT file_read(void);
UINT file_write(void);
UINT file_readblock(void* buf, uint32_t addr, uint16_t size);
UINT file_writeblock(void* buf, uint32_t addr, uint16_t size);
#endif
