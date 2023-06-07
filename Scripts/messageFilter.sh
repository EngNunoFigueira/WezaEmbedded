#!/bin/bash

########################################################################
#  Author: Nuno Figueira                                               #
#  Project:SAPC 1.7                                                    #
#  Date:2019/06/03                                                     #
#                                                                      #
#  Description:                                                        #
#  this script filter duplicate lines of a file and create a new file  #
#  as output.                                                          #
#                                                                      #
#  Parameters:                                                         #
#  file to be rotate                                                   #
#  Execut:                                                             # 
#  ./script name                                                       #
########################################################################

#echo "Hello World"
#awk '!a[$0]++' testFile.txt > newFile
# mv newFile OldFile
# starting rotate


#!/bin/bash

##
## logrotate - Script triggered by rsyslogd when it is time to rotate logs.
##

update_rsyslog()
{
  log "Syslog is being updated with new COM values: maxLogFileSize=${1} maxFilesRotated=${2}"

  maxLogFileSize_in=$1
  maxFilesRotated_in=$2

  sed -i '/outchannel logRot_sapcapp/d' /etc/rsyslog.d/001_SC_sapcLogs.conf 
  sed -i "/#Template for datetime/i\$outchannel logRot_sapcapp,/cluster/storage/no-backup/coremw/var/log/syslog/sapc/sapc.log, $maxLogFileSize_in,/usr/lib/lde/syslog.lde.logrotate /cluster/storage/no-backup/coremw/var/log/syslog/sapc/ sapc $maxFilesRotated_in .log $maxLogFileSize_in" /etc/rsyslog.d/001_SC_sapcLogs.conf
  
  sed -i '/outchannel logRot_sapcec/d' /etc/rsyslog.d/001_SC_sapcLogs.conf 
  sed -i "/#Template for datetime/i\$outchannel logRot_sapcec,/cluster/storage/no-backup/coremw/var/log/syslog/sapc/emergencyCalls.log, $maxLogFileSize_in,/usr/lib/lde/syslog.lde.logrotate /cluster/storage/no-backup/coremw/var/log/syslog/sapc/ emergencyCalls $maxFilesRotated_in .log $maxLogFileSize_in" /etc/rsyslog.d/001_SC_sapcLogs.conf

  sed -i '/outchannel logRot_sapcrest/d' /etc/rsyslog.d/001_SC_sapcLogs.conf 
  sed -i "/#Template for datetime/i\$outchannel logRot_sapcrest,/cluster/storage/no-backup/coremw/var/log/syslog/sapc/rest.log, $maxLogFileSize_in,/usr/lib/lde/syslog.lde.logrotate /cluster/storage/no-backup/coremw/var/log/syslog/sapc/ rest $maxFilesRotated_in .log $maxLogFileSize_in" /etc/rsyslog.d/001_SC_sapcLogs.conf

}

restart_rsyslog()
{
  log "Syslog is being restarted"
  kill -9 `pidof rsyslogd`
}

rotate_files()
{
  #before rotatet filter duplicate logs:	
  filter_duplicates_log_messages

  last_file_rotated=`ls -art ${log_path}/${log_set}_* | tail -1`

  if [[ "$deleteFiles" == "yes" ]]; then
    numwastefiles=$(( number_files_rotated - instances + 1 ))
  else
    numwastefiles=0
  fi
 
  if [[ $numwastefiles -gt 0 ]]; then
    wastefiles=`ls -art ${log_path}/${log_set}_* | head -$numwastefiles`
    rm -f ${wastefiles}
  fi
  
  previous_rotated_log=`echo $last_file_rotated | rev |  cut -d "_" -f-1,-2 | rev | cut -d "." -f1`
  if [ ! -z "$previous_rotated_log" ]; then
    previous_rotated_log="_${previous_rotated_log}"
  fi
  current_date_time=`date '+_%Y%m%d_%H%M%S'`
  for (( i=0; i<$((instances-1)); i++ ))
    do
     if [[ $i -eq 0 ]]; then
      if [ ! -f ${log_path}/${log_set}${previous_rotated_log}${current_date_time}${log_extension} ]; then
        mv ${log_path}/${log_set}${log_extension} ${log_path}/${log_set}${previous_rotated_log}${current_date_time}${log_extension}
        break
      fi
     else
      if [ ! -f ${log_path}/${log_set}${previous_rotated_log}${current_date_time}${log_extension}.$i ]; then
        mv ${log_path}/${log_set}${log_extension} ${log_path}/${log_set}${previous_rotated_log}${current_date_time}${log_extension}.$i
        break
      fi
     fi
    done
  if [[ $instances -eq 0 ]]; then
    rm -f ${log_path}/${log_set}${log_extension}
  fi
}

