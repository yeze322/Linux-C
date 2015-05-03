find . -name "*lua*" \( -path "*template*" -o -path "*script*" -o -print \)
---> Or operator, ignore some filename! USEFUL!!!!
find -maxdepth 1 -type f -exec sh argu.sh {} \;
-user -name -iname -maxpath -minpath -exec
-atime (last visit) -mtime (last change) -ctime (last chown change) +- 7 (day)
-amin -> minite
-type f/d/ (l,c,b,s,p)
-size (b=512byte, c = byte, w = 2byte, k = 1024Byte, G = 1024M) [+/-] supported
-print -print0 -printf  //-fprint(f) : -printf
//I can use -exec printf "" {} \; but cannot use -printf
-delete : delete the file you find

find . -type f \( -path "*erviewQue*" -o \( -name "*.cpp" -o -name "*.h" -o -name "*.c" \) -print0 \) | xargs -0 wc -l > ~/Desktop/statics.txt 