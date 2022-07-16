#include "ayudas.h"

void sillas(bool **puestos)
{
    //FUNCIONAMIENTO
    //coloca en la consola la tabla para saber que asientos
    //estan ocupados si es true pone un "+" si es false "~"

    //VARIABLES
    //letra= va cambiando la letra desde la A hasta la O paraidentificar filas
    //puestos= es la que nos dice si los puestos estan ocupados o no
    unsigned letra=65;
    cout<<"\n";

    //recorre las filas
    for(unsigned int i=0;i<15;i++)
    {   cout<<char(letra+i)<<"|";
        //recorre columnas
        for (unsigned e=0;e<20 ;e++ )
        {
            if(puestos[i][e]==1)
            {
                cout<<"+";
            }
            else
            {
                cout<<"~";

            }
            cout<<"|";
        }
        cout<<"\n";
    }
}




void menu_cua(unsigned **cuadrado,unsigned alto ,unsigned ancho)
{


    unsigned short bole;

   /* unsigned int lado;
    cout<<"ingresa la dimension del cuadrado a llenar\n";
    cin>>lado;
    cout<<"\n";
    cuadrado= new unsigned int *[alto];*/

    //se ingresan los numeroque van a componer el caudrado magico
    for (unsigned int i = 0,puntero=1,grande=0; i < alto; ++i)
    {   cuadrado[i]= new unsigned int [ancho];

        for (unsigned int e = 0; e < ancho; ++e,puntero++)
        {
            cout<<"\nte faltan "<<ancho-e<<" de la fila "<<i+1<<"\n";
            cin>>cuadrado[i][e];
            cout<<"\n";
            //nos ayuda a sacar el numero mas grande para asi poder dibujar el cuadro
            if(grande<cuadrado[i][e])
                grande=cuadrado[i][e];

            cuadro(cuadrado,alto,ancho,puntero,grande);
        }
        cout<<"\ndeseas corregir la fila?\n1.No\n";
        cin>>bole;
        if(bole==1)
        {
            i--;
            puntero=puntero-ancho;
        }
    }
}

void cuadro(unsigned int **matriz ,unsigned int alto, unsigned int ancho,unsigned apuntador,unsigned grande)
{
    unsigned contador=0,espacios;

    grande=decima(grande);

    for (unsigned int i = 0; i < alto; ++i)
    {


        for (unsigned int e = 0; e < ancho; ++e)
        {


            contador++;

            espacios=decima(matriz[i][e]);
            for (unsigned int a = 0; a <= grande-espacios; ++a) cout<<" ";

            cout<<matriz[i][e];

            if(contador>=apuntador) break;


        }
        cout<<"\n";
        if(contador>=apuntador) break;

    }


}


unsigned decima(unsigned numero)
{
    unsigned i=1;
    if(numero==0)
    {
        return 2;
    }
    for (; 0 != numero; i++)
    {
        numero=numero/10;
    }

    return i;
}



void datain(unsigned *cuadrado, char nombre)
{
    cout<<"ingresa cordenada en eje X del cuadrado "<<nombre<<"\n";
    cin>>cuadrado[0];

    cout<<"ingresa cordenada en eje X del cuadrado "<<nombre<<"\n";
    cin>>cuadrado[1];

    cout<<"ingresa el ancho del cuadrado "<<nombre<<"\n";
    cin>>cuadrado[2];

    cout<<"ingresa el alto del cuadrado "<<nombre<<"\n";
    cin>>cuadrado[3];

    cout<<"\n\n\n\n\n\n\n";
}



void posibilidades(unsigned *suma, unsigned lado,unsigned x,unsigned y)
{
    if(x<lado)
    {

        posibilidades(suma,lado,x+1,y);
    }
    if(y<lado)
    {

        posibilidades(suma,lado,x,y+1);
    }
    if(lado==x and lado ==y)
    {
        *suma=*suma+1;
    }
}










void inDatos(char cuadro,int posicion, int *x, int *y, int *alto, int *ancho)
{

    cout<<endl<<"datos del cuadro "<<cuadro<<endl;
    cout<<"ingresa en este orden los datos x,y,alto,ancho dejando estacios de esta manera:\n";
    cout<<"x y alto ancho\n";
    cin>>x[posicion];
    cin>>y[posicion];
    cin>>alto[posicion];
    cin>>ancho[posicion];



}



int mayor(int a,int b)
{
    if(a>b) return a;

    return b;
}









unsigned conversion(char romano)
{
    switch (romano)
    {
    case 'M' | 'm' :
        return 1000;
    case 'D' | 'd':
        return 500;
    case 'C' | 'c':
        return 100;
    case

    default:
        break;
    }
}
