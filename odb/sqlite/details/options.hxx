// -*- C++ -*-
//
// This file was generated by CLI, a command line interface
// compiler for C++.
//

#ifndef LIBODB_SQLITE_DETAILS_OPTIONS_HXX
#define LIBODB_SQLITE_DETAILS_OPTIONS_HXX

// Begin prologue.
//
//
// End prologue.

#include <deque>
#include <iosfwd>
#include <string>
#include <cstddef>
#include <exception>

#ifndef CLI_POTENTIALLY_UNUSED
#  if defined(_MSC_VER) || defined(__xlC__)
#    define CLI_POTENTIALLY_UNUSED(x) (void*)&x
#  else
#    define CLI_POTENTIALLY_UNUSED(x) (void)x
#  endif
#endif

namespace odb
{
  namespace sqlite
  {
    namespace details
    {
      namespace cli
      {
        class usage_para
        {
          public:
          enum value
          {
            none,
            text,
            option
          };

          usage_para (value);

          operator value () const 
          {
            return v_;
          }

          private:
          value v_;
        };

        class unknown_mode
        {
          public:
          enum value
          {
            skip,
            stop,
            fail
          };

          unknown_mode (value);

          operator value () const 
          {
            return v_;
          }

          private:
          value v_;
        };

        // Exceptions.
        //

        class exception: public std::exception
        {
          public:
          virtual void
          print (::std::ostream&) const = 0;
        };

        ::std::ostream&
        operator<< (::std::ostream&, const exception&);

        class unknown_option: public exception
        {
          public:
          virtual
          ~unknown_option () throw ();

          unknown_option (const std::string& option);

          const std::string&
          option () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string option_;
        };

        class unknown_argument: public exception
        {
          public:
          virtual
          ~unknown_argument () throw ();

          unknown_argument (const std::string& argument);

          const std::string&
          argument () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string argument_;
        };

        class missing_value: public exception
        {
          public:
          virtual
          ~missing_value () throw ();

          missing_value (const std::string& option);

          const std::string&
          option () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string option_;
        };

        class invalid_value: public exception
        {
          public:
          virtual
          ~invalid_value () throw ();

          invalid_value (const std::string& option,
                         const std::string& value);

          const std::string&
          option () const;

          const std::string&
          value () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string option_;
          std::string value_;
        };

        class eos_reached: public exception
        {
          public:
          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();
        };

        class file_io_failure: public exception
        {
          public:
          virtual
          ~file_io_failure () throw ();

          file_io_failure (const std::string& file);

          const std::string&
          file () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string file_;
        };

        class unmatched_quote: public exception
        {
          public:
          virtual
          ~unmatched_quote () throw ();

          unmatched_quote (const std::string& argument);

          const std::string&
          argument () const;

          virtual void
          print (::std::ostream&) const;

          virtual const char*
          what () const throw ();

          private:
          std::string argument_;
        };

        class scanner
        {
          public:
          virtual
          ~scanner ();

          virtual bool
          more () = 0;

          virtual const char*
          peek () = 0;

          virtual const char*
          next () = 0;

          virtual void
          skip () = 0;
        };

        class argv_scanner: public scanner
        {
          public:
          argv_scanner (int& argc, char** argv, bool erase = false);
          argv_scanner (int start, int& argc, char** argv, bool erase = false);

          int
          end () const;

          virtual bool
          more ();

          virtual const char*
          peek ();

          virtual const char*
          next ();

          virtual void
          skip ();

          private:
          int i_;
          int& argc_;
          char** argv_;
          bool erase_;
        };

        class argv_file_scanner: public argv_scanner
        {
          public:
          argv_file_scanner (int& argc,
                             char** argv,
                             const std::string& option,
                             bool erase = false);

          argv_file_scanner (int start,
                             int& argc,
                             char** argv,
                             const std::string& option,
                             bool erase = false);

