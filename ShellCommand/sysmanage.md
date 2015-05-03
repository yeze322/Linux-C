1. who/w
2. users
3. last -> last login (last + USER) -> last yeze
4. uptime -> how many time sys has run (-p : total time ; -s : start time)
5. watch COMMAND -> watch out put every 2 seconds ( watch -n 5 'ls -l') //watch every 5 sec
___
#ps
6. ps -eo (-e mean all users's ps) 
-o : [comm(cmd->simple),pcpu,pmem,user,time(totoal cpu time),pid,ppid,etime,tty,euid,stat]
7. top -> dynamic monitor!
8. ps -C [COMMAND NAME] : find out how many process this command have
9. ps -eLf -> thread information
ps -eLf --sort -nlwp
___
10. which -> find the command's postion ( which ls)
11. wahtis ->  descibe command shortly ( wahtis ls )
12. uptime -> average load

#kill

1. kill -l -> show all signals
2. killall process_name
3. killall -s SIGNAL +name
4. ATTENTION: `kill` need a pid; `killall` need a pname