#include <stdio.h>
#include <stdlib.h>
#include <usuario.h>

int main(void)
{
	Users users = (Users){NULL,0};
	imprimirUsuarios(&users);
	registro(&users);
	inicio(&users);
    printf("\n\n FIN DE PROGRAMA :)\n\n");
	return 0;
}