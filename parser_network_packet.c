/*------------------------------------------------------------------------------------------------------------------------------------------
Year: 2022/March
Autor: Nuno Figueira
Email: ekumbi48172@hotail.com
LinkedInd: https://www.linkedin.com/in/nuno-figueira-2aa2785b/
Project: IT job Code Challenge.

This code was developed in ANSIC , OS UBUNTU 14.04 LTS. Editor VISUAL STUDIO CODE. 
Command Line Complitation: gcc main.c -o main -lpcap
Debuguer Tools: UNIX DGB
Execution line: ./main file.pcap
---------------------------------------------------------------------------------------------------------------------------------------------*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/tcp.h>
#include <stdlib.h>

/*To read the pcap file we used the pcap_open_offline function, and receive as a parameter the file path : argv[1] */
pcap_t * read_pcap_file(const u_char *file)
{
  char *errbuffer;
  pcap_t *handle = pcap_open_offline (file, errbuffer);
  if( handle == NULL )
  {
   fprintf(stderr, "Fail opening the pcap file with error: %s\n", errbuffer);
   return NULL;
  }
  return handle;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 The function we used to parser the packet files is the pcap_loop( parameters.... )
 And this function, pcap_loop, receive a callback function as a argument, for process all network packets read. 
 NOTE: As the requeriment is create dedicated functions for parser each parameters individually, such as, sourcer-mac, source-ip, dst_mac or dst_ip.
 We impemented four callback functions listed below:

 But in case of a future release, we suggest:
 In case we need work with big files or in live mode, parsing millions of packets, that will arrived on the network interface every milisecond, maybe the best
 scenario is not create a callback function to parse each parameter separatly: source and destination Mac-Address and IP-Address, like we are doing now. 
 This operation is very slow and have very low performance for a parser programming.
 
 The point is, the function pcap_loop will read all packets, saved in the file, and after finish their job, the handler file descriptor will point to the last line of the pcap file...
 And we cannot parse other information, such as the IP, on this file after close the handler and reopen the file to refresh the handler pointer. So, this scenario was implemented on the function print
 pcap_parsed_file( const char *pcap_file_path ) to keep challenge requeriment.

Solution Proposal:
Parsing all parameters we want in a single callback function and use filters for optimization.
To printout the parser fields we must consider two scenarios:
1- If we know exactly the number of the packtes we need to parse it easy; we can allocate memory for a structure with this fields. Each time the data is ready.
But in case we don't know exactly the number of packets or working in livee mode for hours, using a memory allocation or a fix array size of this data structure can be very dangerous.
2- Maybe is more safe write the data structure in a file.csv
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void parse_mac_src( u_char *args, const struct pcap_pkthdr *header, const u_char *packet )
{  
  int index = ETHER_ADDR_LEN;
  u_char *ptr_mac_address;
  const struct ether_header* ethernetHeader;
  ethernetHeader = (struct ether_header*)packet;
  ptr_mac_address = (u_char *) ethernetHeader->ether_shost;
 printf("Source MAC Address : ");
    do{
        printf("%s%x",(index == ETHER_ADDR_LEN) ? " " : ":",*ptr_mac_address++);
    }while(--index>0);
  printf("\n");
}

void parse_mac_dst( u_char *args, const struct pcap_pkthdr *header, const u_char *packet )
{  
  int index = ETHER_ADDR_LEN;
  u_char *ptr_mac_address;
  const struct ether_header* ethernetHeader;
  ethernetHeader = (struct ether_header*)packet;
  ptr_mac_address = (u_char *) ethernetHeader->ether_dhost;
 printf("Destination MAC Address : ");
    do{
        printf("%s%x",(index == ETHER_ADDR_LEN) ? " " : ":",*ptr_mac_address++);
    }while(--index>0);
  printf("\n");
}

void parse_ip_src( u_char *args, const struct pcap_pkthdr *header, const u_char *packet )
{  
  const struct ip* ipHeader;
  char sourceIp[INET_ADDRSTRLEN];
  const struct ether_header* ethernetHeader;
  ethernetHeader = (struct ether_header*)packet;
  if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) 
  {
      ipHeader = (struct ip*)(packet + sizeof(struct ether_header));
      inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIp, INET_ADDRSTRLEN);
      printf("Source IP :%s \n", sourceIp);
  }
}
void parse_ip_dst( u_char *args, const struct pcap_pkthdr *header, const u_char *packet )
{  
  const struct ip* ipHeader;
  const struct tcphdr* tcpHeader;
  char destIp[INET_ADDRSTRLEN];
  const struct ether_header* ethernetHeader;
  ethernetHeader = (struct ether_header*)packet;
  if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) 
  {
      ipHeader = (struct ip*)(packet + sizeof(struct ether_header));
      inet_ntop(AF_INET, &(ipHeader->ip_dst), destIp, INET_ADDRSTRLEN);
      printf("Destination IP :%s\n",destIp);
  }
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 This function will Printout the source and destination data listed below, after Parser a Network Pcap File with one or more Packets.
 - MAC-ADDRESS 
 - IP-ADDRESS 
 
 comments:
 For now this function work very well, because we are parsing a small pcap files with only one packets... But in future release where the user need parsing big files
 this code must be reviewed.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  void print_pcap_parsed_file( const char *pcap_file_path )
  {
    int print_data_type = 1;
    do {
      unsigned int endfile = 1;
      pcap_t *handle = read_pcap_file(pcap_file_path);
      if(handle == NULL) {
         return;
      }
      switch (print_data_type)
      {
       case 1:
        do { endfile = pcap_loop(handle,0,parse_mac_src,0); } while( endfile==1 );
        break;
       case 2:
        do { endfile = pcap_loop(handle,0,parse_mac_dst,0); } while( endfile==1 );
        break;
       case 3:
        do { endfile = pcap_loop(handle,0,parse_ip_src,0); } while( endfile==1 );
        break;
       case 4:
        do { endfile = pcap_loop(handle,0,parse_ip_dst,0); } while( endfile==1 );
        break;
       default:
        break;
      }
      print_data_type++;
      pcap_close(handle);
    }while(print_data_type < 5);
 
  }

int main(int argc, char ** argv)
{
  fprintf(stderr,"Parsing File....  Data Output\n");
  const char *pcap_file_path = argv[1];
   print_pcap_parsed_file( pcap_file_path );

 return 0;
}