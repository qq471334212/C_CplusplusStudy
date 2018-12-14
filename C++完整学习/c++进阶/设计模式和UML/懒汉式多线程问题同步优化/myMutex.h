#include "stdafx.h"
#include<iostream>
#include"windows.h"
#include<stdio.h>

//在做C++的项目中发现，由于用惯了c#的lock（）{}和java的Synchronize（）｛｝
//，windows自带的临界区，互斥量，内核事件，信号量用起来不太习惯，
//于是打算自己在vc++中封装一个类似的东东。封装这个我决定采用一个临界区来做，最终的形式如下：
//synchronize(object)
//{
//	//....无论此处是否发生异常，object都能被释放掉。和c#的lock一样。
//}

#define synchronized(M)  for(Lock M##_lock = M; M##_lock; M##_lock.SetUnlock())
//这句话后面会用到，可以按java形式直接使用synchronized

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