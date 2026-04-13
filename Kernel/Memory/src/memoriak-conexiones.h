#ifndef CONEXIONES_H
#define CONEXIONES_H

int iniciar_servidor(int puerto);
int esperar_cliente(int servidor);
void enviar_mensaje(int socket, char* mensaje);
char* recibir_mensaje(int socket);

#endif