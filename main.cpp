#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winbgim.h>
#include "paridad.h"


int main() {

	int state = q0, re=0, cont=0;
	char opc, name[30], c = '0';
	
	FILE *created = fopen("Texto_usuario.txt", "w");
	
	do{
		
		while(opc != '1' && opc != '2' ){
			
			printf("¿COMO DESEA TRABAJAR?:\n1)Escribir un texto en consola\n2)Leer desde archivo\n\nSeleccione: ");
			scanf("%c", &opc);
			
			if(opc<48 && opc>57){
				printf("\nCaracter no valido, ingrese un numero");
				getchar();
				system("cls");
				}
			if(opc != '2' && opc != '1')
				printf("\nOpcion no valida, intentar de nuevo!");	
				getchar();
				system("cls");
		}	
		
		system("cls");

		
		switch(opc){
	
			case '1':
			printf("Ingrese el texto:\n\n");
			while( (c = getchar()) != '\n')    {
				
				fputc(c, created);
				cont++;
				
				if(cont>=285 && c == ' '){
					fputc('\n', created);
					cont = 0;
				}
			}
			
			fclose(created);
			leer_desde_archivo("Texto_usuario.txt");
			
				
			break;
			
			case '2':
				printf("Ingrese el nombre del archivo: ");
				scanf("%s",&name);
				leer_desde_archivo(name);
			break;
		}
		
			
	}while (re == 1);
	
	
}

