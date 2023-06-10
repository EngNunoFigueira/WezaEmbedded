
#!/bin/bash

#***********************************************************************************************************#
# Author: Nuno Figueira                                                                                     #
# Date:   17-02-2022                                                                                        #
# Company: Nundel Technologies                                                                              #
#                                                                                                           #
# Project: mPainel version 1.0.8                                                                            #
# Description: The purpose of this script is for testing the systemd service manager "in" UBUNTU 18.04      #
# Script Description: log the dateTime when the User login on the system and save the info in a report file.#
#                                                                                                           #
#***********************************************************************************************************#

workDirector=/media/nundelTech/Scripts/
loginFile="logFile.txt"

getUserName=$(echo `who` | cut -d ' ' -f 1)
cd $workDirector

if [ ! -f $loginFile ] 
   then
	{
       touch $loginFile
	}
   else
	{
		echo "File exist..."
	}
fi

echo "User:" $getUserName "login DateTime:" `date` >> $loginFile

#while true
#do
	sleep 2m
#done

exit 0
