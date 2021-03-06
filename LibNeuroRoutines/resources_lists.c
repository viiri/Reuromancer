#include "neuro_routines.h"

resource_t g_res_imh[29] = {
	{
		0, "BUBBLES.IMH", 0x363F1, 0xFD
	},
	{
		0, "CURSORS.IMH", 0x364EE, 0xF3
	},
	{
		0, "NEURO.IMH", 0x365E1, 0xA8B,
	},
	{
		0, "SPRITES.IMH", 0x3706C, 0x25C3
	},
	{
		0, "TITLE.IMH", 0x395A8, 0x2BAB,
	},
	{
		1, "AIP0.IMH", 0x1873B, 0x334
	},
	{
		1, "AIP1.IMH", 0x18A6F, 0x32A
	},
	{
		1, "AIP2.IMH", 0x18D99, 0x308
	},
	{
		1, "AIP3.IMH", 0x190A1, 0x2D2
	},
	{
		1, "AIP4.IMH", 0x19373, 0x335
	},
	{
		1, "AIP5.IMH", 0x196A8, 0x342
	},
	{
		1, "AIP6.IMH", 0x199EA, 0x373
	},
	{
		1, "AIP7.IMH", 0x19D5D, 0x2EA
	},
	{
		1, "AIP8.IMH", 0x1A047, 0x316
	},
	{
		1, "AIP9.IMH", 0x1A35D, 0x2F8
	},
	{
		1, "AIP10.IMH", 0x1A655, 0x3D2
	},
	{
		1, "AIP11.IMH", 0x1AA27, 0x335
	},
	{
		1, "CSDB.IMH", 0x1AD5C, 0x15BD
	},
	{
		1, "CSPACE.IMH", 0x1C319, 0x106D
	},
	{
		1, "CSPANEL.IMH", 0x1D386, 0x733
	},
	{
		1, "DBSPR.IMH", 0x1DAB9, 0x26B
	},
	{
		1, "ENDGAME.IMH", 0x1DD24, 0x3E92
	},
	{
		1, "GRIDBASE.IMH", 0x21BB6, 0x109B
	},
	{
		1, "GRIDS.IMH", 0x22C51, 0x6084
	},
	{
		1, "ICE.IMH", 0x28CD5, 0x22E1
	},
	{
		1, "SHOTS.IMH", 0x2AFB6, 0x55A
	},
	{
		1, "VIRUSICE.IMH", 0x2B510, 0x467F
	},
	{
		1, "VIRUSROT.IMH", 0x2FB8F, 0x223F
	},
	{
		-1, NULL, 0, 0
	}
};

