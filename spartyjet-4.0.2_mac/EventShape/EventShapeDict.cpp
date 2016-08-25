// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME EventShapeDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "EventShape.hh"
#include "ThrustTool.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SpartyJetcLcLeventshapecLcLThrustTool_Dictionary();
   static void SpartyJetcLcLeventshapecLcLThrustTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLeventshapecLcLThrustTool(void *p);
   static void deleteArray_SpartyJetcLcLeventshapecLcLThrustTool(void *p);
   static void destruct_SpartyJetcLcLeventshapecLcLThrustTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::eventshape::ThrustTool*)
   {
      ::SpartyJet::eventshape::ThrustTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::eventshape::ThrustTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::eventshape::ThrustTool", "ThrustTool.hh", 40,
                  typeid(::SpartyJet::eventshape::ThrustTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLeventshapecLcLThrustTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::eventshape::ThrustTool) );
      instance.SetDelete(&delete_SpartyJetcLcLeventshapecLcLThrustTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLeventshapecLcLThrustTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLeventshapecLcLThrustTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::eventshape::ThrustTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::eventshape::ThrustTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::eventshape::ThrustTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLeventshapecLcLThrustTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::eventshape::ThrustTool*)0x0)->GetClass();
      SpartyJetcLcLeventshapecLcLThrustTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLeventshapecLcLThrustTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLeventshapecLcLShapeConfig_Dictionary();
   static void SpartyJetcLcLeventshapecLcLShapeConfig_TClassManip(TClass*);
   static void *new_SpartyJetcLcLeventshapecLcLShapeConfig(void *p = 0);
   static void *newArray_SpartyJetcLcLeventshapecLcLShapeConfig(Long_t size, void *p);
   static void delete_SpartyJetcLcLeventshapecLcLShapeConfig(void *p);
   static void deleteArray_SpartyJetcLcLeventshapecLcLShapeConfig(void *p);
   static void destruct_SpartyJetcLcLeventshapecLcLShapeConfig(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::eventshape::ShapeConfig*)
   {
      ::SpartyJet::eventshape::ShapeConfig *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::eventshape::ShapeConfig),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::eventshape::ShapeConfig", "EventShape.hh", 62,
                  typeid(::SpartyJet::eventshape::ShapeConfig), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLeventshapecLcLShapeConfig_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::eventshape::ShapeConfig) );
      instance.SetNew(&new_SpartyJetcLcLeventshapecLcLShapeConfig);
      instance.SetNewArray(&newArray_SpartyJetcLcLeventshapecLcLShapeConfig);
      instance.SetDelete(&delete_SpartyJetcLcLeventshapecLcLShapeConfig);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLeventshapecLcLShapeConfig);
      instance.SetDestructor(&destruct_SpartyJetcLcLeventshapecLcLShapeConfig);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::eventshape::ShapeConfig*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::eventshape::ShapeConfig*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::eventshape::ShapeConfig*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLeventshapecLcLShapeConfig_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::eventshape::ShapeConfig*)0x0)->GetClass();
      SpartyJetcLcLeventshapecLcLShapeConfig_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLeventshapecLcLShapeConfig_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLeventshapecLcLThrustTool(void *p) {
      delete ((::SpartyJet::eventshape::ThrustTool*)p);
   }
   static void deleteArray_SpartyJetcLcLeventshapecLcLThrustTool(void *p) {
      delete [] ((::SpartyJet::eventshape::ThrustTool*)p);
   }
   static void destruct_SpartyJetcLcLeventshapecLcLThrustTool(void *p) {
      typedef ::SpartyJet::eventshape::ThrustTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::eventshape::ThrustTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLeventshapecLcLShapeConfig(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::eventshape::ShapeConfig : new ::SpartyJet::eventshape::ShapeConfig;
   }
   static void *newArray_SpartyJetcLcLeventshapecLcLShapeConfig(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::eventshape::ShapeConfig[nElements] : new ::SpartyJet::eventshape::ShapeConfig[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLeventshapecLcLShapeConfig(void *p) {
      delete ((::SpartyJet::eventshape::ShapeConfig*)p);
   }
   static void deleteArray_SpartyJetcLcLeventshapecLcLShapeConfig(void *p) {
      delete [] ((::SpartyJet::eventshape::ShapeConfig*)p);
   }
   static void destruct_SpartyJetcLcLeventshapecLcLShapeConfig(void *p) {
      typedef ::SpartyJet::eventshape::ShapeConfig current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::eventshape::ShapeConfig

namespace {
  void TriggerDictionaryInitialization_EventShapeDict_Impl() {
    static const char* headers[] = {
"EventShape.hh",
"ThrustTool.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/EventShape/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SpartyJet{namespace eventshape{class __attribute__((annotate("$clingAutoload$ThrustTool.hh")))  ThrustTool;}}
namespace SpartyJet{namespace eventshape{class __attribute__((annotate("$clingAutoload$EventShape.hh")))  ShapeConfig;}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "EventShape.hh"
#include "ThrustTool.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::eventshape::ShapeConfig", payloadCode, "@",
"SpartyJet::eventshape::ThrustTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventShapeDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventShapeDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventShapeDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventShapeDict() {
  TriggerDictionaryInitialization_EventShapeDict_Impl();
}
