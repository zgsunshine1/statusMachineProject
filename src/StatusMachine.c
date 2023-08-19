#include "inc/StatusMachine.h"

/*下面的这些函数都是用数据结构中定义的函数指针（模仿成员函数）指向这些具体的定义*/
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
    printf("machine move phase\n");
    return MOVE_PHASE;
}
int idle(int status)
{
    printf("idle but can move immediately\n");
    return IDLE_NOMOVE;  
}
/*如果要扩展状态，这里添加一个函数，把不同的状态放入一个处理，就能随意组合状态*/
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

Act_Handler idleHandler[] = 
{
    {INVALID_ACTION, idle}
};
/*不同状态有不同的执行函数，新添加状态组合都可以直接在这里面添加*/
static Status_Handler statusHandler[] = {
    {IDLE, sizeof(idleHandler)/sizeof(Act_Handler), idleHandler},
    {POSITIVE, sizeof(postiveHandler)/sizeof(Act_Handler), postiveHandler},
    {NEGATIVE, sizeof(negativeHandler)/sizeof(Act_Handler), negativeHandler},
};

static int currentStatus = IDLE;
static int statSize = sizeof(statusHandler)/ sizeof(Status_Handler);
/*执行函数对于扩展逻辑不变*/
void execute(int action)
{
    if((currentStatus >= statSize) || (action >= statSize))
    {
        printf("unknow machine status currentStatus:%d, action:%d\n", currentStatus, action);
        return;
    }
    printf("current status is %d, will do action %d\n",currentStatus, action);
    int nextStatus = currentStatus;
    Act_Handler *actHandler = statusHandler[action].actHandler;
    int actNum = statusHandler[action].actNum;
    int actIdx = 0;
    for(actIdx = 0;actIdx < actNum; actIdx++)
    {
        nextStatus = (actHandler[actIdx].handler)(action);
    }
    currentStatus = nextStatus;
    printf("next status is %d\n",currentStatus);
}