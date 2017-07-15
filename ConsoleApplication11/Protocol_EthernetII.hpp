#pragma once

class Protocol_EthernetII {
	typedef unsigned char u_char;
	typedef struct
	{
		char m_cDstMacAddress[6];
		char m_cSrcMacAddress[6];
		u_char m_ucType[2];
	}_MAC_FRAME_HEADER;
	typedef struct
	{
		u_char *packet;
		int iLength;
	}_MAC_FRAME_BODY;
	_MAC_FRAME_HEADER MAC_FRAME_HEADER;
	_MAC_FRAME_BODY MAC_FRAME_BODY;
public:
	int type();
	Protocol_EthernetII(const u_char *_uBytes, int _iLength);
	int get_protocol_num(int _iCode);
};