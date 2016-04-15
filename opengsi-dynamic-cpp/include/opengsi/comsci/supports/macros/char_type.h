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
 * File:   char_type.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_CHAR_TYPE_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_CHAR_TYPE_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "compiler.h"
#include "os_macro.h"
#include "posix.h"

/** @brief char_type
 *  @file char_type.h
 *  @author Young-Mook Kang
 */

# ifdef OPENGSI_USE_QT
#  include <QtCore/QString>
#  include <QtCore/QByteArray>
std::ostream & operator << (std::ostream& theStream, const QString    &theString);
std::istream & operator >> (std::istream& theStream,       QString    &theString);
std::ostream & operator << (std::ostream& theStream, const QByteArray &theString);
std::istream & operator >> (std::istream& theStream,       QByteArray &theString);
#else
# include <string>
# include <cwchar>
# include <sstream>
# endif

OPENGSI_BEGIN_NAMESPACE 

# ifdef OPENGSI_USE_QT
namespace supports {
    typedef QString                 BasicWString;
    typedef QChar                   BasicWChar;
    typedef QByteArray              BasicString;
    typedef BasicString::value_type BasicChar;
}
# else // else OPENGSI_USE_QT
namespace supports {
    typedef std::wstring             BasicWString;
    typedef BasicWString::value_type BasicWChar;
    typedef std::string              BasicString;
    typedef BasicString::value_type  BasicChar;
}
# endif // end OPENGSI_USE_QT

# define GsiCout ::std::cout
# define GsiCerr ::std::cerr
# define GsiClog ::std::clog

namespace supports {
    typedef std::istream       BasicIStream;
    typedef std::ostream       BasicOStream;
    typedef std::iostream      BasicIOStream;
    typedef std::ostringstream BasicOStringStream;
    typedef std::istringstream BasicIStringStream;
    typedef std::stringstream  BasicStringStream;
}

OPENGSI_END_NAMESPACE


# ifdef OPENGSI_USE_QT
#  define __OPENGSI_DEFINITION_OF_OPERATORS_FOR_STRING_COMPATIBILITY \
inline operator OPENGSI_NAMESPACE::supports::BasicString() const { \
    return this->toString(); \
} \
inline operator std::string() const { \
    return this->toString().data(); \
} 
# else
#  define __OPENGSI_DEFINITION_OF_OPERATORS_FOR_STRING_COMPATIBILITY \
inline operator OPENGSI_NAMESPACE::supports::BasicString() const {\
    return this->toString();\
}
# endif

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_CHAR_TYPE_H_ */
