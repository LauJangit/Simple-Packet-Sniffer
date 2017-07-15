#include "stdafx.h"

inline Protocol_ICMP::Protocol_ICMP(u_char * _uBytes, int _iLength) {
	if (_iLength < 4) {
		return;
	}
	else {
		memcpy(&ICMP_HEADER, _uBytes, 4);
	}
	cout << "ICMP\tType:" << (int)ICMP_HEADER.ucType << " Code:" << (int)ICMP_HEADER.ucCode << endl;
}
