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

void fgetsPlus(char *cad,int max)
{
	int e = max-2;
	inicializar(cad,max,'\0');
	cad[e] = '\n';

	char *err;
	err = fgets(cad,max,stdin);

	if(err == NULL){
		printf("Error en fgets.\n");
	}

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

