#include <DigiCombo.h>

int repeat = 5;
int phonePattern[4] = {0, 3, 6, 7};

void setup() {
  DigiCombo.begin();


  DigiCombo.tapSingle(5000, 5000);
  DigiCombo.tapSingle(5000, 5000);

  
  DigiCombo.delay(2000);
  

  for (int i = 0; i < 4000; i += 100) {
    DigiCombo.moveFinger(5000, 7000 - i);   
  }
  
  DigiCombo.release();
  DigiCombo.delay(2000);
}

void loop() {
  if (repeat == 0) {
    DigiCombo.delay(1000);
    return;
  }
  
  int selectedPointIndex[4] = {0, 0, 0, 0};

  for (int i = 0; i < 4; i++) {
    while (true) {      
      int pointIndex = repeat != 1 ? (random() % 9) : phonePattern[i];
      selectedPointIndex[i] = pointIndex;
      
      int count = 0;    
      for (int j = 0; j <= i; j++) {
        if (selectedPointIndex[j] == pointIndex) count++;
      }

      if (count == 1) break;
    }
    
    DigiCombo.moveFinger(2500 + (selectedPointIndex[i] % 3) * 2500, 4100 + (selectedPointIndex[i] / 3) * 1200);
  }

  DigiCombo.release();
  DigiCombo.delay(1000);

  repeat--;
}
