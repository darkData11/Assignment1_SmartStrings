#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
	this->_str = new StringBuffer();
	next_link = NULL;
	last_link = NULL;
}
//destructor

//linked list implementation for the reference tracking
String::~String() {

	//still has refrences
	if (this->next_link != NULL & this->last_link != NULL)
	{
		if (this->next_link->next_link == this && this->last_link->last_link == this)//only two links
		{
			//set all links pointing to it to null
			this->next_link->next_link = NULL;
			this->last_link->last_link = NULL;

			//set all of its pointers null
			this->last_link = NULL;
			this->next_link = NULL;
		}
		else//more than two links
		{
			this->last_link->next_link = this->next_link;
			this->next_link->last_link = this->last_link;

			this->next_link = NULL;
			this->last_link = NULL;
		}
		
	}
	
	else
	{
		delete this->_str;
	}

}

//copy a const String into this string

String::String( String& newString) {
	this->_str = newString._str;

	
	if (this->next_link == NULL && this->last_link == NULL && newString.next_link == NULL)
	{
		this->next_link = &newString;
		newString.next_link = this;

		this->last_link = &newString;
		newString.last_link = this;
	}
	else
	{
		this->next_link = newString.next_link;
		newString.next_link->last_link = this;

		this->last_link = &newString;
		newString.next_link = this;
	}

}

//copy a char* into your string

String::String(char* newString, int length) {
	
	this->_str = new StringBuffer(newString, length);
	this->next_link = NULL;
	this->last_link = NULL;
}

void String::append(char c) {


	if (this->next_link != NULL && this->last_link !=NULL) {
		//more than 1 reference to this string
		auto_ptr<StringBuffer> smartPtr(new StringBuffer);
		smartPtr.get()->reserve(this->_str->length() + 1);
		smartPtr.get()->smartCopy(this->_str);

		
		if (this->next_link->next_link == this)
		{
			this->next_link->next_link = NULL;
			this->next_link->last_link = NULL;

			this->next_link = NULL;
			this->last_link = NULL;
		}
		else
		{
			this->last_link->next_link = this->next_link;
			this->next_link->last_link = this->last_link;
			this->next_link = NULL;
			this->last_link = NULL;
		}

		this->_str = smartPtr.release();
	}
	
	else 
	{
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
	else 
	{
		//throw new IndexOutOfBoundException();

	}
}
