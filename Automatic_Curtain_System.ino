int photoresistorValue = 0;
int flage = 0;

const int M1 =  5;         
const int M2 =  6;
const int AUTOMANUAL = 13;
const int ONpb = 12;
const int OFFpb = 11;
int automanualstate=0;
int ONpbstate=0;
int OFFpbstate=0;
void setup()
{
  //Sets pins to inputs or outputs
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(AUTOMANUAL, INPUT);
  pinMode(ONpb, INPUT);
  pinMode(OFFpb, INPUT);
     
}

void loop()
{
  automanualstate = digitalRead(AUTOMANUAL);
 if(automanualstate == 0)    //automatic
    {
      photoresistorValue = analogRead(A0); //Read & store anagloue pin
if (photoresistorValue > 200 && flage == 0) { //Check if it is dark
      digitalWrite(M1, HIGH); //Turn clockwise
      digitalWrite(M2, LOW);
      delay(1800);
      digitalWrite(M1, LOW); //Power off motor
      digitalWrite(M2, LOW);
    flage = 1;
  }
  if (photoresistorValue < 200 && flage == 1 ) { //Check if it light
    
        digitalWrite(M1, LOW); //Turn anticlockwise
      digitalWrite(M2, HIGH);
    delay(1800);
      digitalWrite(M1, LOW); //Power off motor
      digitalWrite(M2, LOW);
    flage = 0;
  }
  delay(10); //Delay a little bit to improve simulation performance
}
 else{             // MANUAL MODE
ONpbstate = digitalRead(ONpb);
  OFFpbstate = digitalRead(OFFpb);
 if (ONpbstate == 0 && flage == 0) { //Check if it is dark
      digitalWrite(M1, HIGH); //Turn clockwise
      digitalWrite(M2, LOW);
      delay(1800);
      digitalWrite(M1, LOW); //Power off motor
      digitalWrite(M2, LOW);
    flage = 1;
  }
  else if ( OFFpbstate == 0 && flage == 1 ) { //Check if it light
    
        digitalWrite(M1, LOW); //Turn anticlockwise
      digitalWrite(M2, HIGH);
    delay(1800);
      digitalWrite(M1, LOW); //Power off motor
      digitalWrite(M2, LOW);
    flage = 0;
  }
  delay(100); //Delay a little bit to improve simulation performance


 }
}
