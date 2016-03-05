# Assignment1_SmartStrings
#include <iostream>
#include <cstdlib>
#include<cstring>
#include "StringBuffer.h"
#include "String.h"
using namespace std;


int main(int argc, char** argv) {
	//create a smart string
	//    String ss;
	//create a smart string with const char*
	char* hello = "hello";
//------------------------------------------------a simple string---------------------

	String ss(hello, 5);
	cout << "1st String: ";
	for (int i = 0; i < ss.length(); i++)
		{
			cout << ss.charAt(i);
		}
	

	cout << "1st String's length: " << ss.length() << endl;
	cout<<"----------------"<<endl;
	ss.append('A');
	cout << "1st String revised: ";
	for (int i = 0; i < ss.length(); i++)
		{
			cout << ss.charAt(i);
		}
	cout << endl;
	cout << "1st String revised length: " << ss.length() << endl;

	cout << "============================================================"<< endl;
	//copying from owner
	String ss1(ss); 
	cout << "2nd String: ";
	for (int i = 0; i < ss1.length(); i++)
		{
			cout << ss1.charAt(i);
		}
	cout << endl;
	cout << "2nd String's length: " << ss1.length() << endl;
	cout<<"----------------"<<endl;
	ss1.append('B'); // should also carry previous appends
	cout << "2nd String revised: ";
	for (int i = 0; i < ss1.length(); i++)
		{
			cout << ss1.charAt(i);
		}
	
	cout << "2nd String revised length: " << ss1.length() << endl;
	cout << "============================================================"<< endl;
	
	system("pause");
	return 0;
}
