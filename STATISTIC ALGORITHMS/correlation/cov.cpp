#include <Arduino.h>
#include <avr/pgmspace.h>
#define row 120
#define col 5
const PROGMEM float dataset[120][5]={
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
 void impresion ();
//float correlation_matrix [6];
 float matrix [3][3];
 float prom_matrix [3][4];
 float corr_matrix [3][6];
void setup_corr(){
   Serial.begin(9600);
   Serial.println("r");
  }
  
void correlation (uint8_t label){
   uint8_t i,j,x,y=0;
   float cov;
   float corr,s_1,s_2;
   uint16_t k=0;
   float prom=0;
   uint8_t aux;
// float matrix [0][label];
   /*
   |   1  |   2  |   3  |  abels
   |  40  |  40  |  40  |  n per label
   |  39  |  79  | 119  |  limit per label

    */
  // float prom [labes][col-1]
       /*
              |   col1  |  col2  |  col3  |   col4  |
   |  label1  |  av11   |  av12  |  av13  |   av14  |  
   |  label2  |  av21   |  av22  |  av23  |   av24  |  
   |  label3  |  av31   |  av32  |  av33  |   av34  |  
    */
   /*
 
   |  5,04   |  3,44  |  1,46  |   0,23  |  
   |  6,01   |  2,78  |  4,32  |   1,35  |  
   |  6,55   |  2,96  |  5,53  |   2,05  |  
    */
    for(;i<label;i++){
      for(j=0;j<3;j++){
           if(j==0)
           matrix[j][i]=i+1;
           else
            matrix[j][i]=0;
        }
      }
    
    // couting n observation per label
    for(i=0;i<label;i++){                                        // |    1   |   2    |    3   |
       for(j=0;j<row;j++){                                       // |   40   |   40   |   40   |
         if(pgm_read_float(&dataset[j][col-1])==matrix[0][i]){   // |   39   |  79    |   119  |
              matrix[1][i]++;                                     
              k++;
           } 
         }
        matrix[2][i]=k; 
     }
     aux=0;
   for(k=0;k<label;k++){
     for(i=0;i<col-1;i++){
        for(j=aux;j<matrix[2][k];j++){
            prom+=pgm_read_float(&dataset[j][i]);
          }
          prom_matrix[k][i]=prom/matrix[1][k];
          prom=0;
      }
     aux=matrix[2][k];
    } 
    
     aux=0;
     for(k=0;k<label;k++){
        for(i=0;i<col-2;i++){
         for(x=i+1;x<col-1;x++){ 
             for(j=aux;j<matrix[2][k];j++){
              cov+= (pgm_read_float(&dataset[j][i])-prom_matrix[k][i])* (pgm_read_float(&dataset[j][x])-prom_matrix[k][x]);
              s_1+=pow((pgm_read_float(&dataset[j][i])-prom_matrix[k][i]),2);
              s_2+=pow((pgm_read_float(&dataset[j][x])-prom_matrix[k][x]),2);
             }
             cov=cov/matrix[1][k];
             s_1=sqrt(s_1/(matrix[1][k]-1));
             s_2=sqrt(s_2/(matrix[1][k]-1));
             corr_matrix[k][y]= cov/(s_2*s_1);
            y++;
         }  
        } 
          y=0;
          aux=matrix[2][k];
    } 
     
    impresion();
 }

 void impresion (){
  int i=0;
  int j=0;
  for(i=0;i<3;i++){
    for(j=0;j<6;j++){
    Serial.print(corr_matrix[i][j]);
      Serial.print(":");    
      }
     Serial.println(" ");
    }
       Serial.println("STOP ");
  }