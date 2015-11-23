/*******************************************************************************
* File Name: PWM_LCD_Led.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWM_LCD_Led_H) /* Pins PWM_LCD_Led_H */
#define CY_PINS_PWM_LCD_Led_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWM_LCD_Led_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_LCD_Led_Write(uint8 value) ;
void    PWM_LCD_Led_SetDriveMode(uint8 mode) ;
uint8   PWM_LCD_Led_ReadDataReg(void) ;
uint8   PWM_LCD_Led_Read(void) ;
uint8   PWM_LCD_Led_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_LCD_Led_DRIVE_MODE_BITS        (3)
#define PWM_LCD_Led_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWM_LCD_Led_DRIVE_MODE_BITS))

#define PWM_LCD_Led_DM_ALG_HIZ         (0x00u)
#define PWM_LCD_Led_DM_DIG_HIZ         (0x01u)
#define PWM_LCD_Led_DM_RES_UP          (0x02u)
#define PWM_LCD_Led_DM_RES_DWN         (0x03u)
#define PWM_LCD_Led_DM_OD_LO           (0x04u)
#define PWM_LCD_Led_DM_OD_HI           (0x05u)
#define PWM_LCD_Led_DM_STRONG          (0x06u)
#define PWM_LCD_Led_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWM_LCD_Led_MASK               PWM_LCD_Led__MASK
#define PWM_LCD_Led_SHIFT              PWM_LCD_Led__SHIFT
#define PWM_LCD_Led_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_LCD_Led_PS                     (* (reg32 *) PWM_LCD_Led__PS)
/* Port Configuration */
#define PWM_LCD_Led_PC                     (* (reg32 *) PWM_LCD_Led__PC)
/* Data Register */
#define PWM_LCD_Led_DR                     (* (reg32 *) PWM_LCD_Led__DR)
/* Input Buffer Disable Override */
#define PWM_LCD_Led_INP_DIS                (* (reg32 *) PWM_LCD_Led__PC2)


#if defined(PWM_LCD_Led__INTSTAT)  /* Interrupt Registers */

    #define PWM_LCD_Led_INTSTAT                (* (reg32 *) PWM_LCD_Led__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWM_LCD_Led_DRIVE_MODE_SHIFT       (0x00u)
#define PWM_LCD_Led_DRIVE_MODE_MASK        (0x07u << PWM_LCD_Led_DRIVE_MODE_SHIFT)


#endif /* End Pins PWM_LCD_Led_H */


/* [] END OF FILE */
