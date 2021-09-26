#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char server_message[256] = "socket programming in c";

	// *creating the server socket*
	//int server_socket = socket(AF_INET, SOCK_STREAM, 0); // It means IPv4, TCP, 'default' in sequence.
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// *define the server address*
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; // It means IPv4.
	server_address.sin_port = htons(8080); // It can be anything. You can define your own.
	server_address.sin_addr.s_addr = INADDR_ANY; // It menas that assign any address to it. It automatically assign some address to this one.
	// We are done. We defined the server address.

	// Now we have to specify ip and port which we have to bind it.
	// *Bind the IP and port to the server.*
	// We are binding at server address. and 'server_address' contains all these informations.
	bind(server_socket, (struct sockadd*)&server_address, sizeof(server_address));

	// *listen the port*
	listen(server_socket, 5); // 5 means limits of client

	// accept the incomming connection from the client
	int client_sock;
	client_sock = accept(server_socket, NULL, NULL);

	// send the message on the client address
	send(client_sock, server_message, sizeof(server_message), 0);
	close(server_socket);
	return 0;
}