#include "sigmar.h"

/* LED Layout

Underglow:
    3   2   1   0                   35  34  33  32

    4     5     6                   36    37    38

Key lights:

Xtr Q   W   E   R   T               Y   U   I   O   P   -
12  11  10  9   8   7               44  43  42  41  40  39

Esc A   S   D   F   G   Tab     Ent H   J   K   L   ;   '
13  14  15  16  17  18  19      45  46  47  48  49  50  51

Fn  Z   X   C   V   B               N   M   ,   .   /   Ins
25  24  23  22  21  20              57  56  55  54  53  52

Ctl Alt Win Shf Low Spc             Spc Rai Shf Win Alt Ctl
26  27  28  29  30  31              58  59  60  61  62  63
*/

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
	{
		{ 12, 11, 10, 9,      8,  7,  NO_LED },
		{ 13, 14, 15, 16,     17, 18, 19 },
		{ 25, 24, 23, 22,     21, 20, NO_LED },
		{ 26, 27, 28, NO_LED, 29, 30, 31 },

		{ 44, 43, 42, 41,     40, 39, NO_LED },
		{ 45, 46, 47, 48,     49, 50, 51 },
		{ 57, 56, 55, 54,     53, 52, NO_LED },
		{ 58, 59, 60, NO_LED, 61, 62, 63 }
	},
	{
		{ 93, 19 },  { 70, 15 },  { 42, 15 },  { 18, 21 },
		{ 11, 56 },  { 56, 51 },  { 100, 56 },

		{ 93, 7 },   { 74, 3 },   { 56, 0 },   { 37, 3 },   { 18, 9 },   { 0, 13 },
		{ 0, 28 },   { 18, 25 },  { 37, 18 },  { 56, 15 },  { 74, 18 },  { 93, 22 },  { 112, 18 },
		{ 93, 37 },  { 74, 34 },  { 56, 30 },  { 37, 34 },  { 18, 40 },  { 0, 44 },
		{ 9, 59 },   { 28, 56 },  { 46, 54 },  { 65, 54 },  { 87, 57 },  { 107, 64 },

		{ 131, 19 }, { 154, 15 }, { 182, 15 }, { 206, 21 },
		{ 213, 56 }, { 168, 51 }, { 124, 56 },

		{ 131, 7 },  { 150, 3 },  { 168, 0 },  { 187, 3 },  { 206, 9 },  { 224, 13 },
		{ 224, 28 }, { 206, 25 }, { 187, 18 }, { 168, 15 }, { 150, 18 }, { 131, 22 }, { 112, 18 },
		{ 131, 37 }, { 150, 34 }, { 168, 30 }, { 187, 34 }, { 206, 40 }, { 224, 44 },
		{ 215, 59 }, { 196, 56 }, { 178, 54 }, { 159, 54 }, { 137, 57 }, { 117, 64 }
	},
	{
		LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
		LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,

		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

		LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
		LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,

		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
		LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
	}
};

#endif
