#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define LLAVE 34856
#define MAXIMO 100

struct message {
    long tipo;
    char texto[MAXIMO];
};

void main() {
    key_t llave01;
    int id01;
    unsigned int lenmsg;

    struct message msg01;

    // aqui se crea la cola de mensajes
    if((id01=msgget(LLAVE, IPC_CREAT | 0600 )) == -1) perror('error mssget');
    // con msgrcv se recibe el mensaje
    if(msgrcv(id01, &msg01, MAXIMO, 1, 0) == -1) perror('msgrcv error');

    lenmsg = strlen(msg01.texto);
    msg01.texto[lenmsg] = '\0';

    // aqui se imprime el mensaje
    printf("\n%s\n\n", msg01.texto, strlen(msg01.texto));

    // con msgctl se destruye la cola de mensajes
    if(msgctl(id01, IPC_RMID, NULL) == -1) perror('msgctl error');
}
