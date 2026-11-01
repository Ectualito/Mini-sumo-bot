 const int in1 = 8;
 const int in2 = 12;
 const int in3 = 4;
 const int in4 = 2;
 const int ena = 11;
 const int enb = 10;
 const int Echopin = 13;
 const int Trigpin = 5;
 float pingtravelTime;
 int Distance;

 void setup() {
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);
   pinMode(ena, OUTPUT);
   pinMode(enb, OUTPUT);
   pinMode(Echopin, INPUT);
   pinMode(Trigpin, OUTPUT);
 Serial.begin(9600);
 }

    void loop() {
      digitalWrite(Trigpin, LOW);
      delayMicroseconds(2);
      digitalWrite(Trigpin, HIGH);
      delayMicroseconds(10);
      digitalWrite(Trigpin, LOW);
      pingtravelTime = pulseIn(Echopin, HIGH);
      Distance = pingtravelTime * 0.034 / 2; //Calculates the distance in cm
      Serial.println(Distance);

if (Distance < 50) {
digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(ena, 255);
 analogWrite(enb, 255);
} else {
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(ena, 255);
 analogWrite(enb, 255);
}

    }
    