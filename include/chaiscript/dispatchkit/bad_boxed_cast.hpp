// This file is distributed under the BSD License.
// See "license.txt" for details.
// Copyright 2009-2011, Jonathan Turner (jonathan@emptycrate.com)
// and Jason Turner (jason@emptycrate.com)
// http://www.chaiscript.com

#ifndef CHAISCRIPT_BAD_BOXED_CAST_HPP_
#define CHAISCRIPT_BAD_BOXED_CAST_HPP_

#include "type_info.hpp"

namespace chaiscript 
{
  namespace exception
  {
    /// \brief Thrown in the event that a Boxed_Value cannot be cast to the desired type
    ///
    /// It is used internally during function dispatch and may be used by the end user.
    ///
    /// \sa chaiscript::boxed_cast
    class bad_boxed_cast : public std::bad_cast
    {
      public:
        bad_boxed_cast(const Type_Info &t_from, const std::type_info &t_to,
            const std::string &t_what) noexcept
          : from(t_from), to(&t_to), m_what(t_what)
        {
        }

        bad_boxed_cast(const Type_Info &t_from, const std::type_info &t_to) noexcept
          : from(t_from), to(&t_to), m_what("Cannot perform boxed_cast")
        {
        }

        bad_boxed_cast(const std::string &t_what) noexcept
          : m_what(t_what)
        {
        }

        virtual ~bad_boxed_cast() noexcept {} 

        /// \brief Description of what error occured
        virtual const char * what() const noexcept
        {
          return m_what.c_str();
        }

        Type_Info from; ///< Type_Info contained in the Boxed_Value
        const std::type_info *to; ///< std::type_info of the desired (but failed) result type

      private:
        std::string m_what;
    };
  }
}



#endif

