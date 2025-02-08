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
void agregar_aristas(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();

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

///Agregar aristas
void agregar_aristas(Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
    Tarista q;
    if(aux->adyacencia==NULL){
        aux->adyacencia=nuevo;
        nuevo->destino=aux2;
        cout<<"PRIMERA ARISTA";
    }
    else{
        q=aux->adyacencia;
        while(q->siguiente!=NULL)
            q=q->siguiente;
        nuevo->destino=aux2;
        q->siguiente=nuevo;
        cout<<"ARISTA AGREGADA";
    }
}

///Insertar aristas
void insertar_arista(){
    char ini, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;
    if(p==NULL) { cout<<"GRAFO VACIO"; return;}
    nuevo->siguiente=NULL;
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL){
        if(aux2->nombre==fin) { break;}
        aux2=aux2->siguiente;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            agregar_aristas(aux,aux2, nuevo);
            return;
        }
        aux = aux->siguiente;
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
                insertar_arista();
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