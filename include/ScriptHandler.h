/*
	Copyright 2009-2012, Sumeet Chhetri

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
 * ScriptHandler.h
 *
 *  Created on: Jun 17, 2012
 *      Author: Sumeet
 */

#ifndef SCRIPTHANDLER_H_
#define SCRIPTHANDLER_H_
#include "AppDefines.h"
#include <stdlib.h>
#include "AfcUtil.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#if !defined(OS_MINGW)
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#endif
#include "Timer.h"

#include "LoggerFactory.h"
#include "Constants.h"

class ScriptHandler {
	#if !defined(OS_MINGW)
	static int pcloseRWE(int pid, int *rwepipe);
	static int popenRWE(int *rwepipe, const char *exe, const char *const argv[],string tmpf);
	static int popenRWEN(int *rwepipe, const char *exe, const char** argv);
	#endif
public:
	ScriptHandler();
	static string execute(string exe, bool retErrs);
	static string chdirExecute(string exe, string tmpf, bool retErrs);
#ifdef INC_SCRH
	static bool handle(HttpRequest* req, HttpResponse& res, map<string, string> handoffs,
			string ext, map<string, string> props);
#endif
	virtual ~ScriptHandler();
};

#endif /* SCRIPTHANDLER_H_ */
