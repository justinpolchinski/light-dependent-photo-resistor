//components led
//voltage sensor
//light dependent photo resistor
//Put LDR between + and - wires of voltage sensor

int lightSensor3 = A3;
float voltOut = 0.0;
float voltIn = 0.0;
float R1 = 30000.0; //  
float R2 = 7500.0; // 
int value = 0;
int led4 = 4;



void setup() {
 
  Serial.begin(9600);
  pinMode(led4, OUTPUT);
  pinMode(lightSensor3, INPUT);
  
  Serial.println("Light Check");
  
}


void loop() {
value = analogRead(lightSensor3);
voltOut = (value * 5.0)/1024.0;
voltIn = voltOut / (R2/(R1+R2));

Serial.print("Voltage Changing with Light: ");
Serial.println(voltIn, 3);
delay(250);
if(voltIn<3){
  digitalWrite(led4, HIGH);
  
}
else{
  digitalWrite(led4,LOW);

}
}
