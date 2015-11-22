/*******************************************************************************
* File Name: Led_BLE.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Led_BLE.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Led_BLE_PC =   (Led_BLE_PC & \
                                (uint32)(~(uint32)(Led_BLE_DRIVE_MODE_IND_MASK << (Led_BLE_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Led_BLE_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Led_BLE_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Led_BLE_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Led_BLE_DR & (uint8)(~Led_BLE_MASK));
    drVal = (drVal | ((uint8)(value << Led_BLE_SHIFT) & Led_BLE_MASK));
    Led_BLE_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Led_BLE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Led_BLE_DM_STRONG     Strong Drive 
*  Led_BLE_DM_OD_HI      Open Drain, Drives High 
*  Led_BLE_DM_OD_LO      Open Drain, Drives Low 
*  Led_BLE_DM_RES_UP     Resistive Pull Up 
*  Led_BLE_DM_RES_DWN    Resistive Pull Down 
*  Led_BLE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Led_BLE_DM_DIG_HIZ    High Impedance Digital 
*  Led_BLE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Led_BLE_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Led_BLE__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Led_BLE_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Led_BLE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Led_BLE_Read(void) 
{
    return (uint8)((Led_BLE_PS & Led_BLE_MASK) >> Led_BLE_SHIFT);
}


/*******************************************************************************
* Function Name: Led_BLE_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Led_BLE_ReadDataReg(void) 
{
    return (uint8)((Led_BLE_DR & Led_BLE_MASK) >> Led_BLE_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Led_BLE_INTSTAT) 

    /*******************************************************************************
    * Function Name: Led_BLE_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Led_BLE_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Led_BLE_INTSTAT & Led_BLE_MASK);
		Led_BLE_INTSTAT = maskedStatus;
        return maskedStatus >> Led_BLE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
