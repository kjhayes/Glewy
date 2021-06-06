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

	gly::Entity* background = root->CreateEntity();
	gly::Sprite* bkground_spr = background->AddAttachment<gly::Sprite>();
	bkground_spr->texture = new gly::Texture(gly::vec4<gly_float>(0.0f,0.0f,0.7f,1.0f));
	background->GetTransform()->SetScale((gly::vec3<gly_float>)gly::vec2<gly_float>(root->camera->GetAspectRatio(), 1.0f)*root->camera->GetSize());

	gly::Texture* block_tex = new gly::Texture("assets\\Images\\werm.png");

	gly::Entity* entities[9];
	for(int i = 0; i<9; i++){
		entities[i] = root->CreateEntity();
		entities[i]->GetTransform()->SetScale({0.5f,0.5f,1.0f});
		gly::Sprite* s = entities[i]->AddAttachment<gly::Sprite>();
		entities[i]->AddAttachment<gly::TestComp>();
		s->texture = block_tex;
	}
	float dis = 0.5f;
	entities[0]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(-dis,-dis));
	entities[1]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(0.0f,-dis));
	entities[2]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(dis,-dis));
	entities[3]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(-dis,0.0f));
	entities[4]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(0.0f,0.0f));
	entities[5]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(dis,0.0f));
	entities[6]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(-dis,dis));
	entities[7]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(0.0f,dis));
	entities[8]->GetTransform()->SetPosition((gly::vec3<gly_float>)gly::vec2<gly_float>(dis,dis));

	instance.Run();
	
	delete root;
	delete renderer;

	return 0;
}