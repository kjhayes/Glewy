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
		
		void Link() const;

		void SetActive() const;
		void SetView(Camera*) const;
};

}
#endif