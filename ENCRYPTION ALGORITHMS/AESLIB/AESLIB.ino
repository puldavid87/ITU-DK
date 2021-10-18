//https://www.cplusplus.com/reference/cstring/memcpy/
//https://www.electrodaddy.com/optimizacion-del-codigo-arduino/
//https://www.electrodaddy.com/trabajando-con-memoria-dinamica-en-arduino/
//https://www.electrodaddy.com/progmem-trabajando-con-la-memoria-arduino/
#include "aes128.h"
#define text_length 16   
unsigned long start;
unsigned long elapsed;
                         
//static uint8_t const
uint8_t  key[text_length] ={0x54,0x68,0x61,0x74,0x73,0x20,0x6D,0x79,0x20,0x4B,0x75,0x6E,0x67,0x20,0x46,0x75};
//static uint8_t const 
uint8_t  text[text_length]={0x54,0x77,0x6F,0x20,0x4F,0x6E,0x65,0x20,0x4E,0x69,0x6E,0x65,0x20,0x54,0x77,0x6F};
uint8_t cipertext [text_length];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 updated_key(&key[0]);
}

void loop() {
start = micros();
aes(&text[0],&cipertext[0]);
for(int x=0;x<16;x++){
  Serial.print(cipertext[x],HEX);
    Serial.print(";");
  }
  Serial.println(); 
 
elapsed = micros() - start;
    Serial.print(elapsed / 10000.0);
    Serial.print("us per operation, ");
    Serial.print((10000.0 * 1000000.0) / elapsed);
    Serial.println(" per second");

    
} // end loop
/*
void leer_matriz(){
  uint8_t p=0,s;
  Serial.println("TEXT");
  for(;p<4;p++){
    for(s=0;s<4;s++){
       Serial.print(out[p][s],HEX);
       Serial.print(";");
       delay(50);
      }
         Serial.println(" ");
    }
    p=0;
    Serial.println("CIPER");
      for(;p<4;p++){
    for(s=0;s<4;s++){
       Serial.print(ciper[p][s],HEX);
       Serial.print(";");
       delay(50);
      }
         Serial.println(" ");
    }
    Serial.println(" ");
  }
  */

 
