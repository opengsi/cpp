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

#include "char_type.h"

#ifdef OPENGSI_USE_QT
std::ostream & operator << (std::ostream& theStream, const QString &theString) {
    return theStream << theString.toStdString();
}
std::istream & operator >> (std::istream& theStream,       QString &theString) {
    std::string localBuffer;
    theStream >> localBuffer;
    theString = localBuffer.c_str();
    return theStream;
}
std::ostream & operator << (std::ostream& theStream, const QByteArray &theString) {
    return theStream << static_cast<std::string>(theString.data());
}
std::istream & operator >> (std::istream& theStream,       QByteArray &theString) {
    std::string localBuffer;
    theStream >> localBuffer;
    theString = localBuffer.c_str();
    return theStream;
}
#endif