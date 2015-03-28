import socket
import sys
from time import sleep
from multiprocessing import Process
def client():
	HOST = "192.168.1.97"
	PORT = 1234

	soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	while 1:
		try:
			soc.connect((HOST, PORT))
		except:
			print "No server! ",
			soc.close()
			sys.exit()
		else:
			break

	while 1:
		data = soc.recv(1024)
		if data == 'EOF':
			sys.exit()
		if data == "":
			sys.exit()
		print data,

	soc.close()
print '+'

if __name__ == '__main__':
	for i in range(200):
		p = Process(target = client)
		p.start()