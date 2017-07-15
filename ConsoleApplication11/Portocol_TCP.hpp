#pragma once

class Protocol_TCP {
	typedef unsigned char u_char;
	typedef struct
	{
		short m_sSourPort;
		short m_sDestPort;
		unsigned int m_uiSequNum;
		unsigned int m_uiAcknowledgeNum;
		short m_sHeaderLenAndFlag;
		short m_sWindowSize;
		short m_sCheckSum;
		short m_surgentPointer;
	}_TCP_HEADER;
	_TCP_HEADER TCP_HEADER;
public:
	Protocol_TCP(u_char *_uBytes, int _iLength);
};



