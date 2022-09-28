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

    while(strcmp(msg01.texto, "salir"))
    {
        gets(msg01.texto);
        lenmsg = strlen(msg01.texto);

        if((id01=msgget(LLAVE, 0600 | IPC_CREAT)) == -1) perror("error mssget");
        if(msgsnd(id01, &msg01, lenmsg, 0) == -1) perror("msgsnd error");

        if(strcmp(msg01.texto, "salir") == 0) break;
    }
    while(strcmp(msg01.texto, "salir"))
    {
        gets(msg01.texto);
        lenmsg = strlen(msg01.texto);

        if((id01=msgget(LLAVE, 0600 | IPC_CREAT)) == -1) perror("error mssget");
        if(msgsnd(id01, &msg01, lenmsg, 0) == -1) perror("msgsnd error");

        if(strcmp(msg01.texto, "salir") == 0) break;
    }

}


        // if((id01=msgget(LLAVE, 0600 | IPC_CREAT)) == -1) perror("error mssget");
        // if(msgsnd(id01, &msg01, lenmsg, 0) == -1) perror("msgsnd error");

// while(strcmp(msg01.texto, "salir"))
//     {
//         if(msgrcv(id01, &msg01, MAXIMO, 1, 0) == -1) perror("msgrcv error");

//         lenmsg = strlen(msg01.texto);
//         msg01.texto[lenmsg] = '\0';

//         printf("\n%s\n\n", msg01.texto, strlen(msg01.texto));
//     }