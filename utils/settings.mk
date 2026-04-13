LIBS= commons pthread readline m crypto
CDEBUG=-g -Wall -DDEBUG -fdiagnostics-color=always
CRELEASE=-O3 -Wall -DNDEBUG
TEST_EXCLUDE=src/main.c
