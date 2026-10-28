typedef struct Client {
    int state;
    struct Client *self;
    void (*handler)(void);
} Client;

extern unsigned char D_80179668;
extern short D_8017966A;
extern unsigned char D_8017966D;
extern signed char D_8017966E;
extern signed char D_8017966F;
extern unsigned char D_80179670;
extern unsigned char D_801796D1;
extern unsigned char D_801796D2;
extern void *D_8007C910;
extern void func_80048310(void);
void func_80048274(Client *client) {
    D_80179668 = 8;
    D_801796D1 = 0;
    D_80179670 = D_801796D1;
    D_8017966D = D_80179670;
    D_801796D2 = D_8017966D;
    D_8017966A = D_801796D2;
    D_8017966E = 0;
    D_8017966F = D_8017966E;
    client->state = 0;
    client->handler = func_80048310;
    client->self = client;
    func_8005C8B0(D_8007C910, client);
}
