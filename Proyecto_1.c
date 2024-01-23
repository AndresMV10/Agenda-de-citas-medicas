#include "Agenda_citas.h"

int main() {
    int opc;

    do {
        printf("\n\t.:MENU:.\n");
        printf("1. Agendar Cita\n");
        printf("2. Visualizar Citas\n");
        printf("3. Editar Cita\n");
        printf("4. Eliminar Cita\n");
        printf("5. Salir\n");

        printf("Opcion : ");
        scanf("%i", &opc);

        switch (opc) {
            case 1:
                agendarCita();
                break;
            case 2:
                visualizarCitas();
                break;
            case 3:
                editarCita();
                break;
            case 4:
                eliminarCita();
                break;
        }

    } while (opc != 5);

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// FILE *fd;

// struct cita {
//     char nombre[20];
//     char apellido[20];
//     char email[50];
//     int altura;
//     int peso;
//     int edad;
//     char fecha[10];
//     char hora[5];
//     char doctor[30];
// } cita;

// void agendarCita() {
//     char rpt;
//     fd = fopen("Agenda.txt", "at"); // add text - añadir un texto

//     if (fd == NULL) {
//         printf("Error al tratar de abrir el archivo");
//         return;
//     }

//     printf("\n\t.:Agendando cita médica:.\n");

//     do {
//         fflush(stdin);
//         printf("\nNombre : ");
//         scanf("%s", cita.nombre);
//         printf("Apellido : ");
//         scanf("%s", cita.apellido);
//         printf("Email : ");
//         scanf("%s", cita.email);
//         printf("Altura (cm): ");
//         scanf("%d", &cita.altura);
//         printf("Peso (kg): ");
//         scanf("%d", &cita.peso);
//         printf("Edad : ");
//         scanf("%d", &cita.edad);
//         printf("Fecha de la cita (DD/MM/AAAA): ");
//         scanf("%s", cita.fecha);
//         printf("Hora de la cita (HH:mm): ");
//         scanf("%s", cita.hora);
//         printf("Doctor para la cita : ");
//         scanf("%s", cita.doctor);

//         fprintf(fd, "Nombre : %s\nApellido : %s\nEmail : %s\nAltura : %d\nPeso : %d\nEdad : %d\nFecha de la cita : %s\nHora de la cita : %s\nDoctor para la cita : %s\n\n",
//                 cita.nombre, cita.apellido, cita.email, cita.altura, cita.peso, cita.edad, cita.fecha, cita.hora, cita.doctor);

//         printf("\nDesea agendar más citas (s) : ");
//         scanf(" %c", &rpt);
//     } while (rpt == 's');
//     fclose(fd);
// }

// void visualizarCitas() {
//     int c;
//     fd = fopen("Agenda.txt", "r"); // read text - leer texto

//     if (fd == NULL) {
//         printf("Error al tratar de abrir el archivo");
//         return;
//     }

//     while ((c = fgetc(fd)) != EOF) {
//         putchar(c);
//     }
//     fclose(fd);
// }

// void editarCita() {
//     char nombreEditar[20];
//     fd = fopen("Agenda.txt", "r");

//     if (fd == NULL) {
//         printf("Error al tratar de abrir el archivo");
//         return;
//     }

//     printf("\n\t.:Editar cita médica:.\n");
//     printf("Ingrese el nombre del paciente de la cita a editar: ");
//     scanf("%s", nombreEditar);

//     FILE *tempFd = fopen("temp.txt", "w");

//     while (fscanf(fd, "Nombre : %s\nApellido : %s\nEmail : %s\nAltura : %d\nPeso : %d\nEdad : %d\nFecha de la cita : %s\nHora de la cita : %s\nDoctor para la cita : %s\n\n",
//                   cita.nombre, cita.apellido, cita.email, &cita.altura, &cita.peso, &cita.edad, cita.fecha, cita.hora, cita.doctor) != EOF) {
//         if (strcmp(cita.nombre, nombreEditar) == 0) {
//             printf("Nueva altura para %s: ", cita.nombre);
//             scanf("%d", &cita.altura);
//             printf("Nuevo peso para %s: ", cita.nombre);
//             scanf("%d", &cita.peso);
//             printf("Nueva edad para %s: ", cita.nombre);
//             scanf("%d", &cita.edad);
//             printf("Nueva fecha de la cita para %s (DD/MM/AAAA): ", cita.nombre);
//             scanf("%s", cita.fecha);
//             printf("Nueva hora de la cita para %s (HH:mm): ", cita.nombre);
//             scanf("%s", cita.hora);
//             printf("Nuevo doctor para la cita para %s: ", cita.nombre);
//             scanf("%s", cita.doctor);
//         }
//         fprintf(tempFd, "Nombre : %s\nApellido : %s\nEmail : %s\nAltura : %d\nPeso : %d\nEdad : %d\nFecha de la cita : %s\nHora de la cita : %s\nDoctor para la cita : %s\n\n",
//                 cita.nombre, cita.apellido, cita.email, cita.altura, cita.peso, cita.edad, cita.fecha, cita.hora, cita.doctor);
//     }

//     fclose(fd);
//     fclose(tempFd);

//     remove("Agenda.txt");
//     rename("temp.txt", "Agenda.txt");

//     printf("Cita médica editada exitosamente.\n");
// }

// void eliminarCita() {
//     char nombreEliminar[20];
//     fd = fopen("Agenda.txt", "r");

//     if (fd == NULL) {
//         printf("Error al tratar de abrir el archivo");
//         return;
//     }

//     printf("\n\t.:Eliminar cita médica:.\n");
//     printf("Ingrese el nombre del paciente de la cita a eliminar: ");
//     scanf("%s", nombreEliminar);

//     FILE *tempFd = fopen("temp.txt", "w");
//     int encontrado = 0;

//     while (fscanf(fd, "Nombre : %s\nApellido : %s\nEmail : %s\nAltura : %d\nPeso : %d\nEdad : %d\nFecha de la cita : %s\nHora de la cita : %s\nDoctor para la cita : %s\n\n",
//                   cita.nombre, cita.apellido, cita.email, &cita.altura, &cita.peso, &cita.edad, cita.fecha, cita.hora, cita.doctor) != EOF) {
//         if (strcmp(cita.nombre, nombreEliminar) != 0) {
//             fprintf(tempFd, "Nombre : %s\nApellido : %s\nEmail : %s\nAltura : %d\nPeso : %d\nEdad : %d\nFecha de la cita : %s\nHora de la cita : %s\nDoctor para la cita : %s\n\n",
//                     cita.nombre, cita.apellido, cita.email, cita.altura, cita.peso, cita.edad, cita.fecha, cita.hora, cita.doctor);
//         } else {
//             encontrado = 1;
//         }
//     }

//     fclose(fd);
//     fclose(tempFd);

//     remove("Agenda.txt");
//     rename("temp.txt", "Agenda.txt");

//     if (encontrado) {
//         printf("Cita médica eliminada exitosamente.\n");
//     } else {
//         printf("No se encontró la cita médica con ese nombre.\n");
//     }
// }

// int main() {
//     int opc;
//     do {
//         printf("\n\t.:MENU:.\n");
//         printf("1. Agendar Cita\n");
//         printf("2. Visualizar Citas\n");
//         printf("3. Editar Cita\n");
//         printf("4. Eliminar Cita\n");
//         printf("5. Salir\n");

//         printf("Opcion : ");
//         scanf("%i", &opc);

//         switch (opc) {
//             case 1:
//                 agendarCita();
//                 break;
//             case 2:
//                 visualizarCitas();
//                 break;
//             case 3:
//                 editarCita();
//                 break;
//             case 4:
//                 eliminarCita();
//                 break;
//         }

//     } while (opc != 5);

//     return 0;
// }


