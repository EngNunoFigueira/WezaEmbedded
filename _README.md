VERSION 1.0.0

#Usage
This software is a program developed for Parser Network Packets with saved in file with pcap extension or in offline mode.

#Motivation
The motivation for developing this program is to show my interest in this job vacancy and my skills to learn new technologies/libraries or framework in order to develop something useful.
For example, one of the requeriment of this job challenge, was to write the solution in ANSI C. So, even that during the last six years I am not working with C language, it was really fantastic switch to C language again.

#Editor
visual studio code version 1.65.2

#Solution Overview
The solution was implemented in Linux Ubuntu 18.04 LTS, the principal library used to interact with network protocol specification was the libpcap.h
We consider this solution a cross-platform, any person that have interest on it can compile and run the program in UNIX, MAC or WINDOWS.
just must be sure that the host environment has installed or support the libpcap and has the GCC compiler.

#Program Output
The parser network packets, as the name suggest, will extract the following informations from a pcap file:
a)Source MAC ADDRESS.
b)Destination MAC ADDRESS.
c)Source IP ADDRESS.
d)Destination IP ADDRESS.

#Compile Line
As the libpcap is basically a critical library, because it will interact with sensetive areas of the system, we must have root privileges.
$ sudo gcc parser_network_packet.h -o main -lpcap or $ sudo gcc parser_network_packet.h -lpcap

#Execution Line
The type of information or result we expect to analyze, after parse the network packets, must be speficied on execution command line.
Example of execution command line: $ ./main file.pcap 

Note# In case of the first parameter is not a valid pcap file path the program will terminate with error message.

