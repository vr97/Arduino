const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration1;
int distance;
int sensor_value;



int buzzerPin = 8;
int tempo = 200;
//char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
void playTheShit(char note, int duration) {
  char notesName[] = { 'd', 'e', 'f', 'g','h'};
  int tones[] = { 261, 293, 329, 349, 392 };
  for (int i = 0; i<sizeof(tones); i++) {
    
   
    // Bind the note took from the char array to the array notesName
    if (note == notesName[i]) {
      // Bind the notesName to tones
      tone(buzzerPin, tones[i], duration);
    
    }
  }
}
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
Serial.begin(9600);  

  pinMode(buzzerPin, OUTPUT);
}
void loop() {
 
  // Scan each char from "notes"
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

sensor_value=digitalRead(trigPin); // Reading sensor value from pin 7
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1= pulseIn(echoPin, HIGH);
distance= duration1*0.034/2;

 if(distance==40){
  
 
  for (int i = 0; i<sizeof(notes)-1; i++) {
   
   
         
            
    if (notes[i] == ' ') {
      
      // If find a space it rests
      delay(duration[i] * tempo);
    } else {
      
       
      playTheShit(notes[i], duration[i] * tempo);
    
    }
    // Pauses between notes
    delay((tempo*2)*duration[i]);
          }
          
  
 }
 else
 {
  digitalWrite(buzzerPin,LOW); 
 }
Serial.print("Distance: ");
Serial.println(distance);
  }



