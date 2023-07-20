import socket
#declaration of server address and port
#host = '203.106.71.185'
#port = 8443

print('Waiting for connection...')

host = input('Enter server IP address: ')
port = int(input('Enter server port number: '))

#Qii-establish socket connection to server
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

#set up server address and port
server_address =(host, port)

#connect to the server
try:
   client_socket.connect(server_address)
except socket.error as e:
   print(str(e))
   exit()

#Qii-compose string from user input
user_input = input('Enter student id: ')

#Qiv- send user string to the server
client_socket.sendall(user_input.encode('utf-8'))
print('Student id sent to the server.')

#Qv-print incoming reply string from server
modified_text = client_socket.recv(1024).decode('utf-8')
print('Modified text received from the server: ', modified_text)

#close the client socket
client_socket.close()
