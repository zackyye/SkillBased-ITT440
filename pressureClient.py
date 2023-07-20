#pressure conversion bar to atm
import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Set the server address and port
server_address = ('192.168.9.129', 8484)
# Get pressure value in bar from user
barValue  = int(input("Enter pressure value (bar): "))
# Send the value to the server
client_socket.sendto(str(barValue).encode(), server_address)
# Receive the result from the server
result, server_address = client_socket.recvfrom(1024)
# Print the result
result = result.decode()
print(f"Converted pressure value(atm): {result} atm")
# Close the socket
client_socket.close()
