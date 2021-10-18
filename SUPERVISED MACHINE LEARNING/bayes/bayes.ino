#include <ListLib.h>
#include "datos.h"

// crear una nueva lista (vector dinamico)
List <int> list; // listar, tipo de dato, el nombre de lista

/*
 * CLASIFICADOR BAYESIANO
 * Saber el numero de etiquetas tiene el conjunto de datos
 * el numero de filas y columnas 
 * establecer el radio de la circunferencia
 * 
 * P(1)= Sumatoria de todos lo elementos con etiqueta 1 dividos para el total de filas
 * P(2)= Sumatoria de todos lo elementos con etiqueta 2 dividos para el total de filas
 * P(3)=Sumatoria de todos los elementos con etiqueta 3 dividos para el total de filas
 * 
 * 
 * P(x)= Sumatoria de los elementos dentro de la circunferencia y dividir para el total de filas
 *      *Determinar radio de circunferencia:
 *        -> distancia entre la nueva instancia y la base de datos
 *        -> encuentro la mayor distancia y divido para el resto de distancias
 *        -> con respecto al radio establecido, selecciono las filas de la base de datos 
 *           que se encuentran dentro de la circunferencia
 *P(x/1) = Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 1 y dividir para todas las
 *        instancias de la misma etiqueta
 *P(x/2) = Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 2 y dividir para todas las
 *        instancias de la misma etiqueta
 *P(x/3) = Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 3 y dividir para todas las
 *        instancias de la misma etiqueta        
 *        
 * P(1/x)=P(1)*P(x/1)/P(x)       
 * P(2/x)=P(2)*P(x/2)/P(x) 
 * P(3/x)=P(1)*P(x/3)/P(x) 
 */
 void bayesiano(int etiquetas, int columnas, int filas, float r);
float datos_prueba [5]={6.2,2.9,4.3,1.3,2.0}; // creacion de metodo
void setup() {
Serial.begin(9600);
bayesiano(3,5,120,0.2); // llamada al metodo 
}

void loop() {

}


void bayesiano(int etiquetas, int columnas, int filas, float r){
 int i=0; // variable de recorrido en matriz
 int j=0; // variable de recorrido en matriz
 int k=0; // variable de recorrido en matriz
 int t=0; // variable de recorrido en matriz
 float p_x=0.0; // probabilidad marginal
 float distancia=0.0; 
 float sumatoria=0.0;
 float normalizador=0.0;
 float dist_mayor=0.0001;
 int resultado; // resultado de etiqueta
 float aux=0; // auxiliar de cambio de variable
  /*
   * Matriz de probabilidades
   *  |    1   |  2     |    3   |
   *  |   40   |  40    |    40  | 
   *  | P(x/1) | P(x/2) | P(x/3) |
   *  | P(1/x) | P(2/x) | P(3/x) |
   */

   float prob [4][etiquetas];
   //encerar matriz y asignar etiquetas a la fila 0
    for(i=0;i<4;i++){
       for(j=0;j<etiquetas;j++){   // |    1   |   2    |    3   |
          prob[i][j]=0;            // |    0   |   0    |    0   |
          if(i==0)                 // |    0   |   0    |    0   |
          prob[i][j]=j+1;          // |    0   |   0    |    0   |
        }
      }
    // sumar el valor del total por etiqueta en la matriz
    for(i=0;i<etiquetas;i++){               // |    1   |   2    |    3   |
        for(j=0;j<filas;j++){               // |   40   |   40   |   40   |
          if(matriz[j][columnas-1]==i+1)    // |    0   |   0    |    0   |
            prob[1][i]++;                   // |    0   |   0    |    0   |
          }
      }


    //encontrar la distancia mayor 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2); // realizar la sumatoria de potencia
        }
        distancia=sqrt(sumatoria); // raiz cuadrada para distancia entre dos puntos
        sumatoria=0;
        if(distancia>dist_mayor)
          dist_mayor=distancia; // encuentro distancia mayor
      }
      distancia=0; 
    // normalizar la distancia en toda la matriz 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2);// realizar la sumatoria de potencia
       }
        distancia=sqrt(sumatoria); // raiz cuadrada para distancia entre dos puntos
        sumatoria=0;
        normalizador=distancia/dist_mayor; // distancias entre 0 y 1
        if(normalizador<r)
            list.Add(i); // almancenar la fila de los datos que son parte de la circunferencia
    }
    // sumar por etiqueta a todos los datos que se encuentran en la circuferencia
    for(i=0;i<list.Count();i++){                          // |    1   |   2    |    3   |
      for(j=0;j<etiquetas;j++){                           // |   40   |   40   |   40   |
          if(matriz[list[i]][columnas-1]==prob[0][j])     // |    4   |   1    |    0   |
            prob[2][j]++;                                 // |    0   |   0    |    0   |
        }
      }
      // probabilidades por cada etiqueta
      p_x=float(list.Count())/float(filas); 
   for(k=0;k<etiquetas;k++){  // encontrar la probabilidad por etiqueta
      prob[3][k]=((prob[1][k]/filas)*(prob[2][k]/prob[1][k]))/p_x;
    }
      // |    1   |   2    |    3   |
      // |   40   |   40   |   40   |
      // |    4   |   1    |    0   |
      // |  0.80  |  0.20  |    0   |

      // busqueda de probabilidad por etiqueta
      for(k=0;k<etiquetas;k++){
         if(prob[3][k]>aux){
           resultado=int(prob[0][k]);
           aux=prob[3][k];
          }   
        }
    //retorna el resultado de etiqueta
  Serial.println(resultado);
 }
