/*--------------------------------------------------------------------------------*/
/*Autores:Garcia Juarez Leonel Alexis                                             */
/*        Ramirez Ramirez Ramiro                                                  */
/*        Perez García Floricela                                                  */
/*        Bustamante Santiago Jocelin Marcela                                     */
/*        Vasquez Fabian Luis Fernando                                            */
/*Equipo: 2                                                                       */
/*Email: alexrez2000@gmail.com                                                    */
/*Fecha Creación:29 de octubre de 2020                                            */
/*Fecha Modificación:6 de Noviembre de 2020                                       */
/*Descripción: Este programa determina si los delimitadores (,),{,},[,] en una    */
/*expresión aritmética, por ejemplo, [(5+x)-(y+z)],están bien balanceados.        */
/*--------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
void Decision(int *dec,int *j,int *l, Pila *a){
	int d;
	quitarSaltoLineaEsperaEnter();
	system("clear");
	printf("\n\n\tINGRESAR OTRA OPERACION\n\n\t1.SI\n\t2.NO\n\n\t");
	scanf("%d",&d);//leer la decision del usuario de elegir otra operacion
	PilaVacia(a);
	*j=0;
	*l=0;
	*dec=d;
	system("clear");//limpiar la terminal
}


/*hace el proceso deverificar si el caracter de la cima es el correcto, en caso positivo lo saca de la pila*/
void Proces(int x,int *aux,int *l,char *i,Pila *a){
	*aux=Cima(a); 	
	if(*aux!=x){//)=41 
	          printf("\n\tExpresion no balanceada\n\n");//si no es el caracter manda un mensaje y termina el proces
                  *i='\0';//al asignar termina el ciclo
	          *l=1;
         }else if(*aux==x){
                Pop(a);//Si aux es igual debemos desapilar en la pila a
	}
}

/*Manda un mensaje de Expresion no balanceada y termina el proceso*/
void ExNoBal(int x,char *i,int *l){
	if(*i==x){
		*l=1;  
		*i='\0'; //al asignar termina el ciclo
		printf("\n\tExpresion no balanceada\n\n"); 
	}
}

/*Quita el salto de linea y espera un enter para continuar*/
void quitarSaltoLineaEsperaEnter()
{
	char c;	
	while((c=getchar())!='\n');/*quita el salto de linea del buffer*/
	puts("\n\tingrese un enter para continuar...");
	while((c=getchar())!='\n');/*Espera un salto de linea para continuar*/
}


void PilaVacia (Pila *a)
     {
       a->tope=-1;
     }
     
int EsVacia (Pila *a)
     {
       if (a->tope==-1)
            return 1;
       else
           return 0;  
     }
     
int Cima (Pila *a)
    {
      if (!EsVacia(a))
         return a->arreglo[a->tope];
      else{
           printf("Error de subdesbordamiento UNDERFLOW\n");
           return -9999;
         }
    }


void Push (int x, Pila *a)
     { 
       if (!EsLlena(a))
          {
           a->tope++;
           a->arreglo[a->tope]=x; 
          }
      else
           printf("Error de desbordamiento OVERFLOW\n");
     }
     
int Pop (Pila *a)
    {
      int aux;
      if (EsVacia(a)){
         printf("Error de subdesbordamiento UNDERFLOW\n");
         return -9999;
         }
      else
         {
           aux=a->arreglo[a->tope];
           a->tope--;
           return aux;
         }    
    }

int EsLlena (Pila *a)
     {
       if (a->tope==MAX-1)        
          return 1;
       else
           return 0;  
     }
