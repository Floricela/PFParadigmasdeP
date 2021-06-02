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

#include <stdio.h>//biblioteca de entrada y salida
#include <string.h>//Biblioteca para el uso de cadenas
#include <stdlib.h>//biblioteca para gestión de memoria dinámica 
#include "Pila.h"//comillas por que esa biblioteca es creada,par el uso de funciones prropias

/* Directivas del preprocesador para limpiar pantalla Linux o Windows 64 bits */
#ifdef __linux__
    #define LIMPIAR "clear"
#elif _WIN64
    #define LIMPIAR "cls"
#endif

int main(){      
        Pila a;
        char oper[MAX];//arreglo para guardar la expresión
        int aux,j=0,l=0,dec;//para la decision de hacer mas operaciones
        char i;
        PilaVacia(&a);// crea una pila vacia
        
	do{
		system("clear");     
		printf("\tingrese la operacion a evaluar \n\n\t");
		scanf("%s",oper);

		do{
		    /* valor en el codigo ascii
	      	    (=40       )=41
	 	    [=91       ]=93
		    {=124      ]=125*/
		    
		    i=oper[j];//guarda lo que tiene el arreglo en la posicion j, controla ciclo 
		    switch(oper[j]) {     
		        case 40:
		                 Push(40,&a);//inserta el valor del parentesis que abre  en la pila a
		                 break;
		        case 91: 
		                Push(91,&a);//inserta el valor del corchete que abre a la pila a
		                break; 
		        case 123:    
		                Push(123,&a);//inserta la valor de la llave que abre a la pila a
		                 break;
		  	
		        /*Si encontramos un símbolo de cierre ],},) entonces :consultamos el elemento que hay en la cima de la pila.
		        Si son de distinto tipo, podemos afirmar que la expresión no está balanceada.
		        Si son del mismo tipo, debemos desapilar.*/
		       
		        case 41:
				if(!EsVacia(&a)){
					 Proces(40,&aux,&l,&i,&a);//recibe el codigo ascci de ),la direcion de memoria de aux,l,i y a
				         
				}else if(i==41){
					ExNoBal(41,&i,&l);//recibe el codigo ascci de la pareja (,la direcion de memoria de l,i
				}
				 break; 
			 
			case 93:
				if(!EsVacia(&a)){                
					Proces(91,&aux,&l,&i,&a);//recibe el codigo ascci de ],la direcion de memoria de aux,l,i y a
				}else if(i==93){
					ExNoBal(93,&i,&l);//recibe el codigo ascci de la pareja (,la direcion de memoria de l,i
				}
		                break;
	
		        case 125: 
		        	if(!EsVacia(&a)){
		                	Proces(123,&aux,&l,&i,&a);//recibe el codigo ascci de },la direcion de memoria de aux,l,i y a                 
				}else if(i==125){
					ExNoBal(125,&i,&l); //recibe el codigo ascci de la pareja (,la direcion de memoria de l,i
				}
		                  break;
		        default:
		                 break;
		    }//cierre del switch
		    j++;//controla el arreglo donde esta la expresion
		}while(i!='\0');//i controla el ciclo
		
		if(!EsVacia(&a)){//si no esta vacia la pila a
		    printf("\n\tExpresion no balanceada\n\n");  
		}
		//l!=1  sirve para no repetir el mensaje en caso de tener )]} extras 
		else if(EsVacia(&a)&&l!=1){
		    printf("\n\tExpresion balanceada correctamente\n\n");  
		}
		Decision(&dec,&j,&l,&a);
	}while(dec!=2); //hacer todo eso mientras la decision del usuario sea diferente de 2
}// llave del maim
