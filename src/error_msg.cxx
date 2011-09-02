// error_msg.cxx
//
// Copyright (C) 2011 - GNA SERVICES INC.
// Copyright (C) 2011 - Andrew Smith 2011 <Andrew@GNAServicesInc.com>
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
#include <syslog.h>
void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);
void closelog(void);
#include <stdarg.h>
void vsyslog(int priority, const char *format, va_list ap);
#include <iostream>
using namespace std;

int error_msg(int error_code)
{


	switch (error_code)
	{
		case 1:
			openlog ("gWall", LOG_CONS, LOG_SYSLOG);
			syslog(LOG_ERR, "%s","Error! Someting went wrong when starting up gWall.");
			closelog;
			cout << "Error! Someting went wrong when starting up gWall.";
		break;

		case 2:
			openlog ("gWall", LOG_CONS, LOG_SYSLOG);
			syslog(LOG_ERR, "%s","Error! Someting went wrong when starting up gWall.");
			closelog;

		default:
			openlog ("gWall", LOG_CONS, LOG_SYSLOG);
			syslog(LOG_ERR, "%s","That's Odd... Please Report A Bug Stating: error_code undefined");
			closelog;
			
	}
	
return 0;
	
}