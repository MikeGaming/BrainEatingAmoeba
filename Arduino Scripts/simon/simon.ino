#include <FastLED.h>

// C++ code
//

#define NUM_LEDS_SIMON 4
#define LED_PIN_SIMON 10
CRGB leds_simon[NUM_LEDS_SIMON];

#define _button1Pin 8
#define _button2Pin 7
#define _button3Pin 6
#define _button4Pin 5

bool simonSolved = false;
//sequence must be defined here.
//it is impossible for the sequence to be solved with values above 4
String sequence = "5555";
String currentInputs = "";

void setup()
{

  FastLED.addLeds<WS2812B,LED_PIN_SIMON,GRB>(leds_simon,NUM_LEDS_SIMON);
  
  pinMode(_button1Pin, INPUT);
  pinMode(_button2Pin, INPUT);
  pinMode(_button3Pin, INPUT);
  pinMode(_button4Pin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  ReadSerialData();
  
  if(sequence.length() == currentInputs.length() && !simonSolved){
    Serial.println("Alert6");
    
    if(sequence == currentInputs){
      simonSolved = true;
      Serial.println("#solved");
    }else{
      ResetSimon();
    }
  }
  
  if(!simonSolved){
    if(digitalRead(_button1Pin) == HIGH){
      currentInputs += '1';
      //replace next with LED array change
      leds_simon[0]=CRGB(255);
      
      Serial.println("alert1");
      delay(250);
    }

    if(digitalRead(_button2Pin) == HIGH){
      currentInputs += '2';
      //replace next with LED array change
      leds_simon[1]=CRGB(255);
      
      Serial.println("alert2");
      delay(250);
    }

    if(digitalRead(_button3Pin) == HIGH){
      currentInputs += '3';
      //replace next with LED array change
      leds_simon[2]=CRGB(255);
      
      Serial.println("alert3");
      delay(250);
    }

    if(digitalRead(_button4Pin) == HIGH){
      currentInputs += '4';
      //replace next with LED array change
      leds_simon[3]=CRGB(255);
      
      Serial.println("alert4");
      delay(250);
    }
  }  
}

String readData = "";

void ReadSerialData(){
  //reading data from unity for dynamic changes
  if (Serial.available() > 0) {
    readData = Serial.readString();
    
    //simon says prefix: #
    if(readData.startsWith("#")){
      sequence = readData.substring(1);
      Serial.println(sequence);
    }
    
    //RGB prefix: $
    if(readData.startsWith("$")){
      //do stuff
    }
    
    //RFID prefix: %
    if(readData.startsWith("%")){
      //do stuff
    }
  }
}

void ResetSimon(){
  //replace next with LED array change
  leds_simon[0]=CRGB(0);
  leds_simon[1]=CRGB(0);
  leds_simon[2]=CRGB(0);
  leds_simon[3]=CRGB(0);
  
  currentInputs = "";
}