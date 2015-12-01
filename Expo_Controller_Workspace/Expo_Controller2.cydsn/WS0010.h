/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <Project.h>
    #define LCD_Line 4
    #define LCD_Column 20
    volatile char8 FrameDDR[LCD_Line][LCD_Column];
    volatile uint8 Frame_Tail;
    
    void inline Enable_Frame_DDR();
    void inline LCD_WS0010Start();
    void Add_To_DDR(char8 *string);
    void Print_DDR();
    void ScreenSaver(char *Str, uint16 Rand);
/* [] END OF FILE */
