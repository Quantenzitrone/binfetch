typedef struct rgb_color
{
	byte r;
	byte g;
	byte b;
}
tcolor;

static const tcolor white =
{
	255,
	255,
	255
};

static const tcolor cyan =
{
	109,
	209,
	255
};

static const tcolor magenta =
{
	156,
	89,
	209
};

static const tcolor light_magenta =
{
	234,
	150,
	170
};

static const tcolor red =
{
	255,
	0,
	0
};

static const tcolor grey =
{
	170,
	170,
	170
};

static const tcolor yellow =
{
	252,
	244,
	52
};

void set_color(const tcolor c);
void set_blank(void);
