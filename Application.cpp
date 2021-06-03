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
		vec3<gly_float> pos = entity->GetTransform()->GetPosition();
		
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_ESCAPE)){
			glfwSetWindowShouldClose(info.instance->GetWindow(), true);
		}

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_D)){
			pos.x += info.delta_time;
		}
		else if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_A)){
			pos.x -= info.delta_time;
		}
		
		entity->GetTransform()->SetPosition(pos);
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
	
	gly::Entity* parent = root->CreateEntity();
	
	parent->AddComponent<gly::Sprite>();
	parent->GetComponent<gly::Sprite>()->texture = new gly::Texture("assets\\Images\\werm.png");

	parent->AddComponent<gly::TestComp>();

	instance.Run();

	delete root;

	return 0;
}