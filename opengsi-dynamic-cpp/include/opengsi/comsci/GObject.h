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
 * File:   GObject.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 *
 * Created on April 15, 2016, 3:09 PM
 */

#ifndef __OPEN_GSI_COMSCI_GOBJECT_H_
#define __OPEN_GSI_COMSCI_GOBJECT_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
#include "supports/basic_definition.h"

/** @brief GObject
 *  @file GObject.h
 *  @author Young-Mook Kang
 */

OPENGSI_BEGIN_NAMESPACE

class GObject {

    __OPENGSI_DEFINITION_OF_DEFAULT_TYPES__(GObject);

public:

    typedef supports::BasicString        BasicString;
    typedef supports::BasicIStream       BaseIStream;
    typedef supports::BasicOStream       BaseOStream;
    typedef supports::BasicIStringStream BasicIStringStream;
    typedef supports::BasicOStringStream BasicOStringStream;
    typedef supports::BasicStringStream  BasicStringStream;
    
    
    GObject() {}
    virtual ~GObject() {}

    virtual BasicString getClassName() const ;
    virtual BasicString toString() const ;
    
    friend inline BaseOStream &
    operator <<(BaseOStream &theStream, this_const_reference theSelf) { return (theStream << theSelf.toString()); }

    friend inline BaseIStream &
    operator >>(BaseIStream &theStream, this_reference theSelf) { return theSelf._readStream(theStream); }

protected:
    
    inline void _printMessage(const BasicString &, const BasicString &) const; 
    virtual BaseIStream & _readStream(BaseIStream &theStream);
    
private:    
    BasicString __getMessage(const BasicString&, const BasicString&, const BasicString&) const ;       
};

OPENGSI_END_NAMESPACE

#endif  /* __OPEN_GSI_COMSCI_GOBJECT_H_ */

