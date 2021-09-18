
#include<Glewy/Core/instance.hpp>
#include<Glewy/Core/root.hpp>

#include<Glewy/Rendering/renderer.hpp>

#include<Glewy/Scene/entity.hpp>

void LogTest(const char* test_name, const bool& status){
    if(status){
        std::cout<<test_name<<" : "<<"Passed"<<std::endl;
    }else{
        std::cout<<test_name<<" : "<<"Failed"<<std::endl;
    }
} 

int main(){
    gly::StartUp startParams = {"GLEWY TESTING WINDOW", {100,100}};
    
    gly::Instance* instance = new gly::Instance(startParams);
    LogTest("Instance Constructor", instance != nullptr);

    gly::Root* root = new gly::Root();
    LogTest("Root Constructor", root != nullptr);

    instance->SetCurrentRoot(root);
    LogTest("Root Set", instance->GetCurrentRoot() == root);

    gly::Renderer* renderer = new gly::Renderer({100,100});
    LogTest("Renderer Constructor", renderer != nullptr);

    instance->SetCurrentRenderer(renderer);
    LogTest("Renderer Set", instance->GetCurrentRenderer() == renderer);

    gly::Entity* entity = root->CreateEntity();
    LogTest("Entity Created", entity != nullptr && root->entity_registry.size() == 1);

    root->DestroyEntity(entity);
    entity = nullptr;
    LogTest("Entity Destroyed", root->entity_registry.size() == 0);
    
    instance->Run();

    delete instance;   
    delete root;
    delete renderer;

    return 1;
}
