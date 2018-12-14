#include "stdafx.h"
#include<iostream>
#include"windows.h"
#include<stdio.h>

//����C++����Ŀ�з��֣������ù���c#��lock����{}��java��Synchronize��������
//��windows�Դ����ٽ��������������ں��¼����ź�����������̫ϰ�ߣ�
//���Ǵ����Լ���vc++�з�װһ�����ƵĶ�������װ����Ҿ�������һ���ٽ������������յ���ʽ���£�
//synchronize(object)
//{
//	//....���۴˴��Ƿ����쳣��object���ܱ��ͷŵ�����c#��lockһ����
//}

#define synchronized(M)  for(Lock M##_lock = M; M##_lock; M##_lock.SetUnlock())
//��仰������õ������԰�java��ʽֱ��ʹ��synchronized

class Mutex
{
public:
	Mutex(void);
	~Mutex(void);
	void Lock();
	void UnLock();
private:
	CRITICAL_SECTION m_criticalSection;
};

class Lock
{
public:
	Lock(Mutex &mutex);
	~Lock(void);
	void SetUnlock();
	operator bool() const;
private:
	Mutex & m_mutex;
	bool m_locked;
};