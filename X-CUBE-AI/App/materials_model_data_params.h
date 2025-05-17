/**
  ******************************************************************************
  * @file    materials_model_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-05-17T10:08:42+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef MATERIALS_MODEL_DATA_PARAMS_H
#define MATERIALS_MODEL_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_MATERIALS_MODEL_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_materials_model_data_weights_params[1]))
*/

#define AI_MATERIALS_MODEL_DATA_CONFIG               (NULL)


#define AI_MATERIALS_MODEL_DATA_ACTIVATIONS_SIZES \
  { 42468, }
#define AI_MATERIALS_MODEL_DATA_ACTIVATIONS_SIZE     (42468)
#define AI_MATERIALS_MODEL_DATA_ACTIVATIONS_COUNT    (1)
#define AI_MATERIALS_MODEL_DATA_ACTIVATION_1_SIZE    (42468)



#define AI_MATERIALS_MODEL_DATA_WEIGHTS_SIZES \
  { 111760, }
#define AI_MATERIALS_MODEL_DATA_WEIGHTS_SIZE         (111760)
#define AI_MATERIALS_MODEL_DATA_WEIGHTS_COUNT        (1)
#define AI_MATERIALS_MODEL_DATA_WEIGHT_1_SIZE        (111760)



#define AI_MATERIALS_MODEL_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_materials_model_activations_table[1])

extern ai_handle g_materials_model_activations_table[1 + 2];



#define AI_MATERIALS_MODEL_DATA_WEIGHTS_TABLE_GET() \
  (&g_materials_model_weights_table[1])

extern ai_handle g_materials_model_weights_table[1 + 2];


#endif    /* MATERIALS_MODEL_DATA_PARAMS_H */
