/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2011 - GNA SERVICES INC.
 * Copyright (C) 2011 - Andrew Smith 2011 <Andrew@GNAServicesInc.com>
 *
 * gWall is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gWall is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include "rucmmd.h"
#include "fwatch.h"
#include "gstartup.h"
#include "error_msg.h"
#include "cmmd.h"
#include <syslog.h>
void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);
void closelog(void);
#include <stdarg.h>
void vsyslog(int priority, const char *format, va_list ap);
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int fork_count = 0, exit_flag = 0, err = 0;
	pid_t cpid, w;
    int status;
	cpid = fork();
    if (cpid == -1)
	{
     perror("fork");
     exit(EXIT_FAILURE);
     }
    if (cpid == 0)
	{  
	fork_count = gstartup(fork_count);
	err = fwatch(fork_count, exit_flag);
		
	if (argc == 1)
	
                   pause();                  
               _exit(atoi(argv[1]));
			
    } 

		else {                    
          do {
				   w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
                   if (w == -1) 
					{
                       perror("waitpid");
                       exit(EXIT_FAILURE);
					}	
                        if (WIFEXITED(status))
						{
               			return 0;
               			} 
					   
					else if (WIFSIGNALED(status)) 
					   {
                      cmmd("/usr/bin/gwall",1);
             		  } 
					else if (WIFSTOPPED(status)) 
					   {
                      cmmd("/usr/bin --CONT $(pidof gwall)", 1);
                       } 

				   else if (WIFCONTINUED(status)) 
					   {
                       printf("continued\n");
                        }
               } 
				   while (!WIFEXITED(status) && !WIFSIGNALED(status));
               exit(EXIT_SUCCESS);
           }
		   }