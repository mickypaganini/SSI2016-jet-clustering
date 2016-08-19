// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExamplePluginDict

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
#include "ExamplePlugin.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *fastjetcLcLExamplePlugin_Dictionary();
   static void fastjetcLcLExamplePlugin_TClassManip(TClass*);
   static void delete_fastjetcLcLExamplePlugin(void *p);
   static void deleteArray_fastjetcLcLExamplePlugin(void *p);
   static void destruct_fastjetcLcLExamplePlugin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::ExamplePlugin*)
   {
      ::fastjet::ExamplePlugin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::ExamplePlugin),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::ExamplePlugin", "ExamplePlugin.hh", 10,
                  typeid(::fastjet::ExamplePlugin), DefineBehavior(ptr, ptr),
                  &fastjetcLcLExamplePlugin_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::ExamplePlugin) );
      instance.SetDelete(&delete_fastjetcLcLExamplePlugin);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLExamplePlugin);
      instance.SetDestructor(&destruct_fastjetcLcLExamplePlugin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::ExamplePlugin*)
   {
      return GenerateInitInstanceLocal((::fastjet::ExamplePlugin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::ExamplePlugin*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLExamplePlugin_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::ExamplePlugin*)0x0)->GetClass();
      fastjetcLcLExamplePlugin_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLExamplePlugin_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLExamplePlugin(void *p) {
      delete ((::fastjet::ExamplePlugin*)p);
   }
   static void deleteArray_fastjetcLcLExamplePlugin(void *p) {
      delete [] ((::fastjet::ExamplePlugin*)p);
   }
   static void destruct_fastjetcLcLExamplePlugin(void *p) {
      typedef ::fastjet::ExamplePlugin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::ExamplePlugin

namespace {
  void TriggerDictionaryInitialization_ExamplePluginDict_Impl() {
    static const char* headers[] = {
"ExamplePlugin.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/UserPlugins/ExamplePlugin/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace fastjet{class __attribute__((annotate("$clingAutoload$ExamplePlugin.hh")))  ExamplePlugin;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "ExamplePlugin.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"fastjet::ExamplePlugin", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExamplePluginDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExamplePluginDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExamplePluginDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExamplePluginDict() {
  TriggerDictionaryInitialization_ExamplePluginDict_Impl();
}
