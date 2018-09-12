/* Read LDR and write in LED RGB 
 * Francis David (www.fdavid.com.br) 
 * 
 * Build with IDE Arduino 1.8.4
 * 
 * REQUIREMENT
 *  LDR
 *  LED RGB
 */

#define PIN_GREEN 12
#define PIN_RED 15
#define PIN_BLUE 13

void setup() {
  pinMode(A0, INPUT);
  
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int value = analogRead(A0);
  int adjust_low, adjust_high;
    
  adjust_high = map(value, 0, 1024, 0, 255);
  adjust_low = map(value, 0, 1024, 255, 0);
  
  Serial.println(value);
  
  analogWrite(PIN_GREEN, adjust_low); 
  analogWrite(PIN_BLUE, 0); 
  analogWrite(PIN_RED, adjust_high);
  
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
