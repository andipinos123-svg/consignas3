#include <stdio.h>
#include <string.h>

float validarFlotanteRango(float min, float max);
int main(int argc, char const *argv[])
{
    int opc, opc1, cantE=0;
    float n1[5], n2[5], n3[5], prom[5], promM[3], min, max, maxminC[3][2];
    char nombre[5][30], matSimp[3][20]={"Mat","Len","Prog"}, aprep[3][20];

    do
    {
        do
        {
            printf("\nRegistro de calificaciones:\n");
            printf("\nMenú de opciones:\n");
            printf("1. Ingrese el nombre y calificaciones del estudiante:\n");
            printf("2. Mostrar las calificaciones con su promedio:\n");
            printf("3. Mostrar la calificacion mas alta y mas baja\n");
            printf("4. Materias que aprobaron y reprobaron:\n");
            printf("5. Salir\n");
            printf(">> ");
            scanf("%d", &opc1);
            while (getchar() != '\n');
            if (opc1 < 1 || opc1 > 5) {
                printf("\nOpción inválida. Intente de nuevo.\n");
            }
        } while (opc1 < 1 || opc1 > 5);
        
        switch (opc1)
        {
        case 1:
            if (cantE >= 5) {
                printf("El maximo de estudiantes para ingresar son 5.\n");
                break;
            }
            printf("Ingrese el nombre y apellido del estudiante: ");
            scanf(" %[^\n]", nombre[cantE]);

            printf("Matematicas: ");
            n1[cantE] = validarFlotanteRango(1,10);
            printf("Lenguaje: ");
            n2[cantE] = validarFlotanteRango(1,10);
            printf("Programacion: ");
            n3[cantE] = validarFlotanteRango(1,10);
           
            cantE++;
            break;

        case 2:
            if (cantE == 0) {
                printf("No hay estudiantes registrados.\n");
                break;
            }
        
            promM[0] = 0; promM[1] = 0; promM[2] = 0;

            printf("\n%-4s %-30s %-12s %-10s %-13s %-10s\n", "#", "Nombre", "Matematicas", "Lenguaje", "Programacion", "Promedio");
            for (int i = 0; i < cantE; i++)
            {
                prom[i] = (n1[i] + n2[i] + n3[i]) / 3;
                promM[0]+=n1[i];
                promM[1]+=n2[i];
                promM[2]+=n3[i];
                printf("%-4d %-30s %-12.2f %-10.2f %-13.2f %-10.2f\n", i+1, nombre[i], n1[i], n2[i], n3[i], prom[i]);
            }
            
            promM[0]/=cantE;
            promM[1]/=cantE;
            promM[2]/=cantE;
            printf("%-4s %-30s %-12.2f %-10.2f %-13.2f\n", "", "Promedios:", promM[0], promM[1], promM[2]);
            break;
            
        case 3:
            if (cantE == 0) {
                printf("No hay estudiantes registrados.\n");
                break;
            }

            for (int m = 0; m < 3; m++) {
                min = 10;
                max = 0;
                for (int i = 0; i < cantE; i++) {
                    float notaActual;
                    if (m == 0) notaActual = n1[i];
                    else if (m == 1) notaActual = n2[i];
                    else notaActual = n3[i];

                    if (notaActual <= min) {
                        min = notaActual;
                    }
                    if (notaActual > max) {
                        max = notaActual;
                    }
                }
                maxminC[m][0] = min;
                maxminC[m][1] = max;
            }

            printf("\n%-10s %-10s %-10s\n", "Mats", "Min", "Max");
            for (int i = 0; i < 3; i++)
            {
                printf("%-10s %-10.2f %-10.2f\n",matSimp[i],maxminC[i][0],maxminC[i][1]);
            }
            break;

        case 4:
            if (cantE == 0) {
                printf("No hay estudiantes registrados.\n");
                break;
            }
            printf("\n%-4s %-30s %-15s %-15s %-15s\n", "#", "Nombre", "Matematicas", "Lenguaje", "Programacion");
            for (int i = 0; i < cantE; i++)
            {
                for (int m = 0; m < 3; m++) {
                    float notaActual;
                    if (m == 0) notaActual = n1[i];
                    else if (m == 1) notaActual = n2[i];
                    else notaActual = n3[i];

                    if (notaActual >= 6) {
                        strcpy(aprep[m], "Aprobado");
                    } else {
                        strcpy(aprep[m], "Reprobado");
                    }
                }
                printf("%-4d %-30s %-15s %-15s %-15s\n",i+1,nombre[i],aprep[0],aprep[1],aprep[2]);
            }
            break;

        case 5:
            return 0;

        default:
            break;
        }

        do
        {
            printf("\nDesea seleccionar otra opcion 1.Si/2.No -> ");
            scanf("%d", &opc);
            while (getchar() != '\n');
            if (opc != 1 && opc != 2) {
                printf("\nOpción inválida. Intente de nuevo.\n");
            }
        } while (opc != 1 && opc != 2);
        
    } while (opc == 1);
    
    return 0;
}

float validarFlotanteRango(float min, float max){
    int val = 0;
    float aux = 0;
    do{
        val = scanf("%f",&aux);
        while((getchar())!='\n');
        if (aux < min || aux > max || val != 1)
        {
            printf("Error: Valor ingresado incorrecto\n");
        }
    }while(aux < min || aux > max || val != 1);
    return aux;
}