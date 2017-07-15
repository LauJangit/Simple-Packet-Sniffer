#pragma once


class Protocol_RARP {
	typedef unsigned char u_char;
	typedef struct
	{
		unsigned short hType;
		unsigned short pType;
		unsigned char hLen;
		unsigned char pLen;
		unsigned short oPer;
		unsigned char destMac[6];
		unsigned long spa;
		unsigned char sourceMac[6];
		unsigned long tpa;
	}_RARP_HEADER;
	_RARP_HEADER RARP_HEADER;
public:
	Protocol_RARP(u_char *_uBytes, int _iLength);
};