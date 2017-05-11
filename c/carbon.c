/*
 * carbon.c
 *
 *  Created on: 2017年4月23日
 *      Author: 李枨煊
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  /* netdb is necessary for struct hostent */

#define PORT 2003  /* server port */

#define MAXDATASIZE 100

// 写入数据
short carbon_write(char *key[], float value, unsigned int time) {
	int sockfd, num;
	char buf[MAXDATASIZE];    /* buf will store received text */
	struct hostent *he;
	struct sockaddr_in server;

    if((sockfd=socket(AF_INET,SOCK_STREAM, 0))==-1) {
        return -1;
    }

    bzero(&server,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr = *((struct in_addr *)he->h_addr);
	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server))==-1) {
	   return -2;
	}

	char str[];
	strcpy(str, key);
	strcat(str, " ");
	strcat(str, value);
	strcat(str, " ");
	stract(str, time);

    if((num=send(sockfd,str,sizeof(str),0))==-1) {
        return -3;
    }

    buf[num-1]='\0';
    return 1;
}
