/* Observer Interface class */

#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <iostream>
#include <list>
#include <string>

class iObserver 
{
public:
	virtual ~iObserver(){}
	virtual void update(const std::string messageFromSubject) = 0;
	virtual void stopObserving() = 0;
};

#endif //IOBSERVER_HPP 
