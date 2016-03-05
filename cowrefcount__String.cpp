#include <memory>
#include <iostream>
#include "StringBuffer.h"
#include "String.h"

using namespace std;
//default constructor

String::String() {
	this->_str = new StringBuffer();
}
//destructor

String::~String() {

	cout << "Original Length"<< this->_str->length()<<" :" <<this->_str->_refcount << endl;
	int count= --this->_str->_refcount;
	if (count < 1) {
		cout << "New length" << this->_str->length() << " :" << this->_str->_refcount << endl;			
		delete this->_str;
	}

}

//copy a const String into this string

String::String(const String& newString) {
	this->_str = newString._str;

	//increment the refcount by 1
	this->_str->_refcount++;
}

String::String(char* newString, int length) {
	this->_str = new StringBuffer(newString, length);
	this->_str->_refcount++;

}

void String::append(char c) {

	if (this->_str->_refcount > 1) 
	{
		auto_ptr<StringBuffer> smartPtr(new StringBuffer);
		smartPtr.get()->reserve(this->_str->length() + 1);
		smartPtr.get()->smartCopy(this->_str);

		//decrement the reference count to this String
		--this->_str->_refcount;

		this->_str = smartPtr.release();
	}
	else {
		this->_str->reserve(this->_str->length() + 1);
	}

	//copy the new character at the end of this string
	this->_str->append(c);

}

//get length of the string

int String::length() const {
	return this->_str->length();
}

//get character at index if it is less than length

char String::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();

	}
}
