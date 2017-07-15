// main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Portocols.cpp"
#include "Portocol_ICMP.cpp"
#include "Portocol_TCP.cpp"
#include "Portocol_UDP.cpp"
#include "Portocol_IPV4.cpp"
#include "Protocol_EthernetII.cpp"
#include "Protocol_ARP.cpp"
#include "Protocol_RARP.cpp"
using namespace std;


class Packet {
	int count = 0;
public:
	void new_packet(const u_char* packet, const int len) {
		cout << "[" << count + 1 << "]";
		Protocol_EthernetII EthernetII(packet, len);
		count++;
	}
};


#define LINE_LEN 16


int main(int argc, char **argv)
{
	pcap_if_t *alldevs, *d;
	pcap_t *fp;
	u_int inum, i = 0;
	char errbuf[PCAP_ERRBUF_SIZE];
	int res;
	struct pcap_pkthdr *header;
	const u_char *pkt_data;


	printf("\nNo adapter selected: printing the device list:\n");
	/* The user didn't provide a packet source: Retrieve the local device list */
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", errbuf);
		return -1;
	}

	/* Print the list */
	for (d = alldevs; d; d = d->next)
	{
		printf("%d. %s\n    ", ++i, d->name);

		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	if (i == 0)
	{
		fprintf(stderr, "No interfaces found! Exiting.\n");
		return -1;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);
	
	if (inum < 1 || inum > i)
	{
		printf("\nInterface number out of range.\n");

		/* Free the device list */
		pcap_freealldevs(alldevs);
		return -1;
	}

	/* Jump to the selected adapter */
	for (d = alldevs, i = 0; i< inum - 1; d = d->next, i++);

	/* Open the device */
	if ((fp = pcap_open(d->name,
		100 /*snaplen*/,
		PCAP_OPENFLAG_PROMISCUOUS /*flags*/,
		20 /*read timeout*/,
		NULL /* remote authentication */,
		errbuf)
		) == NULL)
	{
		fprintf(stderr, "\nError opening adapter\n");
		return -1;
	}

	Packet packet;
	while ((res = pcap_next_ex(fp, &header, &pkt_data)) >= 0)// Read the packets
	{
		if (res == 0)
			continue;// Timeout elapsed 
		packet.new_packet(pkt_data, header->caplen);

	}

	if (res == -1)
	{
		fprintf(stderr, "Error reading the packets: %s\n", pcap_geterr(fp));
		return -1;
	}

	return 0;
}
