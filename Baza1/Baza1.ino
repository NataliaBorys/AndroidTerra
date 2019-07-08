#include <DHT.h>
#include <SPI.h>



const int sensorPin = 2;
const int sensorPin2 = 5;
const int sensorPin3 = 12;
const int sensorType = DHT11;
DHT dht (sensorPin, sensorType);
DHT dht2 (sensorPin2, sensorType);
DHT dht3 (sensorPin3, sensorType);

const unsigned long SECOND = 1000;
const unsigned long MIN = 60*SECOND;




void setup() {
Serial.begin(115200);
pinMode(sensorPin,INPUT);
pinMode(sensorPin2,INPUT);
pinMode(sensorPin3,INPUT);
}

void loop() {
float temp=dht.readTemperature();
float hum=dht.readHumidity();

String t=String(temp);
String h=String(hum);
String all="xxx";
all+="S1 T:";
all+=t;
all+="H:";
all+=h;
Serial.println(all);

delay(40*SECOND);

float temp2=dht2.readTemperature();
float hum2=dht2.readHumidity();

String t2=String(temp2);
String h2=String(hum2);
String all2="xxx";
all2+="S2 T:";
all2+=t2;
all2+="H:";
all2+=h2;
Serial.println(all2);

delay(40*SECOND);

float temp3=dht3.readTemperature();
float hum3=dht3.readHumidity();

String t3=String(temp3);
String h3=String(hum3);
String all3="xxx";
all3+="S3 T:";
all3+=t3;
all3+="H:";
all3+=h3;
Serial.println(all3);

delay(2*MIN);
  

}
