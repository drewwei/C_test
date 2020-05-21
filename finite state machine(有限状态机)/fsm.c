#include <stdio.h>
/*
 *有限状态机算法
 *利用函数指针实现
 */

/*1.定义状态*/

typedef enum{
	GetUp,
	Work,
	HaveLunch,
	GoHome,
	Sleep,
}States_t;

/*2.定义触发事件*/

typedef enum{
	Alarm = 1,
	Live,
	Hungry,
	Dark,
	Tired,
}Events_t;

/*3.定义状态表的数据结构 */
typedef struct FsmTable_s{
	Events_t event; //事件类型
	States_t CurState; //当前状态
	void (*EventActFun)();// 事件发生后调用的函数指针
	States_t NextState; //下一个状态
}FsmTable_t;



void GetUpFun(void)
{
	printf("get up.\n");
}
void WorkFun(void)
{
	printf("go to work.\n");
}
void HaveLunchFun(void)
{
	printf("have lunch.\n");
}
void GoHomeFun(void)
{
	printf("go home.\n");
}
void SleepFun(void)
{
	printf("go to sleep.\n");
}


/*4.定义FSM的状态表*/
FsmTable_t FsmTable[] = {
//   到来的事件，当前状态，将要执行的函数，下一个状态
	{Alarm, Sleep, GetUpFun, GetUp},
	{Live, GetUp, WorkFun, Work},
	{Hungry, Work, HaveLunchFun, HaveLunch},
	{Dark, HaveLunch, GoHomeFun, GoHome},
	{Tired, GoHome, SleepFun, Sleep},
};

/*定义状态机*/
typedef struct FSM_s
{
	FsmTable_t *FsmTable;
	States_t CurState;
	Events_t even;
}FSM_t;

/*注册状态机*/
void FSM_Regist(FSM_t *pFSM, FsmTable_t *ptable)
{
	pFSM->FsmTable = ptable;
}
/*状态迁移*/
void FSM_StateTransfer(FSM_t *pFSM, States_t state)
{
	pFSM->CurState = state;
}


void Init_FSM(FSM_t *pFSM, FsmTable_t *ptable, States_t state, Events_t event)
{
	FSM_Regist(pFSM, ptable);
	pFSM->CurState = state;
	pFSM->even = event;
}


int main()
{
	FSM_t FSM;
	Init_FSM(&FSM, FsmTable, Sleep, Alarm);
	int i = 0, j = 5;
	while(1)
	{	
		i = i%(sizeof(FsmTable)/sizeof(FsmTable_t));
		
		if((FSM.CurState == FsmTable[i].CurState) && (FSM.even == FsmTable[i].event))
		{
			FsmTable[i].EventActFun();
			FSM.CurState = FsmTable[i].NextState;
			if( i == (sizeof(FsmTable)/sizeof(FsmTable_t)-1))
			{
				FSM.even = FsmTable[0].event;
			}
			else
			{
				FSM.even = FsmTable[i+1].event;
			}
		}
		i++;
		
		while(j--);

	}

	return 0;
}