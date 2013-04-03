
/**
*   @brief  ��ʱ���߼�������ࡣ���ж�ʱ�����������̳С���Ҫ֧��ֻ�лص�������û��
*/
#ifndef _CTIMERBASE_H_
#define _CTIMERBASE_H_

#include <sys/time.h>

class CTimerBase
{
public:
    CTimerBase();
    virtual ~CTimerBase ();

    /**
    *   @brief  
    */
    virtual int Handle ();
    
    virtual void Reclaim ();

    CTimerBase & operator= (CTimerBase &oRth);
    
    void SetCycleFlag (char cFlag);
    char GetCycleFlag ();

    void SetIntervalTime (unsigned int iIntervalTime);
    unsigned int GetIntervalTime ();

    void SetNewFlag (char cFlag);
    char GetNewFlag ();

    void SetProcessTime (struct timeval *stTime);
    struct timeval *GetProcessTime ();

    void SetCmdID(int iCmdID);
    int GetCmdID(){ return m_iCmdID; }

    virtual int PreHandle();
    virtual int PosHandle();

    void SetExpireTick(unsigned int expire){m_iExpire = expire;};
    unsigned int GetExpireTick(){return m_iExpire;};
    
protected:
    char         m_cCycleFlag;   //ѭ����ʾ��0 ��ѭ����1ѭ����
    unsigned int m_iIntervalTime;   // ��ʱʱ��.��λ:���� 
    unsigned int m_iExpire;         // �����TimerWrap��Init�Ժ��tick��

    struct timeval m_stProcessTime; // �����ʱ�䡣

    char         m_cNewFlag;     // ��̬�����ʶ��1 mgr�Լ�new�����ġ�

    int          m_iCmdID;
};

#endif


