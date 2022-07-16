#include "problema.h"



void problema_3()
{

    int num1,num2;
    bool iguales=true;

    cout<<"numero de caracteres de la primera cadena: ";
    cin>>num1;
    char cadena1[num1];
    cout<<"\n ingresa la palabra a analizar: ";
    cin>>cadena1;
    cout<<"\nnumero de caracteres de la segunda cadena: ";
    cin>>num2;
    char cadena2[num2];
    cout<<"\n ingresa la palabra a analizar: ";
    cin>>cadena2;

    if(num1==num2)
    {
        for (int var = 0; var < num1; ++var)
        {

                if(cadena1[var] != cadena2[var])
                {
                    iguales=false;
                    break ;
                }
        }

    }
    else
    {
        iguales=false;
    }

    if(iguales)
    {
        cout<<"las cadenas de caracteres son iguales"<<endl;
    }
    else
    {
        cout<<"las cadenas de caracteres son diferentes"<<endl;
    }
}


void problema_4()
{
    char cadena[35];
    int var = 0,numero=0;
    cout<<"ingresa la cadena y cuando termine solo coloca un '.' ejemplo '123.'"<<endl;
    cin>>cadena;

    if(cadena[0]=='-')
    {
        var++;
    }
    for (; cadena[var] != '.';var++ )
    {
        numero=numero*10;
        numero=numero+(int(cadena[var])-48);
    }

    if(cadena[0]=='-')
    {
        numero=numero*(-1);
    }


    cout<<endl<<numero<<endl;
}

void problema_5()
{
    int numero,decima=0,dec = 10, i = 0;
    char *num=new char;
    cout<<"ingresa el numero a convertir : ";
    cin>>numero;


    for (;  numero/dec; decima++ ,dec=dec*10);

    if(numero>=0)
    {
        num= new char [decima];
    }
    else
    {
        decima++;
        i++;
        num=  new char [decima+2];

        num[0]='-';

        numero=numero*(-1);
    }

    dec=dec/10;
    for (; i <= decima; ++i,dec=dec/10)
    {
        num[i]=char((numero/dec)+48);
        numero=numero%dec;
    }

    cout<<endl<<num<<endl;

    delete num ;

}

void problema_6()
{
    char cadena[35],mayus[35];
    cout<<"ingresa la cadena y cuando termine solo coloca un '.' ejemplo 'hola.'"<<endl;
    cin>>cadena;

    for (int var = 0; cadena[var] != '.'; ++var)
    {
        if(int(cadena[var])>=97 and int(cadena[var])<=122)
        {
            mayus[var]=char(int(cadena[var])-32);
        }
        else
        {
            mayus[var]=cadena[var];
        }
    }

    cout<<endl<<"Original:"<<cadena<<"En mayuscula:"<<mayus<<endl;

}

void problema_7()
{
    char cadena[35], corte[35];
    bool repe=false;
    unsigned short int ingreso=0;
    cout<<"ingresa la cadena y cuando termine solo coloca un '.' ejemplo 'hola.'"<<endl;
    cin>>cadena;

    for(unsigned short int var=0 ; cadena[var] != '.';var++)
    {
        for (unsigned short int i = 0; i < var; ++i)
        {

            if(corte[i]==cadena[var])
            {
                repe=true;
                break;
            }
        }

        if(repe);
        else
        {
            corte[ingreso]=cadena[var];
            ingreso++;
        }
        repe=0;
    }


    cout<<endl<<"Original:"<<cadena<<"En mayuscula:"<<corte<<endl;
}

void problema_8()
{
    char cadena[35],num[35],letra[35];
    unsigned short cnum=0,cletra=0;
    cout<<"ingresa la cadena y cuando termine solo coloca un '.' ejemplo 'hola.'"<<endl;
    cin>>cadena;

    for ( unsigned short int  var = 0; cadena[var] != '.'; ++ var)
    {
        if((cadena[var]>= 65 and cadena[var]<=90) or (cadena[var]>= 97 and cadena[var]<=122))
        {
            letra[cletra]=cadena[var];
            cletra++;
        }
        else if(cadena[var] >= 48 and cadena[var]<=57)
        {
            num[cnum]=cadena[var];
            cnum++;
        }

    }

    cout<<endl<<"Original: "<<cadena<<endl<<
          "Texto: "<<letra<<". Numero: "<<num<<endl;

}

