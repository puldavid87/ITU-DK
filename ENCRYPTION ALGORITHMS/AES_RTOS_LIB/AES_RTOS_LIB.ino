
#include "AES_RTOS_LIB.h" 
unsigned int start;
unsigned int elapsed;
uint8_t cypertext [16];
uint8_t i,j;
extern uint8_t out [4][4];
extern bool ext; 
void setup() {
  // put your setup code here, to run once:
setup_rtos();
Serial.begin(9600);
}

void loop() {
 start = micros();
 if(ext==true){
    for (i=0;i<4;i++){
      for (j=0;j<4;j++){
          Serial.print(out[j][i],HEX);
          Serial.print(";");
      }
    }
    Serial.println(" ");
    elapsed = micros() - start;
    Serial.print(elapsed / 10000.0);
    Serial.print("us per operation, ");
    Serial.print((10000.0 * 1000000.0) / elapsed);
    Serial.println(" per second");

  }
}
