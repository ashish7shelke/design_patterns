#include <iostream>
#include "iObserver.hpp"
#include "subject.hpp"
#include "observer.hpp"

void observerLogic()
{
	subject *subject0 = new subject;
	
	observer *observer1 = new observer(*subject0);
	observer *observer2 = new observer(*subject0);
	observer *observer3 = new observer(*subject0);
	observer *observer4;// = new Observer(*subject0);
	observer *observer5;// = new Observer(*subject0);
	
	subject0->createMessage();
	
	observer3->stopObserving();
	
	subject0->createMessage();
	
	observer4 = new observer(*subject0);
	
	observer2->stopObserving();		

	observer5 = new observer(*subject0);
	
	subject0->createMessage("Out of Office");
	
	observer4->stopObserving();
	observer5->stopObserving();	
	observer1->stopObserving();
	
	delete observer1;
	delete observer2;
	delete observer3;
	delete observer4;
	delete observer5;
	delete subject0;					
}

int main()
{
	observerLogic();
	return 0;	
}