void problema_9()
{
    unsigned int numero,deci=1,n,conN=0,resultado,componentes,dece=1;

    cout<<"ingresa el numero a convertir : ";
    cin>>numero;
    cout<<"\ningrese n: ";
    cin>>n;

    for(;numero/dece>10;dece=dece*10,deci++);


    if(deci%n !=0)
    {
        conN=1;
    }
    else
    {
        conN=0;
    }

    deci=numero;

    while (dece !=0 or conN!=0)
    {
        if(conN<n)
        {

            conN++;
            componentes= (deci/(dece))+(componentes*10);
            deci=deci%dece;
            dece=dece/10;
        }

        else
        {
            conN=0;
            resultado= componentes+resultado;
            componentes=0;
        }
    }
    cout<<"original: "<<numero<<"\nsuma: "<<resultado<<endl;
}

void problema_10()
{
    char cadena[35];
    unsigned numero;

    cout<<"ingresa la cadena en  y cuando termine solo coloca un '.' ejemplo 'XIV.'"<<endl;
    cin>>cadena;

    for (int var = 0; cadena[var+1] != '.'; ++var)
    {

    }

}

void problema_11()
{
    //FUNCIONAMIENTO
    //la aplicacion es un menu donde va rellenando las memorias dinamicas de silla y pago mediante
    //las openaciones del operador, no se pueden cancelar reservaciones

    //VARIABLE
    //filas= filas de que hay en el cine
    //columnas= columnas que hay en el cine
    //casos= se encarga dirigirnos a los distintos menus de la aplicacion
    //silla= es un arreglo que nos dice si un asiento esta reservado o no
    //pagos= nos dice si el aciento reservado ya esta pago o no
    char filas=15;
    unsigned columnas=20;
    unsigned short casos = 0;
    bool **silla= new bool *[filas],**pagos=new bool *[filas];

    //rellenamos las memorias dinamicas con false para indicar que no se a pagado
    //ni se ha reservado ninguna silla aun
    for(unsigned i=0;i<unsigned(filas);i++)
    {
        silla[i]=new bool [columnas];
        pagos[i]=new bool [columnas];
        for(unsigned e=0;e<columnas;e++)
        {   pagos[i][e]=false;
            silla[i][e]=false;
        }
    }

    //solo se puede salir del bucle si la variable casos es igual a 3
    while(true)
    {
        //mientras caso sea menor a tres le dara tres occiones al operador
        //las cuales son: reserbar y pagar, revisar si ya reservo y pagar , y salirse
        switch (casos)
        {
            case 0:
                while (true)
                {
                    sillas(silla);
                    cout<<"en que asiento te quieres sentar\n"
                          "primero escribe una letra entre la A y la O (porfavor  las escribir las sillas en mayusculas)\n"
                          ;
                    cin>>filas;
                    cout<<"\npara las columnas del 1 al 20\n";
                    cin>>columnas;
                    columnas=columnas-1;

                    //mientras la letra y el numero elejido por el usuario esten en el rango y sean diferentes de cero
                    //la aplicacion revisara si los asientos estan libres o reservados
                    if((unsigned(filas)-65<=15 and columnas<=20) and (unsigned(filas) != 0  ))
                    {
                        if(silla[unsigned(filas)-65][columnas]==true)
                        {
                            cout<<"\nel asiento "<<filas<<columnas+1<< " ya esta reservado";
                        }
                        else
                        {
                            silla[unsigned(filas)-65][columnas]=true;
                            break;
                        }
                    }
                    else
                    {
                        cout<<"\nlo sentimos pero el asiento "<<filas<<columnas<<" no se encuentra en la sala\n\n";
                    }

                }
                cout<<"Deseas pagar el asiento\n"
                      "1.No\n"
                      "2.Si \n";
                cin>>casos;
                if(casos==2)
                {
                    pagos[unsigned(filas)-65][columnas]=true;
                }

                casos=2;
            break;
            case 1:
                while (true)
                {

                    cout<<"cual asiento fue el que reservaste \n"
                          "primero escribe una letra entre la A y la O (porfavor  las escribir las sillas en mayusculas)\n"
                          ;
                    cin>>filas;
                    cout<<"\npara las columnas del 1 al 20\n"
                          "(si quieres salir ingresa el numero 21)\n\n";
                    cin>>columnas;
                    casos=2;
                    columnas=columnas-1;
                    if(columnas==21)
                    {                    
                        break;
                    }
                    else if((unsigned(filas)-65<=15 and columnas<=20) and (unsigned(filas) != 0 ))
                    {
                        casos=2;
                        if(pagos[unsigned(filas)-65][columnas]==true)
                        {
                            cout<<"el asiento "<<filas<<columnas+1<<" ya esta pago\n";
                            break;
                        }
                        if(silla[unsigned(filas)-65][columnas]==false)
                        {
                            cout<<"\nel asiento "<<filas<<columnas+1<<" no se a reservado";
                            casos=0;
                            break;
                        }
                        else
                        {   cout<<"pago realizado con exito\n";
                            pagos[unsigned(filas)-65][columnas]=true;
                            break;
                        }
                    }
                    else
                    {
                        cout<<"lo sentimos pero el asiento "<<filas<<columnas<<" no se encuentra en la sala\n\n";
                    }     
                }

            break;
            case 2:
                cout<<"menu principal\n"
                      "0.reservar\n"
                      "1.pagar reserva\n"
                      "2.menu principal\n"
                      "3.salir\n";
                cin>>casos;
                if(3<casos)
                {
                    casos=3;
                }
            break;
        }
        if(casos==3)
        {
            break;
        }

    }
    delete silla[20];
    delete pagos[20];
}





