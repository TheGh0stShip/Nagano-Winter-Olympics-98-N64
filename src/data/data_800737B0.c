#include "types.h"

extern u8 func_80049E20[];
extern u8 func_80049F88[];
extern u8 func_8004A0FC[];
extern u8 func_8004A120[];
extern u8 func_8004A144[];
extern u8 func_8004A1C8[];
extern u8 func_8004A32C[];
extern u8 func_8004A3B8[];
extern u8 func_8004A3DC[];
extern u8 func_8004A3F4[];
extern u8 func_8004A418[];
extern u8 func_8004B9E0[];
extern u8 func_8004BA1C[];
extern u8 func_8004BB30[];
extern u8 func_8004BDB8[];
extern u8 func_8004BDE0[];
extern u8 func_8004BE10[];
extern u8 func_8004BE6C[];
extern u8 func_8004BF88[];
extern u8 func_8004C00C[];
extern u8 func_8004C0CC[];
extern u8 func_8004C13C[];
extern u8 func_8004C274[];
extern u8 func_8004C27C[];
extern u8 func_8004C2D4[];
extern u8 func_8004C43C[];
extern u8 func_8004C46C[];
extern u8 func_8004C49C[];
extern u8 func_8004C804[];
extern u8 func_8004C878[];
extern u8 func_8004C9CC[];
extern u8 func_8004CC64[];
extern u8 func_8004CD60[];
extern u8 func_8004CE70[];
extern u8 func_8004CEA8[];
extern u8 func_8004CF68[];
extern u8 func_8004CFA0[];
extern u8 func_8004D060[];
extern u8 func_8004D078[];
extern u8 func_8004D090[];
extern u8 func_8004D0B4[];
extern u8 func_8004D140[];
extern u8 func_8004D1F8[];
extern u8 func_8004D224[];
extern u8 func_8004D244[];
extern u8 func_8004D2E0[];
extern u8 func_8004D3CC[];
extern u8 func_8004D428[];
extern u8 func_8004D624[];
extern u8 func_8004D664[];
extern u8 func_8004D6AC[];
extern u8 func_8004D6CC[];
extern u8 func_8004D6EC[];
extern u8 func_8004D7F4[];

/* Initialized data at 0x800737B0..0x800738B0 (ROM 0x743B0..0x744B0); consumer: shared. */
typedef struct Data800737B0 {
    void *ptr0;
    void *ptr4;
    void *ptr8;
    void *ptrC;
    void *ptr10;
    void *ptr14;
    void *ptr18;
    void *ptr1C;
    void *ptr20;
    void *ptr24;
    void *ptr28;
    void *ptr2C;
    void *ptr30;
    void *ptr34;
    u32 word38;
    u32 word3C;
    void *ptr40;
    void *ptr44;
    void *ptr48;
    void *ptr4C;
    void *ptr50;
    void *ptr54;
    void *ptr58;
    void *ptr5C;
    void *ptr60;
    void *ptr64;
    void *ptr68;
    void *ptr6C;
    void *ptr70;
    void *ptr74;
    void *ptr78;
    void *ptr7C;
    void *ptr80;
    void *ptr84;
    void *ptr88;
    void *ptr8C;
    void *ptr90;
    void *ptr94;
    void *ptr98;
    void *ptr9C;
    void *ptrA0;
    void *ptrA4;
    void *ptrA8;
    void *ptrAC;
    void *ptrB0;
    void *ptrB4;
    void *ptrB8;
    void *ptrBC;
    void *ptrC0;
    void *ptrC4;
    void *ptrC8;
    void *ptrCC;
    void *ptrD0;
    void *ptrD4;
    void *ptrD8;
    void *ptrDC;
    void *ptrE0;
    void *ptrE4;
    void *ptrE8;
    void *ptrEC;
    void *ptrF0;
    void *ptrF4;
    void *ptrF8;
    void *ptrFC;
} Data800737B0;

/* Initialized data at 0x800738B0..0x80073A5A (ROM 0x744B0..0x7465A); consumer: func_8004B274. */
typedef struct Data800738B0 {
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
    u16 half1A8;
    u8 tail_bytes[2];
} Data800738B0;

/* Initialized data at 0x80073A5A..0x80073AE0 (ROM 0x7465A..0x746E0); consumer: shared. */
typedef struct Data80073A5A {
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
} Data80073A5A;

/* D_800737B0 groups objects that start mid-word; inner symbols:
 * D_800738B0 = D_800737B0 + 0x100
 * D_80073A5A = D_800737B0 + 0x2aa
 */
typedef struct Group800737B0 {
    Data800737B0 o800737B0;
    Data800738B0 o800738B0;
    Data80073A5A o80073A5A;
} Group800737B0;

