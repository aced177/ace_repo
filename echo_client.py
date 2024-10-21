
# echo-client.py

import socket

HOST = "127.0.0.1"
PORT = 28836

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST, PORT))
	while True:
		msg = input("")
		msg = msg.encode('utf-8')
		s.sendall(msg)
		data = s.recv(1024)
		data = data.decode('utf-8')
		print(f"server: {data}\n")