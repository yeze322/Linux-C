#FTP SERVER V1.0#
2015-03-02 unfinished

# HOW TO USE? #
DO AS FOLLOW:
1 - compile : sh gc
2 - copy client and server to one dir!
3 - copy ser,server,getip to another dir!
4 - start server: sh gc (you can find your server's ip)
5 - start client: ./client 192.168.(+your server's ip)
6 - maybe you need this command: 
    u@filename or upload@FILENAME
    d@filename or download@FILENAME

FILES:
1 - client.c: used to upload files
2 - server.c: used to recieve files
3 - getip.c: used to get server's ip

ADD:
    1-MAKE ONE EXE HAVE BOTH SERVER AND CLIENT FUNCTION
    2-ADD DOWNLOAD
    3-IMPROVE YOUR COMMAND ANALYSER
problem:
    socket 述符没有被共享，在子进程释放，主进程并没有释放依旧占用
    solve -- move close statment

BUG: SEND FILENAME WILL BE ADDED SOME STRANGE BUFS
        -I CHANGE THE NUMBER OF SEND
BUG: DOWNLOAD CAN WORK ONLY ONCE, EXTRA COMMAND
     -BECAUSE FORGET SHAKEHAND!
     AFTER ADD SHAKEHAND, THOSE BUG GONE!
     BUT STILL A BUG, LET ME MAKE THE PROGRAM CONCISE
