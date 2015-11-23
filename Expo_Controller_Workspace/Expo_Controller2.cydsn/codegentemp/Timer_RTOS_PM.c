/*******************************************************************************
* File Name: Timer_RTOS_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Timer_RTOS.h"

static Timer_RTOS_BACKUP_STRUCT Timer_RTOS_backup;


/*******************************************************************************
* Function Name: Timer_RTOS_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_RTOS_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_RTOS_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_RTOS_Sleep(void)
{
    if(0u != (Timer_RTOS_BLOCK_CONTROL_REG & Timer_RTOS_MASK))
    {
        Timer_RTOS_backup.enableState = 1u;
    }
    else
    {
        Timer_RTOS_backup.enableState = 0u;
    }

    Timer_RTOS_Stop();
    Timer_RTOS_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_RTOS_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_RTOS_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_RTOS_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_RTOS_Wakeup(void)
{
    Timer_RTOS_RestoreConfig();

    if(0u != Timer_RTOS_backup.enableState)
    {
        Timer_RTOS_Enable();
    }
}


/* [] END OF FILE */
