#pragma once

class Protocol {
	typedef unsigned char u_char;
public:
	Protocol(u_char * _uBytes, int _iLength);
};

class Protocols {
	typedef unsigned char u_char;
public:
	static struct ProtocolUnit
	{
		char* cName;
		char* cDescription;
		char* cDocument;
		Protocol* oProtocol;
	};
private:
	static Protocols::ProtocolUnit get_new_protocol(char* _cName, char* _cDescription, char* _cDocument);
	static Protocols::ProtocolUnit get_new_protocol(char* _cName, char* _cDescription, char* _cDocument, Protocol* _oProtocol);
public:
	static Protocols::ProtocolUnit get_protocol(int _iCode, u_char *_uBytes, int _iLength);
};


