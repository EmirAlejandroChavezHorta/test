#include <usuario.h>

void registro(Users *users)
{
	if(users->cant <=USUARIOS_MAX){
		users->cant++;
		
		if(users->cant == 1){
			users->users = calloc(1,sizeof(User));
		}
		else{
			void *aux = NULL;
			
			do{
				aux = realloc(users->users, sizeof(User) * users->cant );
			}while(aux == NULL);

			users->users = aux;
		}

		users->users[users->cant-1].username[0] = '\0';

		char nombre[32];

		do{
			printf("\nIntroduce tu usuario:\n");
			fgetsPlus(nombre,32);

			for(int i=0; i<users->cant; i++){
				if( comparar( nombre, users->users[i].username) ){
					printf("\nEse nombre de usuario ya esta en uso.\n");
					break;
				}
				if(i==users->cant-1){  strcpy( users->users[users->cant -1 ].username, nombre ); }
			}

		}while(users->users[users->cant -1].username[0] == '\0');


		if( users->users[users->cant -1].username[0] != '\0'){
			char contra[32];

			printf("\nIntroduce tu contrasena:\n");
			fgetsPlus(contra,32);

			strcpy(users->users[users->cant -1].password,contra);
		}

	}
	else{
		printf("\nNo hay cupo para nuevos usuarios.\n");
	}

}
