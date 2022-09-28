#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define LLAVE 34856
#define MAXIMO 100

struct message
{
    long tipo;
    char texto[MAXIMO];
};

void main()
{
    key_t llave01;
    int id01;
    unsigned int lenmsg;

    struct message msg01;
    msg01.tipo = 1;

    printf("Emisor de mensajes, digite \"salir\" para terminar el progama: ");

    // basicamente te pide palabras que le llegaran al receptor y luego al cliente
    // si escribis salir al ejecutar emisor se terminan todos los programas como receptor y client
    while(strcmp(msg01.texto, "salir"))
    {
        printf("\nIngrese su mensaje (Max 100 caracteres, sin espacios): ");
        // fflush ayuda a que se envie el mensaje en el standar input o sea a la consola
        fflush(stdin);
        scanf("%100s", msg01.texto);
        lenmsg = strlen(msg01.texto);

        // cualquier mensaje que sea distinto a salir se envia al receptor
        if((id01=msgget(LLAVE, 0600 | IPC_CREAT)) == -1) perror("error mssget");
        if(msgsnd(id01, &msg01, (lenmsg + 1), 0) == -1) perror("msgsnd error");
    }

}
