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
 * File:   GObject.cpp
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Created on April 15, 2016, 3:09 PM
 */

#include "opengsi/comsci/GObject.h"

OPENGSI_BEGIN_NAMESPACE 

GObject::BasicString GObject::toString() const {
    return this->getClassName();
}

GObject::BasicString GObject::getClassName() const {
    return "GObject";
}

GObject::BaseIStream& GObject::_readStream(BaseIStream& theStream) {
    return theStream;
}

void GObject::_printMessage(const BasicString& theErrorCode, const BasicString& theFunctionName) const {
    GsiCerr << this->__getMessage(theErrorCode, theFunctionName, this->getClassName()); 
}

GObject::BasicString 
GObject::__getMessage(const GObject::BasicString& theErrorCode,
                      const GObject::BasicString& theFunctionName,
                      const GObject::BasicString& theNameSpace) const {
    std::ostringstream localBuffer;
    localBuffer << ("Error C")  << theErrorCode
            << (", \"")     << theFunctionName
            << ("\" in the ")
            << theNameSpace << (".\n");
#ifdef OPENGSI_USE_QT        
    return static_cast<BasicString>(localBuffer.str().c_str());
#else
    return localBuffer.str();
#endif
}
        
OPENGSI_END_NAMESPACE