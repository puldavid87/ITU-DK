#include <Arduino.h>
#include <avr/pgmspace.h>

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



uint8_t knn (int k,int etiquetas, int tam_col, int tam_fil, float *datos_prueba){

 uint8_t datos_test [tam_fil-1];
 uint8_t col;
 uint8_t fil;
 uint8_t i;
 uint8_t j; 
 uint8_t etiqueta;
  float aux;
  float aux_eti=0;
  float sumatoria=0; // sumatoria de la elevación al cuadrado de cada col
  float distancia=0; // raiz de sumatoria
  
  /*matriz de k-vecinos
  |1|2|3| -> numero de vecinos
  |2|1|1| -> asginacion del vecino por etiqueta
  |0.1|0.2|0.3| -> distancia
  */
 float matriz_k [3][k];
 
  /* etiquetas
  |1|2|3| -> etiquetas que existe dentro de la base de datos
  |2|1|0| -> conteo de etiquetas dentro de los k-vecinos
   */
 int8_t matriz_etiq[2][etiquetas];
  // asignar numero de vecinos y enceramos asignación de etiqueta
   for(i=0;i<k;i++){
      matriz_k[0][i]=i+1.0;
      matriz_k[1][i]=0;
      matriz_k[2][i]=200.0+i;
    /*
     |1|2|3|
     |0|0|0|
     |3000|3001|3002|
     */
    }
   // asignar etiquetas y enceramos su contador
   for(i=0;i<etiquetas;i++){
    matriz_etiq[0][i]=i+1;
    matriz_etiq[1][i]=0;
    /*
     |1|2|3| 
     |0|0|0|
     */
    }

//cambio de float a char vector de prueba
  for(i=0;i<tam_col-1;i++){
      datos_test[i]=(uint8_t)(datos_prueba[i]*10);
    }
    /*PASOS PARA K-NN
     * Leer cada fila de la matriz de entrenamiento
     * distancia entre la fila de la matriz con la nueva instancia (vector de prueba)
     * ordenar la matriz matriz_k (determinar los k vecinos de menor distancia)
     * contar las etiquetas en la matriz_k y asignar en matriz etiquetas
     * eligo al mayor número de matriz etiquetas
     * retorno la etiqueta resultante
     * 
     */

     for(fil=0;fil<tam_fil;fil++){
         for(col=0;col<tam_col-1;col++){ // menos 1 por ultima columna es etiqueta
             sumatoria=sumatoria+pow(pgm_read_byte(&matriz[fil][col])-datos_test[col],2);
          }
             distancia=sqrt(sumatoria);
             // comparación de nuevo dato con solo la distacia mayor almacenada en matriz_k
              if(distancia<matriz_k[2][k-1]){
                 matriz_k[2][k-1]=distancia;
                 matriz_k[1][k-1]=pgm_read_byte(&matriz[fil][tam_col-1]);
                 //ordenar por metodo burbuja
                 for (i=0;i<k;i++){
                     for(j=i+1;j<k;j++){
                          if(matriz_k[2][i]>matriz_k[2][j]){
                            //distancia
                             aux=matriz_k[2][i];
                             matriz_k[2][i]=matriz_k[2][j];
                             matriz_k[2][j]=aux;
                             // etiqueta
                              aux_eti=matriz_k[1][i];
                             matriz_k[1][i]=matriz_k[1][j];
                             matriz_k[1][j]=aux_eti;
                            } //end if
                      } //end for
                  }
                 //fin ordenamiento 
              } 
              //fin condicion de numero menor
              sumatoria=0;
        }
        // fin de lectura de matriz
        // contar por columna, cuantos vecinos hay por etiqueta
        for(i=0;i<etiquetas;i++){
          for(j=0;j<k;j++){
              if(matriz_etiq[0][i]==matriz_k[1][j]){
                 matriz_etiq[1][i]++;
                }
            }
          }

         // buscar la etiqueta con mayor numero de vecinos
           aux_eti=-1.0;
        for(i=0;i<etiquetas-1;i++){
            if(matriz_etiq[1][i]>aux_eti){
              etiqueta=matriz_etiq[0][i];
              aux_eti=matriz_etiq[1][i];
            }
           // Serial.println(etiqueta);  
          }
        
        return etiqueta;    
     }
