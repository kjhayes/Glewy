#include<Glewy/rect.hpp>

namespace gly
{

//Constructors
Rect::Rect(const unsigned int& pivot):pivot(pivot){UpdateRect();}

Rect::Rect(const sml::vec2& position, const unsigned int& pivot):location{position.x,position.y},pivot(pivot){UpdateRect();}

Rect::Rect(const sml::vec2& position, const float& depth, const unsigned int& pivot):location{position.x,position.y,depth},pivot(pivot){UpdateRect();}

Rect::Rect(const sml::vec3& location, const unsigned int& pivot):location(location),pivot(pivot){UpdateRect();}			

Rect::Rect(const sml::vec2& position, const sml::vec2& dimensions, const unsigned int& pivot):location{position.x,position.y},dimensions(dimensions),pivot(pivot){UpdateRect();}

Rect::Rect(const sml::vec2& position, const float& depth, const sml::vec2& dimensions, const unsigned int& pivot):location{position.x,position.y,depth},dimensions(dimensions),pivot(pivot){UpdateRect();}

Rect::Rect(const sml::vec3& location, const sml::vec2& dimensions, const unsigned int& pivot):location(location),dimensions(dimensions),pivot(pivot){UpdateRect();}

//

void Rect::SetPosition(const sml::vec2& position)
{
	this->location.x = position.x;
	this->location.y = position.y;
	UpdateRect();
}
void Rect::SetLocation(const sml::vec3& location)
{
	this->location = location;
	UpdateRect();
}
void Rect::SetDepth(const float& depth)
{
	this->location.z = depth;
	UpdateRect();
}
void Rect::SetDimensions(const sml::vec2& dimensions)
{
	this->dimensions = dimensions;
	UpdateRect();
}

void Rect::SetPositionAndDimensions(const sml::vec2& position, const sml::vec2& dimensions)
{
	this->location.x = position.x;
	this->location.y = position.y;
	this->dimensions = dimensions;
	UpdateRect();
}
void Rect::SetLocationAndDimensions(const sml::vec3& location, const sml::vec2& dimensions)
{
	this->location = location;
	this->dimensions = dimensions;
	UpdateRect();
}
void Rect::SetPositionDepthAndDimensions(const sml::vec2& position, const float& depth, const sml::vec2& dimensions)
{
	this->location.x = position.x;
	this->location.y = position.y;
	this->location.z = depth;
	this->dimensions = dimensions;
	UpdateRect();
}
void Rect::SetDepthAndDimensions(const float& depth, const sml::vec2& dimensions)
{
	this->location.z = depth;
	this->dimensions = dimensions;
	UpdateRect();
}

void Rect::SetPivot(const unsigned int& pivot){this->pivot = pivot;}

sml::vec2 Rect::GetPosition() const {return (sml::vec2)this->location;}
sml::vec3 Rect::GetLocation() const {return this->location;}
float Rect::GetDepth() const {return location.z;}
sml::vec2 Rect::GetDimensions() const {return this->dimensions;}

unsigned int Rect::GetPivot() const {return this->pivot;}

sml::vec3 Rect::GetVertex(const unsigned int& vertex) const {return this->Vertices[vertex];}
sml::vec3* Rect::GetVertices(){return this->Vertices;}

void Rect::UpdateRect()
{
	Vertices[this->pivot] = location;
	switch(this->pivot)
	{
		case 0:
		{
			Vertices[3] = location + (sml::vec3)dimensions;
			Vertices[2] = location;
			Vertices[2].y += dimensions.y; 
			Vertices[1] = location;
			Vertices[1].x += dimensions.x;
			return;
		}
		case 1:
		{
			Vertices[0] = location;
			Vertices[0].x -= dimensions.x;
			Vertices[3] = Vertices[0] + dimensions;
			Vertices[2] = Vertices[0];
			Vertices[2].y += dimensions.y;
			return;
		}
		case 2:
		{
			Vertices[0] = location;
			Vertices[0].y -= dimensions.y;
			Vertices[3] = Vertices[0] + (sml::vec3)dimensions;
			Vertices[1] = Vertices[0];
			Vertices[1].x += dimensions.x;
			return;
		}
		case 3:
		{
			Vertices[0] = location - (sml::vec3)dimensions;
			Vertices[2] = location;
			Vertices[2].x -= dimensions.x;
			Vertices[1] = location;
			Vertices[1].y -= dimensions.y;
			return;
		}
	}
}//class Rect
}//namespace gly