/* Aplicación de gráficas dirigidas para encontrar ciudades comunicadas
➥entre sí por el sistema ferroviario, así como los costos mínimos para
➥ir de una ciudad a las otras o entre todas las ciudades. */

/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/

#include "DiGrafo.h"

int Menu()
{
    int Opc;
    do {
    cout<<"\t\tMENU - SISTEMA FERROVIARIO\n\n";
    cout<<"(0) INGRESA DATOS E IMPRIMIR MATRIZ DE ADYACENCIA";
    cout<<"\n(1) CIUDADES QUE SE COMUNICAN ENTRE SI";
    cout<<"\n(2) MINIMO COSTO ENTRE LAS CIUDADES";
    cout<<"\n(3) MINIMO COSTO ENTRE TODAS LAS CIUDADES Y CIUDADES INTERMEDIAS";
    cout<<"\n(4) MINIMO COSTO ENTRE UNA CIUDAD Y LAS OTRAS";
    cout<<"\n(5) FINALIZAR EL PROECESO"; 
    
    cout<<"\n\nDIGITE UNA OPCION: ";
    
    cin>>Opc;

    system("cls");

    } while (Opc < 0 || Opc > 5);

    return Opc;
}

int main()
{
    system("cls");
    system("color F4");
    
    DiGrafica<int> RedFerrov;
    int Opc;

    do {
        Opc= Menu();
            switch (Opc)
            {
                case 0: cout<<"\tINGRESE DATOS DE CUIDADES Y COSTOS DE PASAJES";

                        RedFerrov.Lee();
                        RedFerrov.Imprime(0);//Imprimir la matriz de adyacencias o costos
                        
                        cout<<endl<<endl;
                        system("pause"); system("cls");
                        
                        break;

                /* El método Warshall permite encontrar todas las ciudades que
                ➥están comunicadas entre sí por medio de la red ferroviaria. */
                case 1: {
                        cout<<"\t\t\tCIUDADES QUE SE COMUNICAN ENTRE SI"<<endl<<endl;

                        RedFerrov.Warshall();
                        RedFerrov.Imprime(1);

                        cout<<endl<<endl;
                        system("pause"); system("cls");

                        break;
                }

                /* El método Floyd permite encontrar los costos mínimos para
                ➥visitar a todas las ciudades que están comunicadas entre sí
                ➥por medio de la red ferroviaria. */
                case 2: {
                        cout<<"\t\t\tMINIMO COSTO ENTRE LAS CIUDADES"<<endl<<endl;

                        RedFerrov.Floyd();
                        RedFerrov.Imprime(2);

                        cout<<endl<<endl;
                        system("pause"); system("cls");

                        break;
                }

                /* El método FloydVerInt permite encontrar los costos mínimos
                ➥para visitar todas las ciudades que están comunicadas entre
                ➥sí por medio de la red ferroviaria y las ciudades intermedias
                ➥(cuando no existe camino directo, o si éste no fuera el de
                ➥costo mínimo). */
                case 3: {
                        cout<<"\t\tMINIMO COSTO ENTRE TODAS LAS CIUDADES Y CIUDADES INTERMEDIAS"<<endl<<endl;

                        RedFerrov.FloydVerInt();
                        RedFerrov.Imprime(3);

                        cout<<endl<<endl;
                        system("pause"); system("cls");

                        break;
                }
                /* El método Dijkstra permite encontrar los costos mínimos
                ➥para ir de una ciudad a todas las otras ciudades con las que
                ➥está comunicada por medio de la red ferroviaria. */
                case 4: {
                        cout<<"\t\t\tMINIMO COSTO ENTRE UNA CIUDAD Y LAS OTRAS"<<endl<<endl;

                        RedFerrov.Dijkstra();
                        RedFerrov.Imprime(4);

                        cout<<endl<<endl;
                        system("pause"); system("cls");

                        break;
                }
        }
        // cout<<endl<<endl;
        // system("pause"); system("cls");

    } while (Opc < 5 && Opc >= 0);

    return 0;
}