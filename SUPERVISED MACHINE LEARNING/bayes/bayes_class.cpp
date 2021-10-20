#include <Arduino.h>
#include <avr/pgmspace.h>
#include <ListLib.h>

// crear una nueva lista (vector dinamico)
List <int> list; // listar, tipo de dato, el nombre de lista

const PROGMEM float matriz[120][5]={
{5.1,3.5,1.4,0.2,1},
{4.9,3,1.4,0.2,1},
{4.7,3.2,1.3,0.2,1},
{4.6,3.1,1.5,0.2,1},
{5,3.6,1.4,0.2,1},
{5.4,3.9,1.7,0.4,1},
{4.6,3.4,1.4,0.3,1},
{5,3.4,1.5,0.2,1},
{4.4,2.9,1.4,0.2,1},
{4.9,3.1,1.5,0.1,1},
{5.4,3.7,1.5,0.2,1},
{4.8,3.4,1.6,0.2,1},
{4.8,3,1.4,0.1,1},
{4.3,3,1.1,0.1,1},
{5.8,4,1.2,0.2,1},
{5.7,4.4,1.5,0.4,1},
{5.4,3.9,1.3,0.4,1},
{5.1,3.5,1.4,0.3,1},
{5.7,3.8,1.7,0.3,1},
{5.1,3.8,1.5,0.3,1},
{5.4,3.4,1.7,0.2,1},
{5.1,3.7,1.5,0.4,1},
{4.6,3.6,1,0.2,1},
{5.1,3.3,1.7,0.5,1},
{4.8,3.4,1.9,0.2,1},
{5,3,1.6,0.2,1},
{5,3.4,1.6,0.4,1},
{5.2,3.5,1.5,0.2,1},
{5.2,3.4,1.4,0.2,1},
{4.7,3.2,1.6,0.2,1},
{4.8,3.1,1.6,0.2,1},
{5.4,3.4,1.5,0.4,1},
{5.2,4.1,1.5,0.1,1},
{5.5,4.2,1.4,0.2,1},
{4.9,3.1,1.5,0.1,1},
{5,3.2,1.2,0.2,1},
{5.5,3.5,1.3,0.2,1},
{4.9,3.1,1.5,0.1,1},
{4.4,3,1.3,0.2,1},
{5.1,3.4,1.5,0.2,1},
{7,3.2,4.7,1.4,2},
{6.4,3.2,4.5,1.5,2},
{6.9,3.1,4.9,1.5,2},
{5.5,2.3,4,1.3,2},
{6.5,2.8,4.6,1.5,2},
{5.7,2.8,4.5,1.3,2},
{6.3,3.3,4.7,1.6,2},
{4.9,2.4,3.3,1,2},
{6.6,2.9,4.6,1.3,2},
{5.2,2.7,3.9,1.4,2},
{5,2,3.5,1,2},
{5.9,3,4.2,1.5,2},
{6,2.2,4,1,2},
{6.1,2.9,4.7,1.4,2},
{5.6,2.9,3.6,1.3,2},
{6.7,3.1,4.4,1.4,2},
{5.6,3,4.5,1.5,2},
{5.8,2.7,4.1,1,2},
{6.2,2.2,4.5,1.5,2},
{5.6,2.5,3.9,1.1,2},
{5.9,3.2,4.8,1.8,2},
{6.1,2.8,4,1.3,2},
{6.3,2.5,4.9,1.5,2},
{6.1,2.8,4.7,1.2,2},
{6.4,2.9,4.3,1.3,2},
{6.6,3,4.4,1.4,2},
{6.8,2.8,4.8,1.4,2},
{6.7,3,5,1.7,2},
{6,2.9,4.5,1.5,2},
{5.7,2.6,3.5,1,2},
{5.5,2.4,3.8,1.1,2},
{5.5,2.4,3.7,1,2},
{5.8,2.7,3.9,1.2,2},
{6,2.7,5.1,1.6,2},
{5.4,3,4.5,1.5,2},
{6,3.4,4.5,1.6,2},
{6.7,3.1,4.7,1.5,2},
{6.3,2.3,4.4,1.3,2},
{5.6,3,4.1,1.3,2},
{5.5,2.5,4,1.3,2},
{6.3,3.3,6,2.5,3},
{5.8,2.7,5.1,1.9,3},
{7.1,3,5.9,2.1,3},
{6.3,2.9,5.6,1.8,3},
{6.5,3,5.8,2.2,3},
{7.6,3,6.6,2.1,3},
{4.9,2.5,4.5,1.7,3},
{7.3,2.9,6.3,1.8,3},
{6.7,2.5,5.8,1.8,3},
{7.2,3.6,6.1,2.5,3},
{6.5,3.2,5.1,2,3},
{6.4,2.7,5.3,1.9,3},
{6.8,3,5.5,2.1,3},
{5.7,2.5,5,2,3},
{5.8,2.8,5.1,2.4,3},
{6.4,3.2,5.3,2.3,3},
{6.5,3,5.5,1.8,3},
{7.7,3.8,6.7,2.2,3},
{7.7,2.6,6.9,2.3,3},
{6,2.2,5,1.5,3},
{6.9,3.2,5.7,2.3,3},
{5.6,2.8,4.9,2,3},
{7.7,2.8,6.7,2,3},
{6.3,2.7,4.9,1.8,3},
{6.7,3.3,5.7,2.1,3},
{7.2,3.2,6,1.8,3},
{6.2,2.8,4.8,1.8,3},
{6.1,3,4.9,1.8,3},
{6.4,2.8,5.6,2.1,3},
{7.2,3,5.8,1.6,3},
{6.7,3.1,5.6,2.4,3},
{6.9,3.1,5.1,2.3,3},
{5.8,2.7,5.1,1.9,3},
{6.8,3.2,5.9,2.3,3},
{6.7,3.3,5.7,2.5,3},
{6.7,3,5.2,2.3,3},
{6.3,2.5,5,1.9,3},
{6.5,3,5.2,2,3},
{6.2,3.4,5.4,2.3,3},
{5.9,3,5.1,1.8,3}
};

