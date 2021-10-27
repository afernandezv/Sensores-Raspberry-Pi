#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define LED_RED 3
#define LED_GREEN 2
#define PIN_SENSOR 4

int main(){
	
	wiringPiSetup();
	pinMode(PIN_SENSOR, INPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	
	for( ; ; ){
		
		digitalWrite(LED_RED, LOW);
		digitalWrite(LED_GREEN, LOW);
		digitalWrite(PIN_SENSOR, LOW);
		
		if(digitalRead(PIN_SENSOR) == 0){
			digitalWrite(LED_GREEN, HIGH);
			printf("Hay humedad\n");
		}else{
			digitalWrite(LED_RED, HIGH);
			printf("No hay humedad\n");
		}
		delay(5000);
	}
	
	digitalWrite(LED_RED, LOW);
	digitalWrite(LED_GREEN, LOW);
	digitalWrite(PIN_SENSOR, LOW);
	
	return 0;
	
}
