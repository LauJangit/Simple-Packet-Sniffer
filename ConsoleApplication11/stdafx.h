// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#include "targetver.h"

#include <tchar.h>
#include<iostream>
#include <stdlib.h>
#include <cstdio>

#include<bitset>
#include<algorithm>

#define HAVE_REMOTE
#include <Include\pcap.h>
#include <Include\remote-ext.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

using namespace std;

#include "Portocols.hpp"
#include "Portocol_ICMP.hpp"
#include "Portocol_TCP.hpp"
#include "Portocol_UDP.hpp"
#include "Portocol_IPV4.hpp"
#include "Protocol_EthernetII.hpp"
#include "Protocol_ARP.hpp"
#include "Protocol_RARP.hpp"