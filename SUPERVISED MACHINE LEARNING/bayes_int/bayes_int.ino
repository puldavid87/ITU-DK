
#include "bayes_class.h"

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

float test [5]={6.2,2.9,4.3,1.3,2.0}; // creacion de metodo
uint8_t respuesta;
unsigned long start;
unsigned long elapsed;
void setup() {
Serial.begin(9600);

}

void loop() {
  start = micros();  
    respuesta=bayes(3,5,120,0.2,&test[0]); // llamada al metodo 
    Serial.println(respuesta);
     elapsed = micros() - start;
    Serial.print(elapsed / 10000.0);
    Serial.print("us per operation, ");
    Serial.print((10000.0 * 1000000.0) / elapsed);
    Serial.println(" per second");
}
