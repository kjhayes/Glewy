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
//		std::cout<<"FPS: "<<1.0f/info.delta_time<<std::endl;
		
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
	Renderer* renderer = new Renderer({1920,1080});
	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.0f,0.0f,0.0f,1.0f});
//	renderer->SetFrag("assets\\Shaders\\convolution.frag");
	
	root->camera->SetSize(3.0f);
	root->camera->SetAspectRatio(16.0f/9.0f);
	instance.SetCurrentRoot(root);

	instance.Set_AR_Option(GLY_USE_ROOT_AR);

	Entity* f = root->CreateEntity();
	f->AddAttachment<FPS>();	

	float sqr_size = 10.0f;

	for(int i = 0; i<10000; i++){
		
		vec2<gly_float> random = {((float)rand())/((float)RAND_MAX)*sqr_size, ((float)rand())/((float)RAND_MAX)*sqr_size};
		random.x -= 0.5f*sqr_size;
		random.y -= 0.5f*sqr_size;

		Entity* e = root->CreateEntity();
		e->GetTransform()->SetPosition({random,0.0f});
		SpriteAtlas* spr = e->AddAttachment<SpriteAtlas>();

		spr->SetTexture(Asset<Texture>::GetAsset(TestContent::blob_spike_texture));
		
		UVTable* uvt_blob_spike = new UVTable(22);
		uvt_blob_spike->Grid({4,6},TOP_LEFT);
		spr->SetUVTable(uvt_blob_spike);

		e->AddAttachment<Anim>();
		Animation<int>* anim1 = new Animation<int>(22);

		for(int i = 0; i<22; i++){
			anim1->SetFrameData(i, {i, 0.05});
		}

		e->GetAttachment<Anim>()->anim = anim1;
		e->GetAttachment<Anim>()->sa = spr;


		Entity* e2 = root->CreateEntity();
		e2->GetTransform()->SetPosition({random,0.0f});
		e2->GetTransform()->SetRotation({0.0f,0.0f,3.1415f});
		SpriteAtlas* spr2 = e2->AddAttachment<SpriteAtlas>();
		spr2->SetTexture(Asset<Texture>::GetAsset(TestContent::blob_spike_texture));
		UVTable* uvt_werm = new UVTable(5);
		uvt_werm->Grid({2,3},TOP_LEFT);
		spr2->SetUVTable(uvt_werm);

		e2->AddAttachment<Anim>();

		Animation<int>* anim2 = new Animation<int>(5);

		for(int i = 0; i<5; i++){
			anim2->SetFrameData(i, {i, 0.1});
		}

		e2->GetAttachment<Anim>()->anim = anim2;
		e2->GetAttachment<Anim>()->sa = spr2;

	}

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}