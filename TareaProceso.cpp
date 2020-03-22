#include <iostream>
#include <fstream>
#include <unistd.h>
#include<sys/wait.h>

using namespace std;

void AbrirYLeerArchivo(){

	string textoDeArchivo;
	ifstream archivo;

	archivo.open("ArchivoDePrueba.txt");

	if(archivo.fail()){
		cout<<"No se pudo abrir,"<<endl;
	}

	while(!archivo.eof()){
		getline(archivo, textoDeArchivo);
		cout<<textoDeArchivo<<endl;
	}

}

void ObtenerVariablesEntornoDelSistema(){

	char* path;

	path = getenv ("PATH");

	if (path!=NULL)
		printf ("VARIABLES DEL SISTEMA: %s \n\n",path);
}

void BifurcarProceso(){

	cout<<"El PID del proceso padre es: "<<getpid()<<endl;

	int valorDeRetorno = fork();

	if(valorDeRetorno == 0){

			cout<<"El PID del proceso hijo es: "<<getpid()<<endl;
	}
}

void BloquearProceso(){

	int valorDeRetorno = fork();

	if (valorDeRetorno == 0){

		cout<<"Proceso hijo iniciado"<<endl;

	}else{

		cout<<("Proceso padre")<<endl;
		cout<<"Padre bloqueado, esperando terminacion de hijo"<<endl;
		wait(NULL);
		cout<<("Proceso hijo terminado")<<endl;
		cout<<"padre desbloqueado"<<endl;
	}
}

void DestruirProceso(){

	if (fork()== 0){

		cout<<"Proceso hijo iniciado"<<endl;
		exit(0);
		cout<<"Hola sigo vivo"<<endl;

	}else{

		cout<<("Proceso padre iniciado y esperando a que el hijo sea eliminado...")<<endl;
		wait(NULL);
		cout<<"Prceso hijo destruido"<<endl;
		cout<<("Proceso padre desbloqueado")<<endl;
	}
}

int main() {

	//AbrirYLeerArchivo();

	//ObtenerVariablesEntornoDelSistema();

	//BifurcarProceso();

	//BloquearProceso();

	//DestruirProceso();


	return 0;
}
