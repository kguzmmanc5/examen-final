#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Cola{
	int frente;
	int final;
	int capacidad;
	char *arreglo;
	
};

struct Cola* crearCola(int capacidad){
	
	struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola)); //Reserva del bloque de memoria
	cola->capacidad = capacidad; //Asignamos el tamaño de la cola
	cola->frente = -1; //Inicializamos el valor en el tope de la cola
	cola->final=0;//Inicialiazamos el valor del final de la cola
	cola->arreglo = (char*)malloc(cola->capacidad*sizeof(char)); //Creamos un arreglo que almacenara los datos
	return cola;
}

//FUNCION QUE UTILIZAMOS PARA REVISAR SI LA PILA ESTA VACIA
int vacia(Cola q){
	
	if (q.final==0) 
		return (1);
	
 return(0);
}

//FUNCION QUE DETERMINA SI LA COLA ESTA LLENA
int llena(Cola *q){
	if (q->final==q->capacidad) return (1);
	
 return(0);
}

//INSERTAMOS ELEMENTOS EN LA COLA
void insertar(Cola *q, char *dato){

	q->arreglo[q->final]=*dato;
 	q->final++;
 	
}

//FUNCION QUE UTILIZAMOS PARA ELIMINAR UN ELEMENTO DE LA COLA
string eliminar(Cola *cola){
	
	int i;
	string x;
	
	x=cola->arreglo[0];
	
	for(i=0;i<cola->final-1;i++)
		cola->arreglo[i]=cola->arreglo[i+1];
		
	cola->final--;
	
	return(x);
	
}

//FUNCION PARA MOSTRAR LA INFORMACION DE LA PILA
void imprimir(struct Cola* q){
	
	struct Cola p=*q;
    int i;
    
	if(!vacia(p)){
    	
	    cout<<"\n\tListado de todos los elementos de la cola.\n";
	    for(i=0;i<q->final;i++)
	    	cout<<q->arreglo<<endl;
	}
	else
		printf("\nLa cola se encuentra vacia.\n");
		
}


int main(int argc, char** argv) {
	
	int op;
	int tam;
	char *nombre;
	struct Cola* cola;
	
	do{
		system("cls");
		cout<<"\n\n\t1.- Establecer tamanio del arreglo"<<endl;
		cout<<"\t2.- Funcion QUEUE"<<endl;
		cout<<"\t3.- Funcion ENQUEUE"<<endl;
		cout<<"\t4.- Mostrar COLA"<<endl;
		cout<<"\t5.- Finalizar";
		cout<<"\n\n\tOpcion: ";
		cin>>op;
		
		switch(op){
			case 1: cout<<"\n\tCaptura el tamanio del arreglo: ";
					cin>>tam;
					cola=crearCola(tam); //Creamos la cola
				break;
				
			case 2:	cout<<"\n\tCaptura el nombre a ingresar: ";
			nombre = (char*)malloc(sizeof(char)); //Creamos un arreglo que almacenara los datos
					cin>>nombre;
					insertar(cola, nombre);
					break;
			
			case 3:	cout<<"\n\tEliminamos un elemento de la cola";
					eliminar(cola);
					cout<<"\n\tSe ha eliminado un elemento";
					break;
			
			case 4:	cout<<"\n\tImprimimos los elementos de la cola\n";
					imprimir(cola);
					system("pause");
					break;
			
			case 5:	cout<<"\n\tTermina la ejecucion del programa:";
					break;
			
			default:	cout<<"\n\tOpcion no valida";
					break;

		}
		
	}while(op!=5);
	
	return 0;
}
