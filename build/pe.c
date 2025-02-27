#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "info.h"
#include "pair.h"
#include "bin_op.h"

#include "pe_arch.h"

extern char ibuffer[128][128];
extern int  buffer_pos;

void pe_parser(FILE * fp)
{
	unsigned short tok[1024];
	
	advance(tok, 10, fp);
	unsigned short toki = 0;
	advance(&toki, 2, fp);
	
	bpair_parser(ibuffer[buffer_pos], toki, pe_arches, sizeof pe_arches / sizeof(bpr), "arch");
	
	add_label("Arch", ibuffer[buffer_pos++]);
}
