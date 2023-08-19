#ifndef STATUS_H
#define STATUS_H
#include <stdio.h>
#define METHOD 0
enum MACHINE_STATUS
{
    IDLE = 0,
    POSITIVE = 1,
    NEGATIVE = 2,
    INVALID_STATUS = 3
};
enum MACHINE_ACTION
{
    IDLE_NOMOVE = 0,
    MOVE_PHASE = 1,
    POSITIVE_MOVE = 2,
    NEGATIVE_MOVE = 3,
    INVALID_ACTION = 4
};


typedef int (*Handler)(int);

typedef struct Act_Handler
{
    int action;
    Handler handler;
}Act_Handler;

typedef struct Status_Handler
{
    int status;
    int actNum;
    Act_Handler *actHandler;
}Status_Handler;

#endif