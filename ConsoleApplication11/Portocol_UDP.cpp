#include "stdafx.h"

inline Protocol_UDP::
Protocol_UDP(u_char * _uBytes, int _iLength) {
	if (_iLength < sizeof(_UDP_HEADER)) {
		return;
	}
	else {
		memcpy(&UDP_HEADER, _uBytes, sizeof(_UDP_HEADER));
	}
	cout << "UDP\tFrom Port:" << (int)UDP_HEADER.m_usSourPort << " To "
		<< (int)UDP_HEADER.m_usDestPort << " Size:" << UDP_HEADER.m_usLength << endl;
}
