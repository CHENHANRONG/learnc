#pragma once
#ifndef ABSTRACT_REQUEST_H
#define ABSTRACT_REQUEST_H

// pure virtual AbstractRequest class
/* 
The advantage of using an abstract class as the basis for 
a request is that it allows the Dispatcher class to handle 
many different types of requests as long as they all 
adhere to this same basic API.
*/
class AbstractRequest {
	//
	
public:
	virtual void setValue(int value) = 0;
	virtual void process() = 0;
	virtual void finish() = 0;
};

#endif
