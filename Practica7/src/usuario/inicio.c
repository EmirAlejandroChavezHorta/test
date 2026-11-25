#include <usuario.h>

void inicio(Users *users){

	if(!users->cant){
		printf("No hay usuarios registrados.\n");
		return;
	}

	char usuario[32], contra[32];
	printf("\nUsuario:\n");
	fgetsPlus(usuario,32);
	printf("\nContrasena:\n");
	fgetsPlus(contra,32);

	for(int i=0; i<users->cant; i++){
		if( comparar(usuario,users->users[i].username) ){
			if( comparar(contra, users->users[i].password ) ){
				printf("\nInicio exitoso\n");
				return;
			}
			printf("\nUsuario no registrado o contrasena incorrecta\n");
			return;
		}

	}
	printf("\nUsuario no registrado o contrasena incorrecta\n");
	return;

}