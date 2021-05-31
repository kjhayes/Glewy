#include<Glewy/glewy.hpp>

namespace gly
{

class TestComp : public Component
{
	public:
		TestComp(Entity* parent):Component(parent){}
		void Update(const UpdateInfo& info) override
		{
			sml::vec3 pos = entity->GetTransform()->GetPosition();
			pos.x+=0.1f*info.delta_time;
			entity->GetTransform()->SetPosition(pos);
		}
};

}

int main()
{
	gly::Instance instance({"WERM",500,500});
	
	gly::Root* root = new gly::Root();
	
	instance.current_root = root;

	root->camera->SetSize(1.0f);
	root->camera->aspect_ratio = 1.0f;
	
	gly::Entity* parent = root->CreateEntity();
	
	gly::Sprite* sprite = parent->AddComponent<gly::Sprite>();
	sprite->texture = new gly::Texture("assets\\Images\\werm.png");

	gly::TestComp* tc = parent->AddComponent<gly::TestComp>();

	instance.Run();

	delete sprite->texture;
	delete root;

	return 0;
}