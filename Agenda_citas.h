//Agendas_citas.h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

FILE *agenda;
struct datosPersona{
  char nombre[22];
  char apellido[20];
  char email[30];
  char altura[20];
  char peso[20];
  char edad[10];
  char fecha[10];
  char hora[10];
}datos;

int cont=1;

void agendar_cita() {
  char adrdressfile[] ="Agenda.txt";
  char rpt;
  
  agenda = fopen("Agenda.txt","at"); //Apertura del archivo
  if(agenda == NULL){
    printf("Error al localizar el archivo\n");
    return 1;
  }
    printf("\t Agregando datos al archivo de texto\n");

  do{
    
    printf("\t Cita #%i\n", cont);
    fflush(stdin);
    printf("\n Nombre :"), gets(datos.nombre);
    printf("\n Apellido :"), gets(datos.apellido);
    printf("\n Email :");gets(datos.email);
    printf("\n Altura :"),gets(datos.altura);
    printf("\n Peso :"), gets(datos.peso);
    printf("\n Edad :"), gets(datos.edad);
    printf("\n Fecha para la cita medica :"), gets(datos.fecha);
    printf("\n Hora para la cita medica :"), gets(datos.hora);

    fprintf(agenda, "\n\n Cita #%i", cont); //Escribe el número de la cita según el contador

    fprintf(agenda,"\n Nombre :");
    fwrite(datos.nombre,1,strlen(datos.nombre),agenda);

    fprintf(agenda,"\n Apellido :");
    fwrite(datos.apellido,1,strlen(datos.apellido),agenda);

    fprintf(agenda,"\n Email :");
    fwrite(datos.email,1,strlen(datos.email),agenda);

    fprintf(agenda, "\n Altura:");
    fwrite(datos.altura,1,strlen(datos.altura),agenda);

    fprintf(agenda, "\n Peso:");
    fwrite(datos.peso,1,strlen(datos.peso),agenda);

    fprintf(agenda, "\n Edad:");
    fwrite(datos.edad,1,strlen(datos.edad),agenda);

    fprintf(agenda, "\n Fecha:");
    fwrite(datos.fecha,1,strlen(datos.fecha),agenda);

    fprintf(agenda, "\n Hora:");
    fwrite(datos.hora,1,strlen(datos.hora),agenda);

    printf("Continuar (si-s || No - n)");
    scanf("%c",&rpt);
    
    cont +=1;
    
  }while(rpt=='s');
  
  fclose(agenda);
}

