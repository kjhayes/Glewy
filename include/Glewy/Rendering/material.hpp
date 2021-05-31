#ifndef GLEWY_MATERIAL_HPP
#define GLEWY_MATERIAL_HPP

#include<list>

typedef unsigned int GLuint;

namespace gly
{

class Camera;
class MaterialRenderable;

class Material
{
	public:
		static std::list<Material*> registry;
		
		static void RenderAll(Camera*);

		std::list<MaterialRenderable*> to_render; 
		void Queue(MaterialRenderable*);
		void RenderQueue(Camera*);
		void ClearQueue();

		GLuint program;
		GLuint vert;
		GLuint frag;
		
		Material(bool load_def = true);
		Material(const char* vert, const char* frag, bool is_path=true); //else is_data

		~Material();

		void SetVert(const char*);
		void SetFrag(const char*);

		void SetVert_Data(const char*);
		void SetFrag_Data(const char*);
		
		void Load();

		void SetActive();
};

}
#endif