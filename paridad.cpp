
#include "paridad.h"



int evaluar (char l, int state, int pos){
	
	if( l >= 48 && l <=57 || (signos(l) && pos != 0)) //Si es un número
	return -1;
	
	else if(signos(l) )
	return q0;
	
	else if( (l != 'i' && l!= 'I') && (state == q0 || l == 39 || (state == q2 && (l!='g' && 'G') )  || state == q3 || (state == q1 && (l!='n' && l!='N' ))) )
	return q0;
	
	else if(l=='i' || l == 'I')
	return q1;
	
	else if( (l=='n' || l == 'N') && state == q1)
	return q2;
	
	else if (state == q2 && (l == 'g' || l == 'G') )
	return q3;	
	
	else
	return -1;
	
	
}

void historial(char l, int state, FILE* archivo){


switch(state){
	
	case q0:
	fprintf(archivo, "%s", " q0 = ");
	fprintf(archivo, "%c", l);
	fprintf(archivo, "%s", ", ");
	break;
	
	case q1:
	fprintf(archivo, "%s", " q1 = ");
	fprintf(archivo, "%c", l);
	fprintf(archivo, "%s", ", ");

	break;
	
	case q2:
	fprintf(archivo, "%s", " q2 = ");
	fprintf(archivo, "%c", l);
	fprintf(archivo, "%s", ", ");
	break;
	
	case q3:
	fprintf(archivo, "%s", "q3 = ");
	fprintf(archivo, "%c", l);
	fprintf(archivo, "%c", ", ");
	break;
	
	case 4:
	fprintf(archivo, "%s","\n");
	break;
	
	default:
	fprintf(archivo, "%s", "  Esto no es una palabra que exista en el lenguaje");
	break;	

}

}

int signos(char l){
	
	if( l == '.' || l == ',' || l == 39 || l == '?' || l == '!' || l == '(' || l == ')' || l == ';' || l == '[' || l == ']'
			|| l == '-' || l == '{' || l == '}' ){
				
				return 1;
			}
			
			else
			return 0;
	
}


int leer_desde_archivo(char name[30] ){
		
			char  words [30], lectura[300], found=0;
			int pal = 0, tam, i, linea = 1, state = q0;
			
			char * token;
			FILE * gerundios = fopen("gerundios.txt", "w");
			FILE * timeline = fopen("Historial.txt", "w"); //Crear archiv para su escritura
			fclose(timeline); 
			fopen("Historial.txt", "a+");
			
			
			
			//Crea un apuntador hacia el archivo señalado por el usuario
			FILE * archivo = fopen(name, "r");
			
			if(archivo == NULL){
				system("cls");
				printf("El archivo no existe. Se saldra del programa");
				return -1;
			}
			
			
			while( !ferror(archivo) && !feof(archivo) ){
			
			fgets(lectura, 300, archivo);
				
				token = strtok(lectura, " ");	
			
				while( token != NULL){
					
					strcpy(words, token);	
					pal++;
					tam = strlen(words);
					
					if(words[tam-1] == '\n'){ //Permite evaluar cadenas que esten al final de la linea
						words[tam-1] = '\0';
						tam--;
					}
					
					if( signos(words[tam-1]) ) { //Si existe un caracter valido al final lo ignora
						tam--;
						words[tam] = '\0';
					}
					
					fputs(words, timeline);
					 
								
					for(i = 0; i<tam; i++){ //Si existe un caracter valido, entonces lo ignora
						state = evaluar(words[i], state, i); 
						historial(words[i], state, timeline);
							
						if(state == -1)
							i = tam;
					}
					
						historial('4',4, timeline);
						
						if(state == q3){
						fprintf(gerundios, "%s", words);
						fprintf(gerundios, "%s", "\tPalabra: #");
						fprintf(gerundios, "%d", pal);
						fprintf(gerundios, "%s", " Linea: #");
						fprintf(gerundios, "%d", linea);
						fprintf(gerundios, "%s", "\n");
						found=1;
						}
					
					
					token = strtok(NULL, " ");
					state = q0;
					
				}
			//	despues de seccionar toda la cadena
			linea++;
			pal = 0;
			fflush(stdin);
			historial('4', 4, timeline); //Agregar un salto de linea cuando termina la palabra
			}
			
			if(found==0){
				fputs("No se encontraron palabras con terminacion ing",gerundios);
				printf("\n\nNo se encontraron palabras con terminacion ing\n\n");
				}
			
			
			fclose(gerundios);
			fclose(timeline);
			printf("Escaneo terminado!\n\n");
			dibujar();
			getchar();
}

