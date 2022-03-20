﻿
/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Thread And Thread Manager
 */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



/**
 *	Include Event And Event Manager
 */
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h> 



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h> 



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h> 



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h> 



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h> 



/**
 *	Include Window
 */
#include <ING/Window/Window.h> 



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h> 



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h> 



/**
 *	Include DX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h> 



/**
 *	Include Time
 */
#include <ING/Time/Time.h> 



/**
 *	Include Math
 */
#include <ING/Math/Math.h> 

using namespace ING::Math;



/**
 *	Include Color
 */
#include <ING/Color/Color.h> 



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h> 



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h> 



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h> 



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h> 



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h> 



/**
 *	Include Rendering Drawable Category
 */
#include <ING/Rendering/Drawable/Category/Category.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h>



/**
 *	Include Rendering Shader Pass
 */
#include <ING/Rendering/Shader/Pass/Pass.h>



/**
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include Rendering Drawable Material
 */
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>



/**
 *	Include Rendering Vertex Shader
 */
#include <ING/Rendering/API/Shader/VertexShader/VertexShader.h>



/**
 *	Include Rendering Pixel Shader
 */
#include <ING/Rendering/API/Shader/PixelShader/PixelShader.h>



/**
 *	Include Rendering Input Layout
 */
#include <ING/Rendering/API/InputLayout/InputLayout.h>



/**
 *	Include Rendering Mesh
 */
#include <ING/Rendering/Mesh/Mesh.h>



#include <xmmintrin.h>
#include <immintrin.h>



using namespace ING;



/* Sample Entity Component */
static struct SampleC {

	ECS::ComponentId id = 0;

};


/* Demo Entity Component System */
static ECS_COMPONENT_SYSTEM(SampleCSystem, SampleC)

public:
	virtual void Init		() override;
	virtual void Release	() override;



	/**
	 *	Event Methods
	 */
public:
	virtual void Awake(ECS::ComponentPtr<SampleC, SampleCSystem> componentPtr) override;
	virtual void Start(ECS::ComponentPtr<SampleC, SampleCSystem> componentPtr) override;
	virtual void Update() override;

};

		

void SampleCSystem::Init() {

	

}

void SampleCSystem::Release() {

	ComponentSystem<SampleC, SampleCSystem>::Release();

}



void SampleCSystem::Awake(ECS::ComponentPtr<SampleC, SampleCSystem> componentPtr) {

	//Debug::Log(String("SampleC ") + String(componentPtr.GetId()) + String(" Awake"));

}

void SampleCSystem::Start(ECS::ComponentPtr<SampleC, SampleCSystem> componentPtr) {

	//Debug::Log(String("SampleC ") + String(componentPtr.GetId()) + String(" Start"));

}

void SampleCSystem::Update() {

	ECS::ComponentSystem<SampleC, SampleCSystem>::Update();



	/**
	 *	Show FPS In Window Title
	 */
	static float t = 0;
	 
	t += Time::GetDeltaTime();

	if (t >= 1.0f) {

		t = 0;

		WindowManager::GetInstance()->GetMainWindow()->SetTitle(WString(L"FPS: ") + WString(Time::GetFPS()));

	}

	//for (SampleC& component : *this) {

	//	component.id = component.id * component.id * component.id;

	//}

}




#include <ING/AMath/AMath.h>

#include <ING/Profiler/Session/Session.h>

#include <ING/Rendering/Pass/Pass.h>
#include <ING/Rendering/Pipeline/Pipeline.h>

#include <ING/Rendering/StandardRP/Pipeline/Pipeline.h>
#include <ING/Rendering/StandardRP/Pass/First/First.h>
#include <ING/Rendering/StandardRP/Pass/Final/Final.h>
#include <ING/Rendering/StandardRP/Drawable/MeshDrawable/MeshDrawable.h>

#include <ING/Rendering/SubRP/Pipeline/Pipeline.h>
#include <ING/Rendering/SubRP/Pass/Pass.h>

#include <ING/Rendering/System/System.h>

#include <ING/Rendering/Renderer/Renderer.h>







/* Custom Rendering Pass Class */
class DemoPass : public Rendering::SubRP::Pass {

public:
	DemoPass(const std::string& name);
	~DemoPass();

public:
	virtual bool CustomRender(Rendering::IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output) override;

};


DemoPass::DemoPass(const std::string& name) : Pass(name) {



}

bool DemoPass::CustomRender(
	Rendering::IDeviceContext* context, 
	Camera* camera, 
	const Rendering::SubRP::PassInput& input, 
	Rendering::SubRP::PassOutput& output
) {

	Rendering::SubRP::PassOutput passOutput;

	IRenderer* renderer = Rendering::System::GetInstance()->GetPipeline()->GetRenderer();

	Rendering::Scene* scene = camera->GetRenderingScene();



	renderer->RenderDrawables(scene, "Opaque");



	output += passOutput;

	return true;
}



