// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>
#include <avr/pgmspace.h>
#include <EEPROM.h>
// Include queue support
#include <queue.h>
#define text_length 16

/*
 * LIBRARY
 */

 const PROGMEM uint8_t sbox [] = {
       0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5,     // 0x00
       0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
       0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0,     // 0x10
       0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
       0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC,     // 0x20
       0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
       0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A,     // 0x30
       0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
       0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0,     // 0x40
       0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
       0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B,     // 0x50
       0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
       0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85,     // 0x60
       0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
       0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5,     // 0x70
       0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
       0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17,     // 0x80
       0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
       0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88,     // 0x90
       0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
       0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C,     // 0xA0
       0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
       0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9,     // 0xB0
       0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
       0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6,     // 0xC0
       0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
       0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E,     // 0xD0
       0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
       0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94,     // 0xE0
       0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
       0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68,     // 0xF0
       0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
   };
const PROGMEM uint8_t matrix [4][4]= {{0x02,0x03,0x01,0x01},
                                     {0x01,0x02,0x03,0x01},
                                     {0x01,0x01,0x02,0x03},
                                     {0x03,0x01,0x01,0x02}};

uint8_t rcon [4]={0x01,0x00,0x00,0x00};

static uint8_t const limit = 4;     
uint8_t  rounds [4][4];
uint8_t  test[4];
uint8_t  ciper [4][4];
uint8_t  out [4][4];
uint8_t  g[4];

//
                                 
uint8_t  text[text_length]={0x54,0x77,0x6F,0x20,0x4F,0x6E,0x65,0x20,0x4E,0x69,0x6E,0x65,0x20,0x54,0x77,0x6F}; 
uint8_t  key[text_length] ={0x54,0x68,0x61,0x74,0x73,0x20,0x6D,0x79,0x20,0x4B,0x75,0x6E,0x67,0x20,0x46,0x75};
// Define a Structure Array
struct messages{
  uint8_t text_array [16];
};


uint8_t x=0;
//Function Declaration
void data_acquisition(void *pvParameters);
void round_key (void *pvParameters);
void matrix_rotation (void *pvParameters);
void cyper_text (void *pvParameters);

QueueHandle_t integerQueue;
TaskHandle_t task_acquisition;
TaskHandle_t task_round_key;
TaskHandle_t task_matrix_rotation;
TaskHandle_t task_cyper_text;

void setup() {
  Serial.begin(9600);
// put your setup code here, to run once:
                             
// Create other task that publish data in the queue if it was created.
integerQueue = xQueueCreate(10, // Queue length
                              sizeof(int) // Queue item size
                              );
  xTaskCreate(data_acquisition,// Task function
              "matrix_rotation",// Task name
              128,  // Stack size
              NULL,
              3,// Priority
              &task_acquisition);
         
  xTaskCreate(round_key,  // Task function
              "round_key",// Task name
              128,// Stack size 
              NULL,
              2,// Priority
              &task_round_key);
 
 // Create other task that publish data in the queue if it was created.
  xTaskCreate(matrix_rotation ,// Task function
              "matrix_rotation",// Task name
              128,  // Stack size
              NULL,
              2,// Priority
               &task_matrix_rotation);

   // Create task that consumes the queue if it was created.
   xTaskCreate(cyper_text,// Task function
              "cyper_text",// A name just for humans
              128,// This stack size can be checked & adjusted by reading the Stack Highwater
              NULL,
              1, // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
              &task_cyper_text);
  
    
 }

void data_acquisition (void *pvParameters){
  (void) pvParameters;
  uint8_t i,j,k=0;
 for(;;){
//  Serial.println("TASK1_BEGINS");
     for(i=0;i<limit;i++){ //text and ciper arrays to matrix  [4][4]
      for(j=0;j<limit;j++){
        ciper[j][i]=key[k]; //EEPROM.read(k);
        out[j][i]=text[k]^ciper[j][i]; // result of first roundkey and first text output
        k++;
      }
     }
  // vTaskDelay(250/portTICK_PERIOD_MS);    
         vTaskSuspend(NULL); 
    }
}

