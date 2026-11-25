#include <stdio.h>
#include <string.h>

void limpiarBuffer();
void fgetsPlus(char *cad,int max);
void inicializar(char *cad,int max,char c);
int buscarC(char *cad,char c);
void removerEnter(char *cad);


typedef struct
{
	char username[32];
	char password[32];
}User;

int comparar(char *cadA,char *cadB);
void RegistrarUsuario(User *users);
void IniciarSesion(User *users);

int main(){

	User users[5];
	for(int i=0;i<5;i++){
		users[i].username[0] = '\0';
		users[i].password[0] = '\0';
	}

	int input;

	do{

		printf("\n1.-Iniciar Sesion. 2.-Registrar Usuario. 3.-Terminar Programa.\n");
		scanf("%i",&input);
		limpiarBuffer();

		switch(input){
			case 1:
				IniciarSesion(users);
				break;
			case 2:
				RegistrarUsuario(users);
				break;
		}

	}while(input!=3);

	return 0;
}

int comparar(char *cadA,char *cadB)
{

	int i;
	for(i=0; cadA[i]!='\0'||cadB[i]!='\0'; i++ ){
		if(cadA[i]!=cadB[i]){return 0;}
	}

	if(cadA[i] == cadB[i] )
	{ return 1; }
	else{ return 0; }

}

void RegistrarUsuario(User *users){

	int ind=-1;
	for(int i=0;i<5;i++){
		if(users[i].username[0]=='\0'){
			ind=i;
			break;
		}
	}

	if(ind != -1){

		char nombre[32];

		do{
			printf("\nIntroduce tu usuario:\n");
			fgetsPlus(nombre,32);

			for(int i=0; i<5; i++){
				if( comparar( nombre, users[i].username) ){
					printf("\nEse nombre de usuario ya esta en uso.\n");
					break;
				}
				if(i==4){  strcpy( users[ind].username, nombre ); }
			}

		}while(users[ind].username[0] == '\0');


		if( users[ind].username[0] != '\0'){
			char contra[32];
			printf("\nIntroduce tu contrasena:\n");
			fgetsPlus(contra,32);
			strcpy(users[ind].password,contra);
		}



	}
	else{
		printf("\nNo hay cupo para nuevos usuarios.\n");
	}

}

void IniciarSesion(User *users){

	for(int i=0; i<5; i++){

		if(users[i].username[0] != '\0'){ break; }

		if(i==4){
			printf("\nNo hay usuarios registrados\n"); 
			return;
		}

	}

	char usuario[32], contra[32];
	printf("\nUsuario:\n");
	fgetsPlus(usuario,32);
	printf("\nContrasena:\n");
	fgetsPlus(contra,32);

	for(int i=0; i<5; i++){
		if( comparar(usuario,users[i].username) ){
			if( comparar(contra, users[i].password ) ){
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



void fgetsPlus(char *cad,int max)
{
	int e = max-2;
	inicializar(cad,max,'\0');
	cad[e] = '\n';
	fgets(cad,max,stdin);
	if(cad[e]!='\n' && buscarC(cad,'\n')==0)
		limpiarBuffer();
	else
		removerEnter(cad);
}

void inicializar(char *cad,int max,char c)
{
	for(int i = 0; i < max; i++)
		cad[i] = c;
}

int buscarC(char *cad,char c)
{
	int i = 0;
	while(cad[i] != '\0')
	{
		if(cad[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void removerEnter(char *cad)
{
	int i = 0;
	while(cad[i]!='\0')
	{
		if(cad[i]=='\n')
		{
			cad[i] = '\0';
			break;
		}
		i++;
	}
}

void limpiarBuffer(void)
{
	char c;
	while( (c=getchar())!='\n' && c!=EOF);
}
