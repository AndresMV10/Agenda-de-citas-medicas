#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fd;

struct Cita {
    char cedula[15];
    char nombre[20];
    char apellido[20];
    char email[50];
    int altura;
    int peso;
    int edad;
    char fecha[11];  // Aumenté un espacio para incluir el carácter nulo '\0'
    char hora[6];    // Aumenté un espacio para incluir el carácter nulo '\0'
    char doctor[30];
};

void agendarCita() {
    char rpt;
    fd = fopen("Agenda.txt", "at");

    if (fd == NULL) {
        printf("Error al tratar de abrir el archivo");
        return;
    }

    printf("\n\t.:Agendando cita médica:.\n");

    do {
        struct Cita nuevaCita;

        fflush(stdin);
        printf("\nCédula: ");
        scanf("%s", nuevaCita.cedula);

        printf("Nombre: ");
        scanf("%s", nuevaCita.nombre);

        printf("Apellido: ");
        scanf("%s", nuevaCita.apellido);

        printf("Email: ");
        scanf("%s", nuevaCita.email);

        printf("Altura (cm): ");
        scanf("%d", &nuevaCita.altura);

        printf("Peso (kg): ");
        scanf("%d", &nuevaCita.peso);

        printf("Edad: ");
        scanf("%d", &nuevaCita.edad);

        printf("Fecha de la cita (DD/MM/AAAA): ");
        scanf("%s", nuevaCita.fecha);

        printf("Hora de la cita (HH:mm): ");
        scanf("%s", nuevaCita.hora);

        printf("Doctor para la cita: ");
        scanf("%s", nuevaCita.doctor);

        fprintf(fd, "Cédula: %s\nNombre: %s\nApellido: %s\nEmail: %s\nAltura: %d\nPeso: %d\nEdad: %d\nFecha de la cita: %s\nHora de la cita: %s\nDoctor para la cita: %s\n\n",
                nuevaCita.cedula, nuevaCita.nombre, nuevaCita.apellido, nuevaCita.email,
                nuevaCita.altura, nuevaCita.peso, nuevaCita.edad, nuevaCita.fecha,
                nuevaCita.hora, nuevaCita.doctor);

        printf("\nDesea agendar más citas (s): ");
        scanf(" %c", &rpt);
    } while (rpt == 's');

    fclose(fd);
}

void visualizarCitas() {
    int c;
    fd = fopen("Agenda.txt", "r");

    if (fd == NULL) {
        printf("Error al tratar de abrir el archivo");
        return;
    }

    while ((c = fgetc(fd)) != EOF) {
        putchar(c);
    }

    fclose(fd);
}

void editarCita() {
    char cedulaEditar[15];
    struct Cita cita; // Declaración de la variable "cita"

    fd = fopen("Agenda.txt", "r");

    if (fd == NULL) {
        printf("Error al tratar de abrir el archivo");
        return;
    }

    printf("\n\t.:Editar cita médica:.\n");
    printf("Ingrese la cédula del paciente de la cita a editar: ");
    scanf("%s", cedulaEditar);

    FILE *tempFd = fopen("temp.txt", "w");
    int encontrado = 0;

    while (fscanf(fd, "Cédula: %s\nNombre: %s\nApellido: %s\nEmail: %s\nAltura: %d\nPeso: %d\nEdad: %d\nFecha de la cita: %s\nHora de la cita: %s\nDoctor para la cita: %s\n\n",
        cita.cedula, cita.nombre, cita.apellido, cita.email, &cita.altura,
        &cita.peso, &cita.edad, cita.fecha, cita.hora, cita.doctor) != EOF) {
        if (strcmp(cita.cedula, cedulaEditar) == 0) {
            printf("Nueva altura para %s: ", cita.nombre);
            scanf("%d", &cita.altura);

            printf("Nuevo peso para %s: ", cita.nombre);
            scanf("%d", &cita.peso);

            printf("Nueva edad para %s: ", cita.nombre);
            scanf("%d", &cita.edad);

            printf("Nueva fecha de la cita para %s (DD/MM/AAAA): ", cita.nombre);
            scanf("%s", cita.fecha);

            printf("Nueva hora de la cita para %s (HH:mm): ", cita.nombre);
            scanf("%s", cita.hora);

            printf("Nuevo doctor para la cita para %s: ", cita.nombre);
            scanf("%s", cita.doctor);

            encontrado = 1;
        }

        fprintf(tempFd, "Cédula: %s\nNombre: %s\nApellido: %s\nEmail: %s\nAltura: %d\nPeso: %d\nEdad: %d\nFecha de la cita: %s\nHora de la cita: %s\nDoctor para la cita: %s\n\n",
                cita.cedula, cita.nombre, cita.apellido, cita.email, cita.altura,
                cita.peso, cita.edad, cita.fecha, cita.hora, cita.doctor);
    }

    fclose(fd);
    fclose(tempFd);

    remove("Agenda.txt");
    rename("temp.txt", "Agenda.txt");

    if (encontrado) {
        printf("Cita médica editada exitosamente.\n");
    } else {
        printf("No se encontró la cita médica con esa cédula.\n");
    }
}

void eliminarCita() {
    char cedulaEliminar[15];
    struct Cita cita; // Declaración de la variable "cita"

    fd = fopen("Agenda.txt", "r");

    if (fd == NULL) {
        printf("Error al tratar de abrir el archivo");
        return;
    }

    printf("\n\t.:Eliminar cita médica:.\n");
    printf("Ingrese la cédula del paciente de la cita a eliminar: ");
    scanf("%s", cedulaEliminar);

    FILE *tempFd = fopen("temp.txt", "w");
    int encontrado = 0;

    while (fscanf(fd, "Cédula: %s\nNombre: %s\nApellido: %s\nEmail: %s\nAltura: %d\nPeso: %d\nEdad: %d\nFecha de la cita: %s\nHora de la cita: %s\nDoctor para la cita: %s\n\n",
                  cita.cedula, cita.nombre, cita.apellido, cita.email, &cita.altura,
                  &cita.peso, &cita.edad, cita.fecha, cita.hora, cita.doctor) != EOF) {
        if (strcmp(cita.cedula, cedulaEliminar) != 0) {
            fprintf(tempFd, "Cédula: %s\nNombre: %s\nApellido: %s\nEmail: %s\nAltura: %d\nPeso: %d\nEdad: %d\nFecha de la cita: %s\nHora de la cita: %s\nDoctor para la cita: %s\n\n",
                    cita.cedula, cita.nombre, cita.apellido, cita.email, cita.altura,
                    cita.peso, cita.edad, cita.fecha, cita.hora, cita.doctor);
        } else {
            encontrado = 1;
        }
    }

    fclose(fd);
    fclose(tempFd);

    remove("Agenda.txt");
    rename("temp.txt", "Agenda.txt");

    if (encontrado) {
        printf("Cita médica eliminada exitosamente.\n");
    } else {
        printf("No se encontró la cita médica con esa cédula.\n");
    }
}
