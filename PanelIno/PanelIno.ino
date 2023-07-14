
#include <Servo.h>


Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;



int red, green, blue, fader, del, preset;




void serialread();



void servo(int f,int r, int g, int b, int d, int p);



void setup() 
{
 
  Serial.begin(9600);

 
  myservo.attach(3);
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(9);
  myservo4.attach(10);
  myservo5.attach(11);
}

  



void loop() 
{
  int r = red;
  int g = green;
  int b = blue;
  int f = fader;
  int d = del;
  int p = preset;

  serialread();

 
  servo(f,r,g,b,d,p);


}

void servo(int f,int r, int g, int b, int d, int p){

   myservo.write(f); 
   myservo1.write(r); 
    myservo2.write(g); 
     myservo3.write(b); 
      myservo4.write(d); 
       myservo5.write(p); 


  
}



void serialread()
{

if (Serial.available()) {
  String data = Serial.readStringUntil('\n');
  char str[data.length() + 1];
  strcpy(str, data.c_str());

  char* token = strtok(str, ",");
  int values[6];
  int numValues = 0;

  while (token != NULL && numValues < 6) {
    values[numValues] = atoi(token);
    token = strtok(NULL, ",");
    numValues++;
  }

  if (numValues == 6) {
      
    fader  = values[0];
    red    = values[1];
    green  = values[2];
    blue   = values[3];
    del    = values[4];
    preset = values[5];
  }
}

}
