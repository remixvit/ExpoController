/*******************************************************************************
* File Name: Button_4.c  
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
#include "Button_4.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Button_4_PC =   (Button_4_PC & \
                                (uint32)(~(uint32)(Button_4_DRIVE_MODE_IND_MASK << (Button_4_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Button_4_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Button_4_Write
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
void Button_4_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Button_4_DR & (uint8)(~Button_4_MASK));
    drVal = (drVal | ((uint8)(value << Button_4_SHIFT) & Button_4_MASK));
    Button_4_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Button_4_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Button_4_DM_STRONG     Strong Drive 
*  Button_4_DM_OD_HI      Open Drain, Drives High 
*  Button_4_DM_OD_LO      Open Drain, Drives Low 
*  Button_4_DM_RES_UP     Resistive Pull Up 
*  Button_4_DM_RES_DWN    Resistive Pull Down 
*  Button_4_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Button_4_DM_DIG_HIZ    High Impedance Digital 
*  Button_4_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Button_4_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Button_4__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Button_4_Read
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
*  Macro Button_4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Button_4_Read(void) 
{
    return (uint8)((Button_4_PS & Button_4_MASK) >> Button_4_SHIFT);
}


/*******************************************************************************
* Function Name: Button_4_ReadDataReg
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
uint8 Button_4_ReadDataReg(void) 
{
    return (uint8)((Button_4_DR & Button_4_MASK) >> Button_4_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Button_4_INTSTAT) 

    /*******************************************************************************
    * Function Name: Button_4_ClearInterrupt
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
    uint8 Button_4_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Button_4_INTSTAT & Button_4_MASK);
		Button_4_INTSTAT = maskedStatus;
        return maskedStatus >> Button_4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