void problema_12()
{

    //VARIABLES
    //cuadrado= donde la matriz donde se van a cuardar los numero que va ingresar el usuario
    //lado= es el que indirara las dimensiones del cuadrado

    unsigned int **cuadrado,lado, suma, prueba;
    bool check=true;
    unsigned short comprueba=0;

    //unsigned int lado;
    cout<<"ingresa la dimension del cuadrado a llenar\n";
    cin>>lado;
    cout<<"\n";
    cuadrado= new unsigned int *[lado];

    menu_cua(cuadrado,lado,lado);

    while(check and comprueba<4 )
    {
        switch (comprueba)
        {
        case 0:
            comprueba++;
            for (unsigned var = 0; var < lado; ++var)
            {
                suma=suma+cuadrado[var][var];
            }
            prueba=suma;
            suma=0;
        break;

        case 1:
            comprueba++;
            for(unsigned a=0;a<=1 ;a++)
            {
                for (unsigned int var = 0; var < lado; ++var)
                {
                    suma=suma+cuadrado[(lado-1)*a][var];
                }
                if(suma!=prueba)
                {
                    check=false;
                    break;
                }
                suma=0;
            }

        break;

        case 2:
            comprueba++;
            for(unsigned a=0;a<=1 ;a++)
            {
                for (unsigned int var = 0; var < lado; ++var)
                {
                    suma=suma+cuadrado[var][(lado-1)*a];
                }
                if(suma!=prueba)
                {
                    check=false;
                    break;
                }
                suma=0;
            }
        break;
        case 3:
            comprueba++;

            for (unsigned var = 0, atras=lado-1; var < lado; ++var,--atras)
            {
                suma=suma+cuadrado[var][atras];
            }
            if(suma!=prueba)
            {
                check=false;
                break;
            }

        break;
       }
    }
    if(check)
    {
        cout<<"el cuadrado que ingreso el usuario es magico\n";
    }
    else
    {
        cout<<"el cuadrado que ingreso el usuario NO es magico\n";
    }

    delete cuadrado[lado];
}










void problema_14()
{


    unsigned **cuadrado= new unsigned *[5],**replica= new unsigned *[5] ;

    //menu_cua(cuadrado,5,5);


    for(unsigned i=0;i<5;i++)
    {
        replica[i]=new unsigned [5];
        cuadrado[i]=new unsigned [5];
    }

    for (unsigned var = 0,num=1; var < 5; ++var)
    {
        for (unsigned i = 0; i < 5; ++i,num++)
        {
            cuadrado[var][i]=num;
        }
    }
    cuadro(cuadrado,5,5,25,25);
    for(unsigned angulo=1;angulo<=3;angulo++)
    {
        for (unsigned var = 0; var < 5; ++var)
        {
            for (unsigned i = 0,e=4; i < 5; ++i,--e)
            {
                replica[var][i]=cuadrado[e][var];
            }
        }

        cout<<"la matriz se roto "<<90*angulo<<" grados\n"<<endl;
        cuadro(replica,5,5,25,25);

        //cuadrado=replica;
        for (unsigned e = 0; e < 5; ++e)
        {
            for (unsigned i = 0; i < 5; ++i)
            {
                cuadrado[e][i]=replica[e][i];
            }
        }
    }
    delete cuadrado[5];
    delete replica[5];
}



/*void problema_15()
{
    int x[3],y[3],alto[3],ancho[3];

    inDatos('A',0,x,y,alto,ancho);

    inDatos('B',1,x,y,alto,ancho);

    x[2]=mayor(x[0],x[1]);
    y[2]=mayor(y[0],y[1]);

    if(x[0]+ancho[0]<x[1]+ancho[1])
    {
        ancho[2]= (x[2]-x[0])
    }

}*/







void problema_16()
{
    unsigned suma ,lado;

    suma=0;
    cout<< "ingresa la dimension que va a tener el cuadrado\n";
    cin>>lado;

    posibilidades(&suma,lado,0,0);

   cout<<"\n hay "<<suma<<" formas para llegar a la otra esquina en un cuadro "<< lado<<"x"<<lado<<endl;
}





