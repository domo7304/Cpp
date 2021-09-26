#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify the address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// connection request
	// It is similar to 'Bind' in server.c
	// connect network & request at server address
	// if there is no connection established, this int will have a value of -1
	int connection_status;
	connection_status = connect(network_socket, (struct sockadd*)&server_address, sizeof(server_address));
	if (connection_status == -1) printf("there is some error in the connection \n\n");

	// receive the data from the server
	char msg[256]; // receive buffer
	recv(network_socket, &msg, sizeof(msg), 0);

	printf("the server sends the data as => %s\n", msg);
	close(network_socket);
	return 0;
}