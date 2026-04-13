#include "memoriak-conexiones.h"
#include <commons/log.h>

int main() {
    t_log* logger = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);

    int server_fd = iniciar_servidor(8000);

    log_info(logger, "Servidor listo, esperando cliente...");

    int cliente = esperar_cliente(server_fd);

    log_info(logger, "Se conectó un cliente");

    char* mensaje = recibir_mensaje(cliente);
    log_info(logger, "Recibí: %s", mensaje);

    enviar_mensaje(cliente, "OK");

    return 0;
}