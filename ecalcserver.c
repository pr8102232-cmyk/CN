/* TCP Continuous Calculator Server */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in serv_addr, cli_addr;

int listenfd, connfd, r;
socklen_t cli_addr_len;

unsigned short serv_port = 25020;
char serv_ip[] = "127.0.0.1";

char buff[128];
char cmd[20];

int main()
{
    int a, b, result, maxfd;
    char op;
    fd_set readfds;

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip, &serv_addr.sin_addr);

    printf("\nTCP CONTINUOUS CALCULATOR SERVER\n");

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 5);

    cli_addr_len = sizeof(cli_addr);

    printf("SERVER: Waiting for client...\n");
    connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &cli_addr_len);

    maxfd = (connfd > 0) ? connfd : 0;

    while (1)
    {
        FD_ZERO(&readfds);
        FD_SET(connfd, &readfds);
        FD_SET(0, &readfds);

        select(maxfd + 1, &readfds, NULL, NULL, NULL);

        /* client input */
        if (FD_ISSET(connfd, &readfds))
        {
            r = read(connfd, buff, sizeof(buff));

            if (r <= 0)
            {
                printf("SERVER: Client disconnected.\n");
                break;
            }

            buff[r] = '\0';

            if (strcmp(buff, "exit") == 0)
            {
                printf("SERVER: Client disconnected.\n");
                break;
            }

            sscanf(buff, "%d %c %d", &a, &op, &b);

            switch (op)
            {
            case '+':
                result = a + b;
                sprintf(buff, "%d + %d = %d", a, b, result);
                break;
            case '-':
                result = a - b;
                sprintf(buff, "%d - %d = %d", a, b, result);
                break;
            case '*':
                result = a * b;
                sprintf(buff, "%d * %d = %d", a, b, result);
                break;
            case '/':
                if (b == 0)
                    sprintf(buff, "Division by zero not possible");
                else
                {
                    result = a / b;
                    sprintf(buff, "%d / %d = %d", a, b, result);
                }
                break;
            default:
                sprintf(buff, "Invalid operator");
            }

            write(connfd, buff, sizeof(buff));
            printf("SERVER: %s\n", buff);
        }

        /* server keyboard input */
        if (FD_ISSET(0, &readfds))
        {
            fgets(cmd, sizeof(cmd), stdin);
            cmd[strcspn(cmd, "\n")] = '\0';

            if (strcmp(cmd, "exit") == 0)
            {
                write(connfd, "exit", 128);
                printf("SERVER: Shutdown complete.\n");
                break;
            }
        }
    }

    close(connfd);
    close(listenfd);
    return 0;
}