#include "types.h"

/* Initialized data at 0x80071580..0x800715A0 (ROM 0x72180..0x721A0); consumer: shared. */
typedef struct Data80071580 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
} Data80071580;

/* Initialized data at 0x800715A0..0x8007178E (ROM 0x721A0..0x7238E); consumer: func_80026520. */
typedef struct Data800715A0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
    u32 word28;
    u32 word2C;
    u32 word30;
    u32 word34;
    u32 word38;
    u32 word3C;
    u32 word40;
    u32 word44;
    u32 word48;
    u32 word4C;
    u32 word50;
    u32 word54;
    u32 word58;
    u32 word5C;
    u32 word60;
    u32 word64;
    u32 word68;
    u32 word6C;
    u32 word70;
    u32 word74;
    u32 word78;
    u32 word7C;
    u32 word80;
    u32 word84;
    u32 word88;
    u32 word8C;
    u32 word90;
    u32 word94;
    u32 word98;
    u32 word9C;
    u32 wordA0;
    u32 wordA4;
    u32 wordA8;
    u32 wordAC;
    u32 wordB0;
    u32 wordB4;
    u32 wordB8;
    u32 wordBC;
    u32 wordC0;
    u32 wordC4;
    u32 wordC8;
    u32 wordCC;
    u32 wordD0;
    u32 wordD4;
    u32 wordD8;
    u32 wordDC;
    u32 wordE0;
    u32 wordE4;
    u32 wordE8;
    u32 wordEC;
    u32 wordF0;
    u32 wordF4;
    u32 wordF8;
    u32 wordFC;
    u32 word100;
    u32 word104;
    u32 word108;
    u32 word10C;
    u32 word110;
    u32 word114;
    u32 word118;
    u32 word11C;
    u32 word120;
    u32 word124;
    u32 word128;
    u32 word12C;
    u32 word130;
    u32 word134;
    u32 word138;
    u32 word13C;
    u32 word140;
    u32 word144;
    u32 word148;
    u32 word14C;
    u32 word150;
    u32 word154;
    u32 word158;
    u32 word15C;
    u32 word160;
    u32 word164;
    u32 word168;
    u32 word16C;
    u32 word170;
    u32 word174;
    u32 word178;
    u32 word17C;
    u32 word180;
    u32 word184;
    u32 word188;
    u32 word18C;
    u32 word190;
    u32 word194;
    u32 word198;
    u32 word19C;
    u32 word1A0;
    u32 word1A4;
    u32 word1A8;
    u32 word1AC;
    u32 word1B0;
    u32 word1B4;
    u32 word1B8;
    u32 word1BC;
    u32 word1C0;
    u32 word1C4;
    u32 word1C8;
    u32 word1CC;
    u32 word1D0;
    u32 word1D4;
    u32 word1D8;
    u32 word1DC;
    u32 word1E0;
    u32 word1E4;
    u32 word1E8;
    u16 half1EC;
    u8 tail_bytes[2];
} Data800715A0;