void round_key (void *pvParameters){
  (void) pvParameters;
  uint8_t m,temp,l,i,j;
  for(;;){ 
     // Serial.println("ROUND_BEGINS");
      for(m=0;m<10;m++){
         temp=ciper[0][3];
          //adding round constat
          for(l=0;l<limit-1;l++){
              g[l]=ciper[l+1][3];
              g[l]=pgm_read_byte(&sbox[g[l]]);
           }
        g[3]=pgm_read_byte(&sbox[temp]);
      //second-ten roundkey
      for(i=0;i<limit;i++){
        for(j=0;j<limit;j++){
          temp=ciper[j][i];
          if(i==0){
            ciper[j][i]=temp^g[j]^rcon[j];
          }
          else{
            ciper[j][i]=ciper[j][i-1]^temp;
          }
      //   out[j][i]=pgm_read_byte(&sbox[out[j][i]]); //s-box to next roundkey   
      }
     }
      // ciper round constat
// ciper round constat
    if (m<=6)
      rcon[0]=rcon[0]*2;
    else if (m==7)
      rcon[0]=0x1B;
   else  
      rcon[0]=0x36;
   //  vTaskDelay(350/portTICK_PERIOD_MS); 
     vTaskSuspend(NULL); 
   } 
   // end roundkey
     rcon [0]=0x01;
     rcon [1]=0x00;
     rcon [2]=0x00;
    rcon [3]=0x00;
     
    }  
  }

void matrix_rotation (void *pvParameters){
    (void) pvParameters;
   uint8_t m,temp,l,k,h,i,j;
  for(;;){
     // Serial.println("ROTATION_BEGINS");
       for(m=0;m<10;m++){
              for(i=0;i<limit;i++){ 
              for(j=0;j<limit;j++){
                  out[j][i]=pgm_read_byte(&sbox[out[j][i]]); //s-box to next roundkey  
                }
              } 
         for(i=1;i<limit;i++){ 
            for(l=0;l<i;l++){
               temp=out[i][0];
               for(j=0;j<3;j++){
                 out[i][j]=out[i][j+1];
               }
            out[i][3]=temp;
        } 
      }
    //linear mix columns
    for(k=0;k<limit;k++){
      for(i=0;i<limit;i++){ 
       for(j=0;j<limit;j++){
          if (pgm_read_byte(&matrix[i][j])==0x02){
            h=(out[j][k]>>7)&1;
            temp=out[j][k]<<1;
            temp ^= h * 0x1B;
            test[j]=temp;
          }
          else if (pgm_read_byte(&matrix[i][j])==0x03){
            h=(out[j][k]>>7)&1;
            temp=out[j][k]<<1;
            temp ^= h * 0x1B;
            test[j]=temp^out[j][k];
          } 
          else {
            test[j]=out[j][k];
          } 
         } //for j
         rounds[i][k]=test[0]^test[1]^test[2]^test[3];
     //  Serial.print(rounds[i][k],HEX);
      //  Serial.print(";");
       } //for i
      } // for k   
     // Serial.println(";");
     // Serial.println("ROTATION_BEGINS");
         //  Serial.println(String("m: ")+String(m));
        xQueueSend(integerQueue, &m, portMAX_DELAY);
     //   vTaskDelay(350/portTICK_PERIOD_MS);    
        vTaskSuspend(NULL); 
       }
    }    
}

void cyper_text (void *pvParameters){
  (void) pvParameters;
  int8_t i,j,m;
  for(;;){
        if (xQueueReceive(integerQueue, &m, portMAX_DELAY) == pdPASS) {
            //ciper xor state matrix
           for(i=0;i<limit;i++){
              for(j=0;j<limit;j++){ 
                  if(m<9)
                    out[j][i]=rounds[j][i]^ciper[j][i];
                  else {
                    out[j][i]=out[j][i]^ciper[j][i]; 
                    Serial.print(out[j][i],HEX);
                    Serial.print(";"); 
                    if(i==3 && j==3){
                        vTaskSuspend(NULL);
                        vTaskSuspend(task_round_key);
                        vTaskSuspend(task_matrix_rotation);
                      }
                   }             
    //            Serial.print(out[j][i],HEX);
    //           Serial.print(";");
              }
           }
           vTaskDelay(100/portTICK_PERIOD_MS); 
           vTaskResume(task_round_key);
           vTaskResume(task_matrix_rotation); 
        }
    }
}
void loop() {
  // put your main code here, to run repeatedly:

}
