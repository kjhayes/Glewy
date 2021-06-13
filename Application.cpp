#include<Glewy/glewy.hpp>
#include<cmath>
#include<cstdlib>
#include<Assets/TestAssets.hpp>

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
	Instance instance({"Glewy",{100,100}});
	Root* root = new Root();
	Renderer* renderer = new Renderer({1920,1080});
	instance.SetCurrentRenderer(renderer);

	instance.SetClearColor({0.3f,0.1f,0.3f,1.0f});
	renderer->SetClearColor({0.5f,0.1f,0.6f,1.0f});

	root->camera->SetSize(3.0f);
	root->camera->SetAspectRatio(16.0f/9.0f);
	instance.SetCurrentRoot(root);

	instance.Set_AR_Option(GLY_USE_ROOT_AR);

	Entity* f = root->CreateEntity();
	f->AddAttachment<FPS>();	

	UVTable* uv = UVTable::GetAsset(TestAssets::BlobSpikeTable);

	SpriteAtlas* atlas = f->AddAttachment<SpriteAtlas>();
	Anim* anim = f->AddAttachment<Anim>();
	anim->anim = new Animation<int>(22);
	for(int i = 0; i<22; i++){
		anim->anim->SetFrameData(i, {i, 0.05f});
	}
	anim->sa = atlas;
	atlas->SetUVTable(uv);
	atlas->SetTexture(Texture::GetAsset(TestAssets::BlobSpikeTex));

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}