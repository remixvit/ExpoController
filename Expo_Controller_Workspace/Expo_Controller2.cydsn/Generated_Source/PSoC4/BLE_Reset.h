/*******************************************************************************
* File Name: BLE_Reset.h  
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

#if !defined(CY_PINS_BLE_Reset_H) /* Pins BLE_Reset_H */
#define CY_PINS_BLE_Reset_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BLE_Reset_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BLE_Reset_Write(uint8 value) ;
void    BLE_Reset_SetDriveMode(uint8 mode) ;
uint8   BLE_Reset_ReadDataReg(void) ;
uint8   BLE_Reset_Read(void) ;
uint8   BLE_Reset_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BLE_Reset_DRIVE_MODE_BITS        (3)
#define BLE_Reset_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BLE_Reset_DRIVE_MODE_BITS))

#define BLE_Reset_DM_ALG_HIZ         (0x00u)
#define BLE_Reset_DM_DIG_HIZ         (0x01u)
#define BLE_Reset_DM_RES_UP          (0x02u)
#define BLE_Reset_DM_RES_DWN         (0x03u)
#define BLE_Reset_DM_OD_LO           (0x04u)
#define BLE_Reset_DM_OD_HI           (0x05u)
#define BLE_Reset_DM_STRONG          (0x06u)
#define BLE_Reset_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define BLE_Reset_MASK               BLE_Reset__MASK
#define BLE_Reset_SHIFT              BLE_Reset__SHIFT
#define BLE_Reset_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLE_Reset_PS                     (* (reg32 *) BLE_Reset__PS)
/* Port Configuration */
#define BLE_Reset_PC                     (* (reg32 *) BLE_Reset__PC)
/* Data Register */
#define BLE_Reset_DR                     (* (reg32 *) BLE_Reset__DR)
/* Input Buffer Disable Override */
#define BLE_Reset_INP_DIS                (* (reg32 *) BLE_Reset__PC2)


#if defined(BLE_Reset__INTSTAT)  /* Interrupt Registers */

    #define BLE_Reset_INTSTAT                (* (reg32 *) BLE_Reset__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define BLE_Reset_DRIVE_MODE_SHIFT       (0x00u)
#define BLE_Reset_DRIVE_MODE_MASK        (0x07u << BLE_Reset_DRIVE_MODE_SHIFT)


#endif /* End Pins BLE_Reset_H */


/* [] END OF FILE */
