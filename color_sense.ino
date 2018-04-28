void setup() {
  Serial.begin(115200);
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}

void loop() {
 
  bool left_first = CircuitPlayground.leftButton();
  bool right_first = CircuitPlayground.rightButton();
  delay(20);
  bool left_second = CircuitPlayground.leftButton();
  bool right_second = CircuitPlayground.rightButton();
 
  if ((left_first && !left_second) || (right_first && !right_second)) {
    
    CircuitPlayground.clearPixels();
  
    uint8_t red, green, blue;
    CircuitPlayground.senseColor(red, green, blue);
   
    Serial.print("Color: red=");
    Serial.print(red, DEC);
    Serial.print(" green=");
    Serial.print(green, DEC);
    Serial.print(" blue=");
    Serial.println(blue, DEC);
   
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, red, green);
    }
    CircuitPlayground.strip.show();
  }
}