int main() {

	/**
	 *
	 * 
	 * This Demo Cant Draw Any thing ^^
	 *  
	 * 
	 */





	/* Create Application */
	ING::Application::CreateInstance();

	/* Init Application */
	ING::Application::GetInstance()->Init();



	/* Show Console Window */
	Window* consoleWindow = WindowManager::GetInstance()->GetConsoleWindow();
	consoleWindow->Show();



	/* On "RUN" */
	ING::Application::GetInstance()->GetEvent("RUN")->AddListener([](Event* event) {



		/* 
		*	Create Custom Rendering Pass 
		* 
		*	Only Add Pass To Pipeline In End Of Frame Or Rendering Thread
		*/
		Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* e) {		
			
			
			Rendering::IPass* demoPass = new DemoPass("Demo Pass");


			Rendering::System* renderingSystem = Rendering::System::GetInstance();

			Rendering::StandardRP::Pipeline* mainPipeline = (Rendering::StandardRP::Pipeline*)renderingSystem->GetTargetPipeline();


			Rendering::SubRP::Pipeline* subPipeline = mainPipeline->GetSubPipeline("After First Pipeline");

			subPipeline->AddPass(demoPass);

			
			mainPipeline->SetMode(Rendering::StandardRP::MODE_FORWARD);

			
			e->RemoveCurrentListener();
			
		});



		/* Create Camera */
		Camera* camera = new Camera();

		camera->SetActive(true);
		camera->SetScreen(ScreenManager::GetInstance()->GetMainScreen());
		camera->SetFOV(Math::Deg2Rad * 90.0f);
		camera->SetFarPlane(1000.0f);
		camera->SetNearPlane(0.1f);



		/* Create Rendering Scene */
		Rendering::Scene* renderingScene = new Rendering::Scene("Sample Rendering Scene");

		renderingScene->ContainLayers({
		
			0
			
		});

		camera->SetRenderingScene(renderingScene);



		/* Create Shaders */
		IVertexShader* vshader = IVertexShader::CreateFromHLSL(Rendering::IAPI::GetInstance()->GetDevice(), L"Assets/Shaders/DemoVS.hlsl");		
		IPixelShader* pshader = IPixelShader::CreateFromHLSL(Rendering::IAPI::GetInstance()->GetDevice(), L"Assets/Shaders/DemoPS.hlsl");

		IShader* shader = new Rendering::IShader("DemoShader");

		shader->AddPass("Demo Pass");

		shader->GetPass("Demo Pass")->AddChild("VertexShader", vshader);
		shader->GetPass("Demo Pass")->AddChild("PixelShader", vshader);

		shader->Apply("Demo Pass");


		/* Create Input Layout */
		IInputLayout* inputLayout = IInputLayout::Create(
			Rendering::IAPI::GetInstance()->GetDevice(),
			{

				{ "POSITION", 0, FORMAT_R32G32B32A32_FLOAT, 0, 0, INPUT_PER_VERTEX_DATA, 0 }

			},
			vshader
		);
		shader->GetPass("Demo Pass")->SetInputLayout(inputLayout);



		/* Create Material */
		IMaterial* material = new Rendering::DrawableMaterial("DemoMat", shader);


		/* Create Mesh (Triangle) */
		IMesh* mesh = new Mesh<Vector4>(
			{
				{0,0,0,1.0f},
				{0,1,0,1.0f},
				{1,0,0,1.0f}
			},
			{ 0, 1, 2 }
		);

		mesh->BuildBuffers();



		/* Create Mesh Drawable (It's something like an mesh can be drawn) */
		StandardRP::MeshDrawable* meshDrawable = new Rendering::StandardRP::MeshDrawable();

		meshDrawable->SetMesh(mesh);
		meshDrawable->SetMaterial(material);
		meshDrawable->SetActive(true);
		meshDrawable->SetCategories({

			"Opaque"

		});
		meshDrawable->SetLayer(0);






		/* ECS Demo */
		ECS::Repository* repository = new ECS::Repository();

		repository->SetActive(true);

		SampleCSystem* exampleCSystem = repository->CreateComponentSystem<SampleCSystem>();
		for (unsigned long i = 0; i < 0; ++i) {

			ECS::Entity* entity = repository->CreateEntity();

			exampleCSystem->AddComponent(entity)->id = i;

		}

	});



	/* Run Application */
	ING::Application::GetInstance()->Run();


	//system("pause");

	return 0;
}