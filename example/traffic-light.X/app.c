/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2020 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  \endcond*/

/* Includes ------------------------------------------------------------------*/
#include "app.h"
#include "mcu.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

STATE(GREEN)
{
  if (ENTRY)
  {
    GPIO_PinWrite(P_B0, HIGH);
    GPIO_PinWrite(P_B1, LOW);
  }
  
  NEXT_STATE(RED);
  
  if (EXIT)
  {
    GPIO_PinWrite(P_B2, HIGH);
  }
}

STATE(RED)
{
  if (ENTRY)
  {
    GPIO_PinWrite(P_B0, LOW);
    GPIO_PinWrite(P_B1, HIGH);
  }
  
  NEXT_STATE(GREEN);
  
  if (EXIT)
  {
    GPIO_PinWrite(P_B2, LOW);
  }
}