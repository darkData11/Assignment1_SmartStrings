#include <iostream>
#include <memory>
#include "StringBuffer.h"
#include "String.h"

using namespace std;


String::String() {
	this->_str = new StringBuffer();
	this->owner = false;
}

String::~String() {

	if (this->owner)
	{
		this->owner = false;
		delete this->_str;
	}
	else
		this->_str = nullptr;

	
}


String::String(String& newString) {
// a new owner to be be set. the ownership is taken from the passed string if it is the owner	
	if (newString.owner)
	{
		this->_str = newString._str;
		this->owner = true;
		newString._str = this->_str;
		newString.owner = false;
	}

//if new string isn't the owner, there will be no transfer of ownership. simple copy here
	else 
	{
		this->_str = newString._str;
		this->owner = false;
	}

}

//copy a char* into your string

String::String(char* newString, int length) {// setting a new owner for a new string 
	this->_str = new StringBuffer(newString, length);
	this->owner = true;

}

void String::append(char c) {
// increase the length for the character and append			
	this->_str->reserve(this->_str->length() + 1);
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
