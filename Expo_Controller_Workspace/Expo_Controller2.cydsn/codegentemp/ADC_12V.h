/*******************************************************************************
* File Name: ADC_12V.h  
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

#if !defined(CY_PINS_ADC_12V_H) /* Pins ADC_12V_H */
#define CY_PINS_ADC_12V_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ADC_12V_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADC_12V_Write(uint8 value) ;
void    ADC_12V_SetDriveMode(uint8 mode) ;
uint8   ADC_12V_ReadDataReg(void) ;
uint8   ADC_12V_Read(void) ;
uint8   ADC_12V_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADC_12V_DRIVE_MODE_BITS        (3)
#define ADC_12V_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ADC_12V_DRIVE_MODE_BITS))

#define ADC_12V_DM_ALG_HIZ         (0x00u)
#define ADC_12V_DM_DIG_HIZ         (0x01u)
#define ADC_12V_DM_RES_UP          (0x02u)
#define ADC_12V_DM_RES_DWN         (0x03u)
#define ADC_12V_DM_OD_LO           (0x04u)
#define ADC_12V_DM_OD_HI           (0x05u)
#define ADC_12V_DM_STRONG          (0x06u)
#define ADC_12V_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ADC_12V_MASK               ADC_12V__MASK
#define ADC_12V_SHIFT              ADC_12V__SHIFT
#define ADC_12V_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_12V_PS                     (* (reg32 *) ADC_12V__PS)
/* Port Configuration */
#define ADC_12V_PC                     (* (reg32 *) ADC_12V__PC)
/* Data Register */
#define ADC_12V_DR                     (* (reg32 *) ADC_12V__DR)
/* Input Buffer Disable Override */
#define ADC_12V_INP_DIS                (* (reg32 *) ADC_12V__PC2)


#if defined(ADC_12V__INTSTAT)  /* Interrupt Registers */

    #define ADC_12V_INTSTAT                (* (reg32 *) ADC_12V__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ADC_12V_DRIVE_MODE_SHIFT       (0x00u)
#define ADC_12V_DRIVE_MODE_MASK        (0x07u << ADC_12V_DRIVE_MODE_SHIFT)


#endif /* End Pins ADC_12V_H */


/* [] END OF FILE */