          struct option_info
          {
            // If search_func is not NULL, it is called, with the arg
            // value as the second argument, to locate the options file.
            // If it returns an empty string, then the file is ignored.
            //
            const char* option;
            std::string (*search_func) (const char*, void* arg);
            void* arg;
          };

          argv_file_scanner (int& argc,
                              char** argv,
                              const option_info* options,
                              std::size_t options_count,
                              bool erase = false);

          argv_file_scanner (int start,
                             int& argc,
                             char** argv,
                             const option_info* options,
                             std::size_t options_count,
                             bool erase = false);

          virtual bool
          more ();

          virtual const char*
          peek ();

          virtual const char*
          next ();

          virtual void
          skip ();

          private:
          const option_info*
          find (const char*) const;

          void
          load (const std::string& file);

          typedef argv_scanner base;

          const std::string option_;
          option_info option_info_;
          const option_info* options_;
          std::size_t options_count_;

          std::string hold_;
          std::deque<std::string> args_;
          bool skip_;
        };

        template <typename X>
        struct parser;
      }
    }
  }
}

#include <string>

namespace odb
{
  namespace sqlite
  {
    namespace details
    {
      class options
      {
        public:
        options ();

        options (int& argc,
                 char** argv,
                 bool erase = false,
                 ::odb::sqlite::details::cli::unknown_mode option = ::odb::sqlite::details::cli::unknown_mode::fail,
                 ::odb::sqlite::details::cli::unknown_mode argument = ::odb::sqlite::details::cli::unknown_mode::stop);

        options (int start,
                 int& argc,
                 char** argv,
                 bool erase = false,
                 ::odb::sqlite::details::cli::unknown_mode option = ::odb::sqlite::details::cli::unknown_mode::fail,
                 ::odb::sqlite::details::cli::unknown_mode argument = ::odb::sqlite::details::cli::unknown_mode::stop);

        options (int& argc,
                 char** argv,
                 int& end,
                 bool erase = false,
                 ::odb::sqlite::details::cli::unknown_mode option = ::odb::sqlite::details::cli::unknown_mode::fail,
                 ::odb::sqlite::details::cli::unknown_mode argument = ::odb::sqlite::details::cli::unknown_mode::stop);

        options (int start,
                 int& argc,
                 char** argv,
                 int& end,
                 bool erase = false,
                 ::odb::sqlite::details::cli::unknown_mode option = ::odb::sqlite::details::cli::unknown_mode::fail,
                 ::odb::sqlite::details::cli::unknown_mode argument = ::odb::sqlite::details::cli::unknown_mode::stop);

        options (::odb::sqlite::details::cli::scanner&,
                 ::odb::sqlite::details::cli::unknown_mode option = ::odb::sqlite::details::cli::unknown_mode::fail,
                 ::odb::sqlite::details::cli::unknown_mode argument = ::odb::sqlite::details::cli::unknown_mode::stop);

        // Option accessors.
        //
        const std::string&
        database () const;

        const bool&
        create () const;

        const bool&
        read_only () const;

        const std::string&
        options_file () const;

        // Print usage information.
        //
        static ::odb::sqlite::details::cli::usage_para
        print_usage (::std::ostream&,
                     ::odb::sqlite::details::cli::usage_para = ::odb::sqlite::details::cli::usage_para::none);

        // Implementation details.
        //
        protected:
        bool
        _parse (const char*, ::odb::sqlite::details::cli::scanner&);

        private:
        void
        _parse (::odb::sqlite::details::cli::scanner&,
                ::odb::sqlite::details::cli::unknown_mode option,
                ::odb::sqlite::details::cli::unknown_mode argument);

        public:
        std::string database_;
        bool create_;
        bool read_only_;
        std::string options_file_;
      };
    }
  }
}

#include "options.ixx"

// Begin epilogue.
//
//
// End epilogue.

#endif // LIBODB_SQLITE_DETAILS_OPTIONS_HXX
