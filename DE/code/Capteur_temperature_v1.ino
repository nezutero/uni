const int TEMP = A2; // pin num
                        
float somme = 0;
int count = 0;

void setup() 
{             
  Serial.begin(9600);
} 

void loop() 
{
  int data = analogRead(TEMP);
  float V_Temp = data * 5.0 / 1023.0;
  float Vout   = V_Temp / 11.0;
  float TEMP_C = Vout * 100.0;

  somme += TEMP_C;
  count++;

  if (count == 5) {
    float avg = somme / 5.0;
    Serial.print("Moyenne: ");
    Serial.print(avg);
    Serial.print(" C");

    somme = 0;
    count = 0;
  }

  delay(1000);
}
