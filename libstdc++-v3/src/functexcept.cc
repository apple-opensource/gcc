// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#include <bits/functexcept.h>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <ios>
#ifdef _GLIBCXX_USE_NLS
# include <libintl.h>
# define _(msgid)   gettext (msgid)
#else
# define _(msgid)   (msgid)
#endif

namespace std 
{
#if __EXCEPTIONS
  void
  __throw_bad_exception(void)
  { throw bad_exception(); }

  void
  __throw_bad_alloc(void)
  { throw bad_alloc(); }

  void
  __throw_bad_cast(void)
  { throw bad_cast(); }

  void
  __throw_bad_typeid(void)
  { throw bad_typeid(); }

  void
  __throw_logic_error(const char* __s)
  { throw logic_error(_(__s)); }

  void
  __throw_domain_error(const char* __s)
  { throw domain_error(_(__s)); }

  void
  __throw_invalid_argument(const char* __s)
  { throw invalid_argument(_(__s)); }

  void
  __throw_length_error(const char* __s)
  { throw length_error(_(__s)); }

  void
  __throw_out_of_range(const char* __s)
  { throw out_of_range(_(__s)); }

  void
  __throw_runtime_error(const char* __s)
  { throw runtime_error(_(__s)); }

  void
  __throw_range_error(const char* __s)
  { throw range_error(_(__s)); }

  void
  __throw_overflow_error(const char* __s)
  { throw overflow_error(_(__s)); }

  void
  __throw_underflow_error(const char* __s)
  { throw underflow_error(_(__s)); }

  /* APPLE LOCAL  begin make libstdc++ more fine-grained  */
  /* This function now lives in ios.cc, so that we can avoid dragging in all
     of IOS when some other function in this file is called.  */
#ifndef APPLE_KEYMGR
  void
  __throw_ios_failure(const char* __s)
  { throw ios_base::failure(_(__s)); }
#endif	/* APPLE_KEYMGR  */
  /* APPLE LOCAL  end make libstdc++ more fine-grained  */
#else
  void
  __throw_bad_exception(void)
  { abort(); }

  void
  __throw_bad_alloc(void)
  { abort(); }

  void
  __throw_bad_cast(void)
  { abort(); }

  void
  __throw_bad_typeid(void)
  { abort(); }

  void
  __throw_logic_error(const char*)
  { abort(); }

  void
  __throw_domain_error(const char*)
  { abort(); }

  void
  __throw_invalid_argument(const char*)
  { abort(); }

  void
  __throw_length_error(const char*)
  { abort(); }

  void
  __throw_out_of_range(const char*)
  { abort(); }

  void
  __throw_runtime_error(const char*)
  { abort(); }

  void
  __throw_range_error(const char*)
  { abort(); }

  void
  __throw_overflow_error(const char*)
  { abort(); }

  void
  __throw_underflow_error(const char*)
  { abort(); }

  void
  __throw_ios_failure(const char*)
  { abort(); }
#endif //__EXCEPTIONS
}
