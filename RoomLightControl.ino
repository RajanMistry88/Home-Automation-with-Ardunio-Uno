#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;
int flag1 = 0;
int flag2 = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); 
}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value == 0XE124609F) //Change Your remote Hax number
    {
      if(flag1==0)
      {
        digitalWrite(9,HIGH);
        flag1==1;
      }
      else if(flag1==1)
      {
        digitalWrite(9,LOW);
        flag1==0;
      } 
     }
     if(results.value == 0XE12448B7) //Change Your remote Hax number
    {
      if(flag2==0)
      {
        digitalWrite(10,HIGH);
        flag2==1;
      }
      else if(flag2==1)
      {
        digitalWrite(10,LOW);
        flag2==0;
      } 
     }
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
