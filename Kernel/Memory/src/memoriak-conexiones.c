#include "memoriak-conexiones.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int iniciar_servidor(int puerto) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in dir;
    dir.sin_family = AF_INET;
    dir.sin_addr.s_addr = INADDR_ANY;
    dir.sin_port = htons(puerto);

    bind(sock, (void*)&dir, sizeof(dir));
    listen(sock, 10);

    return sock;
}

int esperar_cliente(int servidor) {
    return accept(servidor, NULL, NULL);
}

void enviar_mensaje(int socket, char* mensaje) {
    send(socket, mensaje, strlen(mensaje) + 1, 0);
}

char* recibir_mensaje(int socket) {
    char* buffer = malloc(100);
    recv(socket, buffer, 100, 0);
    return buffer;
}