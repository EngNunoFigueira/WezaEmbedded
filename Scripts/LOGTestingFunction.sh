#!/bin/bash


#--------------------------------------------------------------------------#
# Author: Nuno Figueira                                                    #
# Company: Ericsson                                                        #
# Team Name: GreenCode                                                     #
# Product Name: SAPC                                                       #
# Year: 2018/2019                                                          #
#                                                                          #
# SCRIPT DESCRIPTION:                                                      #
# This script is a small bash solution, that will be used to analize       #
# or investigate the CoreMW LOG <sw> or library, in an environment machine.#
#                                                                          #
# SCRIPT paramters:                                                        #
#                                                                          #
# $1 - number of LOG to write                                              #
# $2 - time interval between writes                                        #
# $3 - date "YYY-mm-dd " of LOGs saved.                                    #
#                                                                          #
#--------------------------------------------------------------------------#

FgetPLEndTime(var)
{
   PLnumber=$(`grep "PL-3" $files | cut -d "," -f2 | cut -c7-10`)

   getEndTime=$(`grep "EndTime" $files | cut -d ":" -f5 | cut -c-2`)

   if [ PLnmber=="PL-3" ]
      then
      return "PL-3"
   elif [ PLnmber=="PL-4" ]
      return "PL-4"
   fi
}


# MAIN:

# Create a file with your owne rules for Logrotate:
 touch myRotateFile && mv myRotateFile /etc/Logrotate.d/
 #content of my myRotateFile:
 /var/log/<fileToLog>/* {
    daily
    rotate 3
    size 10M
    compress
    delaycompress
    create 0600 root root
}

where:
#weekly : 
means that the tool will attempt to rotate the logs on a weekly basis. Other possible values are daily and monthly.
#rotate 3:
indicates that only 3 rotated logs should be kept. Thus, the oldest file will be removed on the fourth subsequent run.
#size=10M: 
sets the minimum size for the rotation to take place to 10M. In other words, each log will not be rotated until it reaches 10MB.
#compress and delaycompress:
 are used to tell that all rotated logs, with the exception of the most recent one, should be compressed.

 #RUNNING THE LOG ROTATE:
 Let’s execute a dry-run to see what logrotate would do if it was actually executed now. 
 Use the -d option followed by the configuration file (you can actually run logrotate by omitting this option):

 $ logrotate -d /etc/logrotate.d/apache2.conf

 #ROTATION DIRECTOR:
 create a folder to save all logs came from my Cpp programming.
 this director will be the rotat place.
 mkdir /var/log/nundelLog/<........files:> nundel.log


