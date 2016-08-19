
//STARTHEADER
// $Id: base.hh 2577 2011-09-13 15:11:38Z salam $
//
// Copyright (c) 2005-2011, Matteo Cacciari, Gavin P. Salam and Gregory Soyez
//
//----------------------------------------------------------------------
// This file is part of FastJet.
//
//  FastJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  The algorithms that underlie FastJet have required considerable
//  development and are described in hep-ph/0512210. If you use
//  FastJet as part of work towards a scientific publication, please
//  include a citation to the FastJet paper.
//
//  FastJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with FastJet. If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------
//ENDHEADER

#ifndef __FASTJET_FASTJET_BASE_HH__
#define __FASTJET_FASTJET_BASE_HH__

/// \namespace fastjet
/// the FastJet namespace
/// 
/// all the fastjet-related material is put under that namespace

// define this for easier readability (and obfuscation?) in
// a range of places
#define FASTJET_BEGIN_NAMESPACE namespace fastjet {
#define FASTJET_END_NAMESPACE   }

// define the doxygen groupd
/// \defgroup basic_classes    Fundamental FastJet classes
/// \defgroup area_classes     Area-related classes
/// \defgroup sec_area_classes Secondary area-related classes
/// \defgroup plugins          Plugins for non-native jet definitions
/// \defgroup selectors        Selectors
/// \defgroup tools            FastJet tools
/// \{ \defgroup tools_generic     Generic tools
///    \defgroup tools_background  Background subtraction
///    \defgroup tools_taggers     Taggers
/// \}
/// \defgroup extra_info       Access to extra information
/// \defgroup error_handling   Error handling
/// \defgroup advanced_usage   Advanced usage
/// \if internal_doc
/// \defgroup internal
/// \endif
#endif // __FASTJET_FASTJET_BASE_HH__