/* Initialized data at 0x8007178E..0x80071A38 (ROM 0x7238E..0x72638); consumer: func_800279B8. */
typedef struct Data8007178E {
    u32 word2;
    u32 word6;
    u32 wordA;
    u32 wordE;
    u32 word12;
    u32 word16;
    u32 word1A;
    u32 word1E;
    u32 word22;
    u32 word26;
    u32 word2A;
    u32 word2E;
    u32 word32;
    u32 word36;
    u32 word3A;
    u32 word3E;
    u32 word42;
    u32 word46;
    u32 word4A;
    u32 word4E;
    u32 word52;
    u32 word56;
    u32 word5A;
    u32 word5E;
    u32 word62;
    u32 word66;
    u32 word6A;
    u32 word6E;
    u32 word72;
    u32 word76;
    u32 word7A;
    u32 word7E;
    u32 word82;
    u32 word86;
    u32 word8A;
    u32 word8E;
    u32 word92;
    u32 word96;
    u32 word9A;
    u32 word9E;
    u32 wordA2;
    u32 wordA6;
    u32 wordAA;
    u32 wordAE;
    u32 wordB2;
    u32 wordB6;
    u32 wordBA;
    u32 wordBE;
    u32 wordC2;
    u32 wordC6;
    u32 wordCA;
    u32 wordCE;
    u32 wordD2;
    u32 wordD6;
    u32 wordDA;
    u32 wordDE;
    u32 wordE2;
    u32 wordE6;
    u32 wordEA;
    u32 wordEE;
    u32 wordF2;
    u32 wordF6;
    u32 wordFA;
    u32 wordFE;
    u32 word102;
    u32 word106;
    u32 word10A;
    u32 word10E;
    u32 word112;
    u32 word116;
    u32 word11A;
    u32 word11E;
    u32 word122;
    u32 word126;
    u32 word12A;
    u32 word12E;
    u32 word132;
    u32 word136;
    u32 word13A;
    u32 word13E;
    u32 word142;
    u32 word146;
    u32 word14A;
    u32 word14E;
    u32 word152;
    u32 word156;
    u32 word15A;
    u32 word15E;
    u32 word162;
    u32 word166;
    u32 word16A;
    u32 word16E;
    u32 word172;
    u32 word176;
    u32 word17A;
    u32 word17E;
    u32 word182;
    u32 word186;
    u32 word18A;
    u32 word18E;
    u32 word192;
    u32 word196;
    u32 word19A;
    u32 word19E;
    u32 word1A2;
    u32 word1A6;
    u32 word1AA;
    u32 word1AE;
    u32 word1B2;
    u32 word1B6;
    u32 word1BA;
    u32 word1BE;
    u32 word1C2;
    u32 word1C6;
    u32 word1CA;
    u32 word1CE;
    u32 word1D2;
    u32 word1D6;
    u32 word1DA;
    u32 word1DE;
    u32 word1E2;
    u32 word1E6;
    u32 word1EA;
    u32 word1EE;
    u32 word1F2;
    u32 word1F6;
    u32 word1FA;
    u32 word1FE;
    u32 word202;
    u32 word206;
    u32 word20A;
    u32 word20E;
    u32 word212;
    u32 word216;
    u32 word21A;
    u32 word21E;
    u32 word222;
    u32 word226;
    u32 word22A;
    u32 word22E;
    u32 word232;
    u32 word236;
    u32 word23A;
    u32 word23E;
    u32 word242;
    u32 word246;
    u32 word24A;
    u32 word24E;
    u32 word252;
    u32 word256;
    u32 word25A;
    u32 word25E;
    u32 word262;
    u32 word266;
    u32 word26A;
    u32 word26E;
    u32 word272;
    u32 word276;
    u32 word27A;
    u32 word27E;
    u32 word282;
    u32 word286;
    u32 word28A;
    u32 word28E;
    u32 word292;
    u32 word296;
    u32 word29A;
    u32 word29E;
    u32 word2A2;
    u32 word2A6;
} Data8007178E;

/* D_80071580 groups objects that start mid-word; inner symbols:
 * D_800715A0 = D_80071580 + 0x20
 * D_8007178E = D_80071580 + 0x20e
 */
typedef struct Group80071580 {
    Data80071580 o80071580;
    Data800715A0 o800715A0;
    Data8007178E o8007178E;
} Group80071580;

