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
			sml::vec3 pos = entity->GetTransform()->GetPosition();
			if(pos.x>1.0f){
				pos = -1.0f;
			}
			pos.x+=0.2f*info.delta_time;
			pos.y= 0.1f * sin(pos.x*20.0f);
			entity->GetTransform()->SetPosition(pos);
		}
};

}

int main()
{
	gly::Instance instance({"WERM",500,500});
	
	gly::Root* root = new gly::Root();
	
	root->camera->SetSize(1.0f);
	root->camera->aspect_ratio = 1.0f;

	instance.SetCurrentRoot(root);
	
	gly::Entity* parent = root->CreateEntity();
	
	gly::Sprite* sprite = parent->AddComponent<gly::Sprite>();
	sprite->texture = new gly::Texture("assets\\Images\\werm.png");

	gly::TestComp* tc = parent->AddComponent<gly::TestComp>();

	instance.Run();

	delete sprite->texture;
	delete root;

	return 0;
}