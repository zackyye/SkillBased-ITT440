#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
//define host ip, port and buffer
//#define SERVER_IP "192.168.182.140"
//#define PORT 8484
#define BUFFER_SIZE 2048

int main(){
   int socket_fd;
   struct sockaddr_in server_address;
   char text[BUFFER_SIZE];
   char SERVER_IP[20];
   int PORT;

  //Qi-capture user input for server IP address and Port number
   printf("Enter server IP address: ");
   fgets(SERVER_IP, sizeof(SERVER_IP), stdin);
   SERVER_IP [strcspn(SERVER_IP, "\n")] = '\0';

   printf("Enter server port number: ");
   scanf("%d", &PORT);
   getchar();

   //creating socket
   if((socket_fd = socket(AF_INET,SOCK_STREAM,0)) == 0){
	perror("socket failed");
	exit(EXIT_FAILURE);
   }

   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(PORT);

   if(inet_pton(AF_INET,SERVER_IP,&(server_address.sin_addr)) <= 0){
	perror("inet_pton failed");
	exit(EXIT_FAILURE);
   }

   //Qii-establishing socket connection
   if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
	perror("connect failed");
	exit(EXIT_FAILURE);
   }

   //Qiii- compose a string from user input
   printf("Enter text: ");
   fgets(text, BUFFER_SIZE, stdin);

   //remove the newline character from the input
   size_t text_len = strlen(text);
   if(text_len>0 && text[text_len -1] == '\n'){
	text[text_len - 1] = '\0';
   }

   //Qiv-sending user input to server
   ssize_t sent_bytes = send(socket_fd, text, strlen(text), 0);
   if(sent_bytes<0){
	perror("send failed");
	exit(EXIT_FAILURE);
   }

   //receive the modified text from server
   char modified_text[BUFFER_SIZE];
   ssize_t received_bytes = recv(socket_fd, modified_text, BUFFER_SIZE-1, 0);
   if(received_bytes<0){
	perror("recv failed");
	exit(EXIT_FAILURE);
   }

   modified_text[received_bytes] = '\0';

   //Qv-print incoming reply from server
   printf("Modified text received from server: %s\n", modified_text);

   //closing socket
   close(socket_fd);

   return 0;
}
