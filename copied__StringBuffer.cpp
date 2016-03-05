#include "StringBuffer.h"
#include <memory>
#include <iostream>

using namespace std;


StringBuffer::StringBuffer() {
	_strbuf = 0;
	_length = 0;
}


StringBuffer::~StringBuffer() {
	delete[] _strbuf;
	//this->_strbuf = NULL;
}

//copy a const StringBuffer into this string

StringBuffer::StringBuffer(const StringBuffer& newString) {
	this->_strbuf = new char[newString.length()];
	this->_length = newString.length();
	//copy the passed string into internal buffer
	this->smartCopy(newString._strbuf, _length);
}

//copy a char* into your string

StringBuffer::StringBuffer(char* newString, int length) {
	_length = length;
	delete[] _strbuf;
	_strbuf = new char[length];

	//_strbuf = newString;

	int iter = 0;
	while (iter < length) {//actual element-wise copying
		this->_strbuf[iter] = newString[iter];
		iter++;
	}

	//Should I delete the string passed by the user?
	//delete[] newString;

}

//make a smart copy of the StringBuffer into the callee StringBuffer

void StringBuffer::smartCopy(StringBuffer* newString) {
	int shorterLength = 0;
	(this->_length < newString->_length) ? shorterLength = this->_length : shorterLength = newString->_length;
	int iter = 0;
	while (iter < shorterLength) {
		this->_strbuf[iter] = newString->_strbuf[iter];
		iter++;
	}
}

//make a smart copy of the char* into this string

void StringBuffer::smartCopy(char* newString, int length) {
	//(this->_length == length)?:this->_length=length;
	this->_length = length;
	int iter = 0;
	while (iter < length) {
		this->_strbuf[iter] = newString[iter];
		iter++;
	}
}
//make a smart copy of this string into the passed string

void StringBuffer::revSmartCopy(char* newString) {
	int iter = 0;
	while (iter < _length) {
		newString[iter] = _strbuf[iter];
		iter++;
	}
}

void StringBuffer::reserve(int n) {
	if (_length < n) {
		int newlength = n; //max(_length*2,n);
		char* newbuf = new char[newlength];
		//copy contents of the stored string in the new buffer
		this->revSmartCopy(newbuf);

		//return stuff from the new buffer to the stored buffer
		//delete[] this->_strbuf;
		this->_strbuf = newbuf;
		this->_length = newlength;
	}
}

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBuffer::append(char c) {
	this->_strbuf[this->_length - 1] = c;
}
//get length of the string

int StringBuffer::length() const {
	return this->_length;
}

//get character at index if it is less than length

char StringBuffer::charAt(int index) const {
	if (index < _length) {
		return _strbuf[index];
	}
	else {
		//throw new IndexOutOfBoundException();
		return NULL;
	}
}
