// Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
//                 Brian Martin, and Christopher Vermilion
//
//----------------------------------------------------------------------
// This file is part of SpartyJet.
//
//  SpartyJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  SpartyJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with SpartyJet; if not, write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#ifndef _JETMESSAGE_HH_
#define _JETMESSAGE_HH_

///////////////////////////////////////
//
// A very basic logging system
//
///////////////////////////////////////

#include <string>
#include <iostream>
#include <sstream>

namespace SpartyJet { 

enum MessageLevel {DEBUG=1, INFO, WARNING, ERROR};
static std::string msgLevelStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

class Message {
public:
  Message() : m_name("") {m_level = INFO;}
  Message(std::string s) {m_level = INFO; set_name(s);}
  
	
  void set_name(std::string name) {m_name=name;}

  static void silent_all() {g_level = ERROR;}
  static void set_message_level(MessageLevel l) {g_level = l;}
  static MessageLevel get_message_level() {return g_level;}

  template<class T>
  Message& operator<<(T o) {
    if (m_level < g_level) {
      return (*this);
    }
    m_buff << o;
    return (*this);
  }

  Message& operator<<(MessageLevel m) { 
    m_level = m;
    return (*this);
  }

  typedef std::ostream& (endl_t)(std::ostream&);
  Message& operator<<(endl_t& e) { // detect endl. certainly there is
				   // better to be done !
    if (m_level < g_level) return *this;
    std::cout.width(20);
    std::cout << std::left << m_name;
    std::cout.width(10);
    std::cout << std::left << msgLevelStr[(int)m_level-1];
    std::cout << std::left << m_buff.str() << std::endl;
    m_buff.str("");

    return (*this);
  }

protected:
  std::string m_name;
  MessageLevel m_level;  
  
  std::ostringstream m_buff;

  static MessageLevel g_level;
};

// Just to avoid having to generate a ROOT dict for Message
inline static MessageLevel GlobalLevel() {return Message::get_message_level();}

// print a warning about function name deprecation
inline void deprecation_warning(Message& log, std::string old_name, std::string new_name) {
  log << WARNING << "Sorry, many function names have changed in SpartyJet 4.0 for overall consistency."  << std::endl;
  log << " Please use " << new_name << " instead of " << old_name << "." << std::endl;
}

}  // namespace SpartyJet
#endif
