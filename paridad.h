//Cabecera

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define  on '1'
#define off '0'
#define q0 0
#define q1 1
#define q2 2
#define q3 3

int evaluar(char l, int state, int pos);
void dibujar();
void historial(char l, int state, FILE *archivo);
void escribir_texto();
int leer_desde_archivo(char name[30]);
int signos(char l);
