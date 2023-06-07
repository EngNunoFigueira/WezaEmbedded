import os, sys
from argparse import ArgumentParser, RawTextHelpFormatter
import textwrap
#from connection import HostConnection
#from timeout import Timeout
#import msg_in_file
#import time

controlProcessDict ={
         "pcrf-proc" : "sapcPcrfProc",
         "TimeTriggerEventNotifierProc" : "sapcTTNotifier",
         "rest-server" : "sapcRestServer",
         "notification" : "sapcEndUserNotifier",
         "license-monitor" : "sapcLicenseMonitor",
         "soap-notification-service" : "sapcSoapNotificationService",
         "external-db" : "sapcExtDb",
         "sapc-obsolete-sessions-notifier" : "sapcObsoleteSessionsNotifier",
         "sapc-mobility-policy" : "sapcMobilityPolicy",
         "sapc-app-detection" : "sapcAppDetection",
         "subs-charging-proc" : "sapcSubsChargingProc",
         "geored-control" : "sapcGeoredControl",
         "sapc-data-storage-server" : "sapcDataStorageServer",
         "sapc-ebm-dispatcher" : "sapcEbmDispatcher",
         "sapc-uetrace-relay"  : "sapcUeTraceRelay",
         "sapc-rest-mobility-policy" : "sapcRestMobilityPolicy",
         "session-policy-control" : "sapcSessionPolicyControl"
}

confingFileProcessDict ={
         "pcrf-proc" : "pcrf-proc.cfg",
         "TimeTriggerEventNotifierProc" : "timetriggereventnotifierproc.cfg",
         "rest-server" : "rest-server.cfg",
         "notification" : "java.cfg",
         "license-monitor" : "license-monitor.cfg",
         "soap-notification-service" : "soap-notification-service.cfg",
         "external-db" : "extDBProc.cfg",
         "sapc-obsolete-sessions-notifier" : "sapc-obsolete-sessions-notifier.cfg",
         "sapc-mobility-policy" : "sapc-mobility-policy.cfg",
         "sapc-app-detection" : "sapc-app-detection.cfg",
         "subs-charging-proc" : "subs-charging-proc.cfg",
         "geored-control" : "geored-control.cfg",
         "sapc-data-storage-server" : "sapc-data-storage-server.cfg",
         "sapc-ebm-dispatcher" : "sapc-ebm-dispatcher.cfg",
         "trace" : "/home/trace/subbuffer.conf",
         "pdc" : "pdc.cfg",
         "pds" : "sapc-pds.cfg",
         "sapc-uetrace-relay" : "sapc-uetrace-relay.cfg",
         "sapc-rest-mobility-policy" : "sapc-rest-mobility-policy.cfg",
         "session-policy-control" : "session-policy-control.cfg"
}

process ="pcrf-proc"
print("Testing if in python programming language")
if process in controlProcessDict:
   print "The key was found"
   restart_command="sapcReloadConfig -f {0}".format(confingFileProcessDict[process])
   print ("this is the output of restart_command: ")
   print restart_command   
else:
     print("The key was not found")
