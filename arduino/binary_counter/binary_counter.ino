int COLUMN1 = 11;
int COLUMN2 = 10; 
int COLUMN4 = 9; 
int COLUMN8 = 8; 

int digits[4] = {COLUMN1, COLUMN2, COLUMN4, COLUMN8};

//string to display on Serial Monitor CTRL-SHIFT-M

String stringOne;

void setup() {

  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  stringOne = String();
  
  pinMode(COLUMN1, OUTPUT);
  pinMode(COLUMN2, OUTPUT);
  pinMode(COLUMN4, OUTPUT);
  pinMode(COLUMN8, OUTPUT);

  
  
 
}

// the loop function runs over and over again forever
void loop2() {
  digitalWrite(COLUMN1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(COLUMN1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second

  digitalWrite(COLUMN2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(COLUMN2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);         // wait for a second


}

void loop() {

  int y = 0; 

  while(1){

    y= showNumber(y,16);
    

    Serial.print("Y value");
    Serial.println(y);
    
    delay(500); 
  }


}

/**
 * Shows the input number on LED based on the binary (mod=16) oo any other basearray.
 */
int showNumber(int x,int mod){

  int i = 0; 
  int y = x;

  for(i = 0; i < 4; i++){

    if(x % 2 == 0){
      digitalWrite(digits[i], LOW);  
    }else{
      digitalWrite(digits[i], HIGH);
    }

    x = x/2; 

  }
  
  
  y = (y + 1) % mod;    
  return y;
}

