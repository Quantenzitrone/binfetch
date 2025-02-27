#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "info.h"
#include "pair.h"
#include "bin_op.h"

#include "elf_arch.h"
#include "elf_type.h"
#include "elf_osabi.h"

const size_t max_tok = 1018;
extern char ibuffer[128][128];
extern int  buffer_pos;

void elf_parser(FILE * fp)
{
	
	byte tok[max_tok];
	
	advance(tok, 5, fp);
	
	int bits = 0 ;// 32 or 64
	
	if (tok[0] == 0x01)	
	{
		bits = 1;
		strcpy(ibuffer[buffer_pos], "32 bit");
	}
	else if (tok[0] == 0x02)
	{
		bits = 2;
		strcpy(ibuffer[buffer_pos], "64 bit");
	}
	else
	{
		strcpy(ibuffer[buffer_pos], "unknown");
	}
	
	add_label("Class", ibuffer[buffer_pos++]);
	
	if (tok[1] == 0x01)
	{
		strcpy(ibuffer[buffer_pos], "little endian");
	}
	else if (tok[1] == 0x02)
	{
		strcpy(ibuffer[buffer_pos], "big endian");
	}
	else
	{
		strcpy(ibuffer[buffer_pos], "unknown endian");
	}
	
	add_label("Endian", ibuffer[buffer_pos++]);
	
	
	if (tok[2] == 0x01)
	{
		strcpy(ibuffer[buffer_pos], "ELFv1");
	}
	else if (tok[2] == 0x00)
	{
		strcpy(ibuffer[buffer_pos], "noncompliant");
	}
	
	add_label("Version", ibuffer[buffer_pos++]);
	
	spair_parser(ibuffer[buffer_pos], tok[3], osabis, sizeof osabis / sizeof(spr), "abi");
	
	add_label("OS ABI", ibuffer[buffer_pos++]);
	
	if (tok[4] != 0)
	{
		sprintf(ibuffer[buffer_pos], "%d", tok[4]);
		add_label("ABI Version", ibuffer[buffer_pos]);
	}
	else
	{
		ibuffer[buffer_pos][0] = '\0';
	}
	
	while (fread(tok, 1, 1, fp) && tok[0] == 0);
	fseek(fp, -1, SEEK_CUR);
	// do nothing just padding
	
	advance(tok, 2, fp);
	
	
	spair_parser(ibuffer[buffer_pos], tok[0], elf_types, sizeof elf_types / sizeof(spr), "type");
	
	add_label("Type", ibuffer[buffer_pos++]);
	
	advance(tok, 2, fp);
	
	spair_parser(ibuffer[buffer_pos], tok[0], elf_arches, sizeof elf_arches / sizeof(spr), "arch");
	
	add_label("Arch", ibuffer[buffer_pos++]);
	
	advance(tok, 4, fp);
	
	// do nothing I have no clue how this version is differnt from the previous one
	
	advance(tok, bits == 1 ? 4 : 8, fp);
	
	address_parser(ibuffer[buffer_pos], tok, bits);
	
	add_label("Entry", ibuffer[buffer_pos++]);
	
	advance(tok, bits == 1 ? 4 : 8, fp);
	
	char pgm_table[128];
	address_parser(pgm_table, tok, bits);
	
	advance(tok, bits == 1 ? 4 : 8, fp);
	
	char sec_table[128];
	address_parser(sec_table, tok, bits);
	
	advance(tok, 4, fp);
	//do nothing its just same arch specific flags
	
	unsigned short tbyte[2];
	advance(tbyte, 2, fp);
	
	sprintf(ibuffer[buffer_pos], "0x%02x", tbyte[0]);
	
	add_label("ELF Header Size", ibuffer[buffer_pos++]);
	
	advance(tbyte, 4, fp);
	
	sprintf(ibuffer[buffer_pos], "%s (size 0x%02x entries %d)", pgm_table, tbyte[0] , tbyte[1]);
	
	add_label("Pgm Table", ibuffer[buffer_pos++]);
}
