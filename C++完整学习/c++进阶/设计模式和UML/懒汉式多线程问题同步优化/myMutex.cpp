#include "stdafx.h"
#include<iostream>
#include"windows.h"
#include<stdio.h>
#include"myMutex.h"

//Mutex��ʵ��

//��ʼ����
Mutex::Mutex(void)
{
	InitializeCriticalSection(&m_criticalSection);
}

//�ͷ��ٽ���
Mutex::~Mutex(void)
{
	DeleteCriticalSection(&m_criticalSection);    //��֤��������ʱɾ���ٽ���
}

//�ٽ�������
void Mutex::Lock()
{
	EnterCriticalSection(&m_criticalSection);     //�����ٽ���
}

//�ٽ�������
void Mutex::UnLock()
{
	LeaveCriticalSection(&m_criticalSection);
}

//Lock��ʵ��

Lock::Lock(Mutex &mutex) :m_mutex(mutex), m_locked(true)
{
	m_mutex.Lock();
}
//һ��Ҫ�����������н�������Ϊ���ܷ���ʲô��ֻҪ�����뿪�����������ڣ����뿪�����ţ��������������������
Lock::~Lock(void)
{
	m_mutex.UnLock();
}

void Lock::SetUnlock()
{
	m_locked = false;
}

Lock::operator bool()const
{
	return m_locked;
}