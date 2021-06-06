#include<Glewy/glewy.hpp>
#include<cmath>

namespace gly
{

class TestComp : public Component
{
public:
	TestComp(Entity* parent):Component(parent){}
	
	void Update(const UpdateInfo& info) override
	{
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_ESCAPE)){
			glfwSetWindowShouldClose(info.instance->GetWindow(), true);
		}
	}
};

}

int main()
{
	gly::Instance instance({"WERM",500,500});
	
	gly::Root* root = new gly::Root();
	gly::Renderer* renderer = new gly::Renderer({30,30});//BABY WERMS

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