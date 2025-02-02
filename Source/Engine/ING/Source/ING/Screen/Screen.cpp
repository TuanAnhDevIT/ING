
/**
 *	Include Header
 */
#include "Screen.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Rendering API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Window Event
 */
#include <ING/Window/Event/Event.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Screen::Screen(IWindow* window) :
		isMain(false),
		swapChain(0),
		window(0)
	{

		this->window = window;

		ScreenDesc desc;

		InitWithDesc(desc);

	}

	Screen::Screen(IWindow* window, ScreenDesc desc) :
		isMain(false),
		swapChain(0),
		window(0)
	{

		this->window = window;

		InitWithDesc(desc);

	}

	Screen::~Screen()
	{



	}



	/**
	 *	InitWithDesc, Release Methods
	 */
	void Screen::InitWithDesc(ScreenDesc desc) {

		this->desc = desc;

		if (desc.initSwapChain) {

			/* Create SwapChain */
			Rendering::IDevice* device = Rendering::APIManager::GetInstance()->GetAPI()->GetDevice();

			swapChain = Rendering::ISwapChain::Create(device, window);

			ScreenManager::GetInstance()->InitScreen(this);

		}

	}

	void Screen::Release()
	{

		cameraList.Foreach([](Camera*& camera) {
			
			camera->SetScreen(0);
			
		});

		if(swapChain != nullptr)
			swapChain->Release();

		delete this;

		int a = 0;

	}



	/**
	 *	Properties
	 */
	float	Screen::GetAspectRatio	() {

		return (window->GetDesc().clientWidth) / (window->GetDesc().clientHeight);

	}

	float	Screen::GetClientHeight	() {

		return (window->GetDesc().clientHeight);

	}
	float	Screen::GetClientWidth	() {

		return (window->GetDesc().clientWidth);

	}



	/**
	 *	Methods
	 */
	List<Camera*>::Node* Screen::AddCamera(Camera* camera) {

		return cameraList.Add(camera);

	}

	void	Screen::RemoveCamera(Camera* camera) {

		cameraList.Remove(camera->GetNodeInScreenCameraList());

	}
	
}