uint8_t bayes(int8_t etiquetas, int8_t columnas, int8_t filas, float r, float *datos_prueba){
 int8_t  i=0; // variable de recorrido en matriz
 int8_t  j=0; // variable de recorrido en matriz
 int8_t  k=0; // variable de recorrido en matriz
 int8_t  t=0; // variable de recorrido en matriz
 float p_x=0.0; // probabilidad marginal
 float distancia=0.0; 
 float sumatoria=0.0;
 float normalizador=0.0;
 float dist_mayor=0.0001;
 uint8_t resultado; // resultado de etiqueta
 float aux=0; // auxiliar de cambio de variable
 float prob [4][etiquetas];
  /*
   * Matriz de probabilidades
   *  |    1   |  2     |    3   |
   *  |   40   |  40    |    40  | 
   *  | P(x/1) | P(x/2) | P(x/3) |
   *  | P(1/x) | P(2/x) | P(3/x) |
   */


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
          if(pgm_read_float(&matriz[j][columnas-1])==i+1)    // |    0   |   0    |    0   |
            prob[1][i]++;                   // |    0   |   0    |    0   |
          }
      }

    //encontrar la distancia mayor 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(pgm_read_float(&matriz[i][j])-datos_prueba[j],2); // realizar la sumatoria de potencia
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
         sumatoria=sumatoria+pow(pgm_read_float(&matriz[i][j])-datos_prueba[j],2);// realizar la sumatoria de potencia
       }
        distancia=sqrt(sumatoria); // raiz cuadrada para distancia entre dos puntos
        sumatoria=0;
        normalizador=distancia/dist_mayor; // distancias entre 0 y 1
        if(normalizador<r)
            list.Add(i); // almancenar la fila de los datos que son parte de la circunferencia
    }
    // sumar por etiqueta a todos los datos que se encuentran en la circuferencia
    for(i=0;i<list.Count();i++){                                           // |    1   |   2    |    3   |
      for(j=0;j<etiquetas;j++){                                            // |   40   |   40   |   40   |
          if(pgm_read_float(&matriz[list[i]][columnas-1])==prob[0][j])     // |    4   |   1    |    0   |
            prob[2][j]++;                                                  // |    0   |   0    |    0   |
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
           resultado=prob[0][k];
           aux=prob[3][k];
          }   
        }
    //retorna el resultado de etiqueta
   //out=(char)resultado; 
  return resultado;
 }
