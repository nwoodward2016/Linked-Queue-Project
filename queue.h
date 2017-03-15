#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQueue, int item);
Status queue_service(QUEUE hQueue);
int queue_front(QUEUE hQueue, Status* pStatus);
Boolean queue_empty(QUEUE hQueue);

void queue_destroy(QUEUE* phQueue);

#endif
