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
	gly::Instance instance({"WERM",500,500});
	
	gly::Root* root = new gly::Root();
	gly::Renderer* renderer = new gly::Renderer({500,500});

	instance.SetCurrentRenderer(renderer);
	renderer->SetClearColor({0.0f,0.0f,0.0f,1.0f});
	renderer->SetFrag("assets\\Shaders\\convolution.frag");

	root->camera->SetSize(1.0f);
	root->camera->SetAspectRatio(1.0f);
	instance.SetCurrentRoot(root);
	
	gly::Entity* parent = root->CreateEntity();
	
	parent->AddAttachment<gly::Sprite>();
	parent->GetAttachment<gly::Sprite>()->texture = new gly::Texture("assets\\Images\\werm.png");

	gly::Material* material = new gly::Material(false);
	material->SetVert_Data(gly::Sprite::sprite_vert_shader_default);
	material->SetFrag("assets\\Shaders\\color_shift.frag");
	material->Link();

	parent->GetAttachment<gly::Sprite>()->SetMaterial(material);	

	parent->AddAttachment<gly::TestComp>();
	
	instance.Run();
	
	delete root;

	return 0;
}