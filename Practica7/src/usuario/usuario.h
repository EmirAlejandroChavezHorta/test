#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char username[32];
	char password[32];
}User;

typedef struct
{
	User *users;
	int cant;
}Users;

void imprimirUsuario(User user);
void imprimirUsuarios(Users *users);
void registro(Users *users);
void inicio(Users *users);

#define USUARIOS_MAX 5

void limpiarBuffer();
void fgetsPlus(char *cad,int max);
void inicializar(char *cad,int max,char c);
int buscarC(char *cad,char c);
void removerEnter(char *cad);
int comparar(char *cadA,char *cadB);

#endif