typedef struct { char pad[0x14]; float first; float second; } State;
extern State D_80131920;
void func_8000A97C(float first, float second) { D_80131920.first = first; D_80131920.second = second; }
