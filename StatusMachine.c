#include "StatusMachine.h"
int postiveMove(int status)
{
    printf("machine positive move\n");
    return POSITIVE;
}
int negativeMove(int status)
{
    printf("machine negative move\n");
    return NEGATIVE;
}
int movePhase(int status)
{
    printf("shutDown the machine\n");
    return MOVE_PHASE;
}
int idle()
{
    printf("idle but can move immediately\n");
    return MOVE_PHASE;  
}

Act_Handler postiveHandler[] = 
{
    {MOVE_PHASE, movePhase},
    {POSITIVE_MOVE, postiveMove}
};

Act_Handler negativeHandler[] = 
{
    {MOVE_PHASE, movePhase},
    {NEGATIVE_MOVE, negativeMove}
};

static Status_Handler statusHandler[] = 
{
    {POSITIVE, sizeof(postiveHandler)/sizeof(Act_Handler), postiveHandler},
    {NEGATIVE, sizeof(negativeHandler)/sizeof(Act_Handler), negativeHandler},
};

static int currentStatus = IDLE;
static int statSize = sizeof(statusHandler)/ sizeof(Status_Handler);
void execute(int action)
{
    if(currentStatus >= statSize)
    {
        printf("unknow machine status\n");
        return;
    }
    printf("current status is %d, will do action %d\n",currentStatus, action);
    int nextStatus = currentStatus;
    Act_Handler *actHandler = statusHandler[currentStatus].actHandler;
    int actNum = statusHandler[currentStatus].actNum;
    int actIdx = 0;
    /*遍历指定状态下的行为集，找到对应的行为*/
    for(actIdx = 0;actIdx < actNum; actIdx++)
    {
        if(actHandler[actIdx].action == action)
        {
            nextStatus = (actHandler[actIdx].handler)(action);
            break;
        }
    }
    if(actIdx == actNum)
    {
        printf("did find action %d in status %d\n", action, currentStatus);
    }
    currentStatus = nextStatus;
    printf("next status is %d\n",currentStatus);
}