#include<Glewy/glewy.hpp>
#include<cmath>

namespace gly
{

class TestComp : public Component
{
public:
	TestComp(Entity* parent):Component(parent){}

	SpriteAtlas* sa;
	bool pressed = false;

	void Update(const UpdateInfo& info) override
	{
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_ESCAPE)){
			glfwSetWindowShouldClose(info.instance->GetWindow(), true);
		}

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_D)){
			if(!pressed)
			{sa->SetIndex(sa->GetIndex()+1);std::cout<<sa->GetIndex()<<std::endl;}
			pressed = true;
		}
		
		else if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_A)){
			if(!pressed)
			{sa->SetIndex(sa->GetIndex()-1);std::cout<<sa->GetIndex()<<std::endl;}
			pressed = true;
		}
		else{
			pressed = false;
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
	gly::SpriteAtlas* spr = e->AddAttachment<gly::SpriteAtlas>();
	spr->SetTexture(new gly::Texture("assets\\Images\\BlobSpike.png"));
	spr->SetDimensions({4,6});

	gly::TestComp* tc = e->AddAttachment<gly::TestComp>();
	tc->sa = spr;

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}