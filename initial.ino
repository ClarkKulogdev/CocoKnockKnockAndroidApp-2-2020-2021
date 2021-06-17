int senpin = A7;
int led= 12;
long val=0;
long average = 0;
int threshold = 66;

String answ;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,4);

void setup() {
	pinMode(senpin, INPUT);
	pinMode(led, OUTPUT);
	Serial.begin(9600);
	mySerial.begin(9600);
}


void loop() {
	if(mySerial.available()!=0) {
	answ = Serial.readStringUntil('\n');
	threshold = answ.toInt();
	}

	sensor();

	}


void sensor() {
	for(int i=0; i<160; i++) {
	average = average + analogRead(senpin)'
	}

	val = average/160;
	average = 0;
	delay(10);

	Serial.print(val);
	Serial.printIn(threshold);

	if (val >= threshold) {
		mySerial.printIn(val);
		digitalWrite(led, HIGH);
		delay(150);
		  digitalWrite(led,LOW);
		    delay(150);
		      digitalWrite(led,HIGH);
		delay(200);
		  digitalWrite(led,LOW);
		    delay(900);
}}