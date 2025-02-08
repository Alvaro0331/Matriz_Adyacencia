#include <iostream>

using namespace std;

struct nodo{
    char nombre;//nombre del vertice o nodo
    struct nodo *siguiente;
    struct arista *adyacencia;//puntero - primera arista del nodo
};

struct arista{
    struct nodo *destino;//puntero al nodo llegada
    struct arista *siguiente;
};

typedef struct nodo *Tnodo;// Nodo
typedef struct arista *Tarista; // Arista

Tnodo p;//puntero cabeza

void menu();
void insertar_nodo();

///Insertar nodo
void insertar_nodo(){
    Tnodo t,nuevo=new struct nodo;
    cout<<"INGRESE VARIABLE:";
    cin>>nuevo->nombre;
    nuevo->siguiente = NULL;
    nuevo->adyacencia=NULL;
    if(p==NULL){
        p = nuevo;
        cout<<"PRIMER NODO";
    }else {
        t = p;
        while(t->siguiente!=NULL){
        t = t->siguiente;
        }   
    t->siguiente = nuevo;
    cout<<"NODO INGRESADO";
    }
}

void menu(){
    cout<<"\tGRAFO DIRIGIDO\n\n";
    cout<<"1. INSERTAR NODO"<<endl;
    cout<<"2. INSERTAR ARISTA"<<endl;
    cout<<"3. MOSTRAR GRAFO"<<endl;
    cout<<"4. MOSTRAR MATRIZ"<<endl;
    cout<<"7. SALIR"<<endl;
    cout<<"\nINGRESA OPCION: ";
}


int main(){
    int opcion=0;

    while(opcion!=7){
        menu();
        cout.flush();
        cin>>opcion;
        switch(opcion){
            case 1:{
                insertar_nodo();
                break;
            }
            case 2:{
                cout<<"Opcion 2";
                break;
            }
            case 3:{
                cout<<"Opcion 3";
                break;
            }
            case 4:{
                cout<<"Opcion 4";
                break;
            }
            case 7:{
                cout<<"Que tenga buen dia";
                break;
            }
            default:{
                cout<<"Opcion no valida, intenta de nuevo";
                break;
            }
            system("pause");
            system("cls");
        }
    }
    system("pause");
    return 0;
}