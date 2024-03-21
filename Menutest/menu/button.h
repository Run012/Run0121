int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
bool button[6];
int cek_tombol;
int read_LCD_buttons()
{
 adc_key_in = analogRead(0); 
 if (adc_key_in > 1500) return btnNONE;
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 500)  return btnLEFT; 
 if (adc_key_in < 700)  return btnSELECT;   
 return btnNONE;
}

bool read_tombol(int button_index){
  if(button_index==0){
    button[button_index] = btnRIGHT;
    delay(50);
    return button[button_index];
  }else if(button_index==1){
    button[button_index] = btnLEFT;
    delay(50);
    return button[button_index];
  }else if(button_index==2){
    button[button_index] = btnUP;
    delay(50);
    return button[button_index];
  }else if(button_index==3){
    button[button_index] = btnDOWN;
    delay(50);
    return button[button_index];
  }else if(button_index==4){
    button[button_index] = btnSELECT;
    cek_tombol = 1;
    delay(50);
    return button[button_index];
  }
}
