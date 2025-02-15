// @(#)root/cont:$Id$
// Author: Rene Brun   06/03/95

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TArrayL
#define ROOT_TArrayL


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TArrayL                                                              //
//                                                                      //
// Array of longs (32 or 64 bits per element).                          //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TArray.h"


class TArrayL : public TArray {

public:
   Longptr_t *fArray;       //[fN] Array of fN longs

   TArrayL();
   TArrayL(Int_t n);
   TArrayL(Int_t n, const Longptr_t *array);
   TArrayL(const TArrayL &array);
   TArrayL    &operator=(const TArrayL &rhs);
   virtual    ~TArrayL();

   void          Adopt(Int_t n, Longptr_t *array);
   void          AddAt(Longptr_t c, Int_t i);
   Longptr_t     At(Int_t i) const;
   void          Copy(TArrayL &array) const {array.Set(fN,fArray);}
   const Longptr_t *GetArray() const { return fArray; }
   Longptr_t    *GetArray() { return fArray; }
   Double_t      GetAt(Int_t i) const { return At(i); }
   Stat_t        GetSum() const {Stat_t sum=0; for (Int_t i=0;i<fN;i++) sum+=fArray[i]; return sum;}
   void          Reset()           {memset(fArray,  0, fN*sizeof(Longptr_t));}
   void          Reset(Longptr_t val) {for (Int_t i=0;i<fN;i++) fArray[i] = val;}
   void          Set(Int_t n);
   void          Set(Int_t n, const Longptr_t *array);
   void          SetAt(Double_t v, Int_t i) { AddAt((Longptr_t)v, i); }
   Longptr_t    &operator[](Int_t i);
   Longptr_t     operator[](Int_t i) const;

   ClassDef(TArrayL,1)  //Array of longs
};



#if defined R__TEMPLATE_OVERLOAD_BUG
template <>
#endif
inline TBuffer &operator>>(TBuffer &buf, TArrayL *&obj)
{
   // Read TArrayL object from buffer.

   obj = (TArrayL *) TArray::ReadArray(buf, TArrayL::Class());
   return buf;
}

#if defined R__TEMPLATE_OVERLOAD_BUG
template <>
#endif
inline TBuffer &operator<<(TBuffer &buf, const TArrayL *obj)
{
   // Write a TArrayL object into buffer
   return buf << (const TArray*)obj;
}

inline Longptr_t TArrayL::At(Int_t i) const
{
   if (!BoundsOk("TArrayL::At", i)) return 0;
   return fArray[i];
}

inline Longptr_t &TArrayL::operator[](Int_t i)
{
   if (!BoundsOk("TArrayL::operator[]", i))
      i = 0;
   return fArray[i];
}

inline Longptr_t TArrayL::operator[](Int_t i) const
{
   if (!BoundsOk("TArrayL::operator[]", i)) return 0;
   return fArray[i];
}

#endif
