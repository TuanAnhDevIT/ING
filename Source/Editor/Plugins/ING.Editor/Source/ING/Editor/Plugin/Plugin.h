#pragma once

#include <ING/Editor/EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



/**
 *	Declare Classes
 */
namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Info
 */
DECLARE_PLUGIN_NAME(ING_EDITOR);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_EDITOR, bool, PreRelease)	();