#!/usr/bin/env python
# coding=utf-8
import urllib2
allsets = []
grepset = ["png","gif","jpg",".js"]
def urlfind(root):
    https = []
    html = urllib2.urlopen(root)
    html =html.read()
    while(1):
        a_index = html.find('http://')
        if(a_index==-1):
            break
        c = html[a_index-1]
        html = html[a_index:]
        if(c=="("):
            c=')'
        a_index = html.find(c)
        str = html[0:a_index]
        html = html[a_index:]
        if(str[-3:] in grepset):
            continue
        else:
            https.append(str)
            print str,"---"
    allsets.append(https)

#urlfind('http://www.baidu.com')
urlfind('http://www.zhihu.com')
for i in allsets[0]:
    urlfind(i)
    print i,"========\n"
for i in allsets:
    print i
