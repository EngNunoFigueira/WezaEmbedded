
#!/bin/bash

#**************************************************************************************************************#
# Author: Nuno Figueira                                                                                        #
# Date:   30-03-2022                                                                                           #
# Company: Netadvia                                                                                            #
#                                                                                                              #
# Project: IT Job Challenge Code                                                                               #
#                                                                                                              #
# COMMENT:                                                                                                     #
# Using the UNIX tools/programs, such as the TCPDUMP, we can develop great and robust software solution.       #
# For example, we developed a version of the Parser Network Packtes, wrote in ANSI C, in Bash Script too.      #
# Just using the tpcdump, combined with other UNIX commands (like the sed and pipes to filter the information  #
# we need to parse).                                                                                           #
#                                                                                                              #
# Script Description:                                                                                          #
# The Parser Network Packet receive a pcap file and extract the followings fields listed below.                #
# This script can be updated in order to parse other fields, for ex. the timestamp or the type of protocol.    #
# source and destination MAC-ADDRESS.                                                                          #
# source and destination IP-ADDRESS.                                                                           #
#                                                                                                              #
#**************************************************************************************************************#

output_file=$(echo $1 | sed 's/.pcap/_/')

if [ $# -eq 0 ]
   then 
   {
     echo "Oh oh oh !!!"
     echo "You need insert a pcap file to parsing the network traffic data"
     exit 1
   }
   else if [ $# -eq 1 ]; then  
   {
     getInfo=$(echo `tcpdump -nn -e -r $1  | cut -d " " -f 2,4,10,12 |  sed 's/[,:]//g'`)
     echo "src_mac       dst_mac      src_ip     dst_ip " > $output_file$(date +%d%m%Y-%H:%M).cvs
     echo $getInfo >> $output_file$(date +%d%m%Y-%H:%M).cvs
     echo "operation finish with successfully"
   }
   fi
fi

exit 0