resource_t g_res_pic[56] = {
	{
		0, "R1.PIC", 0x5EE, 0x1346
	},
	{
		0, "R2.PIC", 0x1CE0, 0x1CB3,
	},
	{
		0, "R3.PIC", 0x45CA, 0x1B06,
	},
	{
		0, "R4.PIC", 0x654A, 0x2646,
	},
	{
		0, "R5.PIC", 0x914C, 0x13FF,
	},
	{
		0, "R6.PIC", 0xAD36, 0xFDC,
	},
	{
		0, "R7.PIC", 0xCD55, 0x1AD2,
	},
	{
		0, "R8.PIC", 0xF1CB, 0x187B,
	},
	{
		0, "R9.PIC", 0x110A6, 0x20F8,
	},
	{
		0, "R10.PIC", 0x13561, 0x1051,
	},
	{
		0, "R11.PIC", 0x14D4E, 0x11DC,
	},
	{
		0, "R12.PIC", 0x16BE8, 0x1A35,
	},
	{
		0, "R13.PIC", 0x191B2, 0x1A9F,
	},
	{
		0, "R14.PIC", 0x1AC7E, 0x1DFE,
	},
	{
		0, "R15.PIC", 0x1CAA9, 0x1D0B,
	},
	{
		0, "R16.PIC", 0x1E7E1, 0x1CC0,
	},
	{
		0, "R17.PIC", 0x2055A, 0x1B13,
	},
	{
		0, "R18.PIC", 0x2209A, 0x1730,
	},
	{
		0, "R19.PIC", 0x23C63, 0x1336,
	},
	{
		0, "R20.PIC", 0x27416, 0x164C,
	},
	{
		0, "R21.PIC", 0x28A88, 0xA53,
	},
	{
		0, "R22.PIC", 0x2976E, 0x690,
	},
	{
		0, "R23.PIC", 0x2A6BE, 0x1A98,
	},
	{
		0, "R24.PIC", 0x2C6D9, 0x1DDD,
	},
	{
		0, "R25.PIC", 0x2F436, 0xB59,
	},
	{
		0, "R26.PIC", 0x307A2, 0x1DD3,
	},
	{
		0, "R27.PIC", 0x338EB, 0x133E,
	},
	{
		1, "R29.PIC", 0x33010, 0x1160
	},
	{
		1, "R30.PIC", 0x342A0, 0xCB9
	},
	{
		1, "R31.PIC", 0x34F86, 0x133B
	},
	{
		1, "R32.PIC", 0x3694C, 0xC29
	},
	{
		1, "R33.PIC", 0x3759B, 0xA3A
	},
	{
		1, "R34.PIC", 0x3846D, 0x5CF
	},
	{
		1, "R35.PIC", 0x38F24, 0xA3E
	},
	{
		1, "R36.PIC", 0x39EEB, 0x1C8F
	},
	{
		1, "R37.PIC", 0x3C10D, 0x1253
	},
	{
		1, "R38.PIC", 0x3D38D, 0x1570
	},
	{
		1, "R39.PIC", 0x3E92A, 0x13FD
	},
	{
		1, "R40.PIC", 0x40259, 0xD39
	},
	{
		1, "R41.PIC", 0x41216, 0x707
	},
	{
		1, "R42.PIC", 0x41B89, 0x96D
	},
	{
		1, "R44.PIC", 0x42E0E, 0x12F3
	},
	{
		1, "R45.PIC", 0x445A7, 0x16AA
	},
	{
		1, "R46.PIC", 0x468D1, 0xAE2
	},
	{
		1, "R47.PIC", 0x47462, 0x139C
	},
	{
		1, "R49.PIC", 0x4882B, 0x14B7
	},
	{
		1, "R50.PIC", 0x4A2C9, 0x216D
	},
	{
		1, "R51.PIC", 0x4CBC9, 0xAC3
	},
	{
		1, "R52.PIC", 0x4DAF2, 0x2151
	},
	{
		1, "R53.PIC", 0x5046E, 0x876
	},
	{
		1, "R54.PIC", 0x51455, 0x1396
	},
	{
		1, "R55.PIC", 0x52811, 0x13B1
	},
	{
		1, "R56.PIC", 0x53F4A, 0x1612
	},
	{
		1, "R57.PIC", 0x55765, 0x15F7
	},
	{
		1, "R58.PIC", 0x56E0F, 0x170C
	},
	{
		-1, NULL, 0, 0
	}
};

resource_t g_res_bih[10] = {
	{
		0, "CORNERS.BIH", 0x3526D, 0x21
	},
	{
		0, "ROOMPOS.BIH", 0x3528E, 0x336
	},
	{
		0, "R1.BIH", 0, 0x5EE
	},
	{
		0, "R2.BIH", 0x1C19, 0xC7
	},
	{
		0, "R17.BIH", 0x204A1, 0xB9
	},
	{
		1, "COPEN1.BIH", 0x3D2, 0x39B
	},
	{
		1, "DB0.BIH", 0x76D, 0x9F2
	},
	{
		-1, NULL, 0, 0
	}
};

resource_t g_res_anh[22] = {
	{
		0, "R1.ANH", 0x1934, 0x2E5
	},
	{
		0, "R2.ANH", 0x3993, 0x340
	},
	{
		0, "R4.ANH", 0x8B90, 0x58F
	},
	{
		0, "R6.ANH", 0xBD12, 0xD9C
	},
	{
		0, "R8.ANH", 0x10A46, 0x1BC
	},
	{
		0, "R11.ANH", 0x15F2A, 0x372
	},
	{
		0, "R12.ANH", 0x1861D, 0xB68
	},
	{
		0, "R19.ANH", 0x24F99, 0x1E33
	},
	{
		0, "R22.ANH", 0x29DFE, 0xA9
	},
	{
		0, "R24.ANH", 0x2E4B6, 0xB9C
	},
	{
		0, "R26.ANH", 0x32575, 0xB8B
	},
	{
		0, "R27.ANH", 0x34C29, 0x232
	},
	{
		1, "R29.ANH", 0x34170, 0x10A
	},
	{
		1, "R34.ANH", 0x38A3C, 0x420
	},
	{
		1, "R36.ANH", 0x3BB7A, 0x566
	},
	{
		1, "R41.ANH", 0x4191D, 0x13E
	},
	{
		1, "R44.ANH", 0x44101, 0x3CE
	},
	{
		1, "R45.ANH", 0x45C51, 0x489
	},
	{
		1, "R50.ANH", 0x4C436, 0x6D4
	},
	{
		1, "R52.ANH", 0x4FC43, 0x31B
	},
	{
		1, "R53.ANH", 0x50CE4, 0x74B
	},
	{
		-1, NULL, 0, 0
	}
};
