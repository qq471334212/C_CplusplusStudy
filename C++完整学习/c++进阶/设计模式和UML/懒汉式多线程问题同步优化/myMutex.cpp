#include "stdafx.h"
#include<iostream>
#include"windows.h"
#include<stdio.h>
#include"myMutex.h"

//Mutex类实现

//初始化区
Mutex::Mutex(void)
{
	InitializeCriticalSection(&m_criticalSection);
}

//释放临界区
Mutex::~Mutex(void)
{
	DeleteCriticalSection(&m_criticalSection);    //保证对象被析构时删除临界区
}

//临界区加锁
void Mutex::Lock()
{
	EnterCriticalSection(&m_criticalSection);     //进入临界区
}

//临界区解锁
void Mutex::UnLock()
{
	LeaveCriticalSection(&m_criticalSection);
}

//Lock类实现

Lock::Lock(Mutex &mutex) :m_mutex(mutex), m_locked(true)
{
	m_mutex.Lock();
}
//一定要在析构函数中解锁。因为不管发生什么，只要对象离开他的生命周期（即离开大括号），都会调用其析构函数
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