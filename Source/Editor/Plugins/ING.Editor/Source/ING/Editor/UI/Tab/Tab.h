#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



namespace ING {

	namespace Editor {

		namespace UI {

			class PLUGIN_API(ING_EDITOR) ITab : public ING::UI::IElement
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				ITab	(const String& name);
				~ITab	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void Start()		override;

				virtual void PreUpdate()	override;
				virtual void Update()		override;
				virtual void LateUpdate()	override;

				virtual void PreRender()	override;
				virtual void Render()		override;
				virtual void LateRender()	override;

				virtual void Resize()		override;

			};

		}

	}

}