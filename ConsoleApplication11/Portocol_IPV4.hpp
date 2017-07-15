#pragma once

class Protocol_IPV4 {
	typedef unsigned char u_char;
	typedef struct
	{
		u_char ucVersionHeaderLen;
		u_char ucTypeOfService;
		u_char ucTotalLenOfPacket[2];
		u_char ucPacketID[2];
		u_char ucSliceinfo[2];
		u_char ucTTL;
		u_char ucTypeOfProtocol;
		u_char ucCheckSum[2];
		u_char ucSourIp[4];
		u_char ucDestIp[4];
	}_IP_HEADER;
	typedef struct
	{
		u_char* packet;
		int iLength;
	}_IP_BODY;
public:
	_IP_HEADER IP_HEADER;
	_IP_BODY IP_BODY;
public:
	int length();
	int type();
	Protocol_IPV4(u_char *_uBytes, int _iLength);
	int get_protocol_num(int _iCode);
};

