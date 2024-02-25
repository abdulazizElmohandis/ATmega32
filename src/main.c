

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"


int main(void)
{

  MDIO_voidInit();
  HLCD_voidInit();

  u8 local_KeyValue;
  u8 counter = 0;
  while(1) //infinite loop
  {
    local_KeyValue = HKEYPAD_u8GetPressedKey();

    if (local_KeyValue != NO_KEY_PRESSED)
    {
      HLCD_voidSendData(local_KeyValue);
      counter++;

      if (counter == 16)
      {
        HLCD_voidGotoPosition(LCD_ROW_2, LCD_COL_1);
      }
      else if(counter == 32){
        HLCD_ClearDisplay();
        HLCD_voidGotoPosition(LCD_ROW_1, LCD_COL_1);
        counter = 0;

      }

      
    }
    

  }
}