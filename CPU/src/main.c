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

    // IP del servidor y puerto
    err = getaddrinfo("127.0.0.1", "4444", &hints, &memoriak_info);
    if (err != 0) {
        printf("Error en getaddrinfo\n");
        return 1;
    }

    int fd = socket(memoriak_info->ai_family,
                    memoriak_info->ai_socktype,
                    memoriak_info->ai_protocol);

    // 🔑 El cliente se conecta
    if (connect(fd, memoriak_info->ai_addr, memoriak_info->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    printf("Conectado al servidor\n");

    freeaddrinfo(memoriak_info);
    close(fd);
    return 0;
}