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
 * File:   TShared.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 *
 * Created on April 15, 2016, 4:20 PM
 */

#ifndef __OPEN_GSI_COMSCI_SMART_POINTERS_TSHARED_H_
#define __OPEN_GSI_COMSCI_SMART_POINTERS_TSHARED_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

# include <memory>
# include <string>
# include <cassert>
# include "TSharedTraits.h"

/** @brief TShared
 *  @file TShared.h
 *  @author Young-Mook Kang
 */

OPENGSI_BEGIN_NAMESPACE

template<typename TValue>
class TShared {
    
    typedef supports::BasicString BasicString;
    
    template<class _AnyType_> friend class TShared;
    __OPENGSI_DEFINITION_OF_DEFAULT_TYPES__(TShared<TValue>);
    typedef std::ostream BaseOStream;
    typedef std::istream BaseIStream;

public:
    typedef TValue value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef typename supports::TSharedTraits<value_type>::reference reference;
    typedef typename supports::TSharedTraits<value_type>::const_reference const_reference;
    typedef std::auto_ptr<value_type> auto_pointer;

    typedef std::string::size_type size_type;
    typedef std::string::difference_type difference_type;

    inline BasicString toString() const { return this->getClassName(); }
    inline BasicString getClassName() const { return "TShared"; }

    friend
    BaseOStream &
    operator <<(BaseOStream &theStream, this_const_reference theSelf) {
        return (theStream << theSelf.toString());
    }

    friend
    BaseIStream &
    operator >>(BaseIStream &theStream, this_reference theSelf) {
        return theSelf >> (theStream);
    }

protected:

    inline
    void
    _destroy() {
        delete itsPointer;
        delete itsSharedCount;
        this->itsPointer = NULL;
    }

private:

    pointer itsPointer;
    size_type* itsSharedCount;

public:

    TShared() : itsPointer(new TValue()),
    itsSharedCount(new size_type(1)) {
    }

    TShared(value_type *theValue)
    : itsPointer(theValue),
    itsSharedCount(new size_type(1)) {
    }

    template<typename _AnyType_>
    TShared(std::auto_ptr<_AnyType_> theAutoPtr)
    : itsPointer(theAutoPtr.release()),
    itsSharedCount(new size_type(1)) {
        if (itsPointer == NULL)
            itsPointer = new TValue();
    }

    TShared(this_const_reference theShared)
    : itsPointer(theShared.itsPointer),
    itsSharedCount(theShared.itsSharedCount) {
        ++*itsSharedCount;
    }

    template<typename _AnyType_>
    TShared(const TShared<_AnyType_> &theShared)
    : itsPointer(theShared.itsPointer),
    itsSharedCount(theShared.itsSharedCount) {
        ++*itsSharedCount;
    }

    ~TShared() {
        if (--*itsSharedCount == 0) {
            this->_destroy();
        }
    }

    // get methods

    const_reference get() const {
        return *itsPointer;
    }

    // swap methods

    void swap(this_reference theShared) {
        std::swap(itsPointer, theShared.itsPointer);
        std::swap(itsSharedCount, theShared.itsSharedCount);
    }

    // reset methods

    void reset() {
        this->makeUnique(value_type());
    }

    template<typename _AnyType_>
    void reset(std::auto_ptr<_AnyType_> theAutoPtr) {
        assert((itsPointer != theAutoPtr.get())
                && ("An auto_ptr have a same pointer that TShared 's pointer."));
        if (--*itsSharedCount == 0) {
            _destroy();
        }
        itsSharedCount = new size_type(1);
#ifdef OPENGSI_USE_MSC
        itsPointer = theAutoPtr.release();
        if (!(itsPointer)) {
#else
        if (!(itsPointer = theAutoPtr.release())) {
#endif
            assert(itsPointer != theAutoPtr.get()
                    && ("An auto_ptr have a Null pointer, TShared.reset(auto_ptr)."));
            itsPointer = new TValue();
        }
    }

    template<typename _AnyType_>
    void reset(const TShared<_AnyType_> &theShared) {
        if (itsPointer != theShared.itsPointer) {
            ++*theShared.itsSharedCount;
            if (--*itsSharedCount == 0) {
                _destroy();
            }
            itsSharedCount = theShared.itsSharedCount;
            itsPointer = theShared.itsPointer;
        }
    }

    // makeUnique methods

    void makeUnique() {
        if (*itsSharedCount != 1) {
            --*itsSharedCount;
            itsSharedCount = new size_type(1);
            if (itsPointer) {
                itsPointer = new TValue(*itsPointer);
            }
        }
    }

    void makeUnique(const value_type &theValue) {
        if (*itsSharedCount != 1) {
            --*itsSharedCount;
            itsSharedCount = new size_type(1);
            itsPointer = new TValue(theValue);
        } else {
            *itsPointer = theValue;
        }
    }

    size_type size() const {
        return *itsSharedCount;
    }

    bool isUnique() const {
        if (this->size() > 1)
            return false;
        return true;
    }

    bool isNotUnique() const {
        return !(this->isUnique());
    }

    // operator methods

    operator GsiBool() const {
        return itsPointer;
    }

    reference operator*() {
        this->makeUnique();
        return *itsPointer;
    }

    const_reference operator*() const {
        return *itsPointer;
    }

    pointer operator->() const {
        return itsPointer;
    }

    this_reference operator =(this_const_reference theElement) {
        this->reset(theElement);
        return *this;
    }

    this_reference operator =(std::auto_ptr<value_type> &theElement) {
        this->reset(theElement);
        return *this;
    }

    template<typename _AnyType_>
            this_reference operator =(const TShared<_AnyType_> &theElement) {
        this->reset(theElement);
        return *this;
    }

    template<typename _AnyType_>
            this_reference operator =(std::auto_ptr<_AnyType_> theElement) {
        this->reset(theElement);
        return *this;
    }
};
OPENGSI_END_NAMESPACE

#endif  /* __OPEN_GSI_TSHARED_H_ */
