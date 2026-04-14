   int main(int argc, char *argv[])
{
   
   
   config = iniciar_config(argv[1]);

    logger = iniciar_logger_con_LOG_LEVEL(config, MEMORIA);

    iniciar_conexiones();

}


void iniciar_conexiones()
{
    char *puerto_escucha = config_get_string_value(config, "PUERTO_ESCUCHA");
    socket_servidor_MEMORIA = iniciar_servidor(puerto_escucha);

    socket_cliente_CPU = esperar_cliente(socket_servidor_MEMORIA, "CPU");
    
}

void atender_KERNEL()
{

    while (1)
    {

        int socket_cliente_KERNEL = esperar_cliente(socket_servidor_MEMORIA, "KERNEL");

        pthread_t hilo_socket_cliente_;
        pthread_create(&hilo_socket_cliente_, NULL, (void *)atender_cliente, socket_cliente_KERNEL);
        pthread_detach(hilo_socket_cliente_);
    }
}
