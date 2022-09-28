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

    struct message msg01 = {1, "Primer mensaje"};
    lenmsg = strlen(msg01.texto);

    // aqui se crea la cola de mensajes
    if((id01=msgget(LLAVE, IPC_CREAT | 0600)) == -1) perror("error mssget");
    // aqui se envia el mensaje
    if(msgsnd(id01, &msg01, lenmsg, 0) == -1) perror('msgsnd error');

    // el strcpy es para copiar el mensaje en el buffer
    strcpy(msg01.texto, "Segundo mensaje");
    // strlen es para obtener la longitud del mensaje
    lenmsg = strlen(msg01.texto);

    // aqui se envia el mensaje
    if(msgsnd(id01, &msg01, lenmsg, 0) == -1) perror('msgsnd error');


    // en pocas palabras, el msgsnd envia: "Primer mensaje"
    // y el "Segundo mensaje" se envia en el segundo msgsnd
}
