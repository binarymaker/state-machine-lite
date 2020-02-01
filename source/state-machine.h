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

#ifndef STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51
#define STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __STATE_MACHINE_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
typedef void (*function_pointer)(void *);

typedef struct{
    function_pointer handler;
    uint8_t entry;
}state_machine;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define STATE(task)         void task(state_machine *_sm_)
#define NEXT_STATE(task)    _sm_->handler = (function_pointer)task
#define INIT(sm,task)       {                                                  \
                              sm.handler = (function_pointer)task;             \
                              sm.entry = 1u;                                   \
                            }
#define EXEC(sm)            {                                                  \
                              function_pointer last_task = sm.handler;         \
                              sm.handler(&sm);                                 \
                              sm.entry = (last_task != sm.handler);            \
                            }
#define ENTRY               (_sm_->entry)
#define COMPARE(sm,task)    (sm.handler == (function_pointer)task)

/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51 */
