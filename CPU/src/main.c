    
int conectar_con_MEMORIA(char *ip, char *puerto, char *servidor);
void iniciar_conexiones();


int main(int argc, char *argv[])
{
    config = iniciar_config(argv[1]);
    logger = iniciar_logger_con_LOG_LEVEL(config, CPU);
    iniciar_conexiones();
}

int conectar_con_MEMORIA(char *ip, char *puerto, char *servidor)
{
    return crear_conexion(ip, puerto, servidor);
}

void iniciar_conexiones()
{
    char *ip_memoria = config_get_string_value(config, "IP_MEMORIA");
    char *puerto_memoria = config_get_string_value(config, "PUERTO_MEMORIA");
    socket_memoria = conectar_con_MEMORIA(ip_memoria, puerto_memoria, "MEMORIA");
    char *puerto_escucha_dispatch = config_get_string_value(config, "PUERTO_ESCUCHA_DISPATCH");
    char *puerto_escucha_interrupt = config_get_string_value(config, "PUERTO_ESCUCHA_INTERRUPT");
    int socket_servidor_dispach = iniciar_servidor(puerto_escucha_dispatch);
    int socket_servidor_interrupt = iniciar_servidor(puerto_escucha_interrupt);
    socket_kernel_dispach = esperar_cliente(socket_servidor_dispach, "KERNEL_DISPACH");
    socket_kernel_interrup = esperar_cliente(socket_servidor_interrupt, "KERNEL_INTERRUP");
}