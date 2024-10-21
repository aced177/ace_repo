
# echo-server.py

import socket

HOST = "127.0.0.1"
PORT = 28836

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind((HOST, PORT))
	s.listen()
	conn, addr = s.accept()
	with conn:
		print(f"Connected by {addr}")
		while True:
			data = conn.recv(1024)
			print("***"*10)
			print(f"Recieved {len(data)} bytes")
			print(f":= {data}")
			print("***"*10)
			if not data:
				break
			conn.sendall(data)