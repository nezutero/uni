
/******************************************************************************************/
/* 
/* L1 - DE1
/* BARGRAPH
/*
/* S. CRAND - mai 2025
/*
/* Statut :  
/******************************************************************************************/

/**********************************/
/* Bargraph : Broches utilisées   */
/*
pin ADC : 4 -> LED 8 -> pin mC : 13
pin ADC : 5 -> LED 7 -> pin mC : 12
pin ADC : 9 -> LED 5 -> pin mC : 8
pin ADC : 6 -> LED 4 -> pin mC : 11
pin ADC : 7 -> LED 3 -> pin mC : 10
pin ADC : 8 -> LED 6 -> pin mC : 9
pin ADC : 10 -> LED 10 -> pin mC : 7
pin ADC : 11 -> LED 1 -> pin mC : 6
/**********************************/

 //LEDS

int bargraph[8] = {13,12,8,11,10,9,7,6};



void setup()
{

// Définition du débit de la 
// transmission série : 9600 bits/s

for (int i = 0; i <= 7; i++) {
  pinMode(bargraph[i], OUTPUT);
}        
Serial.begin(9600);

}

void loop()
{ 

for (int i = 0; i <= 7; i++) {
  digitalWrite(bargraph[i], HIGH);
  if (i>0) { digitalWrite(bargraph[i-1], LOW);}
  delay(500);
} 
digitalWrite(bargraph[7], LOW);

}
