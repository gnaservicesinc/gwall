// rucmmd.cxx
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

int rucmmd(const char *strCommand)
{
	int fork_id, status;
	fork_id = vfork();
	
	if (fork_id == 0)	
		{
		status = execl("/bin/sh","sh","-c", strCommand, (char*) NULL);
		exit(status);	 
		}
	else if (fork_id > 0)
		{
		status = 0;
		}
	else
		{
		status = -1;
		}
	return(status);
} 