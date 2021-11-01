#include <Arduino.h>
#include <avr/pgmspace.h>

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


uint8_t knn (uint8_t k,uint8_t etiquetas, uint8_t tam_col, uint8_t tam_fil, float *datos_prueba){
uint8_t col;
uint8_t fil;
uint8_t i=0;
uint8_t j; 
uint8_t etiqueta;
  float aux=0;
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
 int matriz_etiq[2][etiquetas];
  // asignar numero de vecinos y enceramos asignación de etiqueta

   for(;i<k;i++){
      matriz_k[0][i]=i+1.0;
      matriz_k[1][i]=0;
      matriz_k[2][i]=3000.0+i;
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
             sumatoria=sumatoria+pow(pgm_read_float(&matriz[fil][col])-datos_prueba[col],2);
          }
             distancia=sqrt(sumatoria);
             // comparación de nuevo dato con solo la distacia mayor almacenada en matriz_k
              if(distancia<matriz_k[2][k-1]){
                 matriz_k[2][k-1]=distancia;
                 matriz_k[1][k-1]=pgm_read_float(&matriz[fil][tam_col-1]);
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
          }
        
        return etiqueta;    
     }
