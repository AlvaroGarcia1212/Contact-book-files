//
// Created by Álvaro on 25/04/2023.
//

#ifndef AGENDAFICHEROS_FUNCIONES_H
#define AGENDAFICHEROS_FUNCIONES_H
#define MAX 50
#define CONST_NUM 10
#define CONST_EDAD 3
#include <stdio.h>

typedef enum CONTACTO{
    FAVORTO, CONOCIDO, TRABAJO
}tTipo;

typedef struct AGENDA{
    char nombre[MAX];
    char apellido[MAX];
    char num[CONST_NUM];
    char edad[CONST_EDAD];
    tTipo tipoContacto;
}tContacto;

void menu();


void nuevaPersona();
void muestraAgenda();




#endif //AGENDAFICHEROS_FUNCIONES_H
