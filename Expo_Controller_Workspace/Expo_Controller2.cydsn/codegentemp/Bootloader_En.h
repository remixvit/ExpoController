/*******************************************************************************
* File Name: Bootloader_En.h  
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

#if !defined(CY_PINS_Bootloader_En_H) /* Pins Bootloader_En_H */
#define CY_PINS_Bootloader_En_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Bootloader_En_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Bootloader_En_Write(uint8 value) ;
void    Bootloader_En_SetDriveMode(uint8 mode) ;
uint8   Bootloader_En_ReadDataReg(void) ;
uint8   Bootloader_En_Read(void) ;
uint8   Bootloader_En_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Bootloader_En_DRIVE_MODE_BITS        (3)
#define Bootloader_En_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Bootloader_En_DRIVE_MODE_BITS))

#define Bootloader_En_DM_ALG_HIZ         (0x00u)
#define Bootloader_En_DM_DIG_HIZ         (0x01u)
#define Bootloader_En_DM_RES_UP          (0x02u)
#define Bootloader_En_DM_RES_DWN         (0x03u)
#define Bootloader_En_DM_OD_LO           (0x04u)
#define Bootloader_En_DM_OD_HI           (0x05u)
#define Bootloader_En_DM_STRONG          (0x06u)
#define Bootloader_En_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Bootloader_En_MASK               Bootloader_En__MASK
#define Bootloader_En_SHIFT              Bootloader_En__SHIFT
#define Bootloader_En_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bootloader_En_PS                     (* (reg32 *) Bootloader_En__PS)
/* Port Configuration */
#define Bootloader_En_PC                     (* (reg32 *) Bootloader_En__PC)
/* Data Register */
#define Bootloader_En_DR                     (* (reg32 *) Bootloader_En__DR)
/* Input Buffer Disable Override */
#define Bootloader_En_INP_DIS                (* (reg32 *) Bootloader_En__PC2)


#if defined(Bootloader_En__INTSTAT)  /* Interrupt Registers */

    #define Bootloader_En_INTSTAT                (* (reg32 *) Bootloader_En__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Bootloader_En_DRIVE_MODE_SHIFT       (0x00u)
#define Bootloader_En_DRIVE_MODE_MASK        (0x07u << Bootloader_En_DRIVE_MODE_SHIFT)


#endif /* End Pins Bootloader_En_H */


/* [] END OF FILE */
