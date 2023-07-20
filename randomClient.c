#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define BUFFER_SIZE 1024
int main()
{
 int client_socket;
 struct sockaddr_in server_address;
 char buffer[BUFFER_SIZE];

 // Create the client socket
 client_socket = socket(AF_INET, SOCK_STREAM, 0);

 if (client_socket == -1)
 {
 perror("Socket creation failed");
 exit(1);
 }

 // Set up the server address
 server_address.sin_family = AF_INET;
 server_address.sin_port = htons(8484); // Use the same port as the server
 if (inet_pton(AF_INET, "192.168.9.129", &server_address.sin_addr) <= 0)
 {
 perror("Invalid address or address not supported");
 exit(1);
 }
 // Connect to the server
 if (connect(client_socket, (struct sockaddr *)&server_address,
sizeof(server_address)) < 0)
 {
 perror("Connection failed");
 exit(1);
 }
 // Receive the random number from the server
 int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
 if (bytes_received < 0)
 {
 perror("Receiving data failed");
 exit(1);
 }
 // Null-terminate the received data
 buffer[bytes_received] = '\0';

 // Print the received random number
 printf("Received random number: %s\n", buffer);

 // Close the client socket
 close(client_socket);
 return 0;
}