Group800737B0 D_800737B0 = {
    {
        func_80049E20,
        func_80049F88,
        func_8004A0FC,
        func_8004A120,
        func_8004A144,
        func_8004A1C8,
        func_8004A32C,
        func_8004A32C,
        func_8004A32C,
        func_8004A32C,
        func_8004A3B8,
        func_8004A3DC,
        func_8004A3F4,
        func_8004A418,
        0x01020401,
        0x00000000,
        func_8004B9E0,
        func_8004BA1C,
        func_8004BB30,
        func_8004BDB8,
        func_8004BDE0,
        func_8004BE10,
        func_8004BE6C,
        func_8004BF88,
        func_8004C00C,
        func_8004C0CC,
        func_8004C13C,
        func_8004D7F4,
        func_8004C274,
        func_8004C27C,
        func_8004C2D4,
        func_8004C43C,
        func_8004C46C,
        func_8004C49C,
        func_8004C804,
        func_8004C878,
        func_8004C9CC,
        func_8004CC64,
        func_8004CD60,
        func_8004CE70,
        func_8004CEA8,
        func_8004CF68,
        func_8004CFA0,
        func_8004D060,
        func_8004D078,
        func_8004D090,
        func_8004D0B4,
        func_8004D140,
        func_8004D1F8,
        func_8004D224,
        func_8004D244,
        func_8004D2E0,
        func_8004D7F4,
        func_8004D7F4,
        func_8004D7F4,
        func_8004D7F4,
        func_8004D3CC,
        func_8004D428,
        func_8004D624,
        func_8004D664,
        func_8004D6AC,
        func_8004D6CC,
        func_8004D6EC,
        func_8004D7F4,
    },
    {
        0x3D000000,
        0x3D079C7C,
        0x3D0FACD6,
        0x3D1837EF,
        0x3D214517,
        0x3D2ADC01,
        0x3D3504EE,
        0x3D3FC87E,
        0x3D4B2FEC,
        0x3D5744ED,
        0x3D6411E4,
        0x3D71A1B2,
        0x3D800000,
        0x3D879C7C,
        0x3D8FACD6,
        0x3D9837EF,
        0x3DA14517,
        0x3DAADC01,
        0x3DB504EE,
        0x3DBFC87E,
        0x3DCB2FEC,
        0x3DD744ED,
        0x3DE411E4,
        0x3DF1A1B2,
        0x3E000000,
        0x3E079C7C,
        0x3E0FACD6,
        0x3E1837EF,
        0x3E214517,
        0x3E2ADC01,
        0x3E3504EE,
        0x3E3FC87E,
        0x3E4B2FEC,
        0x3E5744ED,
        0x3E6411E4,
        0x3E71A1B2,
        0x3E800000,
        0x3E879C7C,
        0x3E8FACD6,
        0x3E9837EF,
        0x3EA14517,
        0x3EAADC01,
        0x3EB504EE,
        0x3EBFC87E,
        0x3ECB2FEC,
        0x3ED744ED,
        0x3EE411E4,
        0x3EF1A1B2,
        0x3F000000,
        0x3F079C7C,
        0x3F0FACD6,
        0x3F1837EF,
        0x3F214517,
        0x3F2ADC01,
        0x3F3504EE,
        0x3F3FC87E,
        0x3F4B2FEC,
        0x3F5744ED,
        0x3F6411E4,
        0x3F71A1B2,
        0x3F800000,
        0x3F879C7C,
        0x3F8FACD6,
        0x3F9837EF,
        0x3FA14517,
        0x3FAADC01,
        0x3FB504EE,
        0x3FBFC87E,
        0x3FCB2FEC,
        0x3FD744ED,
        0x3FE411E4,
        0x3FF1A1B2,
        0x40000000,
        0x40000000,
        0x00000000,
        0x00000000,
        0x00000001,
        0x00020002,
        0x00030004,
        0x00050006,
        0x00070008,
        0x0009000A,
        0x000B000B,
        0x000C000D,
        0x000E000F,
        0x00100011,
        0x00120013,
        0x00140015,
        0x00160018,
        0x001A001C,
        0x001E001F,
        0x00200022,
        0x00240026,
        0x0028002A,
        0x002C002E,
        0x00320036,
        0x003A003E,
        0x00420046,
        0x004A004D,
        0x00500054,
        0x0058005E,
        0x0066006E,
        0x0076007C,
        0x0084008C,
        0x0094009A,
        0x00A000A8,
        0x00B0,
        { 0x00, 0xC0 },
    },
    {
        0x00D000E0,
        0x00F000FE,
        0x010C011C,
        0x012C013A,
        0x01480158,
        0x01680186,
        0x01A401C2,
        0x01E001F8,
        0x0210022A,
        0x02440262,
        0x0280029E,
        0x02BC02F8,
        0x03340370,
        0x03AC03E8,
        0x04240460,
        0x049C04D8,
        0x05140550,
        0x058C05F0,
        0x066806E0,
        0x075807D0,
        0x084808D4,
        0x096009C4,
        0x0A280A8C,
        0x0AF00BE0,
        0x0CD00DD4,
        0x0ED80FC8,
        0x10B811BC,
        0x12C013B0,
        0x14A015A4,
        0x16A81838,
        0x19C81B58,
        0x1DB02008,
        0x22602580,
    }
};