update_rsyslog_config_in_backup_system_controller()
{
  h=`hostname`
  get_backup_hostname=(`cat /etc/cluster/nodes/control/*/hostname|grep -v $h`)
  
  log "Updating ${get_backup_hostname} with new COM values"
  
  if [ "$restart_first_rotation" == "yes" ]; then
     log "Executing against ${get_backup_hostname} kill -9 \`pidof rsyslogd\`;/usr/lib/lde/syslog.lde.logrotate \"$1\" notrotate"
     #Why is there a restart before the modification? Shouldn't be after the modification via notrotate ?
     ssh $get_backup_hostname "kill -9 \`pidof rsyslogd\`; /usr/lib/lde/syslog.lde.logrotate \"$1\" notrotate" 
  else
     log "Executing against ${get_backup_hostname} /usr/lib/lde/syslog.lde.logrotate \"$1\" notrotate"
     ssh $get_backup_hostname "/usr/lib/lde/syslog.lde.logrotate \"$1\" notrotate"
  fi
}

filter_duplicates_log_messages()
{
	touch ${log_path}tmpSapc.log.filtered
    awk '!a[$0]++' ${log_path}${log_set}${log_extension} > ${log_path}/tmpSapc.log.filtered
    mv ${log_path}tmpSapc.log.filtered ${log_path}${log_set}${log_extension}
}

log() {
  logger "[SAPC_APP_REST_LOGS] $@"
}

args=($1)
node=${args[0]}
log_set=${args[1]}
instances=${args[2]}
log_extension=${args[3]}
file_size=${args[4]}
log_path=${node}

log " Rotating sapc_app logs with following arguments:"
log "     $@"

if [ "$log_set" == "rest" ]; then
   immElement="restEventsId"
else
   immElement="businessEventsId"
fi

immMaxLogFileSize=`immlist $immElement=1 -a maxLogFileSize|cut -d= -f2`
immMaxFilesRotated=`immlist $immElement=1 -a maxFilesRotated|cut -d= -f2`
if [ "$immMaxLogFileSize" == "" ]; then
  immMaxLogFileSize=$file_size
fi

restart_first_rotation="no"
number_files_rotated=`ls ${log_path}/${log_set}_* | wc -l`
if [[ $instances -gt 1 ]] && [[ $number_files_rotated -eq 0 ]]; then
    restart_first_rotation="yes"
fi

deleteFiles=yes
if [ "$immMaxFilesRotated" == "" ]; then
  immMaxFilesRotated=$instances
  deleteFiles=no
fi

somethingChanged=""
if [ "$immMaxLogFileSize" != "$file_size" ] || [ "$immMaxFilesRotated" != "$instances" ]; then
  instances=$immMaxFilesRotated
  update_rsyslog $immMaxLogFileSize $immMaxFilesRotated $immElement
  somethingChanged=yes
fi

if [[ $immMaxLogFileSize -le $file_size && $# -eq 1 ]]; then
  rotate_files
fi

if [ "$somethingChanged" == "yes" ] || [ "$restart_first_rotation" == "yes" ]; then
  restart_rsyslog
  if [[ $# -eq 1 ]]; then
     log "Updating backup system controller"
     update_rsyslog_config_in_backup_system_controller "${args[0]} ${args[1]} ${args[2]} ${args[3]} ${args[4]}"
  fi

fi


# [0]= /cluster/storage/no-backup/coremw/var/log/syslog/sapc/ : corresponde ao log_path
# [1]= sapc                                                   : corresponde ao log_set
# [2]= 99 
# [3]=.log                                                     : corresponde ao log_extension                                                      
# [4]= 20971520


while IFS= read -r line
do
	  grep $line -c $file
done < file.input	

#while IFS= read -r line; do echo $line; done < testFile.txt