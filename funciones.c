//
// Created by Álvaro on 25/04/2023.
//

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones auxiliares-privadas

void arreglar(char *palabra){
    int aux = 0;
    for (int i = 0; i<250 && aux == 0; i++){
        if (palabra[i] == '\n') {
            palabra[i] = '\0';
            aux =1;
        }
    }
}

void menu(){

    printf("Menu de agenda de contactos\n");
    printf("------------------------------------\n");
    printf("1 - Listado de personas\n");
    printf("2 - Nueva persona\n");
    printf("3 - Borrar persona\n");
    printf("4 - Exportar agenda de fichero de texto\n");
    printf("5 - Importar agenda de fichero de texto\n");
    printf("0 - Salir\n");
    printf("------------------------------------\n");
}

void nuevaPersona() {
    char aux[MAX];
    FILE *agenda = fopen("agenda.dat", "ab");
    if (agenda == NULL)
        perror("Error de apertura: ");
    tContacto persona[1];
    printf("Nombre:");
    gets(persona->nombre);
    printf("Apellidos:");
    gets(persona->apellido);
    printf("Numero:");
    gets(persona->num);
    printf("Edad");
    gets(persona->edad);
    printf("Tipo de contacto:\n");
    printf("1 - Favorito\n");
    printf("2 - Conocido\n");
    printf("3 - Trabajo\n");
    gets(aux);
    switch (atoi(aux)) {
        case 1:
            persona->tipoContacto = 0;
            break;
        case 2:
            persona->tipoContacto = 1;
            break;
        case 3:
            persona->tipoContacto = 2;
            break;
        default:
            printf("Entrada incorrecta");
            break;
    }
    fwrite(persona, sizeof(tContacto), 1, agenda);
    fflush(agenda);
    fclose(agenda);
}

void muestraAgenda(){
    int i = 1;
    FILE *agenda;
    agenda = fopen("agenda.dat", "rb");
    if (agenda == NULL){
        perror("Error en apertura de agenda: ");
        exit(-1);
    }
    tContacto persona[1];
    fread(persona, sizeof(tContacto), 1, agenda);
    while (!feof(agenda)){
        printf("%i;%s;%s;%s;%s\n", i, persona->nombre, persona->apellido, persona->num, persona->edad);
        i++;
        fread(persona, sizeof(tContacto), 1, agenda);
    }
    fclose(agenda);
}
