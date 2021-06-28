#include<Glewy/Standard/UtilAttachments/cameracontroller.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Input/button.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Core/awakeinfo.hpp>

namespace gly{

CameraController::CameraController(Entity* e):Component(e){}

void CameraController::Awake(const AwakeInfo& info){
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

void CameraController::Sleep(const AwakeInfo& info){
    delete W;
    delete A;
    delete S;
    delete D;
    delete Q;
    delete E;
}

void CameraController::Update(const UpdateInfo& info){
    float s = GetEntity()->GetRoot()->camera->GetSize();
    if(Q->active.GetValue()){s*=1.0f+(zoom_speed*info.delta_time);}
    if(E->active.GetValue()){s/=1.0f+(zoom_speed*info.delta_time);}
    GetEntity()->GetRoot()->camera->SetSize(s);
    
    vec3<gly_float> pos = GetEntity()->GetRoot()->camera->GetPosition();
    if(D->active.GetValue()){pos.x += s*speed.x*info.delta_time;}
    if(A->active.GetValue()){pos.x -= s*speed.x*info.delta_time;}

    if(W->active.GetValue()){pos.y += s*speed.y*info.delta_time;}
    if(S->active.GetValue()){pos.y -= s*speed.y*info.delta_time;}
    GetEntity()->GetRoot()->camera->SetPosition(pos);
}

}