Group80071580 D_80071580 = {
    {
        0x00000000,
        0x00000000,
        0x3F800000,
        0x3F800000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    },
    {
        0xC6909600,
        0x4744E000,
        0xC79C6080,
        0x42980000,
        0x46CDC800,
        0x00000000,
        0xC4FB4000,
        0x45E76000,
        0xC6D1E400,
        0xC6909200,
        0x4744E000,
        0xC79C5900,
        0x42980000,
        0x46CDC000,
        0xC0A00000,
        0xC4FB4000,
        0x45E76000,
        0xC6D1C200,
        0xC79C5900,
        0xC0A00000,
        0xC6D1D000,
        0xC79AE200,
        0x44B28000,
        0xC6CA0000,
        0x47703400,
        0x4799ED80,
        0x46D3B400,
        0xC7966400,
        0x44BFE000,
        0xC6CA0000,
        0xC79AE200,
        0x44B28000,
        0xC6CA0000,
        0xC78CA000,
        0x45EA6000,
        0xC6ABE000,
        0xC77DE800,
        0x46421000,
        0xC6947000,
        0xC76C5E00,
        0x468C3800,
        0xC6435000,
        0xC75C4400,
        0x46C13A00,
        0xC5F1A000,
        0xC7379800,
        0x46D99800,
        0xC4B6C000,
        0xC7287100,
        0x47028700,
        0x00000000,
        0xC6EAC400,
        0x4710CC00,
        0x44FA0000,
        0xC6B89000,
        0x472DAF00,
        0x457A0000,
        0xC6878C00,
        0x473ED800,
        0x45DAC000,
        0xC61DF000,
        0x4755CD00,
        0x463B8000,
        0xC58B8800,
        0x475AB100,
        0x466A6000,
        0x44FBE000,
        0x476C3F00,
        0x468CA000,
        0x4608D800,
        0x47756F00,
        0x46947000,
        0x46989E00,
        0x47811400,
        0x46B3B000,
        0x46A62000,
        0x47894D00,
        0x46BB0800,
        0x46E24E00,
        0x4793F680,
        0x46D2F000,
        0x47102700,
        0x479C4000,
        0x46D2F000,
        0x472B0500,
        0x479C4000,
        0x46D2F000,
        0x473EA800,
        0x46D2F000,
        0x46D2F000,
        0x474BB900,
        0x46D2F000,
        0x46D2F000,
        0x4753EA00,
        0x46D2F000,
        0x46D2F000,
        0xC6AC5400,
        0x47051000,
        0xC7154800,
        0x4618DC00,
        0x46698400,
        0x46661400,
        0xC6AC5400,
        0x47051000,
        0xC7154800,
        0x4618DC00,
        0x46698400,
        0x46661400,
        0xC6AC5400,
        0x47051000,
        0xC7154800,
        0x4618DC00,
        0x46698400,
        0x46661400,
        0x00000000,
        0x00000000,
        0x060708DC,
        0x24252726,
        0xEBDD2302,
        0x22222020,
        0xEBEBEAEA,
        0xEBE7E7EA,
        0x1A1AEB19,
        0x191A,
        { 0x06, 0x07 },
    },
    {
        0x08DC2425,
        0x272614DD,
        0x23022222,
        0x20201414,
        0xE6E614E7,
        0xE7E61A1A,
        0x1419191A,
        0x060708DC,
        0x24252726,
        0x15DD2302,
        0x22222020,
        0x1515E6E6,
        0x15E7E7E6,
        0x16161519,
        0x19160607,
        0x08DC2425,
        0x2726EBDD,
        0x23022222,
        0x2020EBEB,
        0xE9E9EBE8,
        0xE8E91A1A,
        0xEB19191A,
        0x060708DC,
        0x24252726,
        0x14DD2302,
        0x22222020,
        0x1414E6E6,
        0x14E7E7E6,
        0x1A1A1419,
        0x191A0607,
        0x08DC2425,
        0x272615DD,
        0x23022222,
        0x20201515,
        0xE6E615E7,
        0xE7E61717,
        0x15181817,
        0x060708FD,
        0x03040905,
        0xF5E51BF5,
        0x22221D1D,
        0xF5F2F2F3,
        0xF3F3F5EF,
        0xEFF21212,
        0x131313F5,
        0x11111206,
        0x0708FD03,
        0x040905F5,
        0xE51BF522,
        0x221D1DF5,
        0xEEEEF4F4,
        0xF4F5EFEF,
        0xEE121213,
        0x1313F511,
        0x11120607,
        0x08FD0304,
        0x09050AE5,
        0x1B0A2222,
        0x1D1D0AEE,
        0xEEEDEDED,
        0x0AEFEFEE,
        0x12121313,
        0x130A1111,
        0x12060708,
        0xFD030409,
        0x050BE51B,
        0x0B22221D,
        0x1D0BEEEE,
        0xEDEDED0B,
        0xEFEFEE12,
        0x120C0C0C,
        0x0B111112,
        0x060708FD,
        0x03040905,
        0x0BE51B0B,
        0x22221D1D,
        0x0BEEEEED,
        0xEDED0BEF,
        0xEFEE0E0E,
        0x0D0D0D0B,
        0x11110E06,
        0x0708FD03,
        0x040905F5,
        0xE51BF522,
        0x221D1DF5,
        0xF1F1F3F3,
        0xF3F5F0F0,
        0xF1121213,
        0x1313F511,
        0x11120607,
        0x08FD0304,
        0x0905F5E5,
        0x1BF52222,
        0x1D1DF5EE,
        0xEEF4F4F4,
        0xF5EFEFEE,
        0x12121313,
        0x13F51111,
        0x12060708,
        0xFD030409,
        0x050AE51B,
        0x0A22221D,
        0x1D0AEEEE,
        0xEDEDED0A,
        0xEFEFEE12,
        0x12131313,
        0x0A111112,
        0x060708FD,
        0x03040905,
        0x0BE51B0B,
        0x22221D1D,
        0x0BEEEEED,
        0xEDED0BEF,
        0xEFEE1212,
        0x0C0C0C0B,
        0x11111206,
        0x0708FD03,
        0x0409050B,
        0xE51B0B22,
        0x221D1D0B,
        0xEEEEEDED,
        0xED0BEFEF,
        0xEE0F0F0D,
        0x0D0D0B10,
        0x100F0000,
        0x67687C69,
        0x6A6C6B6D,
        0x6E7E7E66,
        0x7D7D6E7B,
        0x6E6E6F6F,
        0x6E73736F,
        0x76766E79,
        0x79766768,
        0x7C696A6C,
        0x6B6D7A7E,
        0x7E667D7D,
        0x7A7B7A7A,
        0x70707A73,
        0x73707676,
        0x7A797976,
        0x67687C69,
        0x6A6C6B6D,
        0x747E7E66,
        0x7D7D747B,
        0x74747070,
        0x74737370,
        0x75757479,
        0x79756768,
        0x7C696A6C,
        0x6B6D6E7E,
        0x7E667D7D,
        0x6E7B6E6E,
        0x71716E72,
        0x72717676,
        0x6E797976,
        0x67687C69,
        0x6A6C6B6D,
        0x7A7E7E66,
        0x7D7D7A7B,
        0x7A7A7070,
        0x7A737370,
        0x76767A79,
        0x79766768,
        0x7C696A6C,
        0x6B6D747E,
        0x7E667D7D,
        0x747B7474,
        0x70707473,
        0x73707777,
        0x74787877,
    }
};
