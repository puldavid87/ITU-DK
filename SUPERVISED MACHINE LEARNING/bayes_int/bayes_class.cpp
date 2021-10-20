#include <Arduino.h>
#include <avr/pgmspace.h>
#include <ListLib.h>

// crear una nueva lista (vector dinamico)
List <int> list; // listar, tipo de dato, el nombre de lista

const PROGMEM  uint8_t matriz[120][5]={
{51,35,14,2,1},
{49,30,14,2,1},
{47,32,13,2,1},
{46,31,15,2,1},
{50,36,14,2,1},
{54,39,17,4,1},
{46,34,14,03,1},
{50,34,15,02,1},
{44,29,14,02,1},
{49,31,15,01,1},
{54,37,15,02,1},
{48,34,16,02,1},
{48,30,14,01,1},
{43,30,11,01,1},
{58,40,12,02,1},
{57,44,15,04,1},
{54,39,13,04,1},
{51,35,14,03,1},
{57,38,17,03,1},
{51,38,15,03,1},
{54,34,17,02,1},
{51,37,15,04,1},
{46,36,10,02,1},
{51,33,17,05,1},
{48,34,19,02,1},
{50,30,16,02,1},
{50,34,16,04,1},
{52,35,15,02,1},
{52,34,14,02,1},
{47,32,16,02,1},
{48,31,16,02,1},
{54,34,15,04,1},
{52,41,15,01,1},
{55,42,14,02,1},
{49,31,15,01,1},
{50,32,12,02,1},
{55,35,13,02,1},
{49,31,15,01,1},
{44,30,13,02,1},
{51,34,15,02,1},
{70,32,47,14,2},
{64,32,45,15,2},
{69,31,49,15,2},
{55,23,40,13,2},
{65,28,46,15,2},
{57,28,45,13,2},
{63,33,47,16,2},
{49,24,33,10,2},
{66,29,46,13,2},
{52,27,39,14,2},
{50,20,35,10,2},
{59,30,42,15,2},
{60,22,40,10,2},
{61,29,47,14,2},
{56,29,36,13,2},
{67,31,44,14,2},
{56,30,45,15,2},
{58,27,41,10,2},
{62,22,45,15,2},
{56,25,39,11,2},
{59,32,48,18,2},
{61,28,40,13,2},
{63,25,49,15,2},
{61,28,47,12,2},
{64,29,43,13,2},
{66,30,44,14,2},
{68,28,48,14,2},
{67,30,50,17,2},
{60,29,45,15,2},
{57,26,35,10,2},
{55,24,38,11,2},
{55,24,37,10,2},
{58,27,39,12,2},
{60,27,51,16,2},
{54,30,45,15,2},
{60,34,45,16,2},
{67,31,47,15,2},
{63,23,44,13,2},
{56,30,41,13,2},
{55,25,40,13,2},
{63,33,60,25,3},
{58,27,51,19,3},
{71,30,59,21,3},
{63,29,56,18,3},
{65,30,58,22,3},
{76,30,66,21,3},
{49,25,45,17,3},
{73,29,63,18,3},
{67,25,58,18,3},
{72,36,61,25,3},
{65,32,51,20,3},
{64,27,53,19,3},
{68,30,55,21,3},
{57,25,50,20,3},
{58,28,51,24,3},
{64,32,53,23,3},
{65,30,55,18,3},
{77,38,67,22,3},
{77,26,69,23,3},
{60,22,50,15,3},
{69,32,57,23,3},
{56,28,49,20,3},
{77,28,67,20,3},
{63,27,49,18,3},
{67,33,57,21,3},
{72,32,60,18,3},
{62,28,48,18,3},
{61,30,49,18,3},
{64,28,56,21,3},
{72,30,58,16,3},
{67,31,56,24,3},
{69,31,51,23,3},
{58,27,51,19,3},
{68,32,59,23,3},
{67,33,57,25,3},
{67,30,52,23,3},
{63,25,50,19,3},
{65,30,52,20,3},
{62,34,54,23,3},
{59,30,51,18,3}
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
 uint8_t datos_test [filas-1];
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
    for(i=0;i<etiquetas;i++){                                     // |    1   |   2    |    3   |
        for(j=0;j<filas;j++){                                     // |   40   |   40   |   40   |
          if(pgm_read_byte(&matriz[j][columnas-1])==i+1)          // |    0   |   0    |    0   |
            prob[1][i]++;                                         // |    0   |   0    |    0   |
          }
      }


//conversion de datos uint8
//cambio de float a char vector de prueba
  for(i=0;i<columnas-1;i++){
      datos_test[i]=(uint8_t)(datos_prueba[i]*10);
    }
    
    //encontrar la distancia mayor 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(pgm_read_byte(&matriz[i][j])-datos_test[j],2); // realizar la sumatoria de potencia
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
         sumatoria=sumatoria+pow(pgm_read_byte(&matriz[i][j])-datos_test[j],2);// realizar la sumatoria de potencia
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
          if(pgm_read_byte(&matriz[list[i]][columnas-1])==prob[0][j])     // |    4   |   1    |    0   |
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
