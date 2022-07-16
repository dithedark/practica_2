#ifndef AYUDAS_H
#define AYUDAS_H


#include <iostream>
using namespace std;

unsigned conversion(char romano);


void sillas(bool **puestos);
void cuadro(unsigned int **matriz ,unsigned int alto, unsigned int ancho,unsigned apuntador,unsigned grande);
unsigned decima(unsigned numero);
void menu_cua(unsigned **cuadrado,unsigned alto,unsigned ancho);

void  datain(unsigned *cuadrado,char nombre);
//bool cdentroc(unsigned *cuadradoA,unsigned *cuadradoB,unsigned test);

void posibilidades(unsigned *suma, unsigned lado,unsigned x,unsigned y);


void inDatos(char cuadro,int posicion,int *x,int *y,int *alto,int *ancho);
int mayor(int a,int b);



#endif // AYUDAS_H
