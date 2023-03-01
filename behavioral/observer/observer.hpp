/**
* Observer owns some important state and notifies observer when the state changes
*/

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "iObserver.hpp"
#include "subject.hpp"

class observer : public iObserver
{
public:
	observer(subject &obj) : object(obj)
	{
		this->object.attach(this);
		std::cout << "Hello, I'm observer with Id " << ++observer::totalObserver << "." << std::endl;
		this->id = observer::totalObserver;		
	}
	
	virtual ~observer()
	{
		std::cout << "GoodBye, I was the observer with id " << this->id << "." << std::endl;
	}
	
	void update(const std::string messageFromSubject) override
	{
		this->messageFromSubject =  messageFromSubject;
		
		std::cout << "Observer " << this->id << " received new message from Subject * " << this->messageFromSubject <<" *"<< std::endl;
	}
	
	void stopObserving() override
	{
		this->object.detach(this);
		std::cout << "Observer id " << this->id << " stopped observing subject." << std::endl;
	}
	
private:
	std::string messageFromSubject;
	subject &object;
	unsigned int id;
	static unsigned int totalObserver;	
};

unsigned int observer::totalObserver = 0;

#endif //OBSERVER_HPP

