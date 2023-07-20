#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 1024

int main()
{
 int server_socket, client_socket;
 struct sockaddr_in server_address, client_address;
 socklen_t client_address_length;
 char buffer[BUFFER_SIZE];

 int lower=100, upper=999, count=1;
 int num;

 //use curren time ad seed for random generator
 srand(time(0));

 // Create the server socket
 server_socket = socket(AF_INET, SOCK_STREAM, 0);
 if (server_socket == -1)
 {
   perror("Socket creation failed");
   exit(1);
 }

 // Set up the server address
 server_address.sin_family = AF_INET;
 server_address.sin_addr.s_addr = INADDR_ANY;
 server_address.sin_port = htons(8484);
 if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
 {
   perror("Binding failed");
   exit(1);
 }
 // Listen for incoming connections
 if (listen(server_socket, 5) < 0)
 {
   perror("Listening failed");
   exit(1);
 }
   printf("Server listening on port 8484 ...\n");
 while (1)
 {
   // Accept a client connection
   client_address_length = sizeof(client_address);
   client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
 if (client_socket < 0)
 {
   perror("Accepting connection failed");
   exit(1);
 }
 printf("Client connected\n");

 // Generate a random number
 for(int i = 0; i<count; i++){
   num = (rand() % (upper - lower + 1)) + lower;
  }

 // Convert the random number to a string
 sprintf(buffer, "%d", num);

 // Send the random number to the client
 if (send(client_socket, buffer, strlen(buffer), 0) < 0)
 {
   perror("Sending data failed");
   exit(1);
 }

 printf("Random number sent: %s\n", buffer);

 // Close the client socket
 close(client_socket);
 printf("Client disconnected\n");
 }

 // Close the server socket
 close(server_socket);


 return 0;
}
