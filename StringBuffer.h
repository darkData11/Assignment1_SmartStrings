#ifndef STRINGBUFFER_H
#define	STRINGBUFFER_H

class StringBuffer{

public:
	StringBuffer();  
	~StringBuffer();                
	StringBuffer(const StringBuffer&);              
	StringBuffer(char*, int); 
	void smartCopy(char*, int);
	void smartCopy(StringBuffer*);
	void revSmartCopy(char* newString);

	char charAt(int) const;   
	int length() const;                 
	void reserve(int);                  
	void append(char);                  
										
private:
	char* _strbuf;                                  
	int _length;                                    
	
};

#endif	/* STRINGBUFFER_H */
