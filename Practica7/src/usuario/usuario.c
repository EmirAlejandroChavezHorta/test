#include <usuario.h>

void imprimirUsuario(User user)
{
	printf("\n Username: %s",user.username);
	printf("\n Password: %s",user.password);
}

void imprimirUsuarios(Users *users)
{
	printf("\n USUARIOS: ");
	for(int i = 0; i < users->cant ; i++)
	{
		printf("\n [%d]Usuario",i);
		imprimirUsuario(users->users[i]);
	}
}