// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/MessageService.h
//! @brief     Defines MSG namespace and Logger class.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MESSAGESVC_H
#define MESSAGESVC_H

#include "WinDllMacros.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


//! Sets of logging utilities
namespace MSG
{

enum MessageLevel { VERBOSE, DEBUG, INFO, WARNING, ERROR, FATAL };


class BA_CORE_API_ Logger
{
public:
    Logger(MessageLevel level);

    template <typename T>
    Logger&  operator<<(T const&  value)
    {
        m_buffer << value;
        return *this;
    }

    ~Logger();

    std::string NowTime();
    const std::string& ToString(MessageLevel level);
    static void SetLevel(MessageLevel level);
    static void SetLevel(const std::string& levelname);
    static MessageLevel GetLevel();

private:
    static MessageLevel m_logLevel;
    static std::vector<std::string > m_level_names;
    std::ostringstream m_buffer;
};

//inline void SetLevel(MessageLevel level) { Logger::SetLevel(level); }
//inline void SetLevel(const std::string& levelname) { Logger::SetLevel(levelname); }

BA_CORE_API_ void SetLevel(MessageLevel level);
BA_CORE_API_ void SetLevel(const std::string& levelname);

}

#define msglog(level) \
if (level < MSG::Logger::GetLevel()) ; \
else MSG::Logger(level)



#endif // MESSAGESVC_H


