#include "problema.h"


int main()
{

    bool salir=true;
    unsigned seleccionar;

    while(salir)
    {
        cout<<"ingresa un numero del 3 al 16 para revisar los ejercicios\n"
              "si ingresas un numero diferente te salgras del menu"<<endl;
        cin>>seleccionar;

        switch (seleccionar) {
        case 3:
            problema_3();
            break;
        case 4:
            problema_4();
            break;
        case 5:
            problema_5();
            break;
        case 6:
            problema_6();
            break;
        case 7:
            problema_7();
            break;
        case 8:
            problema_8();
            break;
        case 9:
            problema_9();
            break;
        case 10:

            cout<<"\nlo siento no lo hice :)\n";
            break;
        case 11:
            problema_11();
            break;
        case 12:
            problema_12();
            break;
        case 13:
            cout<<"\nlo siento no lo hice :)\n";
            break;
        case 14:
            problema_14();
            break;
        case 15:
            cout<<"\nlo siento no lo hice :)\n";
            //problema_15();
            break;
        case 16:
            problema_16();
            break;


        default:
            salir=0;
            break;
        }
    }

    return 0;
}