void editar_cita() {
  int numeroCita;
  FILE *tempFile;
  char tempFileName[] = "TempAgenda.txt";
  int citaEncontrada = 0;

  // Solicita al usuario ingresar el número de la cita a editar
  printf("Ingrese el número de la cita que desea editar: ");
  scanf("%d", &numeroCita);

  // Abre el archivo original en modo de lectura
  agenda = fopen("Agenda.txt", "rt");

  // Verifica si el archivo original se pudo abrir
  if (agenda == NULL) {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Abre un archivo temporal en modo de escritura
  tempFile = fopen(tempFileName, "wt");

  // Verifica si el archivo temporal se pudo abrir
  if (tempFile == NULL) {
    printf("Error al abrir el archivo temporal\n");
    fclose(agenda);
    return;
  }

  // Recorre el archivo original
  while (fscanf(agenda, "\n\n Cita #%*i") == 1) {
    // Encuentra la cita deseada
    if (numeroCita == fscanf(agenda, "%d", &numeroCita)) {
      // Marca que la cita ha sido encontrada
      citaEncontrada = 1;

      // Muestra los datos actuales y permite editarlos
      printf("\n Datos Actuales de la Cita #%d:", numeroCita);
      printf("\n Nombre : %s", datos.nombre);
      printf("\n Apellido : %s", datos.apellido);
      // ... (mostrar otros datos)

      // Solicita la edición de datos
      printf("\n\n Ingrese los nuevos datos para la cita:\n");
      fflush(stdin);
      printf("\n Nombre :"); gets(datos.nombre);
      printf("\n Apellido :"); gets(datos.apellido);
      // ... (solicitar otros datos)

      // Escribe los nuevos datos en el archivo temporal
      fprintf(tempFile, "\n\n Cita #%d", numeroCita);
      fprintf(tempFile,"\n\n Nombre : %s", datos.nombre);
      fprintf(tempFile,"\n Apellido : %s", datos.apellido);
      // ... (escribir otros datos)
    } else {
      // Si no es la cita deseada, copia la información tal como está en el archivo temporal
      char buffer[1024];
      fgets(buffer, sizeof(buffer), agenda);
      fprintf(tempFile, "%s", buffer);
    }
  }

  // Cierra los archivos
  fclose(agenda);
  fclose(tempFile);

  // Renombra el archivo temporal al archivo original
  remove("Agenda.txt");
  rename(tempFileName, "Agenda.txt");

  // Informa si la cita fue encontrada o no
  if (citaEncontrada) {
    printf("\n Cita #%d editada exitosamente.\n", numeroCita);
  } else {
    printf("\n Cita #%d no encontrada.\n", numeroCita);
  }
}

void eliminar_cita() {
  int numeroCita;
  FILE *tempFile;
  char tempFileName[] = "TempAgenda.txt";
  int citaEliminada = 0;

  // Solicita al usuario ingresar el número de la cita a eliminar
  printf("Ingrese el número de la cita que desea eliminar: ");
  scanf("%d", &numeroCita);

  // Abre el archivo original en modo de lectura
  agenda = fopen("Agenda.txt", "rt");

  // Verifica si el archivo original se pudo abrir
  if (agenda == NULL) {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Abre un archivo temporal en modo de escritura
  tempFile = fopen(tempFileName, "wt");

  // Verifica si el archivo temporal se pudo abrir
  if (tempFile == NULL) {
    printf("Error al abrir el archivo temporal\n");
    fclose(agenda);
    return;
  }

  // Recorre el archivo original
  while (fscanf(agenda, "\n\n Cita #%d", &numeroCita) == 1) {
    if (numeroCita == numeroCita) {
      // Si es la cita que se desea eliminar, marca que fue eliminada y salta al siguiente bloque
      citaEliminada = 1;
      printf("\n Cita #%d encontrada y marcada para eliminación.\n", numeroCita);

      // Salta al siguiente bloque en lugar de copiarlo al archivo temporal
      while (fgetc(agenda) != '\n') {
        continue;
      }
    } else {
      // Si no es la cita deseada, copia la información tal como está en el archivo temporal
      char buffer[1024];
      fgets(buffer, sizeof(buffer), agenda);
      fprintf(tempFile, "%s", buffer);
    }
  }

  // Cierra los archivos
  fclose(agenda);
  fclose(tempFile);

  // Renombra el archivo temporal al archivo original
  remove("Agenda.txt");
  rename(tempFileName, "Agenda.txt");

  // Informa si la cita fue encontrada y eliminada o no
  if (citaEliminada) {
    printf("\n Cita #%d eliminada exitosamente.\n", numeroCita);
  } else {
    printf("\n Cita #%d no encontrada.\n", numeroCita);
  }
}

void mostrar_citas() {
  int numeroCita;
  bool hayCitas = false;

  // Abre el archivo en modo de lectura
  agenda = fopen("Agenda.txt", "rt");

  // Verifica si el archivo se pudo abrir
  if (agenda == NULL) {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Muestra todas las citas
  while (fscanf(agenda, "\n\n Cita #%d", &numeroCita) == 1) {
    printf("\n\n Cita #%d", numeroCita);
    // ... (mostrar otros datos)
    hayCitas = true;
  }

  // Cierra el archivo
  fclose(agenda);

  // Informa si no hay citas
  if (!hayCitas) {
    printf("\n No hay citas almacenadas.\n");
  }
}