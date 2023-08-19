#ifndef STATUS_H
#define STATUS_H
#include <stdio.h>
enum MACHINE_STATUS
{
    IDLE = 0,
    POSITIVE = 1,
    NEGATIVE = 2,
    INVALID_STATUS = 3
};
enum MACHINE_ACTION
{
    MOVE_PHASE = 0,
    POSITIVE_MOVE = 1,
    NEGATIVE_MOVE = 2,
    INVALID_ACTION = 3
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