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
#define MAX 50


typedef struct{
int arreglo[MAX];
int tope;
}Pila;

void ExNoBal(int x,char *i,int *l);

void Proces(int x,int *aux,int *l,char *i,Pila *a);

void Decision(int *dec,int *j,int *l,Pila *a);

void quitarSaltoLineaEsperaEnter();
void PilaVacia (Pila *a);
int EsVacia (Pila *a);
int Cima (Pila *a);
void Push (int x, Pila *a);
int Pop (Pila *a); 
int EsLlena(Pila *a);
