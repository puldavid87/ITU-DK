
 #include "pca.h"
 #include "svm.h"
unsigned long start;
unsigned long elapsed;
float test[4]={727,585,1,0};
float input[2];
int respuesta;
Eloquent::ML::Port::PCA pca;
Eloquent::ML::Port::SVM clf;
void setup() {
   Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  start = micros();
  test[0]=test[0]/828.0;
  test[1]=test[1]/660.0;
  test[2]=test[2]/483.0;
  test[3]=test[3]/79.0;
  pca.transform(test,input);
  respuesta=clf.predict(input);
  Serial.println(respuesta);
  elapsed = micros() - start;
  Serial.print(elapsed / 10000.0);
  Serial.print("us per operation, ");
  Serial.print((10000.0 * 1000000.0) / elapsed);
  Serial.println(" per second");
}
