#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *Nombre;
    int Creditos;
    int Semestre;
} Alumno;

typedef struct
    enlace
{
    Alumno alum;
    struct enlace *siguiente;
} Nodo;

Alumno *crearAlumno(char *, int, int);
void imprimirAlumno(Alumno);
Nodo *crearNodo(Nodo*, Alumno *);
void insertarNodoOrdenadoCreditos(Alumno*, Nodo **);
void imprimirLista(Nodo **);
void insertar_nodo_inicial(Alumno* alumno, Nodo **cabeza);
Nodo* crear_lista();

int main()
{
    Nodo* cabeza;

    cabeza = crear_lista();
    insertar_nodo_inicial(crearAlumno("Alex Dzul", 56, 6), &cabeza);

    insertarNodoOrdenadoCreditos(crearAlumno("Julio Cesar", 2, 2), &cabeza);
    insertarNodoOrdenadoCreditos(crearAlumno("Rodrigo Adrian", 6, 4), &cabeza);
    insertarNodoOrdenadoCreditos(crearAlumno("David Chable", 17, 6), &cabeza);
    insertarNodoOrdenadoCreditos(crearAlumno("Juan Kao", 101, 5), &cabeza);

    imprimirLista(&cabeza);

    return 0;
}

Nodo* crear_lista(){
    Nodo* cabeza;
    cabeza = NULL;
    return cabeza;
}

void insertar_nodo_inicial(Alumno* alumno, Nodo **cabeza){
    *cabeza = crearNodo(NULL, alumno);
}

Alumno *crearAlumno(char *nombre, int creditos, int semestre)
{
    Alumno *nuevo = (Alumno *)malloc(sizeof(Alumno));
    nuevo->Nombre = nombre;
    nuevo->Creditos = creditos;
    nuevo->Semestre = semestre;
    printf("Se ha creado una estructura Alumno en la direccion %x", nuevo);
    return nuevo;
}

void imprimirAlumno(Alumno alum)
{
    printf("Nombre: %s, Creditos Aprobados: %d, Semestre Equivalente: %d\n", alum.Nombre, alum.Creditos, alum.Semestre);
}

Nodo *crearNodo(Nodo* sig, Alumno *dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->alum.Nombre = dato->Nombre;
    nuevo->alum.Creditos = dato->Creditos;
    nuevo->alum.Semestre = dato->Semestre;
    nuevo->siguiente = sig;
    printf("\nSe ha creado un Nodo en la lista de Alumnos en %x\n", nuevo);
    return nuevo;
}

void insertarNodoOrdenadoCreditos(Alumno* alumno, Nodo **cabeza){
    Nodo* ultimo;
    Nodo* siguiente;
    
    ultimo = NULL;
    siguiente = *cabeza;

    while(siguiente != NULL){
        if(alumno->Creditos >= siguiente->alum.Creditos){
            if(siguiente == *cabeza){
                *cabeza = crearNodo(siguiente, alumno);
            }
            else{
                ultimo->siguiente = crearNodo(siguiente, alumno);
            }
            break;
        }
        else{
            ultimo = siguiente;
            siguiente = siguiente->siguiente;
        }
    }
    if(siguiente == NULL){
        ultimo->siguiente = crearNodo(NULL, alumno);
    }
}

void imprimirLista(Nodo **cabeza)
{
    Nodo *actual;
    actual = *cabeza;

    printf("\nImpresion de la lista de Alumnos: \n\n");

    while (actual != NULL)
    {
        imprimirAlumno(actual->alum);
        actual = actual->siguiente;
    }
}