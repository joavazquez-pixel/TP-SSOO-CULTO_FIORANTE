#ifndef MAINMEMORIA_H_
#define MAINMEMORIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include <commons/temporal.h>
#include <utils/conexiones.h>
#include <utils/serializacion.h>
#include <utils/loggin.h>
#include <utils/desserializar.h>

#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

void iniciar_conexiones();




#endif