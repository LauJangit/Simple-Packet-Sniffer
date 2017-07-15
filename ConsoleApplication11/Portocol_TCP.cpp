#include "stdafx.h"


inline Protocol_TCP::Protocol_TCP(u_char *_uBytes, int _iLength) {
	if (_iLength < sizeof(_TCP_HEADER)) {
		return;
	}
	else {
		memcpy(&TCP_HEADER, _uBytes, sizeof(_TCP_HEADER));
	}
	cout << "TCP\tFrom Port:" << (int)TCP_HEADER.m_sSourPort << " To " << (int)TCP_HEADER.m_sDestPort << endl;
}

#include "stdafx.h"
