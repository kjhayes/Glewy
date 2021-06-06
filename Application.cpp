#include<Glewy/glewy.hpp>
#include<cmath>

namespace gly
{

class TestComp : public Component
{
public:
	TestComp(Entity* parent):Component(parent){}

	modulo_tau<gly_float> val = 0.0f;

	void Update(const UpdateInfo& info) override
	{
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_ESCAPE)){
			glfwSetWindowShouldClose(info.instance->GetWindow(), true);
		}

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_D)){
			val+= (float)info.delta_time;
			this->GetEntity()->GetTransform()->SetRotation({0.0f,0.0f,val});
		}
		std::cout<<val.GetValue()<<std::endl;
	}
};

}

int main()
{
	gly::Instance instance({"WERM",500,500});
	
	gly::Root* root = new gly::Root();
	gly::Renderer* renderer = new gly::Renderer({100,100});//BABY WERMS

	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.5f,0.5f,0.5f,1.0f});

	root->camera->SetSize(1.0f);
	root->camera->SetAspectRatio(1.0f);
	instance.SetCurrentRoot(root);
	
	gly::Entity* parent = root->CreateEntity();
	
	parent->AddAttachment<gly::Sprite>();
	parent->GetAttachment<gly::Sprite>()->texture = new gly::Texture("assets\\Images\\werm.png");
	parent->AddAttachment<gly::TestComp>();
	
	instance.Run();
	
	delete root;

	return 0;
}