/* Subject Interface class */

#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include <iostream>
#include <list>
#include <string>

class iSubject
{
public:
	virtual ~iSubject(){}
	virtual void attach(iObserver *observer) = 0;
   	virtual void detach(iObserver *observer) = 0;
   	virtual void notify() = 0;
   	virtual void createMessage(std::string text) = 0;
   	virtual void changeState(std::string text) = 0;
};

#endif //ISUBJECT_HPP
 
