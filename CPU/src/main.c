#include "cpu-conexiones.h"
#include <commons/log.h>

int main() {
    t_log* logger = log_create("cpu.log", "CPU", true, LOG_LEVEL_INFO);

    int conexion = conectar_a_servidor("127.0.0.1", 8000);

    log_info(logger, "Conectado a memoria");

    enviar_mensaje(conexion, "HOLA");

    char* respuesta = recibir_mensaje(conexion);
    log_info(logger, "Respuesta: %s", respuesta);

    return 0;
}