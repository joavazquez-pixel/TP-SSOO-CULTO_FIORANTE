#include "memoriak-conexiones.h"

int socket_servidor;
int puerto_escucha;
t_config* config;
int socket_cpu;
t_log* logger;
t_log_level log_level;

int main(int argc, char* argv[]) {
    saludar("kernel");
    obtenerConfig();
    logger = log.create("memoriak.log", "MEMORIAK_H", true, log_level)
    socket_servidor = inciarServidor(puerto_escucha);
    socket_cpu=esperarConexion(socket_servidor);
    log_info(logger,"se conecto la cpu")
    return 0;
}

void obtenerConfig(){
    config=config_create("memoriak.config");
    puerto_escucha=config_get_int_value(config,"PUERTO_ESCUCHA");
    log_level= log_level_from_string(config_get_string_value(config,"LOG_LEVEL"));,
}