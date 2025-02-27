const spr elf_arches[] =
{
	{
		.key = 0x00,
		.str = "Unknown instruction set"
	},
	
	{
		.key = 0x01,
		.str = "AT&T WE 32100"
	},
	
	{
		.key = 0x02,
		.str = "SPARC"
	},
	
	{
		.key = 0x03,
		.str = "x86"
	},
	
	{
		.key = 0x04,
		.str = "M68k"
	},
	
	{
		.key = 0x05,
		.str = "M88k"
	},
	
	{
		.key = 0x06,
		.str = "Intel MCU"
	},
	
	{
		.key = 0x07,
		.str = "Intel 80860"
	},
	
	{
		.key = 0x08,
		.str = "MIPS"
	},
	
	{
		.key = 0x09,
		.str = "IBM System/370"
	},
	
	{
		.key = 0x0A,
		.str = "MIPS RS3000"
	},
	
	{
		.key = 0x0B,
		.str = "Unknown instruction set"
	},
	
	{
		.key = 0x0E,
		.str = "PA-RISC"
	},
	
	{
		.key = 0x0F,
		.str = "Unknown instruction set"
	},
	
	{
		.key = 0x13,
		.str = "Intel 80960"
	},
	
	{
		.key = 0x14,
		.str = "PowerPC"
	},
	
	{
		.key = 0x15,
		.str = "PowerPC"
	},
	
	{
		.key = 0x16,
		.str = "S390(x)"
	},
	
	{
		.key = 0x17,
		.str = "IBM SPU/SPC"
	},
	
	{
		.key = 0x18,
		.str = "Unknown instruction set"
	},
	
	{
		.key = 0x24,
		.str = "NEC V800"
	},
	
	{
		.key = 0x25,
		.str = "Fujitsu FR20"
	},
	
	{
		.key = 0x26,
		.str = "TRW RH-32"
	},
	
	{
		.key = 0x27,
		.str = "Motorola RCE"
	},
	
	{
		.key = 0x28,
		.str = "Armv7"
	},
	
	{
		.key = 0x29,
		.str = "Digital Alpha"
	},
	
	{
		.key = 0x2A,
		.str = "SuperH"
	},
	
	{
		.key = 0x2B,
		.str = "SPARCv9"
	},
	
	{
		.key = 0x2C,
		.str = "Siemens TriCore embedded processor"
	},
	
	{
		.key = 0x2D,
		.str = "Argonaut RISC Core"
	},
	
	{
		.key = 0x2E,
		.str = "Hitachi H8/300"
	},
	
	{
		.key = 0x2F,
		.str = "Hitachi H8/300H"
	},
	
	{
		.key = 0x30,
		.str = "Hitachi H8S"
	},
	
	{
		.key = 0x31,
		.str = "Hitachi H8/500"
	},
	
	{
		.key = 0x32,
		.str = "IA-64"
	},
	
	{
		.key = 0x33,
		.str = "MIPS-X"
	},
	
	{
		.key = 0x34,
		.str = "Motorola ColdFire"
	},
	
	{
		.key = 0x35,
		.str = "Motorola M68HC12"
	},
	
	{
		.key = 0x36,
		.str = "Fujitsu MMA Multimedia Accelerator"
	},
	
	{
		.key = 0x37,
		.str = "Siemens PCP"
	},
	
	{
		.key = 0x38,
		.str = "Sony nCPU embedded RISC processor"
	},
	
	{
		.key = 0x39,
		.str = "Denso NDR1 microprocessor"
	},
	
	{
		.key = 0x3A,
		.str = "Motorola Star*Core processor"
	},
	
	{
		.key = 0x3B,
		.str = "Toyota ME16 processor"
	},
	
	{
		.key = 0x3C,
		.str = "STMicroelectronics ST100 processor"
	},
	
	{
		.key = 0x3D,
		.str = "Advanced Logic Corp. TinyJ embedded processor family"
	},
	
	{
		.key = 0x3E,
		.str = "x86-64"
	},
	
	{
		.key = 0x3F,
		.str = "Sony DSP Processor"
	},
	
	{
		.key = 0x40,
		.str = "Digital Equipment Corp. PDP-10"
	},
	
	{
		.key = 0x41,
		.str = "Digital Equipment Corp. PDP-11"
	},
	
	{
		.key = 0x42,
		.str = "Siemens FX66 microcontroller"
	},
	
	{
		.key = 0x43,
		.str = "STMicroelectronics ST9+ 8/16 bit microcontroller"
	},
	
	{
		.key = 0x44,
		.str = "STMicroelectronics ST7 8-bit microcontroller"
	},
	
	{
		.key = 0x45,
		.str = "Motorola MC68HC16 Microcontroller"
	},
	
	{
		.key = 0x46,
		.str = "Motorola MC68HC11 Microcontroller"
	},
	
	{
		.key = 0x47,
		.str = "Motorola MC68HC08 Microcontroller"
	},
	
	{
		.key = 0x48,
		.str = "Motorola MC68HC05 Microcontroller"
	},
	
	{
		.key = 0x49,
		.str = "Silicon Graphics SVx"
	},
	
	{
		.key = 0x4A,
		.str = "STMicroelectronics ST19 8-bit microcontroller"
	},
	
	{
		.key = 0x4B,
		.str = "Digital VAX"
	},
	
	{
		.key = 0x4C,
		.str = "Axis Communications 32-bit embedded processor"
	},
	
	{
		.key = 0x4D,
		.str = "Infineon Technologies 32-bit embedded processor"
	},
	
	{
		.key = 0x4E,
		.str = "Element 14 64-bit DSP Processor"
	},
	
	{
		.key = 0x4F,
		.str = "LSI Logic 16-bit DSP Processor"
	},
	
	{
		.key = 0x8C,
		.str = "TMS320C6000 Family"
	},
	
	{
		.key = 0xAF,
		.str = "MCST Elbrus e2k"
	},
	
	{
		.key = 0xB7,
		.str = "Armv8"
	},
	
	{
		.key = 0xDC,
		.str = "Zilog Z80"
	},
	
	{
		.key = 0xF3,
		.str = "RISC-V"
	},
	
	{
		.key = 0xF7,
		.str = "Berkeley Packet Filter"
	},
};
