
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;


int delay_gap = 300;
int speakerPin = 13;
int i = 0;


// Init the Pins used for 10K pots
const int redPotPin = 0;
const int greenPotPin = 1;
const int bluePotPin = 2;
 
// Init our Vars
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;


void setup() 
{
  for(i = 0; i< 5; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}


void loop() 
{


/*  for(i = 0; i< 5; i++) {
    digitalWrite(i, LOW);    
  }
  delay(delay_gap);              

  for(i = 0; i< 5; i++) {
    digitalWrite(i, HIGH);
    delay(delay_gap);    
  }

  digitalWrite(RED_PIN,HIGH);  
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);
  delay(delay_gap);

  digitalWrite(RED_PIN,HIGH);  
  digitalWrite(GREEN_PIN,HIGH);
  digitalWrite(BLUE_PIN,LOW);
  delay(delay_gap);

  digitalWrite(RED_PIN,LOW);  
  digitalWrite(GREEN_PIN,HIGH);
  digitalWrite(BLUE_PIN,HIGH);
  delay(delay_gap);

  for(i = 0; i< 5; i++) {
    digitalWrite(i, LOW);    
  }
  delay(delay_gap);              

  for(i = 0; i< 5; i++) {
    digitalWrite(i, HIGH);   
    delay(delay_gap);              
    digitalWrite(i, LOW);    
  }
  delay(delay_gap);              

  for(i = 5; i>=0; i--) {
    digitalWrite(i, HIGH);
    delay(delay_gap);    
  }
  delay(delay_gap);              


  digitalWrite(RED_PIN,LOW);  
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);
  */

  analogWrite(BLUE_PIN,random(255));
  analogWrite(GREEN_PIN,random(255));
  analogWrite(RED_PIN,random(255));
  delay(delay_gap);              
}



//int pitch[] = {261, 277, 294, 311, 330};
//tone(speakerPin, pitch[i%4]);
//noTone(speakerPin);

void setColor(int red, int green, int blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}
