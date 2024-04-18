#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    char matricula[10];
    char carrera[25];
    int edad;
    float promedio;
    int ciclo;
} Alumno;

int main()
{
    int num_alumnos;
    Alumno *alumnos;
    FILE *archivo;
    char nombre_archivo[30];

    printf("Ingrese el numero de alumnos que desea almacenar: ");
    scanf("%d", &num_alumnos);

    alumnos = (Alumno*)malloc(num_alumnos * sizeof(Alumno));
    if (alumnos == NULL)
    {
        printf("No se pudo asignar memoria \n");
        return 1;
    }

    printf("Ingrese los detalles de cada alumno: \n");
    for (int i = 0; i < num_alumnos; i++)
    {
        printf("Alumno %d:\n", i + 1);
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", alumnos[i].nombre);
        printf("Ingrese la matricula: ");
        scanf("%s", alumnos[i].matricula);
        printf("Ingrese la carrera: ");
        scanf("%s", alumnos[i].carrera);
        printf("Ingrese la edad: ");
        scanf("%d", &alumnos[i].edad);
        printf("Ingrese el Promedio: ");
        scanf("%f", &alumnos[i].promedio);
        printf("Ingrese el ciclo: ");
        scanf("%d", &alumnos[i].ciclo);
    }

    printf("Ingrese el nombre del archivo donde se guardarán los datos del alumnos: ");
    scanf("%s", nombre_archivo);

    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    for (int i = 0; i < num_alumnos; i++)
    {
        fprintf(archivo, "Alumno %d:\nNombre: %s\nMatricula: %s\nCarrera: %s\nEdad: %d\nPromedio: %.2f\nCiclo: %d\n\n", i + 1, alumnos[i].nombre, alumnos[i].matricula, alumnos[i].carrera, alumnos[i].edad, alumnos[i].promedio, alumnos[i].ciclo);
    }

    fclose(archivo);

    free(alumnos);

    printf("Los detalles de los alumnos se han guardado exitosamente en el archivo %s.\n", nombre_archivo);

    return 0;
}
