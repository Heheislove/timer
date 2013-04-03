/**
 *   @file     TimerWrap.h
 *   @brief    ��ʱ����װ��
 *   @author   kurtliu.JS.IEG.Tencent.
 *   @date     2013-02-01
 *   @note
 */

#ifndef __TIMER_WRAP_H__
#define __TIMER_WRAP_H__

#include "TimerBase.h"
#include <list>

#include <cstdio>
#define LOG_ERR printf
#define LOG_DBG printf

#define MILLISEC_PER_SEC 1000 //1����1000����
#define MICROSEC_PER_MS  1000 //1������1000΢��

#define TICK_INTERVAL    200  //ÿ��TICK֮���ʱ��������λ����

#define SLOTS_PER_WHEEL  10
#define SLOT_MASK        (SLOTS_PER_WHEEL - 1)
#define WHEEL_NUM        10    //�ܹ�֧�ֵ�200����~2 * 10^9��Ķ�ʱʱ��

struct timeval;

class TimerWrap
{
public:
    TimerWrap() : m_tickCount(0){};
    ~TimerWrap(){};

    int AddTimer(CTimerBase *timer);
    int Tick();

    static TimerWrap* Instance(){static TimerWrap timerWrap; return &timerWrap;};

private:
    int TimevalInterval(struct timeval& tv1, struct timeval& tv2);
    int UpdateLastTick(unsigned int ticks);
    unsigned int MsToTick(unsigned int ms);
    unsigned int GetTicks(struct timeval &tv1, struct timeval &tv2);
    int RunTimer(std::list<CTimerBase*>& timerList);
    int CascadeTimer(std::list<CTimerBase*>& timerList);
    int InternalTick();
    int InternalAddTimer(CTimerBase *timer);

    unsigned int          m_tickCount;
    struct timeval        m_lastTick;
    struct timeval        m_initTime;
    std::list<CTimerBase*> m_wheels[WHEEL_NUM][SLOTS_PER_WHEEL];
};

#endif
