#!/usr/bin/env python
# coding=utf-8
import string
def atoi_bit(str,md5):
    count = 0
    md = 0
    for i in str:
        md = md + (ord(i)<<(8*count))# i need to rotate it 
        print count,hex(ord(i)),hex(md)
        count+=1
        if(count==4):
            md5.append(md)
            md = 0
            count = 0
    if(len(str)%4!=0):
        md5.append(md)

def itoa_bit(md5,str):
    for i in md5 :
        while(i!=0):
            c = i-((i>>8)<<8)
            i = i>>8
            c = chr(c)
            str = str + c
    return str
str = "http://www.baidu.com"
md5 = []
atoi_bit(str,md5)
str2 = ""
str2 = itoa_bit(md5,str2)
print str2
print 0xFFFFFFF
