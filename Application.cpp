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
			val-= (float)info.delta_time;
			this->GetEntity()->GetTransform()->SetRotation({0.0f,0.0f,val});
		}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_A)){
			val+= (float)info.delta_time;
			this->GetEntity()->GetTransform()->SetRotation({0.0f,0.0f,val});
		}
	}
};

}


int main()
{
	gly::Instance instance({"Glewy Game",1000,1000});
	
	gly::Root* root = new gly::Root();
	gly::Renderer* renderer = new gly::Renderer({1000,1000});

	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.0f,0.0f,0.5f,0.0f});

	//renderer->SetFrag("assets\\Shaders\\convolution.frag");

	root->camera->SetSize(2.0f);
	root->camera->SetAspectRatio(1.0f);
	instance.SetCurrentRoot(root);

	instance.Set_AR_Option(gly::GLY_USE_ROOT_AR);

	gly::Entity* e = root->CreateEntity();
	gly::Sprite* spr = e->AddAttachment<gly::Sprite>();
	spr->SetTexture(new gly::Texture("assets\\Images\\BlobSpike.png"));
	
	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}