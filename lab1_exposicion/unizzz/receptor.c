#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

// Este programa es el receptor de mensajes

#define LLAVE 34856 // Llave para la cola de mensajes
#define MAXIMO 100 // Tamaño máximo del mensaje

struct message
{
    long tipo; // Tipo de mensaje
    char texto[MAXIMO]; // Texto del mensaje
};

void main()
{
    key_t llave01; // Llave para la cola de mensajes
    int id01; // Identificador de la cola de mensajes
    unsigned int lenmsg; // Tamaño del mensaje

    struct message msg01;

    // for(int i= 0; i<MAXIMO; i++)
    //     msg01.texto[i] = ' ';

    // Aquí se abre la cola de mensajes del cliente
    if ((id01 = msgget(LLAVE, IPC_CREAT | 0600)) == -1)
        perror("error mssget");

    while (strcmp(msg01.texto, "salir"))
    {
        // Recibe el mensaje
        if (msgrcv(id01, &msg01, MAXIMO, 1, 0) == -1)
            perror("msgrcv error");

        lenmsg = strlen(msg01.texto);
        msg01.texto[lenmsg] = '\0';

        // Imprime el mensaje
        printf("\n%s\n\n", msg01.texto, strlen(msg01.texto));
    }
    if (msgctl(id01, IPC_RMID, NULL) == -1)
        perror("msgctl error");
}
