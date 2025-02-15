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
void eliminar_arista();
void vaciar_aristas(Tnodo &);
void mostrar_grafo();
void eliminar_nodo();
void eliminar_aristas_nodo(Tnodo nodo);
void mostrar_aristas();
void mostrar_matriz();

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

///Eliminar aristas
void eliminar_arista(){
    char ini, fin;
    cout << "INGRESE NODO DE INICIO: ";
    cin >> ini;
    cout << "INGRESE NODO FINAL: ";
    cin >> fin;

    Tnodo aux = p;

    // Buscar el nodo de inicio en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == ini) {
            Tarista actual = aux->adyacencia;
            Tarista anterior = NULL;

            // Recorrer la lista
            while (actual != NULL) {
                if (actual->destino->nombre == fin) {
                    // Si la arista es la primera en la lista de adyacencias
                    if (anterior == NULL) {
                        aux->adyacencia = actual->siguiente;
                    } else {
                        anterior->siguiente = actual->siguiente;
                    }
                    delete actual; // Eliminar la arista
                    cout << "ARISTA ELIMINADA CORRECTAMENTE." << endl;
                    return;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
            cout << "LA ARISTA NO EXISTE EN ESTE NODO." << endl;
            return;
        }
        aux = aux->siguiente;
    }
    cout << "NODO INICIO NO ENCONTRADO." << endl;
}

//Vaciar aristas
void vaciar_aristas(Tnodo &aux){
    Tarista q,r;
    q=aux->adyacencia;
    while(q->siguiente!=NULL){
        r=q;
        q=q->siguiente;
        delete(r);
    }
}

///Eliminar nodo
void eliminar_nodo(){
    char nombre;
    cout << "INGRESE EL NODO A ELIMINAR: ";
    cin >> nombre;

    Tnodo aux = p, anterior = NULL;

    // Buscar el nodo en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == nombre) {
            //Eliminar aristas del nodo
            eliminar_aristas_nodo(aux);
            Tarista arista = aux->adyacencia;
            while (arista != NULL) {
                Tarista temp = arista;
                arista = arista->siguiente;
                delete temp;
            }

            //Eliminar el nodo de la lista
            if (anterior == NULL) {
                p = aux->siguiente; //Primer elemento
            } else {
                anterior->siguiente = aux->siguiente;
            }

            delete aux; // Eliminar el nodo
            cout << "NODO ELIMINADO CORRECTAMENTE." << endl;
            return;
        }
        anterior = aux;
        aux = aux->siguiente;
    }
    cout << "NODO NO ENCONTRADO." << endl;
}

