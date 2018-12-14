#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void eyeTreat()
	{
		cout << "治疗 眼科病" << endl;
	}

	void noseTreat()
	{
		cout << "治疗 鼻科病" << endl;
	}
};

//对命令进行抽象
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


//护士为命令发起者，接受病例，发送给医生
class Nurse
{
public:
	Nurse(Command * command)
	{
		this->command = command;
	}
	void SubCase()      //提交病历，下达命令
	{
		command->treat();
	}
private:
	Command * command;
};

//护士长，可以一次收集多个命令
class AdvNurse
{
public:
	AdvNurse()
	{
		m_list.clear();
	}
	void SetCommand(Command *command)      //收集命令
	{
		m_list.push_back(command);
	}
	void SubCase()      //提交病历，下达命令
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
	//1.医生直接看病
	//Doctor *d = new Doctor;
	//d->eyeTreat();

	//delete d;

	//2.通过一个命令,让医生治疗眼科病，鼻科病
	//Doctor *d = new Doctor;
	//CommandEyeTreat *commandeyetreat = new CommandEyeTreat(d);
	//commandeyetreat->treat();

	//CommandNoseTreat *commandnosetreat = new CommandNoseTreat(d);
	//commandnosetreat->treat();

	//delete d;
	//delete commandeyetreat;
	//delete commandnosetreat;

	//3.护士来发布命令，医生看病
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


	//4.护士长发布多条命令
	AdvNurse    *advnurse = NULL;
	Doctor		*d = NULL;
	Command		*command1 = NULL;
	Command		*command2 = NULL;

	d = new Doctor;
	command1 = new CommandEyeTreat(d);
	command2 = new CommandNoseTreat(d);

	advnurse = new AdvNurse();  //护士长
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