/*******************************************************************************
* File Name: ADC_3V.c  
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
#include "ADC_3V.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ADC_3V_PC =   (ADC_3V_PC & \
                                (uint32)(~(uint32)(ADC_3V_DRIVE_MODE_IND_MASK << (ADC_3V_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ADC_3V_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ADC_3V_Write
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
void ADC_3V_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ADC_3V_DR & (uint8)(~ADC_3V_MASK));
    drVal = (drVal | ((uint8)(value << ADC_3V_SHIFT) & ADC_3V_MASK));
    ADC_3V_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ADC_3V_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ADC_3V_DM_STRONG     Strong Drive 
*  ADC_3V_DM_OD_HI      Open Drain, Drives High 
*  ADC_3V_DM_OD_LO      Open Drain, Drives Low 
*  ADC_3V_DM_RES_UP     Resistive Pull Up 
*  ADC_3V_DM_RES_DWN    Resistive Pull Down 
*  ADC_3V_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ADC_3V_DM_DIG_HIZ    High Impedance Digital 
*  ADC_3V_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ADC_3V_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ADC_3V__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ADC_3V_Read
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
*  Macro ADC_3V_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADC_3V_Read(void) 
{
    return (uint8)((ADC_3V_PS & ADC_3V_MASK) >> ADC_3V_SHIFT);
}


/*******************************************************************************
* Function Name: ADC_3V_ReadDataReg
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
uint8 ADC_3V_ReadDataReg(void) 
{
    return (uint8)((ADC_3V_DR & ADC_3V_MASK) >> ADC_3V_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADC_3V_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADC_3V_ClearInterrupt
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
    uint8 ADC_3V_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ADC_3V_INTSTAT & ADC_3V_MASK);
		ADC_3V_INTSTAT = maskedStatus;
        return maskedStatus >> ADC_3V_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
