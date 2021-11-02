#include "fuctions.h"
unsigned long start;
unsigned long elapsed;
float test[4]={727,585,1,0};
uint8_t y_pred;
void setup() {
  void setup_1();
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  start = micros();
  y_pred=knn(3,4,3,245,&test[0]);
  Serial.println(y_pred);
  elapsed = micros() - start;
  Serial.print(elapsed / 10000.0);
  Serial.print("us per operation, ");
  Serial.print((10000.0 * 1000000.0) / elapsed);
  Serial.println(" per second");
}
