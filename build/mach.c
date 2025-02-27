#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "info.h"
#include "pair.h"
#include "bin_op.h"

#include "mach_arch.h"
#include "mach_type.h"

extern char ibuffer[128][128];
extern int  buffer_pos;

void mach_parser(FILE * fp, int bit, int end)
{
	fbyte tok = 0;
	
	advance(&tok, 4, fp);
	
	bpair_parser(ibuffer[buffer_pos], tok, mach_arches, sizeof mach_arches / sizeof(bpr), "cpu type");
	
	add_label("Arch", ibuffer[buffer_pos++]);
	
	fbyte cls = (tok >> 24);
	
	if (cls == 0x00)	
	{
		strcpy(ibuffer[buffer_pos], "32 bit");
	}
	else if (cls == 0x1)
	{
		strcpy(ibuffer[buffer_pos], "64 bit");
	}
	else if (cls == 0x2)
	{
		strcpy(ibuffer[buffer_pos], "LP 32 bit");
	}
	else
	{
		sprintf(ibuffer[buffer_pos], "unknown (%x)", cls);
	}
	
	add_label("Class", ibuffer[buffer_pos++]);
	
	if (end == 0)
	{
		strcpy(ibuffer[buffer_pos], "little endian");
	}
	else if (end == 1)
	{
		strcpy(ibuffer[buffer_pos], "big endian");
	}
	else
	{
		strcpy(ibuffer[buffer_pos], "unknown endian");
	}
	
	add_label("Endian", ibuffer[buffer_pos++]);
	
	advance(&tok, 4, fp);
	advance(&tok, 4, fp);
	
	spair_parser(ibuffer[buffer_pos], tok, mach_types, sizeof mach_types / sizeof(spr), "type");
	
	add_label("Type", ibuffer[buffer_pos++]);
}
