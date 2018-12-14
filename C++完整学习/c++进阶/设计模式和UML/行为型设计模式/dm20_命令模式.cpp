#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void eyeTreat()
	{
		cout << "���� �ۿƲ�" << endl;
	}

	void noseTreat()
	{
		cout << "���� �ǿƲ�" << endl;
	}
};

//��������г���
class Command
{
public:
	virtual void treat() = 0;
};

class CommandEyeTreat: public Command
{
public:
	CommandEyeTreat(Doctor *d)
	{
		m_d = d;
	}
	virtual void treat()
	{
		m_d->eyeTreat();
	}
private:
	Doctor * m_d;
};

class CommandNoseTreat: public Command
{
public:
	CommandNoseTreat(Doctor *d)
	{
		m_d = d;
	}
	virtual void treat()
	{
		m_d->noseTreat();
	}
private:
	Doctor * m_d;
};


//��ʿΪ������ߣ����ܲ��������͸�ҽ��
class Nurse
{
public:
	Nurse(Command * command)
	{
		this->command = command;
	}
	void SubCase()      //�ύ�������´�����
	{
		command->treat();
	}
private:
	Command * command;
};

//��ʿ��������һ���ռ��������
class AdvNurse
{
public:
	AdvNurse()
	{
		m_list.clear();
	}
	void SetCommand(Command *command)      //�ռ�����
	{
		m_list.push_back(command);
	}
	void SubCase()      //�ύ�������´�����
	{
		for (list<Command *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}
private:
	list<Command *> m_list;
};

void main201()
{
	//1.ҽ��ֱ�ӿ���
	//Doctor *d = new Doctor;
	//d->eyeTreat();

	//delete d;

	//2.ͨ��һ������,��ҽ�������ۿƲ����ǿƲ�
	//Doctor *d = new Doctor;
	//CommandEyeTreat *commandeyetreat = new CommandEyeTreat(d);
	//commandeyetreat->treat();

	//CommandNoseTreat *commandnosetreat = new CommandNoseTreat(d);
	//commandnosetreat->treat();

	//delete d;
	//delete commandeyetreat;
	//delete commandnosetreat;

	//3.��ʿ���������ҽ������
	//Doctor *d = new Doctor;
	//Command *command=new CommandEyeTreat(d);
	//command->treat();

	//Nurse		*nurse = NULL;
	//Doctor		*d = NULL;
	//Command		*command = NULL;
	//d = new Doctor;
	////command = new CommandEyeTreat(d);
	//command = new CommandNoseTreat(d);
	//nurse = new Nurse(command);
	//nurse->SubCase();

	//delete d;
	//delete command;
	//delete nurse;


	//4.��ʿ��������������
	AdvNurse    *advnurse = NULL;
	Doctor		*d = NULL;
	Command		*command1 = NULL;
	Command		*command2 = NULL;

	d = new Doctor;
	command1 = new CommandEyeTreat(d);
	command2 = new CommandNoseTreat(d);

	advnurse = new AdvNurse();  //��ʿ��
	advnurse->SetCommand(command1);
	advnurse->SetCommand(command2);
	advnurse->SubCase();

	delete advnurse;
	delete command2;
	delete command1;
	delete d;
}
int main20()
{
	main201();
	system("pause");
	return 0;
}