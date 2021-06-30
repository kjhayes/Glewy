#include<Glewy/Standard/UtilAttachments/transformcontroller.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Input/button.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Core/awakeinfo.hpp>

namespace gly{

void TransformController::SetTransform(Transform* t){transform = t;}

TransformController::TransformController(Entity* e):Component(e){transform = e->GetTransform();}

void TransformController::Awake(const AwakeInfo& info){
    W = new Button(info.instance);
    W->keycode = (int)'W';
    A = new Button(info.instance);
    A->keycode = (int)'A';
    S = new Button(info.instance);
    S->keycode = (int)'S';
    D = new Button(info.instance);
    D->keycode = (int)'D';
    Q = new Button(info.instance);
    Q->keycode = (int)'Q';
    E = new Button(info.instance);
    E->keycode = (int)'E';
}

void TransformController::Sleep(const AwakeInfo& info){
    delete W;
    delete A;
    delete S;
    delete D;
    delete Q;
    delete E;
}

void TransformController::Update(const UpdateInfo& info){
    vec3<gly_float> s = transform->GetLocalScale();
    if(Q->active.GetValue()){s*=1.0f+(zoom_speed*info.delta_time);}
    if(E->active.GetValue()){s/=1.0f+(zoom_speed*info.delta_time);}
    transform->SetLocalScale(s);
    
    vec3<gly_float> pos = transform->GetLocalPosition();
    if(D->active.GetValue()){pos.x += s.x*speed.x*info.delta_time;}
    if(A->active.GetValue()){pos.x -= s.x*speed.x*info.delta_time;}

    if(W->active.GetValue()){pos.y += s.y*speed.y*info.delta_time;}
    if(S->active.GetValue()){pos.y -= s.y*speed.y*info.delta_time;}
    transform->SetLocalPosition(pos);
}

}