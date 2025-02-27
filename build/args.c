#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "pair.h"
#include "color.h"

int parse_cfg(const char * path);
int fetch(char * path);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		set_color(red);
		printf("you did not provide a binary\n");
		set_blank();
		return 1;
	}
	
	const char * short_options = "h:v:c";
	const struct option long_options[] =
	{
		{
			"help",    no_argument,       0, 'h'
		},
		
		{
			"version", no_argument,       0, 'V'
		},
		
		{
			"config",  required_argument, 0, 'c'
		},
		
		{
			0, 0, 0, 0
		},
	};
	
	char config[128] = "";
	while (1)
	{
		const int opt = getopt_long(argc, argv, short_options, long_options, NULL);
		
		if (-1 == opt)
		{
			break;
		}
		
		switch (opt)
		{
			case '?': ;// Unrecognized option
			case 'h':
				printf("Usage: binfetch [OPTION] [EXECUTABLES]\n\n" \
				     " -h, --help    -> prints this\n" \
				     " -V, --version -> prints version\n" \
				     " -c, --config  -> set config file\n");
				return 0;
			case 'V':
				printf("v1");
				return 0;
			case 'c':
				strcpy(config, optarg);
				break;
			default:
		}
	}
	
	if (optind >= argc)
	{
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}
	
	if (parse_cfg(config))
	{
		return 1;
	}
	
	
	for(; optind < argc; optind++)
	{
		fetch(argv[optind]);
	}
	
	return 0;
}
