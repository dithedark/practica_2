#include <iostream>

using namespace std;

// DECLARACION DE FUNCIONES
// en este lugar van las funciones donde cada
// funcion va resolver un problema o ejercicio
// de los presentados en el taller
// cada ejercicicio va ha ser simplificado con "eje" y su respectiva numeracion
// y cada problema va ha ser simplicado con "proble" y su respectiva numeracion

void proble_4();
void proble_6();
void proble_15();
void proble_19();

void esquina(unsigned int lado, unsigned int fila,unsigned int esqui);


int main()
{
    /*
    proble_4();
    proble_6();

    proble_15();
    */
    proble_19();
}

//Escriba un programa para leer dos números enteros con el siguiente signicado: el
//valor del primer número representa una hora del día en un reloj de 24 horas, de modo que 1245
//representa las doce y cuarenta y cinco de la tarde. El segundo entero representa un tiempo de
// duración de la misma manera, por lo que 345 representa tres horas y 45 minutos. El programa debe
//sumar esta duración primer número, y el resultado será impreso en la misma notación, en este caso
//1630, que es el tiempo de 3 horas y 45 minutos después de 12:45.
//Nota: el formato de salida debe ser: La hora es 1630.
//Otra nota: se debe imprimir un mensaje como el siguiente cuando uno de los datos ingresados en
//inválido: 1560 es un tiempo invalido.

// separa horas minutos y segundos
// valirables:
// senum= numero a dividir
// espo= esponente de 10

long double di10(unsigned int senum, unsigned short int espo)
{
    long double divicion=senum/10;
    unsigned short int i=1;
    for (; i < espo; ++i)
    {
        divicion=divicion/10;
    }
    return divicion;
}

void proble_4()
{
    //variables necesarias horario y tiempo a sumar
    //hora
    unsigned int horario, tiempo, dias;
    //minutos es una variable que en un princio ayuda a guardar datos enteros y despues si guarda los minutos de la hora
    //long double minutos;

    //pedir ingreso de la hora y el tiempo a sumar
    cout<<"\nIngresar hora como lo indica el ejercicio\n";
    cin>>horario;
    cout<<"\nIngresa el tiempo a sumar como lo indica el ejercicio\n";
    cin>>tiempo;
    //minutos=di10(horario,2);
    // aca verificamos si los numeros ingresados son o no validos
    if(((horario%100 < 60) and (horario <2400)) and (tiempo%100<60) )
    {
        //si las suma de los minutos es mayor a 60 entonces
        //le sumamos una hora para esto le sumamos 100 y los minutos solo se le
        // descuentan los 60
        if((horario%100)+(tiempo%100) >= 60)
        {
            horario=(horario+(tiempo%100))-60;
            horario=horario+100;

        }
        //y si la suma no es mayor a 60 solo se suman los dos minutos
        else
        {
            horario=horario+(tiempo%100);
        }
        tiempo=tiempo-(tiempo%100);
        //asi mismo como se hizo con los segundos se va hacer con las horas del dia
        //asi que cada vez que se le aumente de 24 horas va a reiniciar y va haber un contardor
        horario=horario+tiempo;

        dias=horario/2400;
        horario=horario-(2400*dias);
        cout<<"\nel tiempo sumado es "<<horario<<" del dia "<<dias <<endl;

    }
    else
    {
        cout<<"\nATENCION: la hora y el tiempo deben tener menos de 60 segundos\n";
        cout<<"\nLa hora o el tiempo iniciado es invalido\n";
        cout<<"horario: "<<horario<<"\ntiempo: "<<tiempo;
    }
}


void proble_6()
{
    //aproximado= numero de iteraciones para encontrar euler
    unsigned int aproximado;
    //euler= aproximado segun el numero ingresado por el usuario
    //guarda= ayuda guardando los resultados de euler
    double euler,guarda=1;
    cout<<"\nnumero de iteraciones para encontrar euler\n";
    cin>>aproximado;
    if(aproximado<3)
    {
        euler=aproximado;
    }
    else
    {   euler=2;

        for(unsigned int i=2;i<aproximado;i++)
        {
            guarda=guarda*i;
            euler=euler+(1/guarda);
        }

    }

    cout<<"e es aproximadamente: "<<euler<<endl;
}





