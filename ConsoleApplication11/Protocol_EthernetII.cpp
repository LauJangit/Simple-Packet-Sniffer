#include "stdafx.h"


inline int Protocol_EthernetII::type() {
	return ((int)MAC_FRAME_HEADER.m_ucType[0]*100+ (int)MAC_FRAME_HEADER.m_ucType[1]);
}

inline Protocol_EthernetII::Protocol_EthernetII(const u_char * _uBytes, int _iLength) {
	if (_iLength < 20) {
		return;
	}
	else {
		memcpy(&MAC_FRAME_HEADER, _uBytes, sizeof(MAC_FRAME_HEADER));
	}
	const int iHeadLength = 14;
	const int iTailLength = 4;
	MAC_FRAME_BODY.packet = new u_char[_iLength - iHeadLength - iTailLength];
	memcpy(MAC_FRAME_BODY.packet, _uBytes + iHeadLength, _iLength - iHeadLength - iTailLength);
	Protocols::ProtocolUnit new_protocol = Protocols::get_protocol(get_protocol_num(type()), MAC_FRAME_BODY.packet, _iLength - iHeadLength - iTailLength);
	delete new_protocol.oProtocol;
	delete MAC_FRAME_BODY.packet;
}

inline int Protocol_EthernetII::get_protocol_num(int _iCode) {
	switch (_iCode) {
	case 800: return 141;
	case 806: return 142;
	case 835: return 143;
	default:cout << "E_ll(" << _iCode << ")"; return 0;
	}
	
}
