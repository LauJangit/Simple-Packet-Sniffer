#include "stdafx.h"
/*
#include "Portocol_ICMP.cpp"
#include "Portocol_IPV4.cpp"
#include "Portocol_UDP.cpp"
#include "Portocol_TCP.cpp"
*/

inline Protocol::Protocol(u_char * _uBytes, int _iLength) {
	cout << "UNKONWN PROTOCOL" << endl;
}

inline Protocols::ProtocolUnit Protocols::get_new_protocol(char * _cName, char * _cDescription, char * _cDocument) {
	Protocols::ProtocolUnit new_protocol;
	new_protocol.cName = _cName;
	new_protocol.cDescription = _cDescription;
	new_protocol.cDocument = _cDocument;
	new_protocol.oProtocol = new Protocol(NULL, 0);
	return new_protocol;
}

inline Protocols::ProtocolUnit Protocols::get_new_protocol(char * _cName, char * _cDescription, char * _cDocument, Protocol * _oProtocol) {
	Protocols::ProtocolUnit new_protocol;
	new_protocol.cName = _cName;
	new_protocol.cDescription = _cDescription;
	new_protocol.cDocument = _cDocument;
	new_protocol.oProtocol = _oProtocol;
	return new_protocol;
}

inline Protocols::ProtocolUnit Protocols::get_protocol(int _iCode, u_char * _uBytes, int _iLength) {
	switch (_iCode) {
	case 1: return get_new_protocol("ICMP", "Internet Control Message", "[RFC792]", (Protocol*)(new Protocol_ICMP(_uBytes, _iLength)));
	case 2: return get_new_protocol("IGMP", "Internet Group Management", "[RFC1112]");
	case 3: return get_new_protocol("GGP", "Gateway-to-Gateway", "[RFC823]");
	case 4: return get_new_protocol("IP", "IP in IP (encapsulation)", "[RFC2003]");
	case 5: return get_new_protocol("ST", "Stream", "[RFC1190,RFC1819]");
	case 6: return get_new_protocol("TCP", "Transmission Control", "[RFC793]", (Protocol*)(new Protocol_TCP(_uBytes, _iLength)));
	case 7: return get_new_protocol("CBT", "CBT", "[Ballardie]");
	case 8: return get_new_protocol("EGP", "Exterior Gateway Protocol", "[RFC888,DLM1]");
	case 9: return get_new_protocol("IGP", "any private interior gateway", "[IANA]");
	case 10: return get_new_protocol("BBN-RCC-MON", "BBN RCC Monitoring", "[SGC]");
	case 11: return get_new_protocol("NVP-II", "Network Voice Protocol", "[RFC741,SC3]");
	case 12: return get_new_protocol("PUP", "PUP", "[PUP,XEROX]");
	case 13: return get_new_protocol("ARGUS", "ARGUS", "[RWS4]");
	case 14: return get_new_protocol("EMCON", "EMCON", "[BN7]");
	case 15: return get_new_protocol("XNET", "Cross Net Debugger", "[IEN158,JFH2]");
	case 16: return get_new_protocol("CHAOS", "Chaos", "[NC3]");
	case 17: return get_new_protocol("UDP", "User Datagram", "[RFC768,JBP]", (Protocol*)(new Protocol_UDP(_uBytes, _iLength)));
	case 18: return get_new_protocol("MUX", "Multiplexing", "[IEN90,JBP]");
	case 19: return get_new_protocol("DCN-MEAS", "DCN Measurement Subsystems", "[DLM1]");
	case 20: return get_new_protocol("HMP", "Host Monitoring", "[RFC869,RH6]");
	case 21: return get_new_protocol("PRM", "Packet Radio Measurement", "[ZSU]");
	case 22: return get_new_protocol("XNS-IDP", "XEROX NS IDP", "[ETHERNET,XEROX]");
	case 23: return get_new_protocol("TRUNK-1", "Trunk-1", "[BWB6]");
	case 24: return get_new_protocol("TRUNK-2", "Trunk-2", "[BWB6]");
	case 25: return get_new_protocol("LEAF-1", "Leaf-1", "[BWB6]");
	case 26: return get_new_protocol("LEAF-2", "Leaf-2", "[BWB6]");
	case 27: return get_new_protocol("RDP", "Reliable Data Protocol", "[RFC908,RH6]");
	case 28: return get_new_protocol("IRTP", "Internet Reliable Transaction", "[RFC938,TXM]");
	case 29: return get_new_protocol("ISO-TP4", "ISO Transport Protocol Class 4", "[RFC905,RC77]");
	case 30: return get_new_protocol("NETBLT", "Bulk Data Transfer Protocol", "[RFC969,DDC1]");
	case 31: return get_new_protocol("MFE-NSP", "MFE Network Services Protocol", "[MFENET,BCH2]");
	case 32: return get_new_protocol("MERIT-INP", "MERIT Internodal Protocol", "[HWB]");
	case 33: return get_new_protocol("DCCP", "Datagram Congestion Control protocol", "[RFC-ietf-dccp-spec-11.txt]");
	case 34: return get_new_protocol("3PC", "Third Party Connect Protocol", "[SAF3]");
	case 35: return get_new_protocol("IDPR", "Inter-Domain Policy Routing Protocol", "[MXS1]");
	case 36: return get_new_protocol("XTP", "XTP", "[GXC]");
	case 37: return get_new_protocol("DDP", "Datagram Delivery Protocol", "[WXC]");
	case 38: return get_new_protocol("IDPR-CMTP", "IDPR Control Message Transport Proto", " [MXS1]");
	case 39: return get_new_protocol("TP++", "TP++ Transport Protocol", "[DXF]");
	case 40: return get_new_protocol("IL", "IL Transport Protocol", "[Presotto]");
	case 41: return get_new_protocol("IPv6", "Ipv6", "[Deering]  ");
	case 42: return get_new_protocol("SDRP", "Source Demand Routing Protocol", "[DXE1]");
	case 43: return get_new_protocol("IPv6-Route", "Routing Header for IPv6", "[Deering]");
	case 44: return get_new_protocol("IPv6-Frag", "Fragment Header for IPv6", "[Deering]");
	case 45: return get_new_protocol("IDRP", "Inter-Domain Routing Protocol", "[Sue Hares]");
	case 46: return get_new_protocol("RSVP", "Reservation Protocol", "[Bob Braden]");
	case 47: return get_new_protocol("GRE", "General Routing Encapsulation", "[Tony Li]");
	case 48: return get_new_protocol("MHRP", "Mobile Host Routing Protocol", "[David Johnson]");
	case 49: return get_new_protocol("BNA", "BNA", "[Gary Salamon]");
	case 50: return get_new_protocol("ESP", "Encap Security Payload", "[RFC2406]");
	case 51: return get_new_protocol("AH", "Authentication Header", "[RFC2402]");
	case 52: return get_new_protocol("I-NLSP", "Integrated Net Layer Security TUBA", "[GLENN]");
	case 53: return get_new_protocol("SWIPE", "IP with Encryption", "[JI6]");
	case 54: return get_new_protocol("NARP", "NBMA Address Resolution Protocol", "[RFC1735]");
	case 55: return get_new_protocol("MOBILE", "IP Mobility", "[Perkins]");
	case 56: return get_new_protocol("TLSP", "Transport Layer Security Protocol", "[Oberg]");
	case 57: return get_new_protocol("SKIP", "SKIP", "[Markson]");
	case 58: return get_new_protocol("IPv6-ICMP", "ICMP for IPv6", "[RFC1883]");
	case 59: return get_new_protocol("IPv6-NoNxt", "No Next Header for IPv6", "[RFC1883]");
	case 60: return get_new_protocol("IPv6-Opts", "Destination Options for IPv6", "[RFC1883]");
	case 61: return get_new_protocol("any host internal protocol", "any host internal protocol", "[IANA]");
	case 62: return get_new_protocol("CFTP", "CFTP", "[CFTP,HCF2]");
	case 63: return get_new_protocol("any local network", "any local network", "[IANA]");
	case 64: return get_new_protocol("SAT-EXPAK", "SATNET and Backroom EXPAK", "[SHB]");
	case 65: return get_new_protocol("KRYPTOLAN", "Kryptolan", "[PXL1]");
	case 66: return get_new_protocol("RVD", "MIT Remote Virtual Disk Protocol", "[MBG]");
	case 67: return get_new_protocol("IPPC", "Internet Pluribus Packet Core", "[SHB]");
	case 68: return get_new_protocol("any distributed file system", "any distributed file system", "[IANA]");
	case 69: return get_new_protocol("SAT-MON", "SATNET Monitoring", "[SHB]");
	case 70: return get_new_protocol("VISA", "VISA Protocol", "[GXT1]");
	case 71: return get_new_protocol("IPCV", "Internet Packet Core Utility", "[SHB]");
	case 72: return get_new_protocol("CPNX", "Computer Protocol Network Executive", "[DXM2]");
	case 73: return get_new_protocol("CPHB", "Computer Protocol Heart Beat", "[DXM2]");
	case 74: return get_new_protocol("WSN", "Wang Span Network", "[VXD]");
	case 75: return get_new_protocol("PVP", "Packet Video Protocol", "[SC3]");
	case 76: return get_new_protocol("BR-SAT-MON", "Backroom SATNET Monitoring", "[SHB]");
	case 77: return get_new_protocol("SUN-ND", "SUN ND PROTOCOL-Temporary", "[WM3]");
	case 78: return get_new_protocol("WB-MON", "WIDEBAND Monitoring", "[SHB]");
	case 79: return get_new_protocol("WB-EXPAK", "WIDEBAND EXPAK", "[SHB]");
	case 80: return get_new_protocol("ISO-IP", "ISO Internet Protocol", "[MTR]");
	case 81: return get_new_protocol("VMTP", "VMTP", "[DRC3]");
	case 82: return get_new_protocol("SECURE-VMTP", "SECURE-VMTP", "[DRC3]");
	case 83: return get_new_protocol("VINES", "VINES", "[BXH]");
	case 84: return get_new_protocol("TTP", "TTP", "[JXS]");
	case 85: return get_new_protocol("NSFNET-IGP", "NSFNET-IGP", "[HWB]");
	case 86: return get_new_protocol("DGP", "Dissimilar Gateway Protocol", "[DGP,ML109]");
	case 87: return get_new_protocol("TCF", "TCF", "[GAL5]");
	case 88: return get_new_protocol("EIGRP", "EIGRP", "[CISCO,GXS]");
	case 89: return get_new_protocol("OSPF", "OSPFIGP", "[RFC1583,JTM4]");
	case 90: return get_new_protocol("Sprite-RPC", "Sprite RPC Protocol", "[SPRITE,BXW]");
	case 91: return get_new_protocol("LARP", "Locus Address Resolution Protocol", "[BXH]");
	case 92: return get_new_protocol("MTP", "Multicast Transport Protocol", "[SXA]");
	case 93: return get_new_protocol("AX.25", "AX.25 Frames", "[BK29]       ");
	case 94: return get_new_protocol("IPIP", "IP-within-IP Encapsulation Protocol", "[JI6]");
	case 95: return get_new_protocol("MICP", "Mobile Internetworking Control Pro.", "[JI6]");
	case 96: return get_new_protocol("SCC-SP", "Semaphore Communications Sec. Pro.", "[HXH]   ");
	case 97: return get_new_protocol("ETHERIP", "Ethernet-within-IP Encapsulation", "[RFC3378]");
	case 98: return get_new_protocol("ENCAP", "Encapsulation Header", "[RFC1241,RXB3]");
	case 99: return get_new_protocol("any private encryption scheme", "any private encryption scheme", "[IANA]");
	case 100: return get_new_protocol("GMTP", "GMTP", "[RXB5]");
	case 101: return get_new_protocol("IFMP", "Ipsilon Flow Management Protocol", "[Hinden]");
	case 102: return get_new_protocol("PNNI", "PNNI over IP", "[Callon]");
	case 103: return get_new_protocol("PIM", "Protocol Independent Multicast ", "[Farinacci]");
	case 104: return get_new_protocol("ARIS", "ARIS", "[Feldman]");
	case 105: return get_new_protocol("SCPS", "SCPS", "[Durst]");
	case 106: return get_new_protocol("QNX", "QNX", "[Hunter]");
	case 107: return get_new_protocol("A/N", "Active Networks", "[Braden]");
	case 108: return get_new_protocol("IPComp", "IP Payload Compression Protocol", "[RFC2393]");
	case 109: return get_new_protocol("SNP", "Sitara Networks Protocol", "[Sridhar]");
	case 110: return get_new_protocol("Compaq-Peer", "Compaq Peer Protocol", "[Volpe]");
	case 111: return get_new_protocol("IPX-in-IP", "IPX in IP", "[Lee]");
	case 112: return get_new_protocol("VRRP", "Virtual Router Redundancy Protocol ", "[RFC3768]");
	case 113: return get_new_protocol("PGM", "PGM Reliable Transport Protocol", "[Speakman]");
	case 114: return get_new_protocol("any 0-hop protocol", "any 0-hop protocol", "[IANA]");
	case 115: return get_new_protocol("L2TP", "Layer Two Tunneling Protocol", "[Aboba]");
	case 116: return get_new_protocol("DDX", "D-II Data Exchange (DDX)", "[Worley]");
	case 117: return get_new_protocol("IATP", "Interactive Agent Transfer Protocol", "[Murphy]");
	case 118: return get_new_protocol("STP", "Schedule Transfer Protocol", "[JMP]");
	case 119: return get_new_protocol("SRP", "SpectraLink Radio Protocol", "[Hamilton]");
	case 120: return get_new_protocol("UTI", "UTI", "[Lothberg]");
	case 121: return get_new_protocol("SMP", "Simple Message Protocol", "[Ekblad]");
	case 122: return get_new_protocol("SM", "SM", "[Crowcroft]");
	case 123: return get_new_protocol("PTP", "Performance Transparency Protocol", "[Welzl]");
	case 124: return get_new_protocol("ISIS over IPv4", "ISIS over IPv4", "[Przygienda]");
	case 125: return get_new_protocol("FIRE", "FIRE", "[Partridge]");
	case 126: return get_new_protocol("CRTP", "Combat Radio Transport Protocol", "[Sautter]");
	case 127: return get_new_protocol("CRUDP", "Combat Radio User Datagram", "[Sautter]");
	case 128: return get_new_protocol("SSCOPMCE", "SSCOPMCE", "[Waber]");
	case 129: return get_new_protocol("IPLT", "IPLT", "[Hollbach]");
	case 130: return get_new_protocol("SPS", "Secure Packet Shield", "[McIntosh]");
	case 131: return get_new_protocol("PIPE", "Private IP Encapsulation within IP", "[Petri]");
	case 132: return get_new_protocol("SCTP", "Stream Control Transmission Protocol", "[Stewart]");
	case 133: return get_new_protocol("FC", "Fibre Channel", "[Rajagopal]");
	case 134: return get_new_protocol("RSVP-E2E-IGNORE", "RSVP-E2E-IGNORE", "[RFC3175]");
	case 135: return get_new_protocol("Mobility Header", "Mobility Header", "[RFC3775]");
	case 136: return get_new_protocol("UDPLite", "UDPLite", "[RFC3828]");
	case 137: return get_new_protocol("MPLS-in-IP", "MPLS-in-IP", "[RFC4023]");
	case 138: return get_new_protocol("Unassigned", "Unassigned", "[IANA]");
	case 139: return get_new_protocol("Use for experimentation and testing", "Use for experimentation and testing", "[RFC3692]");
	case 140: return get_new_protocol("Reserved", "Reserved", "[IANA]");
	case 141: return get_new_protocol("IPv4", "Internet Protocol", "[RFC791]", (Protocol*)(new Protocol_IPV4(_uBytes, _iLength)));
	case 142: return get_new_protocol("ARP", "Address Resolution Protocol", "[RFC 826]", (Protocol*)(new Protocol_ARP(_uBytes, _iLength)));
	case 143: return get_new_protocol("RARP", "Reverse Address Resolution Protocol", "[RFC903]", (Protocol*)(new Protocol_RARP(_uBytes, _iLength)));
	default: return get_new_protocol("UNKNOWN PROTOCOL", "UNKNOWN PROTOCOL", "NULL");
	}
}
