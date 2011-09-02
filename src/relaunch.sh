#!/bin/bash

 #
 # Copyright (C) 2011 Andrew Smith 2011 <Andrew@GNAServicesInc.com>
 # Copyright (C) 2011 GNA SERVICES INC.
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation; either version 2 of the License, or
 # (at your option) any later version.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program. If not, see <http://www.gnu.org/licenses/>.

function error_log {
	case $1 in 
	
	1) 
		echo $(date +%c) " gwall-relaunch: INFO: gwall stopped runnning and had been restarted" >> /var/log/gwall.log  
		echo $(date +%c) "gwall-relaunch: INFO: gwall stopped runnning and had been restarted"
	  ;; 
 	2) 
		echo $(date +%c) "gwall-relaunch: WARNING: gwall stopped runnning. Attempting to relaunch gwall" >> /var/log/gwall.log  
		echo $(date +%c) "gwall-relaunch: WARNING: gwall stopped runnning. Attempting to relaunch gwall"
	  ;; 
	3) 
		echo $(date +%c) " gwall-relaunch: ALERT: gwall stopped runnning and was unable to be restarted. Attemping to reboot the system" >> /var/log/gwall.log  
		echo $(date +%c) " gwall-relaunch: ALERT: gwall stopped runnning and was unable to be restarted. Attemping to reboot the system"
		;;
	4) 
		echo $(date +%c) " gwall-relaunch: EMERGENCY: SYSTEM MAY BE IN UNSTABLE STATE gwall stopped runnning and I was unable to relaunch it. I tried rebooting the system but fail. I am now giving up. EMEGERNCY: SYSTEM MAY BE IN UNSTABLE STATE" >> /var/log/gwall.log  
		echo $(date +%c) " gwall-relaunch: EMERGENCY: SYSTEM MAY BE IN UNSTABLE STATE gwall stopped runnning and I was unable to relaunch it. I tried rebooting the system but fail. I am now giving up. EMEGERNCY: SYSTEM MAY BE IN UNSTABLE STATE"
	/sbin/gna-emergency-response
		;;
	*)
	echo $(date +%c) " gwall-relaunch: DEBUG: Error detected in relaunch.sh"  >> /var/log/gwall.log 
	echo $(date +%c) " gwall-relaunch: DEBUG: Error detected in relaunch.sh"  
		;;
	esac
}

function take_action {

		case $1 in
        
        1) 
        	error_log 2
        	(/sbin/restart gnasnort) &
        	;;
        2) 
        	error_log 2
        	/etc/init.d/gnasnort stop
            (/etc/init.d/gnasnort start) &
       		;;
        3)
      	   error_log 2 
        	(/usr/bin/gwall) &
        	;;
        4)
           error_log 2
            /sbin/reboot
        	;;
        5)
       		error_log 3
        	/sbin/reboot --force
        	;;
        6)
        	error_log 3
        	/sbin/shutdown -r now
        done
        ;;
        *)
          error_log 3
          /sbin/shutdown -r now
          ;;
        esac
	}
	
function launch_control {

start=0
emer=0

 while [ z $(/bin/pidof gwall) ]
        do
	     start+=1
		if [ $nosnort -eq 7 ]
		  then 
			error_log 4
			emer=1
			break
		fi
		
        sleep 60
        take_action $start
        done
        
     if [ $emer -eq 1 ]
	 then 
         	exit 1
	fi
	
	 if [ $emer -eq 0 ]
	 then
         	error_log 0
	fi
 }
 
 function check {
 if [ -z "$(pgrep gwall)" ]
  then
  	launch_control
  fi
  }
  
check
return 0 There is no reference pot file in this directory.
Make sure you are running status.pl in a po directory.
...... Aborting.