///Eliminar aristas de un nodo
void eliminar_aristas_nodo(Tnodo nodo){
    Tnodo aux = p; // Apunta al primer nodo del grafo

    while (aux != NULL) {
        Tarista actual = aux->adyacencia;
        Tarista anterior = NULL;

        while (actual != NULL) {
            if (actual->destino == nodo) {
                //Buscar si la arista es la primera
                if (anterior == NULL) {
                    aux->adyacencia = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual; // Eliminar la arista
                actual = (anterior == NULL) ? aux->adyacencia : anterior->siguiente;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        aux = aux->siguiente;
    }
}

///Mostrar aristas de un nodo
void mostrar_aristas(){
    char nodo;
    cout << "INGRESE EL NODO A CONSULTAR: ";
    cin >> nodo;

    Tnodo aux = p;

    // Buscar el nodo en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == nodo) {
            cout << "NODO " << nodo << " | LISTA DE ADYACENCIA: ";
            
            // Verificar si tiene aristas
            if (aux->adyacencia == NULL) {
                cout << "SIN ARISTAS." << endl;
                return;
            }

            Tarista arista = aux->adyacencia;
            while (arista != NULL) {
                cout << arista->destino->nombre << " ";
                arista = arista->siguiente;
            }
            cout << endl;
            return;
        }
        aux = aux->siguiente;
    }

    cout << "NODO NO ENCONTRADO." << endl;
}

///Mostrar grafo
void mostrar_grafo(){
    Tnodo ptr;
    Tarista arista;
    ptr=p;
    cout<<"NODO|LISTA DE ADYACENCIA\n";
    while(ptr!=NULL){
        cout<<" "<<ptr->nombre<<"|";
        if(ptr->adyacencia!=NULL){
            arista=ptr->adyacencia;
            while(arista!=NULL){
                cout<<" "<<arista->destino->nombre;
                arista=arista->siguiente;
            }

        }
         ptr=ptr->siguiente;
        cout<<endl;
    }
}

///Mostrar matriz
void mostrar_matriz() {
    //Contar nodos y almacenarlos en un arreglo
    int cantidad = 0;
    Tnodo aux = p;
    while(aux != NULL) {
        cantidad++;
        aux = aux->siguiente;
    }
    if(cantidad == 0) {
        cout << "GRAFO VACÍO." << endl;
        return;
    }

    // Crear un arreglo dinámico para almacenar los punteros a nodos
    Tnodo* nodosArray = new Tnodo[cantidad];
    aux = p;
    for (int i = 0; i < cantidad; i++) {
        nodosArray[i] = aux;
        aux = aux->siguiente;
    }

    //Crear e inicializar la matriz de adyacencia
    int **matriz = new int*[cantidad];
    for(int i = 0; i < cantidad; i++){
        matriz[i] = new int[cantidad];
        for(int j = 0; j < cantidad; j++){
            matriz[i][j] = 0;
        }
    }

    //Rellenar la matriz
    for (int i = 0; i < cantidad; i++) {
        Tarista aristaPtr = nodosArray[i]->adyacencia;
        while (aristaPtr != NULL) {
            // Buscar el índice del nodo destino en el arreglo
            int j = 0;
            for (; j < cantidad; j++) {
                if (nodosArray[j] == aristaPtr->destino)
                    break;
            }
            if(j < cantidad)
                matriz[i][j] = 1; // Marca la existencia de la arista
            aristaPtr = aristaPtr->siguiente;
        }
    }

    //Imprimir la matriz de adyacencia
    cout << "\nMATRIZ DE ADYACENCIA:\n\n";
    //Imprimir cabecera (nombres de columnas)
    cout << "     ";
    for (int j = 0; j < cantidad; j++) {
        cout << " " << nodosArray[j]->nombre << " ";
    }
    cout << "\n";

    //Imprimir cada fila
    for (int i = 0; i < cantidad; i++) {
        cout << " " << nodosArray[i]->nombre << "  ";
        for (int j = 0; j < cantidad; j++) {
            cout << " " << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    //Liberar la memoria asignada para la matriz y el arreglo de nodos
    for (int i = 0; i < cantidad; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    delete[] nodosArray;
}

void menu(){
    cout<<"\tGRAFO DIRIGIDO\n\n";
    cout<<"1. INSERTAR NODO"<<endl;
    cout<<"2. INSERTAR ARISTA"<<endl;
    cout<<"3. MOSTRAR GRAFO"<<endl;
    cout<<"4. MOSTRAR ARISTAS DE UN NODO"<<endl;
    cout<<"5. ELIMINAR ARISTA"<<endl;
    cout<<"6. ELIMINAR NODO"<<endl;
    cout<<"7. MOSTRAR MATRIZ"<<endl;
    cout<<"8. SALIR"<<endl;
    cout<<"\nINGRESA OPCION: ";
}


int main(){
    int opcion=0;

    while(opcion!=8){
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
                mostrar_grafo();
                break;
            }
            case 4:{
                mostrar_aristas();
                break;
            }
            case 5:{
                eliminar_arista();
                break;
            }
            case 6:{
                eliminar_nodo();
                break;
            }
            case 7:{
                mostrar_matriz();
                break;
            }
            case 8:{
                cout<<"Que tenga buen dia"<<endl;
                break;
            }
            default:{
                cout<<"Opcion no valida, intenta de nuevo";
                break;
            }
        }
    }
    return 0;
}