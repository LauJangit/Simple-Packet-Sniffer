#pragma once

using namespace std;

class Protocol_ICMP  {
	typedef unsigned char u_char;
	typedef struct
	{
		u_char ucType;
		u_char ucCode;
		u_char ucCheckSum[2];
	}_ICMP_HEADER;
	_ICMP_HEADER ICMP_HEADER;
public:
	
	Protocol_ICMP(u_char *_uBytes, int _iLength);
};
