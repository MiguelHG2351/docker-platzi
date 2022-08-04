# Docker (Platzi)

Curso de Platzi de Docker

## Los 3 grandes problemas del desarrollo de software

Cuando creamos software normalmente podemos tener ciertos problemas al crear software

### Cuando construimos software

- Entorno de desarrollo: 

- Dependencias: Dependencias, Frameworks y que funcione de la misma manera

- Entorno de ejecución: Que versión de Node, etc

- Equivalencia con entorno productivo: Si estas programando en Windows pero vas a subirlo a un servidor Linux.

- Servicios externos: Tener la misma versión de una db externa.

### Cuando distribuimos software

- Acceso a los servidores de producción

- Disponibilidad de servicios externos

### Problemas al ejecutar

- Compatibilidad de OS.

- Recursos de hardware

## Virtualización

Permite solucionar los 3 problemas del software. En Docker se piensa que aunque puede solucionarse con VM puede hacerse mejor

### Problemas con VM

1. El inicio es muy lento por motivos de peso como OS

2. Requiere más administración

3. Múltiples formatos de VMs, dependiendo del proveedor puede tener cierto formato disponible

## Contenedores

Una forma de transportar software, algunas de sus ventajas pueden ser:

- Flexibles: Cualquier app puedes meter en un contenedor

- Livianos: Reutilizar el kernel y código del OS y solo empaquetar el código y no el OS

- Portables: Capacidad de correr en cualquier maquina

- Bajo acoplamiento: Tiene todo lo que necesita sin importarle lo que este en el OS

- Son escalables: Si necesitas más ancho de banda o más clientes es fácil crear muchos clientes

- Seguros: Solo puede acceder a lo que necesita, no a otros contenedores, máquina anfitriona, etc.

## Instalación de Docker

## Hoja de comandos del CLI de Docker

[Imagen con comandos de Docker](./readme_files/cheatsheet.webp)

