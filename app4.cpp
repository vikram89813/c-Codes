// app4.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <functional>
#include <algorithm>
#include <mutex>

using namespace std;

/*
develop a reminder application in which user should be able to enter
1. day month year hh mm and message
user should be able to enter repeatedly
application should remember user inputs and keep watching system time
when application finds that when the system time and one of the entry matching, user should display the message
that particular entry should be removed or forgotten
*/

//Features: template, function<>, Thread Safety, RAII, vector<>, alorithm, variadic templates
//operator overloading, perfect forwarding

template<class TFunctionSignature>
class Event final
{
	vector<function<TFunctionSignature>> listeners;//many listeners objects
	mutex m;
public:
	Event(/*this*/){}
	void operator += (/*this*/const function<TFunctionSignature>& listener){
		lock_guard<mutex> guard(m);
		listeners.push_back(listener);
	}

	void operator -= (/*this*/const function<TFunctionSignature>& listener){
		lock_guard<mutex> guard(m);
		//TODO: find and erase algorithm
	}

	template<class... TArgs>
	void operator() (/*this*/TArgs... args){
		lock_guard<mutex> guard(m);
		for (function<TFunctionSignature> listener : listeners){
			listener(forward <TArgs>(args)...);
		}
	}

	Event(const Event&) = delete;
	Event& operator= (const Event&) = delete;
};


class DateTime{
	int day, month, year, hour, minute;
public:
	DateTime(/*DateTime *const this */ int day, int month, int year, int hour, int minute)
		:day(day), month(month), year(year), hour(hour), minute(minute)
	{
		
	}
	int getDate(/*const DateTime * const this*/) const { return day; }
	int getMonth(/*const DateTime * const this*/) const { return month; }
	int getYear(/*const DateTime * const this*/) const { return year; }
	int getHour(/*const DateTime * const this*/) const { return hour; }
	int getMinute(/*const DateTime * const this*/) const { return minute; }

	static DateTime now(){
		time_t t = time(NULL); //get the current time
		tm now;
		localtime_r(&t,&now);
		//now = localtime(&t);
		return DateTime(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900, now.tm_hour, now.tm_min);
	}

	bool operator == (/*const DateTime* const this = &lhs*/const DateTime& rhs) const {
		return this->year == rhs.year && this->month && rhs.month && this->day == rhs.day && this->hour == rhs.hour && this->minute == rhs.minute;
	}
};

class ReminderEntry{
	DateTime dateTime;
	string message;
	bool _isCompleted = false;
public:
	ReminderEntry(/*ReminderEntry * const this*/const DateTime& dateTime, const string& message)//copy ctor will b called for message
	:dateTime(dateTime),
	message(message){}

	const DateTime& getDateTime(/*ReminderEntry * const this*/) const { return dateTime; }
	const string& getMessage(/*ReminderEntry * const this*/) const { return message; }
	const bool& isCompleted() const { return _isCompleted; }
	void markCompleted() { _isCompleted = true; }
};

template<class T>
class my_lock_guard {
private:
	T& obj;//T* const obj;
public:
	my_lock_guard(T &obj) :obj(obj)
	{
		obj.lock();
	}
	~my_lock_guard(){
		obj.unlock();
	}
	my_lock_guard(const my_lock_guard&) = delete;
	my_lock_guard& operator=(const my_lock_guard&) = delete;
};

class ReminderLogic{
	vector<ReminderEntry> reminders;
	thread monitorThread;
	mutex m;
	
	//Secondary Thread
	void monitor(/*ReminderLogic* const this*/) { 
		while (true) {
			//m.lock();
			my_lock_guard<mutex> guard1(m);
			DateTime currentTime = DateTime::now();
			//For each item in the array check current time == reminder time
			//fire event and mark the reminder completed
			//-----------------------Refer
			for_each(begin(reminders), end(reminders), 
				[&currentTime, this](ReminderEntry& reminder){
								if (reminder.getDateTime() == currentTime) {
									Alarm(reminder.getMessage());
									reminder.markCompleted();
								}});

			//TODO remove the reminder from reminders array
			auto it = stable_partition(begin(reminders), end(reminders), [](ReminderEntry& reminder){return reminder.isCompleted() == false; });//shift towards left
			if (it != reminders.end())
				reminders.erase(it, reminders.end());
			//m.unlock();
		}//guard1 will be killed and dtor will be called; which will unlock the mutex;
	}

public:

	Event<void(string)> Alarm;
	Event<void(string,double)> Event2;
	Event<void(string,double,string)> Event3;

	//Main Thread
	ReminderLogic()
		: monitorThread(bind(&ReminderLogic::monitor, this)) //binds, function address and the object address;
	{

	}

	//Main Thread
	void addReminder(/*ReminderLogic * const this*/const DateTime& dateTime, const string& message) {
		//m.lock();
		//my_lock_guard<mutex> guard2(m);
		{
			my_lock_guard<mutex> guard2(m); //only for this block guard2 is applied. block structure is needed if u want to unlock after reminders is used.
		    reminders.emplace_back(dateTime, message);
		}//guard2 will die here.
		//m.unlock();
	}//guard2 will be killed and dtor will be called; which will unlock the mutex;
};

class ConsoleUI{
	ReminderLogic reminderLogic;
public:
	ConsoleUI(){
		reminderLogic.Alarm += [](string message){
			cout << message << endl;
		};
	}

	void show(/*ConsoleUI * const this = &cui */){ //Main Thread
		int day, month, year, hour, minute;
		string message;
		while (true) { //Main Thread
			cout << "Day:";
			cin >> day; //Main Thread will get blocked by cin; cin is a blocking call;

			cout << "Month:";
			cin >> month;//Main Thread will get blocked by cin; cin is a blocking call;

			cout << "Year:";
			cin >> year;//Main Thread will get blocked by cin; cin is a blocking call;

			cout << "Hour:";
			cin >> hour;//Main Thread will get blocked by cin; cin is a blocking call;

			cout << "Minute:";
			cin >> minute;//Main Thread will get blocked by cin; cin is a blocking call;

			cout << "Message:";
			getline(cin, message);

			reminderLogic.addReminder(DateTime(day, month, year, hour, minute), message);
		}
	}
};

int main()
{

	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//rotate(begin(arr) + 1, begin(arr)+3, begin(arr)+7);
	//for (int item : arr)
	//	cout << item << " ";

	ConsoleUI cui;
	//1. Memory for cui is allocated on the Main Thread's Stack
	//2. jmp ConsoleUI::ConsoleUI(&cui) (EB)

	cui.show(); //jmp &ConsoleUI::show(&cui); (EB)

	return 0;
}//cui object will die
//Dtor is called
//memory deallocted

