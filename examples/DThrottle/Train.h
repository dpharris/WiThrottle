class Train {
 public:
  int id;
  int speed;
  Train(int i, int s) { id = i; speed = s; }
  int getId() { return id; }
  setId(int i) { id = i; }
  int getSpeed() { return speed; }
  setSpeed(int speed) { speed = s; }
  
  void displayID() {
    Serial.print("\nTrain: ");
    Serial.print(id);
  }
  void displaySpeed() {
    Serial.print("\nSpeed: ");
    Serial.print(speed);
  }
};
