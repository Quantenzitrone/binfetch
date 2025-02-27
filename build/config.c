#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pair.h"
#include "color.h"

#ifndef CONFIG
	#define CONFIG /tmp
#endif

extern tcolor ascii_cols[128];
extern tcolor main_cols[128];
extern char ascii_art[128][128];
extern char label_order[128][128];
extern int  label_order_count;
extern int flag_max_colors;
extern int main_max_colors;

int parse_cfg(const char * path)
{
	FILE * fp;
	if (path[0] == '\0')
	{
		while (1)
		{
			char path[128];
			strcpy(path, getenv("HOME"));
			strcat(path, "/.config/binfetch/binfetch.cfg");
			if ((fp = fopen(path, "r")))
			{
				break;
			}
			// add what ever paths you want
			strcpy(path, getenv("HOME"));
			strcat(path, "CONFIG");
			if ((fp = fopen(path, "r")))
			{
				break;
			}
			printf("failed to open standard config\n");
			return 1;
		}
		
	}
	else
	{
		fp = fopen(path, "r");
		if (!fp)
		{
			printf("failed to open defined config\n");
			return 1;
		}
	}
	
	char tok[128];
	while (fgets(tok, 128, fp))
	{
		if (!strncmp("[art_colors]", tok, 6))
		{
			while (fgets(tok, 128, fp))
			{
				if (tok[0] != '\t')
				{
					break ;
				}
				sscanf(tok + 1, "#%2x%2x%2x", (unsigned int *) &ascii_cols[flag_max_colors].r, (unsigned int *) &ascii_cols[flag_max_colors].g, (unsigned int *) &ascii_cols[flag_max_colors].b);
				++flag_max_colors;
			}
		}
		if (!strncmp("[label_colors]", tok, 6))
		{
			while (fgets(tok, 128, fp))
			{
				if (tok[0] != '\t')
				{
					break ;
				}
				sscanf(tok + 1, "#%2x%2x%2x", (unsigned int *) &main_cols[main_max_colors].r, (unsigned int *) &main_cols[main_max_colors].g, (unsigned int *) &main_cols[main_max_colors].b);
				++main_max_colors;
			}
		}
		if (!strncmp("[order]", tok, 6))
		{
			while (fgets(tok, 128, fp))
			{
				if (tok[0] != '\t')
				{
					break;
				}
				tok[strlen(tok) - 1] = '\0';
				strcpy(label_order[label_order_count++], tok + 1) ;
			}
		}
	}
	
	return 0;
}
