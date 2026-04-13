#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    int err;
    struct addrinfo hints, *memoriak_info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;  // 🔑 importante para servidor

    // NULL = escuchar en cualquier IP local
    err = getaddrinfo(NULL, "4444", &hints, &memoriak_info);
    if (err != 0) {
        printf("Error en getaddrinfo\n");
        return 1;
    }

    int fd = socket(memoriak_info->ai_family,
                    memoriak_info->ai_socktype,
                    memoriak_info->ai_protocol);

    // 🔑 Asociar socket al puerto
    if (bind(fd, memoriak_info->ai_addr, memoriak_info->ai_addrlen) == -1) {
        perror("bind");
        return 1;
    }

    // 🔑 Escuchar conexiones
    listen(fd, SOMAXCONN);

    printf("Servidor escuchando...\n");

    // 🔑 Aceptar cliente
    int cpu_fd = accept(fd, NULL, NULL);

    printf("cpu conectado\n");

    freeaddrinfo(memoriak_info);
    close(cpu_fd);
    close(fd);
    return 0;
}