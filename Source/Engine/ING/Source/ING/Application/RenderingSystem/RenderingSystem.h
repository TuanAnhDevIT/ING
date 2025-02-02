#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace Rendering {

		class Renderer;

		class IRenderer;

		class IPipeline;

		class IDevice;

	}

	class ING_API ApplicationRenderingSystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationRenderingSystem(IApplication* application);
		~ApplicationRenderingSystem();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		Rendering::IPipeline*	mainPipeline;

		Rendering::IDevice*		mainDevice;

	public:

		Rendering::IPipeline*	GetMainPipeline	() { return mainPipeline; }

		void					SetMainPipeline (Rendering::IPipeline* pipeline);
		void					ReleaseMainPipeline();

		Rendering::IDevice*		GetMainDevice	() { return mainDevice; }

		void					SetMainDevice	(Rendering::IDevice* device) { this->mainDevice = device; }



		/**
		 *	Methods
		 */
	public:
		virtual void			Start		() override;

		virtual void			PreUpdate	() override;
		virtual void			Update		() override;
		virtual void			LateUpdate	() override;

		virtual void			PreRender	() override;
		virtual void			Render		() override;
		virtual void			LateRender	() override;

	};

}