#FTP SERVER V2.0#


# HOW TO USE? #

DO AS FOLLOW:

1 - compile : sh gc.sh

2 - copy client and server to one dir!

3 - copy ser,server,getip to another dir!

4 - start server: sh gc (you can find your server's ip)

5 - start client: ./client 192.168.(+your server's ip)

6 - maybe you need this command: 

    u@filename or upload@FILENAME

    d@filename or download@FILENAME

    sh@ls -al or shell@ps -aux or @pstree (etc...)


WHAT'S ADDED IN THIS VERSION?

    MOST IMPORTANT IS --- YOU CAN USE shell TO DO WHAT YOU WANT

    (
        THE SHELL FILE IS SAVED IN ./_shell 

        SO IF YOU WANT TO CHANGE SOMETHING , YOU CAN VIA CHANGE THE SHELL!

    )

    BUT!IT'S UNFINISHED! YOUR SHELL COMMAND CAN ONLYY SEEN ON THE SERVER, I DICIDE TO SAVE THOSE IMFORMATION TO A FILE THEN UPLOAD IT TO THE CLIENT! IT'S NOT HARD.
    

FILES:

1 - client.c: used to upload files

2 - server.c: used to recieve files

3 - getip.c: used to get server's ip


    AND ALSO, IN THIS VERSION, DOWNLOAD IS USABLE. I ADD SOME SHAKEHAND STATMENT TO MAKE SURE IT WORKS STABLE.

    I ALSO WANT TO ADD: USE CD TO CHANG DIR


ADD:

    1-MAKE ONE EXE HAVE BOTH SERVER AND CLIENT FUNCTION

//    2-ADD DOWNLOAD

    3-IMPROVE YOUR COMMAND ANALYSER



HISTORY problem:

    socket 述符没有被共享，在子进程释放，主进程并没有释放依旧占用

    solve -- move close statment


BUG: SEND FILENAME WILL BE ADDED SOME STRANGE BUFS

        -I CHANGE THE NUMBER OF SEND

BUG: DOWNLOAD CAN WORK ONLY ONCE, EXTRA COMMAND

     -BECAUSE FORGET SHAKEHAND!

     AFTER ADD SHAKEHAND, THOSE BUG GONE!

     BUT STILL A BUG, LET ME MAKE THE PROGRAM CONCISE

