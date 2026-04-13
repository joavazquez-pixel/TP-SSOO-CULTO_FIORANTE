#include "cpu-conexiones.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int conectar_a_servidor(char* ip, int puerto) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in dir;
    dir.sin_family = AF_INET;
    dir.sin_port = htons(puerto);
    dir.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (void*)&dir, sizeof(dir));

    return sock;
}

void enviar_mensaje(int socket, char* mensaje) {
    send(socket, mensaje, strlen(mensaje) + 1, 0);
}

char* recibir_mensaje(int socket) {
    char* buffer = malloc(100);
    recv(socket, buffer, 100, 0);
    return buffer;
}