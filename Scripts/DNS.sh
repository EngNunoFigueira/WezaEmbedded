#!/bin/bash

#--------------------------------------------------------------------------#
# Author: Nuno Figueira                                                    #
# Company: Nundel Tech                                                     #
# Year: 28/NOV/2019                                                        #
#                                                                          #
# SCRIPT DESCRIPTION:                                                      #
# This script configur a local DNS server over a hostPC with dynamic       #
# IP address atribute. The purpose is launch the DNS server on the boot    #
# time reconfigure the bind files for the specific IP...                   #
#                                                                          #
# SCRIPT paramters: none                                                   #
#                                                                          #
#--------------------------------------------------------------------------#

bindDir="/etc/bind/"
cd $bindDir
cp db.dns.nundel.pt.backup db.dns.nundel.pt
cp db.dns.nundel.pt.rev.backup db.dns.nundel.pt.rev
cp named.conf.options.backup named.conf.options
cp named.conf.local.backup named.conf.local

cp /media/nundelTech/Scripts/resolv.conf.back /etc/resolv.conf


null=" "
newIpAddressIs=(`hostname -I`)
echo this is the new Ip address: $newIpAddressIs
newReverseZone=(`hostname -I | cut -d "." -f 3`)
echo this is the new reverse zone: $newReverseZone
newLastOctectOfIpAddressIs=(`hostname -I | cut -d "." -f 4`)
echo this is the their last Octect : $newLastOctectOfIpAddressIs
#oldReverseZone=(`grep "in-addr.arpa" /etc/bind/named.conf.local | awk '{print $2}' | sed 's/\"//' | cut -d "." -f 1`)
oldIpAddressIs=(`grep transfer-source /etc/bind/named.conf.options | sed 's/transfer-source//g' | sed 's/ //g' | sed 's/;//g'`)
echo this is the old Ip address: $oldIpAddressIs
oldLastOctectOfIpAddressIs=(`echo $oldIpAddressIs | cut -d "." -f 4`)
echo this is their last Octect : $oldLastOctectOfIpAddressIs
oldZone=(`echo $oldIpAddressIs | cut -d "." -f 3`)
echo this is the old reverse Zone: $oldZone


if [[ "$newIpAddressIs" != "$null" ]] && [[ "$newIpAddressIs" != "$null" ]] && [[ "$newIpAddressIs" != "$oldIpAddressIs" ]]; then
{
   echo change the config files to getting up new IP address paramters
   sed -i  "s/$oldIpAddressIs/$newIpAddressIs/g" /etc/bind/db.dns.nundel.pt
   sed -i  "s/$oldIpAddressIs/$newIpAddressIs/g" /etc/bind/named.conf.options
   sed -i  "s/nameserver/nameserver $newIpAddressIs/" /etc/resolv.conf
   sed -i  "s/$oldLastOctectOfIpAddressIs/$newLastOctectOfIpAddressIs/g" /etc/bind/db.dns.nundel.pt.rev
   if [ "$oldZone" != "$newReverseZone" ]; then
   	{
   	   echo change the config zone to the new Ip address
   	   sed -i  "s/$oldZone/$newReverseZone/g" /etc/bind/named.conf.local
   	}
   	fi  
  
   service bind9 status
   service bind9 restart

   if [ "$?" == 0 ]; then
   	  {
   	  	echo "The Domain Name Server <DNS> was configured successul"
   	  	exit 0
   	  }
   	else
   	  {
   		  echo "The Domain Name Server <DNS> Configuration failed"
   		  exit -1
   	  }
   fi
}
else
{
	   #checkResolvConfigFile=(`grep $newIpAddressIs /etc/resolv.conf`)
	   #sed -i  "s/nameserver $oldIpAddressIs/nameserver $newIpAddressIs/" /etc/resolv.conf
	   #service bind9 status
       service bind9 restart
}
fi	
