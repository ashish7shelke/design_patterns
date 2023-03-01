/**
* Subject owns some important state and notifies observer when the state changes
*/

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "iSubject.hpp"

class subject : public iSubject
{
public:
	virtual ~subject()
	{
		std::cout << "GoodBye, I was the subject." << std::endl;
	}
	
	void attach(iObserver *observer) override
	{
		listObserver.push_back(observer);
	}
	
	void detach(iObserver *observer) override
	{
		listObserver.remove(observer);
	}
	
	void notify() override
	{
		std::list<iObserver *>::iterator iter = listObserver.begin();
		
		while(iter != listObserver.end())
		{
			(*iter)->update(message);
			++iter;
		}
	}
	
	void createMessage(std::string text = "Offline")
	{
		this->message = text;
		this->notify();
	}
	
	void changeState(std::string text = "Online")
	{
		this->message = text;
		this->notify();
		std::cout << "Subject state is changed to " << this->message << "." << std::endl;
	}
	
	auto numberOfObserver()
	{	
		return listObserver.size();
	}
	
private:
	std::list<iObserver *> 	listObserver;
	std::string 		message;
};

#endif //SUBJECT_HPP
