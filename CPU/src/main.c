#include "cpu-conexiones.c"
t_config* config;
char* ip_kernel;
int puerto_kernel;
t_log_level log_level;
t_log* logger;
int socket_kernel

int main(int argc, char* argv[]) {
    saludar("cpu");
    obtenerConfig();
    logger = log_create("cpu.log","cpu",true,log_level);
    socket_kernel=crearConexion(ip_kernel, puerto_kernel);

    
    return 0;
}

void obtenerConfig(){
    config = config_create("cpu_config");
    ip_kernel = config_get_string_value(config,"IP_KERNEL");
    puerto_kernel = config_get_int_value(config, "PUERTO_KERNEL");
    log_level = log_level_from_string(config_get_string_value(config,"LOG_LEVEL");

}