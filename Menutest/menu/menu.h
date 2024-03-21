#include "button.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte menu = 0; //byte menu {0}
byte sub_menu = 0;
bool status_sub_menu = false, back = false;
const String StrText[] = {"TESLA MK.7", "-BERSERKER-", 
                          "Helga", "Saeful", "Abu", "Sepdi", "Salsa", "Taufik", "Bintang", "Awanda", "Sulthan", "Enggar", "Rahmat" , "Nadaa",
                          "Chulqy", "Imal", "Ragil", "Rifqi", "Aef", "Deo", "Alya", "Ferro", "Febri", "Arsyad", "Azhar", "Agung", "Iwan" , "Rafid",
                          "Firman", "Fahmi", "Akhdan", "Aryo", "Fikra", "AI", "Iqbal", "Taqi", "Bagja", "Tegar" , "Harun"};
void init_menu(){
  // lcd.init();
  lcd.init();
  lcd.backlight();
}
void start_menu(){
  // back = false; 

  byte i;
  String StrTemp, Str;

  while (true){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print(StrText[0]);
    lcd.setCursor(4, 1);
    lcd.print(StrText[1]);
    for (i = 0; i < StrText[0].length(); i++){
      for(int x = 0; x < 20; x++){
        if (read_tombol(0)){
          // menu_master();}
          lcd.clear();
        }else if (read_tombol(1)){
          // plan_set();}
          lcd.clear();
        }else if (read_tombol(4)){
          // startrun();}
          lcd.clear();
        }else if (read_tombol(5)){
          // startrun();}
          lcd.clear();
        delay(10);
      }

      lcd.clear();
      lcd.setCursor(3, 0);
      StrTemp = StrText[0];
      StrTemp[i] = '*';
      lcd.print(StrTemp);
      lcd.setCursor(4, 1);
      lcd.print(StrText[1]);
      delay (20);
    }

    for (i = 0; i < StrText[1].length(); i++){
      for(int x = 0; x < 20; x++){
         if (read_tombol(0)){
          // menu_master();
           lcd.clear();
           lcd.print("0");
        }
        else if (read_tombol(1)){
          // plan_set();
           lcd.clear();
            lcd.print("1");
        }
        else if (read_tombol(4)){
          // startrun();
           lcd.clear();
            lcd.print("2");
        }
        else if (read_tombol(5)){
          // startrun();
           lcd.clear();
            lcd.print("3");
      delay(20);
        }
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print(StrText[0]);
      lcd.setCursor(4, 1);
      StrTemp = StrText[1];
      StrTemp[i] = '*';
      lcd.print(StrTemp);
      delay (20);
    }

    for (i = 2; i < 33; i++){
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print(StrText[i]);
      i++;
      lcd.setCursor(0, 1); lcd.print(StrText[i]);
      i++;
      lcd.setCursor(16-(StrText[i].length()), 0); lcd.print(StrText[i]);
      i++;
      lcd.setCursor(16-(StrText[i].length()), 1); lcd.print(StrText[i]);
      
      for(int x = 0; x < 60; x++){
        lcd_key = read_LCD_buttons();
        if (lcd_key == btnRIGHT){
          // menu_master();
           lcd.clear();
           lcd.print("0");
        }
        else if (read_tombol(1)){
          // plan_set();
           lcd.clear();
            lcd.print("1");
        }
        else if (read_tombol(4)){
          // startrun();
           lcd.clear();
            lcd.print("2");
        }
        else if (read_tombol(5)){
          // startrun();
           lcd.clear();
            lcd.print("3");
        }
      delay(20);
      }
    }
  }
    }
  }
}
void sub_menu_master(){  
  switch (menu){
    case 0 :
      lcd.setCursor(0, 0); lcd.print("Sensor menu: ");
      // sensor_menu();
      break;
    case 1 :
      lcd.setCursor(0, 0); lcd.print("Walk menu: ");
      // walk_menu(); 
      break; 
    case 2 :
      lcd.setCursor(0, 0); lcd.print("Testgrip menu: ");
      // test_grip_menu(); 
      break;
    case 3 :
      lcd.setCursor(0, 0); lcd.print("Set Tolerance menu: ");
      // set_tolerance_menu(); 
      break;       
  }     
} 
void switch_menu(byte menu){
  if (status_sub_menu == true){
    sub_menu_master();
  }
  else if (status_sub_menu == false){
    start_menu();
  }
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Input Option");
    switch (menu){
      case 0 :  
        lcd.setCursor(0, 1);
        lcd.print("->1. Sensors Check");
        break;
      case 1 :  
        lcd.setCursor(0, 1);
        lcd.print("->2. Walk Test"); 
        break;
      case 2 :  
        lcd.setCursor(0, 1);
        lcd.print("->3. Test Grip"); 
        break;
      case 3 :
        lcd.setCursor(0, 1);
        lcd.print("->4. Set tolerance"); 
        break;
    }
  }
}
void menu_master(){
  back = false;
  lcd.clear();
  menu = 0;
  while (true){
    switch_menu(menu);
    if (read_tombol(3)){
      if (menu == -1) menu = 3;
      else menu--;
    }
    else if (read_tombol(2)){
      if (menu == 4) menu = 0;    
      else menu++;
    }
    else if (read_tombol(1)){
      status_sub_menu = false;
    }
    else if (read_tombol(0)){
      status_sub_menu = true;
    }
  }
}