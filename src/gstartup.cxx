// gstartup.cxx
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


int gstartup(int fork_count)
{
	//int rucmmd_return = 0;

	fork_count=cmmd("/var/snort/ethprep", fork_count);
	fork_count=cmmd("/var/snort/prom", fork_count);
	fork_count=cmmd("/usr/bin/7z a -t7z -m0=lzma2 -mx=9 -mfb=64 -md=512m -ms=on /var/log/snort/archive/snort-$(date +%H_%M_%S-%m_%d_%y).7z /var/snort/log", fork_count);
	fork_count=cmmd("/bin/rm -rf /var/snort/log/*", fork_count);
	fork_count=cmmd("/var/snort/go", fork_count);
	fork_count=cmmd("/var/snort/gnice", fork_count);
	return (fork_count);
}

