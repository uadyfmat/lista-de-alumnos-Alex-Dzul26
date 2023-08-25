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
Nodo *crearNodo(Alumno *);
void insertarNodoOrdenadoCreditos(Nodo *, Nodo **);
void imprimirLista(Nodo **);

int main()
{

    Nodo **cabeza = NULL;

    insertarNodoOrdenadoCreditos(crearNodo(crearAlumno("Alex", 56, 6)), cabeza);
    insertarNodoOrdenadoCreditos(crearNodo(crearAlumno("DECO", 2, 2)), cabeza);
    insertarNodoOrdenadoCreditos(crearNodo(crearAlumno("Rodrigo", 6, 4)), cabeza);
    insertarNodoOrdenadoCreditos(crearNodo(crearAlumno("David", 17, 6)), cabeza);
    insertarNodoOrdenadoCreditos(crearNodo(crearAlumno("Juan", 101, 5)), cabeza);

    imprimirLista(cabeza);

    return 0;
}

Alumno *crearAlumno(char *nombre, int semestre, int creditos)
{
    Alumno *nuevo = (Alumno *)malloc(sizeof(Alumno));
    nuevo->Nombre = nombre;
    nuevo->Creditos = creditos;
    nuevo->Semestre = semestre;
    return nuevo;
}

void imprimirAlumno(Alumno alum)
{
    printf("Nombre Completo: %s\nCreditos Aprovados: %d\nSemestre Equivalente: %d", alum.Nombre, alum.Creditos, alum.Semestre);
}

Nodo *crearNodo(Alumno *alum)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->alum.Nombre = alum->Nombre;
    nuevo->alum.Creditos = alum->Creditos;
    nuevo->alum.Semestre = alum->Semestre;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarNodoOrdenadoCreditos(Nodo *Alumno, Nodo **cabeza)
{
    Nodo *actual = cabeza;
    Nodo *anterior = cabeza;

    if (actual == NULL)
    {
        actual = Alumno;
    }
    else
    {
        if (actual->alum.Creditos < Alumno->alum.Creditos)
        {
            *cabeza = Alumno;
            Alumno->siguiente = actual->siguiente;
        }
        else
        {
            actual = actual->siguiente;

            while (actual != NULL)
            {
                if (actual->alum.Creditos > Alumno->alum.Creditos)
                {
                    anterior = actual;
                    actual = actual->siguiente;
                }
                else
                {
                    break;
                }
            }
            anterior->siguiente = Alumno;
            if (actual == NULL)
            {
                Alumno->siguiente = NULL;
            }
            else
            {
                Alumno->siguiente = actual->siguiente;
            }
        }
    }
}

void imprimirLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;

    while (actual != NULL)
    {
        imprimirAlumno(actual->alum);
    }
}