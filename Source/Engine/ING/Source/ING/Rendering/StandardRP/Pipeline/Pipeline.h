#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include SubRP Pipeline
 */
#include <ING/Rendering/StandardRP/Mode/Mode.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		namespace StandardRP {

			class ING_API Pipeline : public IPipeline
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Pipeline(const String& name);
				~Pipeline();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				IPass*				firstPass;

				IPass*				depthPrepass;
				IPass*				gbufferPass;
				IPass*				skyPass;
				IPass*				opaquePass;
				IPass*				transparentPass;
				IPass*				uiPass;
				IPass*				postProcessPass;

				IPass*				finalPass;

				Mode				mode;

			public:
				IPass*				GetFirstPass					() { return firstPass; }
				void				SetFirstPass					(IPass* firstPass) { this->firstPass = firstPass; }

				IPass*				GetFinalPass					() { return finalPass; }
				void				SetFinalPass					(IPass* finalPass) { this->finalPass = finalPass; }

				IPass*				GetDepthPrepass					() { return depthPrepass; }
				IPass*				GetGbufferPass					() { return gbufferPass; }
				IPass*				GetSkyPass					() { return skyPass; }
				IPass*				GetOpaquePass					() { return opaquePass; }
				IPass*				GetTransparentPass					() { return transparentPass; }
				IPass*				GetUiPass						() { return uiPass; }
				IPass*				GetPostProcessPass				() { return postProcessPass; }

				void				SetDepthPrepass					(IPass* pass) { this->depthPrepass = pass; }
				void				SetGbufferPass					(IPass* pass) { this->gbufferPass = pass; }
				void				SetSkyPass						(IPass* pass) { this->skyPass = pass; }
				void				SetOpaquePass					(IPass* pass) { this->opaquePass = pass; }
				void				SetTransparentPass				(IPass* pass) { this->transparentPass = pass; }
				void				SetUiPass						(IPass* pass) { this->uiPass = pass; }
				void				SetPostProcessPass				(IPass* pass) { this->postProcessPass = pass; }

				Mode				GetMode							() { return mode; }
				void				SetMode							(Mode mode) { this->mode = mode; }



				/**
				 *	Methods
				 */
			public:
				virtual void SetupCamera		(IDeviceContext* context, Camera* camera) override;
				virtual void ClearCameraData	(Camera* camera) override;

				virtual bool Render				(IDeviceContext* context) override;

			};

		}

	}

}