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
	
	root->camera->SetSize(1.0f);
	root->camera->SetAspectRatio(1.0f);

	instance.SetCurrentRoot(root);
	instance.SetClearColor({0, 200, 50, 0});

	gly::Entity* parent = root->CreateEntity();
	
	parent->AddComponent<gly::Sprite>();
	parent->GetComponent<gly::Sprite>()->texture = new gly::Texture("assets\\Images\\werm.png");

	parent->AddComponent<gly::TestComp>();

	instance.Run();

	delete root;

	return 0;
}