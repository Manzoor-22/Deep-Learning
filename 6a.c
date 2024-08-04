#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>

int main() {
    struct sockaddr_in sa;
    int n, sockfd;
    int len;
    char buff[100];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("\nError in Socket");
        exit(0);
    } else{
        printf("\nSocket is Opened");
    }
    
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(80);

    if(connect(sockfd, (struct sockaddr*)&sa, sizeof(sa)) < 0){
        printf("\nError in connection failed");
        exit(0);
    } else{
        printf("\nConnected successfully!");
    }
    
    n = read(sockfd, buff, sizeof(buff));
    
    if(n < 0){
        printf("\nError in reading");
        exit(0);
    } else{
        printf("\nMessage Read = \"%s\"", buff);
    }

    return 0;
}