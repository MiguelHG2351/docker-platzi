#!/bin/bash

gcc emisor.c -o emisor.out

./emisor.out

gcc ./client.c -o ./cliente.out

./cliente.out