void proble_15()
{
    //LO QUE HACE EL PROGRAMA
    //el cuadro crece apartir del los numero impares, por ende usamos la formula de los inpares que seria "2*x+1"
    // asi que cada que necesitemos hacer un cuadro mas grande multiplicamos por dos la formular y asi vamos consiguiendo
    //el cuadro, y despues lo unico que se hace es sumar


    //VARIABLES
    //tamano = en principio guarda la longitud de los lados
    //aumento= es una variable que se encarga de ir aumento de dos en dos para in encontrando las esquinas del cuadrado
    unsigned int tamano,aumento=2;
    //numeros= es la variable que encuentra  de la esquina el cual es el que necesitamos para la suma
    //suma= es la suma de todas las esquias y es el que esta en la pantalla final
    unsigned long numeros=1,suma=0;
    //cuatro= va contando las esquinas y cuando llega a 4 se reinicia para contar el siguiente cuadro
    unsigned short cuatro = 0;

    //EXPLICACION CODIGO
    //ingreso de datos
    cout<<"\ningresa tamaño impar del lado de cuadrado"<<endl;
    cin>>tamano;

    //entramos a un bucle hasta que la variable numero sea igual al numero de la esquina
    //el numero de la esquia es la multiplicacion de la variable tamano al cuadrado
    for(;numeros<=tamano*tamano;numeros=numeros+aumento,cuatro++)
    {
        //suma de las esquinas
        suma=suma+numeros;

        // cada vez que la variable cuatro llegue al numero 4
        // aumentamos 2 para que el siguiente cuadro siga los requisitos de crecimiento
        if(cuatro==4)
        {
            aumento=aumento+2;
            cuatro=0;
        }

    }
    cout<<"la suma de las esquinas del cuadrado es "<<suma<<endl;
    // el for lo unico que hace es avanzar la fila en la que va
    for(unsigned int i=0;i<tamano;i++)
    {
        esquina(tamano,i,(tamano*tamano)-(tamano-1));
        cout<<"\n";
    }


}

void esquina(unsigned int lado, unsigned int fila, unsigned int esqui)
{
    //LO QUE HACE EL PROGRAMA
    //el programa es dibujar el cuadro con las formulas que voy a explicar
    //el cuadro se divide en tres partes, la primera es la superios en la cual dependiendo de la esquina
    //y del lado sumamos osea si la esquina es 21 entonces la parte de superios sera 21 22 23
    // y asi segun el lado lo determine
    // la segunda es el medio que es la que nos va llamando la recursividad por ende va llando la funcion indefinidamente
    // y cuando regresa se hace una operacion para determinar el numero final
    // y la tercerna que es la que nos escribe los numeros del final los cuales van en secuencia inverla a la del principio
    // osea si la esquina inferios es 21 entonces la secuencia iria 21 20 19

    //VARIABLES
    //lado = es la cantidad de numero que tiene que tener en los lados
    //fila = ubica la fila en la que va escribiendo
    //esqui = es la penultima esquina del cuadro en orden numerico que es donde inicia de izquierda a derecha

    //EXPLICACION
    //primera fase
    if(fila==0)
    {
        //cuando la esquina es igual a 0 significa que estamos hablando del cuadro de 1*1
        //por ende en ves de hacer operacione complicadas solo colocamos un if
        //para esta situacion tan peculiar
        if(esqui==0)
        {
            cout<<"1 ";
        }
        else
        {   // imprime los numero siguientes a la esquina hasta llegar
            // a la ultima esquina
            for(unsigned int i=0;i<lado;i++)
            {
                cout<<esqui+i<<" ";

            }

        }
    }
    //segunda fase
    else if(fila<lado-1)
    {
        // ya que fila nos indica en donde vamos entonces le restamos a esqui fila
        //dandonos dandonos un numero anterios a esquina
        cout<<esqui-fila<<" ";
        //llamamos otra vez la funcion para que nos cree un cuadrado de lado impar mas pequeño
        // y repita este mismo proceso
        // como el nuevo cuadrado que vamos a crear va a ser mas pequeño el cuadro ira siempre un proseco mas
        // atras que el actual osea que si nosotros ya vamos dibujando la segunda linea el cuadromas pequeño
        //apenas dibujara la primera y asi indefinidamente
        esquina(lado-2,fila-1,((lado-2)*(lado-2))-((lado-2)-1));
        //posicion actual = esqui - fila
        //diminicion borede = lado - fila - 1
        //diminicion boredes = 2(lado - fila - 1)
        //numero contrario = posicion - lado - dimisminucion de bordes
        // despejamos y nos da lo que esta en la parte inferior
        cout<<esqui-(3*lado)+fila+3<<" ";
    }
    //tercera fase
    else
    {   // al contrario que en la primera fase solo que con la esquina inferior izquierda del
        //cuadrado

        for(unsigned int i=0;i<lado;i++)
        {
            cout<<(esqui-(lado-1))-i<<" ";

        }

    }
}

void proble_19()
{
    //VARIABLES
    //mDivisor=cantidad de divisores a buscar
    //mdbuscador= el que busca los divisores  para salir del ciclo
    unsigned short int mDivisor,mdbuscador=0;
    //ntriangular= el que guarda los numeros triangulares que da el programa
    unsigned int ntriangular;
    cout<<"ingresa el numero de divisores que necesita\n";
    cin>>mDivisor;

    for(unsigned int posicion=1;mDivisor>mdbuscador;posicion++)
    {
        mdbuscador=0;
        ntriangular= posicion*(posicion+1)/2;
        for(unsigned i=1;i<=ntriangular;i++)
        {
            if(ntriangular%i==0)
                mdbuscador++;
        }

    }

    cout<<"El numero es:"<<ntriangular<< " que tiene "<<mdbuscador<<"  divisores.\n";
}


