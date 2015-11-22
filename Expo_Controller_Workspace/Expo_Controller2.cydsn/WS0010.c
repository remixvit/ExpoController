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
#include "WS0010.h"

    void inline Enable_Frame_DDR()
    {
        uint8 Line, Col;
    
        for(Line = 0; Line < LCD_Line; Line++)
        {
            for(Col = 0; Col < LCD_Column; Col++)
            {
                FrameDDR[Line][Col] = 0x20;
            }
        }
        Frame_Tail = 0;
    }
    
    void inline LCD_WS0010Start()
    {
      
        LCD_WriteControl(0x00);//
        LCD_WriteControl(0x00);
        LCD_WriteControl(0x02);
        LCD_WriteControl(0x2A);
        LCD_WriteControl(0x08);
        LCD_WriteControl(0x01);
        LCD_WriteControl(0x02);
        LCD_WriteControl(0x06);
        
        Enable_Frame_DDR();
        LCD_WriteControl(0x0C);
    }
    
    void Add_To_DDR(char8 *string)
    {
        uint8 TailBuf = Frame_Tail;
        uint8 index = 1;
        uint8 Col = 0;
        uint8 Line;
        char8 current = *string;
        if(TailBuf == 4)
        {
            for(Col = 0; Col < LCD_Column; Col++)
            {
                FrameDDR[0][Col] = (char8) ' ';
            }
            for(Line = 1; Line< LCD_Line; Line++)
            {
                for(Col = 0; Col < LCD_Column; Col++)
                {
                    FrameDDR[Line - 1][Col] = FrameDDR[Line][Col]; 
                }
            }
            for(Col = 0; Col < LCD_Column; Col++)
            {
                FrameDDR[3][Col] = (char8) ' ';
            }
            Col = 0;
            while((char8) '\0' != current)
                {
                    FrameDDR[3][Col] = current;
                    current = string[index];
                    index++;
                    Col++;
                }
        }
        else
        {
            while((char8) '\0' != current)
                {
                    FrameDDR[TailBuf][Col] = current;
                    current = string[index];
                    index++;
                    Col++;
                }
                Frame_Tail++;
        }
    }
    
    void Print_DDR()
    {
        uint8 Line, Col;
    
        for(Line = 0; Line < LCD_Line; Line++)
        {
            LCD_Position(Line,0);
            for(Col = 0; Col < LCD_Column; Col++)
            {
                LCD_PutChar(FrameDDR[Line][Col]);
            }
        }
    }

/* [] END OF FILE */
