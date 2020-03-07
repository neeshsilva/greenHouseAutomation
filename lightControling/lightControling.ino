const int interiorLdr0 = A0;



const int interiorLightControler = 2;

void pidLigthController();

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Well Come");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(analogRead(interiorLdr0));
  delay(1000);
}

void pidLigthController(){
  
}
