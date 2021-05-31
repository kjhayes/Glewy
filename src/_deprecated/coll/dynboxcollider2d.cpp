#include<Glewy/dynboxcollider2d.hpp>
#include<Glewy/util.hpp>

namespace gly
{

void DynBoxCollider2D::Update(const UpdateInfo& info)
{
	ApplyNormals();
	velocity.x *= exp(-drag.x * info.delta_time);
	velocity.y *= exp(-drag.y * info.delta_time);
	if(velocity.x < min_velocity.x){velocity.x = min_velocity.x;}
	else if(velocity.x > max_velocity.x){velocity.x = max_velocity.x;}
	if(velocity.y < min_velocity.y){velocity.y = min_velocity.y;}
	else if(velocity.y > max_velocity.y){velocity.y = max_velocity.y;}
	TryMove(velocity*info.delta_time);
}

void DynBoxCollider2D::ApplyNormals()
{
	sml::vec3 scale = entity->transform.GetScale();
	sml::vec3 pos = entity->transform.GetPosition();

	sml::vec2 true_bl(bottom_left.x*scale.x, bottom_left.y*scale.y);
	sml::vec2 true_tr(top_right.x*scale.x, top_right.y*scale.y);

	true_bl.x += pos.x;true_bl.y += pos.y;
	true_tr.x += pos.x;true_tr.y += pos.y;

	std::list<sml::vec2> hor;
	std::list<sml::vec2> ver;

	float x_sign;
	float y_sign;

	if(velocity.x >= 0.0f){hor = Util::PointsBetween(sml::vec2(true_tr.x, true_bl.y), true_tr, 5);x_sign = 1.0f;}
	else{hor = Util::PointsBetween(true_bl, sml::vec2(true_bl.x, true_tr.y), 5); x_sign = -1.0f;}
	if(velocity.y > 0.0f){ver = Util::PointsBetween(true_tr, sml::vec2(true_bl.x, true_tr.y), 5); y_sign = 1.0f;}
	else{ver = Util::PointsBetween(true_bl, sml::vec2(true_tr.x, true_bl.y), 5); y_sign = -1.0f;}
	
	sml::vec2 inner_normal_skin(x_sign*-0.01f, y_sign*-0.01f);

	sml::vec2 hor_normal;float hor_count = 0.0f;
	for(auto iter = hor.begin(); iter != hor.end(); iter++)
	{
		Collision2D coll = Collider2D::GetClosestCollision({(*iter), {inner_normal_skin.x, 0.0f}});
		if(coll.collider!=nullptr){hor_count++; hor_normal+=coll.normal;}		
	}
	if(hor_count>0.0f)
	{
		hor_normal /= hor_count;
	}
	sml::vec2 ver_normal;float ver_count = 0.0f;
	for(auto iter = ver.begin(); iter != ver.end(); iter++)
	{
		Collision2D coll = Collider2D::GetClosestCollision({(*iter), {0.0f, inner_normal_skin.y}});
		if(coll.collider!=nullptr){ver_count++; ver_normal+=coll.normal;}
	}
	if(ver_count>0.0f)
	{
		ver_normal /= ver_count;
	}

	hor_normal*=abs(velocity.x);
	ver_normal*=abs(velocity.y);

	velocity += (hor_normal+ver_normal);
}

void DynBoxCollider2D::TryMove(const sml::vec2& distance)
{
	sml::vec3 scale = entity->transform.GetScale();
	sml::vec3 pos = entity->transform.GetPosition();

	sml::vec2 true_bl(bottom_left.x*scale.x, bottom_left.y*scale.y);
	sml::vec2 true_tr(top_right.x*scale.x, top_right.y*scale.y);

	true_bl.x += pos.x;true_bl.y += pos.y;
	true_tr.x += pos.x;true_tr.y += pos.y;

	std::list<sml::vec2> hor;
	std::list<sml::vec2> ver;

	if(distance.x >= 0.0f){hor = Util::PointsBetween(sml::vec2(true_tr.x, true_bl.y), true_tr, 5);}
	else{hor = Util::PointsBetween(true_bl, sml::vec2(true_bl.x, true_tr.y), 5);}
	if(distance.y > 0.0f){ver = Util::PointsBetween(true_tr, sml::vec2(true_bl.x, true_tr.y), 5);}
	else{ver = Util::PointsBetween(true_bl, sml::vec2(true_tr.x, true_bl.y), 5);}
	
    sml::vec2 diag_allowed = distance;
	for(auto iter = hor.begin(); iter != hor.end(); iter++)
    {
        Collision2D coll = Collider2D::GetClosestCollision({(*iter),diag_allowed});
        diag_allowed = coll.point - (*iter);
    }
    for(auto iter = ver.begin(); iter != ver.end(); iter++)
    {
        Collision2D coll = Collider2D::GetClosestCollision({(*iter),diag_allowed});
        diag_allowed = coll.point - (*iter);
    }
	sml::vec2 left = distance - diag_allowed;
	sml::vec2 hor_allowed(left.x, 0.0f);
	for(auto iter = hor.begin(); iter != hor.end(); iter++)
	{
		Collision2D coll = Collider2D::GetClosestCollision({(*iter)+diag_allowed, hor_allowed});
		hor_allowed = coll.point - ((*iter)+diag_allowed);
	}
	sml::vec2 ver_allowed(0.0f, left.y);
	for(auto iter = ver.begin(); iter != ver.end(); iter++)
	{
		Collision2D coll = Collider2D::GetClosestCollision({(*iter)+diag_allowed, ver_allowed});
		ver_allowed = coll.point - ((*iter)+diag_allowed);
	}
    entity->transform.SetPosition(pos+diag_allowed+hor_allowed+ver_allowed);
}

}