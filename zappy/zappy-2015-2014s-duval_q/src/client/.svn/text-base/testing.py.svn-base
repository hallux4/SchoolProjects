import socket
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 4242))

input = b""
output = b""
teamname = "toto\n"

print ("Script python de test");

while input != b"BIENVENUE\n":
	input = sock.recv(1024)
print (input)

print ("Send to server teamname : " + teamname)
sock.send(teamname)

while 1:
	try:
		input = sock.recv(1024);
		sock.send(b"avance\n");
		sock.send(b"droite\n");
		print ("RECEIVE : " + input);
#		time.sleep(1);

	except:
		print ("mort");
		sock.close();
		exit();

