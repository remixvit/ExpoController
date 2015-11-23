/*******************************************************************************
* File Name: PWM_Contrast.c  
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
#include "PWM_Contrast.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWM_Contrast_PC =   (PWM_Contrast_PC & \
                                (uint32)(~(uint32)(PWM_Contrast_DRIVE_MODE_IND_MASK << (PWM_Contrast_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWM_Contrast_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWM_Contrast_Write
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
void PWM_Contrast_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWM_Contrast_DR & (uint8)(~PWM_Contrast_MASK));
    drVal = (drVal | ((uint8)(value << PWM_Contrast_SHIFT) & PWM_Contrast_MASK));
    PWM_Contrast_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWM_Contrast_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWM_Contrast_DM_STRONG     Strong Drive 
*  PWM_Contrast_DM_OD_HI      Open Drain, Drives High 
*  PWM_Contrast_DM_OD_LO      Open Drain, Drives Low 
*  PWM_Contrast_DM_RES_UP     Resistive Pull Up 
*  PWM_Contrast_DM_RES_DWN    Resistive Pull Down 
*  PWM_Contrast_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWM_Contrast_DM_DIG_HIZ    High Impedance Digital 
*  PWM_Contrast_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWM_Contrast_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWM_Contrast__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWM_Contrast_Read
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
*  Macro PWM_Contrast_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWM_Contrast_Read(void) 
{
    return (uint8)((PWM_Contrast_PS & PWM_Contrast_MASK) >> PWM_Contrast_SHIFT);
}


/*******************************************************************************
* Function Name: PWM_Contrast_ReadDataReg
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
uint8 PWM_Contrast_ReadDataReg(void) 
{
    return (uint8)((PWM_Contrast_DR & PWM_Contrast_MASK) >> PWM_Contrast_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWM_Contrast_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWM_Contrast_ClearInterrupt
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
    uint8 PWM_Contrast_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWM_Contrast_INTSTAT & PWM_Contrast_MASK);
		PWM_Contrast_INTSTAT = maskedStatus;
        return maskedStatus >> PWM_Contrast_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
