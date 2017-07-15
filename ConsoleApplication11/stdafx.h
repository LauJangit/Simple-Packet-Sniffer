// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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

// TODO:  在此处引用程序需要的其他头文件

using namespace std;

#include "Portocols.hpp"
#include "Portocol_ICMP.hpp"
#include "Portocol_TCP.hpp"
#include "Portocol_UDP.hpp"
#include "Portocol_IPV4.hpp"
#include "Protocol_EthernetII.hpp"
#include "Protocol_ARP.hpp"
#include "Protocol_RARP.hpp"