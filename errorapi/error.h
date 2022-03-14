///////////////////////////////////////////////////
//                                               //
//                    FORTC                      //
//                                               //
//      Copyright (c) 2022, Thomas Stainer       //
//                                               //
//            All rights reserved.               //
//    Licensed under the 3-clause BSD license.   //
//                                               //
///////////////////////////////////////////////////

#ifndef ERROR_LIB_HH
#define ERROR_LIB_HH

#include <string>
#include <vector>

/*
C++ implementation file for the error library.
*/

template <typename T>
using LogContainer = std::vector<T>;

namespace error
{

  enum Severity
  {
    INFO,
    WARNING,
    ERROR,
    FATAL
  };

  std::string severity_to_string(Severity severity) noexcept
  {
    switch (severity)
    {
    case INFO:
      return "INFO";
    case WARNING:
      return "WARNING";
    case ERROR:
      return "ERROR";
    case FATAL:
      return "FATAL";
    default:
      return "UNKNOWN";
    }
  }

  class Error
  {
  public:
    Error() : _fatalOccurred(false){};

    ~Error(){};

    inline void reset()
    {
      _messages.clear();
      _fatalOccurred = false;
    }

    inline size_t size() const
    {
      return _messages.size();
    }

    inline void addMessage(const std::string &message, Severity severity = Severity::INFO)
    {
      const std::string formatted_message = "[" + severity_to_string(severity) + "] " + message;
      _messages.push_back(formatted_message);
    }

    inline const std::string &get(size_t index) const
    {
      return _messages[index];
    }

  private:
    bool _fatalOccurred;
    LogContainer<std::string> _messages;
  };
}

#endif //ERROR_LIB_HH
