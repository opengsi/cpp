/*
 * Copyright (C) 2016 Young-Mook Kang <youngmook@opengsi.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */

/* 
 * File:   TSharedTraits.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SMART_POINTERS_TSHAREDTRAITS_H_
#define __OPEN_GSI_COMSCI_SMART_POINTERS_TSHAREDTRAITS_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include "../supports/basic_definition.h"

/** @brief TSharedTraits
 *  @file TSharedTraits.h
 *  @author Young-Mook Kang
 */

OPENGSI_BEGIN_NAMESPACE
namespace supports {

    template<typename TValue>
    struct TSharedTraits {
        typedef TValue& reference;
        typedef const TValue& const_reference;
    };

    template<>
    struct TSharedTraits<void> {
        typedef void reference;
        typedef void const_reference;
    };
}
OPENGSI_END_NAMESPACE

#endif  /* __OPEN_GSI_COMSCI_SMART_POINTERS_TSHAREDTRAITS_H_ */
