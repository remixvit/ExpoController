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
#include <project.h>
#include "OPT3001.h"
#include "WS0010.h"
#include "TaskDispatcher.h"
#include <string.h>
#include <stdio.h>

typedef struct
{
    uint8 DisplayCursor;
    uint32 Lux;
    uint8 OPT_Status;
    uint16 Max_Bright;
    uint16 Min_Bright;
}MyStruct;
volatile MyStruct GlobalStruct;

typedef struct
{
    uint32 Time;
    uint32 Alarm;
}TimeType;
volatile TimeType TimeStruct;
//volatile char Main_Display_Buf[4][21];




void Check_Boot()
{
    if(Bootloader_En_Read() == 0)
    {
        Bootloadable_Load();
    }
}

void Check_OPT()
{
    uint16 Manufacturer, Device;
    uint8 Status;
    
    Status = I2C_ReadRegister(OPT3001_I2C_ADDRESS, REG_DEVICE_ID, &Device);
    
    if(Status == 0)
    {
        Add_To_DDR("Optic Error");
        return;
        I2C_I2C_MSTR_ERR_LB_NAK;
        I2C_I2C_MSTR_ERR_ARB_LOST;
    }
    
    Status = I2C_ReadRegister(OPT3001_I2C_ADDRESS, REG_MANUFACTURER_ID, &Manufacturer);
    
    if(Status == 0)
    {
        Add_To_DDR("Optic Error");
        return;
    }
    
    if((Manufacturer == 0x5449) && (Device == 0x3001))
    {
        Add_To_DDR("Optic OK");
        Add_To_DDR("Device OPT3001 EN");
        Print_DDR();
        return;
    }              
    return;
}


void Start_Display()
{
    SetTimerTask(Check_OPT, 10);
    LCD_WS0010Start();
    Add_To_DDR("OS Start");
    Print_DDR();
}
void WaitPowerStab()
{
   SetTimerTask(Start_Display, 1000);
}

void OPT_Get_Result()
{
    if(GlobalStruct.OPT_Status == 0)
    {
        if(OPT_StartConvert())
        {
            SetTimerTask(OPT_Get_Result, 1000);
            GlobalStruct.OPT_Status = 1;
        }
        else
        {
            SetTimerTask(OPT_Get_Result, 300);
            GlobalStruct.OPT_Status = 0;
        }
        
    }
    else if(GlobalStruct.OPT_Status == 1)
    {
        if(OPT_IsReady())
        {
            OPT_GetResultString(&GlobalStruct.Lux);
            SetTimerTask(OPT_Get_Result, 2000);
            GlobalStruct.OPT_Status = 0;
        }
        else
        {
            SetTimerTask(OPT_Get_Result, 800);
        }
        
    }
}

void Main_Display_Print()
{
    char BLE_Status[20] = "BLE_Status: ";
    char Lamp_Status[20] = "UV Lamp: ";
    char timeBuffer[20];
    const char ON[3] = "ON";
    const char OFF[4] = "OFF";
    const char Conected[9] = "Conected";
    const char Error[6] = "Error";
    TimeStruct.Time = RTC_GetTime();
    sprintf(timeBuffer, "            %02lu:%02lu:%02lu", RTC_GetHours(TimeStruct.Time), RTC_GetMinutes(TimeStruct.Time), RTC_GetSecond(TimeStruct.Time));
    strcat(BLE_Status, ON);
    strcat(Lamp_Status, OFF);
    Add_To_DDR(timeBuffer);
    Add_To_DDR(OPT_Out_String);    
    Add_To_DDR(BLE_Status);
    Add_To_DDR(Lamp_Status);
    Print_DDR();
    SetTimerTask(Main_Display_Print, 200);
}

void Brightles_PID_Controll()
{
    volatile uint8 Procent = 0;
    volatile uint8 PWM;
    if(GlobalStruct.Lux > 0)
    {
        Procent = GlobalStruct.Lux / 160;
        if(Procent > 100) Procent = 100;
        PWM = (uint8)(68 - (0.68 * Procent));
        PWM_WriteCompare1(PWM);
    }
    else
    {
        PWM = 68;
        PWM_WriteCompare1(PWM);
    }
    SetTimerTask(Brightles_PID_Controll, 2000);
}
void BLE_Status()
{
    char Comand[10] = "AT";
    uint16 Inc = 0;
    UART_UartPutString(Comand);
    while(UART_SpiUartGetRxBufferSize() == 0)
    {
        Inc++;
        if(Inc>1000) return;
    }
    Inc = 0;
    while(UART_SpiUartGetRxBufferSize() > 0)
    {
        Comand[Inc] = (char)UART_SpiUartReadRxData();
        Inc++;
    }
    Add_To_DDR(Comand);
    Print_DDR();
}


int main()
{
    CyGlobalIntEnable;
    Check_Boot();
    Timer_RTOS_Start();
    PWM_Start();
    I2C_Start();
    UART_Start();
    RTC_Start();
    RTC_SetPeriod(1,1000);
    RTOS_Start();
    SetTask(Brightles_PID_Controll);
    LCD_WS0010Start();
    SetTask(WaitPowerStab);
    SetTimerTask(OPT_Get_Result, 1300);
    //BLE_Status();
    SetTimerTask(Main_Display_Print, 2000);
    for(;;)
    {
        TaskManager();
    }
}

/* [] END OF FILE */
