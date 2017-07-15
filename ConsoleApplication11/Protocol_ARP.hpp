#pragma once


class Protocol_ARP {
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
	}_ARP_HEADER;
	_ARP_HEADER ARP_HEADER;
public:
	Protocol_ARP(u_char *_uBytes, int _iLength);
};