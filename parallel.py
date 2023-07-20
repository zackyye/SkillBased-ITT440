import socket

def Main():
 print('Waiting for connection...')
 host = input('Enter server IP address: ')
 port = int(input('Enter server port number: '))
 ClientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

 try:
  ClientSocket.connect((host, port))
 except socket.error as e:
  print(str(e))
 Response = ClientSocket.recv(1024)
 print(Response)

 while True:
  Input = input('Your Quote of The Day!: ')
  ClientSocket.send(str.encode(Input))
  Response = ClientSocket.recv(1024)
  print(Response.decode('utf-8'))

  ans = input('\nDo you want to continue adding?(y/n): ')
  if ans == 'y':
    continue
  else:
    break

 ClientSocket.close()

if __name__ == '__main__':
 Main()
