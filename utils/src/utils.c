#include "utils.h"


void saludar(char* quien) {
    printf("Hola desde %s!!\n", quien);
}
int iniciarServidor(int puerto);
int esperarConexion(int sochet_servidor);
int crearConexion(char *ip, int puerto)