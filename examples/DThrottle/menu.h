// Menu system

bool (Action)(int parm);
class Menu {
  public:
    Action cAction;
    char title[8];
    uint8_t nitems;
    struct {
      String name;
      Action* action;  // actions return true if they need to be called again, false if finished
    } item[20];
    uint8_t curItem;
    
    void addItem( String n, Action* a) {
      if(nitems+1 >= mex_items) return false;
      nitems++;
      name[nitems] = n;
      action[nitems] = a;
    }
    
    void move(uint8_t n) {
      curItem += n;
      if( curItem<0 ) curItem += max_items;          // roll
      if( curItem>max_items ) curItem -= max_items;
    }
    
    bool subMenu() {
      if( action ) {
        cAction = action[curItem];
        if( action[curItem]() ) return true;
        curAction = 0;
      } 
      return false;
    }
    
    void show() {
      int first =  mod(curItem - pre_lines, max_items);
      int last = mod(curItem + post_lines, max_items);
      for(int i=firstl i<last; i++) {
        display(x,y,item[i].name);
      }
      // show cursor
      display(x-8,y,"->");
    }
    
    process() {
      if( action ) return subMenu();
      if( select() ) return subMenu();
      else if( up() ) move(-1);
      else if( down() ) move(1);
      return;
    }
};

void mainMenu() {
  // display connection
  // display battery
  // display power
  // display loco#
  // display direction
  // display function status
}

bool locoMenu() {
  static int newLoco = -1;
  if( newLoco == -1 ) newLoco = curLoco;
  // exit on select or left
  if( select() ) return false;
  if( left() ) return false
  // display current loco
  display(x,y, newLoco);
  // use joystick inout to change loco number
  int j = (joystick() / 10)^2;
  if( j!=0 ) {
    newLoco += j;
    if(newLoco>9999) newLoco=9999;
    if(newLoco<0) newLoco=0;
    return true;
  }
  return true;
}

void chooseRack(int i) {
  // update recent locos
  
}

void rackMenu() {
  show();
}

bool subMenu() {
  static Menu menu = {
    0, "choose:", 20,
    { 0, chooseRecent(3) },
    { 0, chooseRecent(2) },
    { 0, chooseRecent(1) },
    { 0, chooseRecent(0) },
    { "Loco->", locoMenu },
    { "Rack->", rackMenu },
    { "F0", toggle(0)},
    { "F1", toggle(0)},
    { "F2", toggle(0)},
    { "F3", toggle(0)},
    { "F4", toggle(0)},
    { "F5", toggle(0)}
  };
  show();
  
  bool 
}
