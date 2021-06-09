#include<Glewy/glewy.hpp>
#include<cmath>

namespace gly
{

class Anim : public Component
{
public:
	Anim(Entity* parent):Component(parent){}
	
	SpriteAtlas* sa;

	double tt = 0.05f;
	double tu = tt;

	vec2<gly_float> speed = {1.0f,1.0f};

	void Update(const UpdateInfo& info) override
	{
			if(tu<=0.0f){
				sa->SetIndex(sa->GetIndex()+1);
				tu = tt;
			}
			else{tu-=info.delta_time;}

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_E)){GetEntity()->GetRoot()->camera->SetSize(GetEntity()->GetRoot()->camera->GetSize()+info.delta_time);}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_Q)){GetEntity()->GetRoot()->camera->SetSize(GetEntity()->GetRoot()->camera->GetSize()-info.delta_time);}
	
		vec3<gly_float> pos = GetEntity()->GetRoot()->camera->GetPosition();

		vec2<gly_float> dis = speed*info.delta_time;

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_W)){GetEntity()->GetRoot()->camera->SetPosition({pos.x,pos.y+dis.y});}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_S)){GetEntity()->GetRoot()->camera->SetPosition({pos.x,pos.y-dis.y});}

		pos = GetEntity()->GetRoot()->camera->GetPosition();

		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_A)){GetEntity()->GetRoot()->camera->SetPosition({pos.x-dis.x,pos.y});}
		if(glfwGetKey(info.instance->GetWindow(), GLFW_KEY_D)){GetEntity()->GetRoot()->camera->SetPosition({pos.x+dis.x,pos.y});}
	
	}
};

}

using namespace gly;

int main()
{
	Instance instance({"Glewy Game",1000,1000});
	
	Root* root = new Root();
	Renderer* renderer = new Renderer({1000,1000});

	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.0f,0.0f,0.0f,1.0f});

	renderer->SetFrag("assets\\Shaders\\convolution.frag");

	root->camera->SetSize(3.0f);
	root->camera->SetAspectRatio(1.0f);
	instance.SetCurrentRoot(root);

	instance.Set_AR_Option(GLY_USE_ROOT_AR);

	Entity* e = root->CreateEntity();
	e->GetTransform()->SetPosition({-0.7f,0.0f,0.0f});
	SpriteAtlas* spr = e->AddAttachment<SpriteAtlas>();
	spr->SetTexture(new Texture("assets\\Images\\BlobSpike.png"));
	UVTable* uvt_blob_spike = new UVTable(22);
	uvt_blob_spike->Grid({4,6},TOP_LEFT);
	spr->SetUVTable(uvt_blob_spike);

	e->AddAttachment<Anim>();
	e->GetAttachment<Anim>()->sa = spr;
	e->GetAttachment<Anim>()->tt = 0.05f;

	Entity* e2 = root->CreateEntity();
	e2->GetTransform()->SetPosition({0.7f,0.0f,0.0f});
	SpriteAtlas* spr2 = e2->AddAttachment<SpriteAtlas>();
	spr2->SetTexture(new Texture("assets\\Images\\Werm.png"));
	UVTable* uvt_werm = new UVTable(5);
	uvt_werm->Grid({2,3},TOP_LEFT);
	spr2->SetUVTable(uvt_werm);

	e2->AddAttachment<Anim>();
	e2->GetAttachment<Anim>()->sa = spr2;
	e2->GetAttachment<Anim>()->tt = 0.08f;

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}