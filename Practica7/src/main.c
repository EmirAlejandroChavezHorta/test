#include <stdio.h>
#include <stdlib.h>
#include <usuario.h>

int main(void)
{

	Users users = (Users){NULL,0};
	int input, err;
	do{

		imprimirUsuarios(&users);
		printf("\n1.-Iniciar usuario. 2.-Registrar usuario. 3.-Terminar programa.\n");
		err = scanf("%i",&input);
		limpiarBuffer();

		if(err!=1){
			printf("Error en la lectura de entrada %i %i.\n", err, input);
		}
		else{
			switch(input){

				case 1:
					inicio(&users);
					break;
				case 2:
					registro(&users);

			}
		}

	}while(input!=3);

	free(users.users);

    printf("\n\n FIN DE PROGRAMA :)\n\n");
	return 0;
}