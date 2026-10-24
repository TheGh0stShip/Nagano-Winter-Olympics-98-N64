typedef struct SchedulerClient SchedulerClient;

struct SchedulerClient {
    SchedulerClient *next;
};

typedef struct Scheduler {
    unsigned char pad_000[0xD28];
    SchedulerClient *clients;
} Scheduler;

extern unsigned int func_8004E680(unsigned int mask);

void func_80003FB0(Scheduler *scheduler, SchedulerClient *target) {
    SchedulerClient *client = scheduler->clients;
    SchedulerClient *previous = 0;
    unsigned int mask = func_8004E680(1);

    while (client != 0) {
        if (client == target) {
            if (previous != 0) {
                previous->next = target->next;
            } else {
                scheduler->clients = target->next;
            }
            break;
        }
        previous = client;
        client = client->next;
    }
    func_8004E680(mask);
}
