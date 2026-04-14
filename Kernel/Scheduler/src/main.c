
/*
#include <stdlib.h>
#include <stdio.h>
#include <commons/config.h>
#include <commons/log.h>
#include <utils/loggin.h>
#include <utils/conexiones.h>
#include <utils/serializacion.h>
#include <utils/desserializar.h>
#include <semaphore.h>
#include <stdint.h>
#include <pthread.h>
*/


t_config *config;
t_log *logger;

int socket_cpu_dispatch;
int socket_cpu_interrupt;
int socket_memoria;


void iniciar_conexiones_con_CPU_y_MEMORIA()


int main(int argc, char *argv[])
{
	config = iniciar_config(argv[3]);
	logger = iniciar_logger_con_LOG_LEVEL(config, KERNEL);
	iniciar_conexiones_con_CPU_y_MEMORIA();
	// enviar_mensaje("BANANA", socket_cpu_dispatch);
    return 0;
}

void iniciar_conexiones_con_CPU_y_MEMORIA()
{
	char *ip_cpu = config_get_string_value(config, "IP_CPU");
	char *puerto_cpu_dispatch = config_get_string_value(config, "PUERTO_CPU_DISPATCH");
	char *puerto_cpu_interrupt = config_get_string_value(config, "PUERTO_CPU_INTERRUPT");
	socket_cpu_dispatch = conectar_con_CPU(ip_cpu, puerto_cpu_dispatch, "CPU DISPATCH");
	socket_cpu_interrupt = conectar_con_CPU(ip_cpu, puerto_cpu_interrupt, "CPU INTERRUPT");
	char *ip_memoria = config_get_string_value(config, "IP_MEMORIA");
	char *puerto_memoria = config_get_string_value(config, "PUERTO_MEMORIA");

	log_info(logger, "Los valores de config son:\n ip_memoria=%s\n puerto_memoria=%s\n ", ip_memoria, puerto_memoria);
}
