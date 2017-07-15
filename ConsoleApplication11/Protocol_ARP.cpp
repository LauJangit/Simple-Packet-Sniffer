#include "stdafx.h"


inline Protocol_ARP::Protocol_ARP(u_char * _uBytes, int _iLength) {
	if (_iLength < sizeof(_ARP_HEADER)) {
		return;
	}
	else {
		memcpy(&ARP_HEADER, _uBytes, sizeof(_ARP_HEADER));
	}
	cout << "ARP" << endl;
}
