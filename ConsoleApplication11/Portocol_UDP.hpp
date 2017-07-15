#pragma once

class Protocol_UDP  {
	typedef unsigned char u_char;
	typedef struct
	{
		unsigned short m_usSourPort;
		unsigned short m_usDestPort; 
		unsigned short m_usLength;
		unsigned short m_usCheckSum;
	}_UDP_HEADER;
	_UDP_HEADER UDP_HEADER;
public:
	Protocol_UDP(u_char *_uBytes, int _iLength);
};
