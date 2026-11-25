#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>

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



#endif