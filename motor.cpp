#include <stdio.h>
#include <wiringPi.h>

int main()
{

    int LED = 1;
    int LED2 = 4;
    int LED3 = 0;
    wiringPiSetup();

    pinMode(LED,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
   
   while(1)
     {
        digitalWrite(LED3,HIGH);
        digitalWrite(LED,HIGH); 
        digitalWrite(LED2,LOW);
        printf("sssss\n");
       delay(1000);

         digitalWrite(LED3,HIGH);
        digitalWrite(LED,LOW); 
        digitalWrite(LED2,HIGH);
        printf("sssss\n");
  delay(1000);
      
    }


    return 0;
}

