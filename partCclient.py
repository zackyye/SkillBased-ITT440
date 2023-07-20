#
# by munerrr
#
import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Set the server address and port
server_address = ('192.168.9.129', 8888) #tukar ip sendiri

# Get a number from the user
number = int(input("Enter a number: "))

# Send the number to the server
client_socket.sendto(str(number).encode(), server_address)

# Receive the result from the server
result, server_address = client_socket.recvfrom(1024)

# Print the result
result = result.decode()
if result == "True":
 print(f"{number} is a prime number.")
else:
 print(f"{number} is not a prime number.")

# Close the socket
client_socket.close()
