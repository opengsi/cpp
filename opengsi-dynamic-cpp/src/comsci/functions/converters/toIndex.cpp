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

#include "opengsi/comsci/functions/converters/toIndex.h"

OPENGSI_BEGIN_FUNC_NAMESPACE
        
namespace gsiConvert {
    GsiSize toIndex(GsiIndex theInput, GsiSize theContainerLength) {
        if(theInput < 0) {
            GsiIndex localIndex = (static_cast<GsiIndex>(theContainerLength) + theInput);
            if(localIndex < 0) 
                return theContainerLength;
            return static_cast<GsiSize>(localIndex);
        } else 
            return static_cast<GsiSize>(theInput);
    }
}
        
OPENGSI_END_FUNC_NAMESPACE