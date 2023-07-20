#convert pressure bar to atm
import socket

def convert(barValue):
 atmValue = barValue*0.986923
 #round value up to 3 decimal places
 roundedAtm = round(atmValue, 3)
 print(f"Converted to atm: {roundedAtm}")
 return roundedAtm

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific IP address and port
server_address = ('192.168.9.129', 8484)
server_socket.bind(server_address)
print("Server listening on port 8484...")
while True:
 # Receive data from the client
 data, client_address = server_socket.recvfrom(1024)
 barValue = int(data.decode())
 print("Received pressure value in bar: %2d" %barValue )
 # convert bar to atm
 result = convert(barValue)
 # Send the result back to the client
 message = str(result).encode()
 server_socket.sendto(message, client_address)
