//used a modified continous turning servo motor here 

#define BlYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <Servo.h> 

//input all the wifi information and auth token for BLYNK app
char auth[] = "6d846695f5e245939394088c4c2d5795";
char ssid [] = "W1KBN";  // wifi name
char pass[] = "wireless"; // wifi password

//create servo object 
Servo servo; 


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(15);
  servo.write(33);
}

void loop() {
  Blynk.run();
}

//create motion for the servo motor in the feeder 
BLYNK_WRITE(V2) //set pin on app to virtual 2 (or which ever you like)
{
  servo.write(0); //set the servo to turn at a certain speed
  delay(3000);
  servo.write(33); //set the servo to turn at no speed
                   //33 is the balance speed for my modified servo 
                   //the balance speed is different from servos 
}








