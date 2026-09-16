const int LUM = A0;
                           
int prevData = 0;

void setup() 
{             
  Serial.begin(9600);
  prev = analogRead(LUM);
} 

void loop() 
{
  int data = analogRead(LUM);
  
  if (abs(data - prevData) > 100){
    Serial.println("Changements importants: ");
    Serial.print(data);
    prev = data;
  }
  delay(100);                      
}
