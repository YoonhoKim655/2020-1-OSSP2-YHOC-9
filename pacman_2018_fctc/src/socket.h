#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include <errno.h>

typedef struct
{
	int server_fd;
	int client_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t addr_len;
	int gameMode; // 1 = normal / 2 = chase
} Socket_value;

void init_server(Socket_value *socket_info,int gamemode);

int connect_server(Socket_value *socket_info);
int connect_client(Socket_value *socket_info, char *severIP);