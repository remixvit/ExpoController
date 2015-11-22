/*******************************************************************************
* File Name: Bootloader_En.c  
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
#include "Bootloader_En.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Bootloader_En_PC =   (Bootloader_En_PC & \
                                (uint32)(~(uint32)(Bootloader_En_DRIVE_MODE_IND_MASK << (Bootloader_En_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Bootloader_En_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Bootloader_En_Write
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
void Bootloader_En_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Bootloader_En_DR & (uint8)(~Bootloader_En_MASK));
    drVal = (drVal | ((uint8)(value << Bootloader_En_SHIFT) & Bootloader_En_MASK));
    Bootloader_En_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Bootloader_En_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Bootloader_En_DM_STRONG     Strong Drive 
*  Bootloader_En_DM_OD_HI      Open Drain, Drives High 
*  Bootloader_En_DM_OD_LO      Open Drain, Drives Low 
*  Bootloader_En_DM_RES_UP     Resistive Pull Up 
*  Bootloader_En_DM_RES_DWN    Resistive Pull Down 
*  Bootloader_En_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Bootloader_En_DM_DIG_HIZ    High Impedance Digital 
*  Bootloader_En_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Bootloader_En_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Bootloader_En__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Bootloader_En_Read
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
*  Macro Bootloader_En_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Bootloader_En_Read(void) 
{
    return (uint8)((Bootloader_En_PS & Bootloader_En_MASK) >> Bootloader_En_SHIFT);
}


/*******************************************************************************
* Function Name: Bootloader_En_ReadDataReg
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
uint8 Bootloader_En_ReadDataReg(void) 
{
    return (uint8)((Bootloader_En_DR & Bootloader_En_MASK) >> Bootloader_En_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Bootloader_En_INTSTAT) 

    /*******************************************************************************
    * Function Name: Bootloader_En_ClearInterrupt
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
    uint8 Bootloader_En_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Bootloader_En_INTSTAT & Bootloader_En_MASK);
		Bootloader_En_INTSTAT = maskedStatus;
        return maskedStatus >> Bootloader_En_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
