#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){
    struct sockaddr_in sa;
    struct sockaddr_in cli;
    int sockfd,conntfd;
    int len,ch;
    char str[100];
    time_t tick;
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    
    if(sockfd<0){
        printf("\nError in socket");
        exit(0);
    }
    else{
        printf("\nSocket opened");
    }    
    
    bzero(&sa,sizeof(sa));
    sa.sin_port=htons(5600);
    sa.sin_addr.s_addr=htonl(0);
    
    if(bind(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0){
        printf("\nError in binding");
        exit(0);
    }
    else{
        printf("\nBinded Successfully");
    }
    
    listen(sockfd,50);
    
    for(;;){
        len=sizeof(ch);
        conntfd=accept(sockfd,(struct sockaddr*)&cli,&len);
        printf("Accepted");
        tick=time(NULL);
        snprintf(str,sizeof(str),"%s",ctime(&tick));
        printf("%s",str);
        write(conntfd,str,100);
    }
}
