#include "stdafx.h"


inline Protocol_RARP::Protocol_RARP(u_char * _uBytes, int _iLength) {
	if (_iLength < sizeof(_RARP_HEADER)) {
		return;
	}
	else {
		memcpy(&RARP_HEADER, _uBytes, sizeof(_RARP_HEADER));
	}
	cout << "RARP" << endl;
}
