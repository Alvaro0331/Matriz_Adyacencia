#include <iostream>

using namespace std;

void menu();

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
                cout<<"Opcion 1";
                system("pause");
                system("cls");
                break;
            }
            case 2:{
                cout<<"Opcion 2";
                system("pause");
                system("cls");
                break;
            }
            case 3:{
                cout<<"Opcion 3";
                system("pause");
                system("cls");
                break;
            }
            case 4:{
                cout<<"Opcion 4";
                system("pause");
                system("cls");
                break;
            }
            case 7:{
                cout<<"Que tenga buen dia";
                system("pause");
                system("cls");
                break;
            }
            default:{
                cout<<"Opcion no valida, intenta de nuevo";
                system("pause");
                system("cls");
                break;
            }
        }
    }
    system("pause");
    return 0;
}