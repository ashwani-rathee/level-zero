/*
 *
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_layer.h
 *
 */
#pragma once
#include "ze_ddi.h"
#include "zet_ddi.h"
#include "zes_ddi.h"
#include "ze_util.h"
#include "loader/ze_loader.h"
#include "param_validation.h"
#include <memory>

#define VALIDATION_COMP_NAME "validation layer"

namespace validation_layer
{
    ///////////////////////////////////////////////////////////////////////////////
    class __zedlllocal context_t
    {
    public:
        ze_api_version_t version = ZE_API_VERSION_1_5;

        bool enableParameterValidation = false;
        bool enableHandleLifetime = false;
        bool enableThreadingValidation = false;

        ze_dditable_t   zeDdiTable = {};
        zet_dditable_t  zetDdiTable = {};
        zes_dditable_t  zesDdiTable = {};

        std::unique_ptr<ParameterValidation> paramValidation;

        context_t();
        ~context_t();
    };

    extern context_t context;
} // namespace validation_layer
