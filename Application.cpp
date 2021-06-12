#include<Glewy/glewy.hpp>
#include<cmath>
#include<cstdlib>

namespace gly
{

class FPS : public Component{
public:
	FPS(Entity* parent):Component(parent){}

	vec2<gly_float> speed = {1.0f,1.0f};

	void Update(const UpdateInfo& info){
		std::cout<<"FPS: "<<1.0f/info.delta_time<<std::endl;
		
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_E)){GetEntity()->GetRoot()->camera->SetSize(GetEntity()->GetRoot()->camera->GetSize()+info.delta_time);}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_Q)){GetEntity()->GetRoot()->camera->SetSize(GetEntity()->GetRoot()->camera->GetSize()-info.delta_time);}
	
		vec3<gly_float> pos = GetEntity()->GetRoot()->camera->GetPosition();

		vec2<gly_float> dis = (speed * info.delta_time) * GetEntity()->GetRoot()->camera->GetSize();

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_W)){GetEntity()->GetRoot()->camera->SetPosition({pos.x,pos.y+dis.y});}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_S)){GetEntity()->GetRoot()->camera->SetPosition({pos.x,pos.y-dis.y});}

		pos = GetEntity()->GetRoot()->camera->GetPosition();

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_A)){GetEntity()->GetRoot()->camera->SetPosition({pos.x-dis.x,pos.y});}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_D)){GetEntity()->GetRoot()->camera->SetPosition({pos.x+dis.x,pos.y});}	
	}
};

class Anim : public Component
{
public:
	Anim(Entity* parent):Component(parent){}
	
	SpriteAtlas* sa;

	Animation<int>* anim;

	void Update(const UpdateInfo& info) override
	{
		anim->Tick(info.delta_time);
		sa->SetIndex(anim->CurrentFrame());
	}
};

}

using namespace gly;

int main()
{
	Instance instance({"Glewy Game",{1000,1000}});
	Root* root = new Root();
	Renderer* renderer = new Renderer({1000,1000});
	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.0f,0.0f,0.0f,1.0f});
//	renderer->SetFrag("assets\\Shaders\\convolution.frag");
	
	root->camera->SetSize(3.0f);
	root->camera->SetAspectRatio(1.0f);
	instance.SetCurrentRoot(root);

	instance.Set_AR_Option(GLY_USE_ROOT_AR);

	Entity* f = root->CreateEntity();
	f->AddAttachment<FPS>();	

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}