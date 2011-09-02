// fwatch.cxx
//
// Copyright (C) 2011 - GNA SERVICES INC.
// Copyright (C) 2011 - Andrew J Smith
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

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
#include <iostream>
using namespace std;

int fwatch(int fork_count, int exit_flag)
{
	 int exit_count = 0, fork_exit_status = 0;
	
while (fork_count && !exit_flag)
	{
	exit_count = waitpid(-1, &fork_exit_status, WNOHANG);
	if (exit_count < 0)
		{
		exit_flag = 1;
		error_msg (exit_flag);
		}
		else if (exit_count > 0)
		{
		fork_count--;		
		}
		else  
		{
		sleep(3);	
		}
	} 
 return (exit_flag);
}